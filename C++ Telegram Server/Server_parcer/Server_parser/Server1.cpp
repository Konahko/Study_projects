#include "Server.h"
#include "iostream"
#include "thread"
#include "string"
#include <time.h>
#include <conio.h>

#include <vector>

#include <windows.h>
#include "wininet.h";
#include <strstream> //for std::strstream

#include "parser.h"
#pragma comment(lib,"wininet")



#include <nlohmann/json.hpp>



using namespace std;
using json = nlohmann::json;



Server::Server()
{
	string token = "814664800:AAFCf9cmFhzoGNNq2kSIqU4xzvBFo2Bw3ng";
	string url = "https://api.telegram.org/bot";
	char Token[] = "814664800:AAFCf9cmFhzoGNNq2kSIqU4xzvBFo2Bw3ng";
	char Url[] = "https://api.telegram.org/bot";
	bool work = 0;
	update_id = "";
}


Server::~Server()
{
}



//void Server::server(string update_id, string message_id, string from_id, bool is_bot, string furst_name, string last_name, 
//	string username, string language_code, string chat_id, string chat_type, string date, string message_text)
void server1()
{
	string s_stream;
	std::string update_id="1";

	//message

	std::string message_id;
	std::string from_id;
	bool is_bot;
	std::string first_name;
	std::string last_name;
	std::string username;
	std::string language_code;

	//chat

	std::string chat_id;
	std::string chat_type;
	std::string date;
	std::string message_text;



	



	struct tm newtime;


	cout << "ID процесса парсера" << this_thread::get_id << endl;
	while (1)
	{
		
		time_t t = time(NULL);
		localtime_s(&newtime,&t);
		cout << newtime.tm_hour<<":"<< newtime.tm_min <<":"<< newtime.tm_sec <<endl;

		static string response = "";
	//	string cache_response = "";

		bool ok = false;

		// инициализируем WinInet
		HINTERNET hInternet =
			::InternetOpen(
				TEXT("WinInet Test"),
				INTERNET_OPEN_TYPE_PRECONFIG,
				NULL, NULL,
				0);

		if (hInternet != NULL) {
			// открываем HTTP сессию
			HINTERNET hConnect =
				::InternetConnect(
					hInternet,
					TEXT("api.telegram.org"),
					INTERNET_DEFAULT_HTTP_PORT,
					NULL, NULL,
					INTERNET_SERVICE_HTTP,
					0,
					1u);

			int update_int = stol(update_id);
			update_int++;
			//обратная конвертация



			update_id = to_string(update_int);

			cout << update_id << "UPDATE" << endl;

			s_stream = "bot814664800:AAFCf9cmFhzoGNNq2kSIqU4xzvBFo2Bw3ng/getupdates?offset="+update_id;
			cout << s_stream << "s_stream" << endl;
			LPCSTR lp_string = s_stream.c_str();
			//lp_string ;

			if (hConnect != NULL) {
				// открываем запрос
				HINTERNET hRequest =
					::HttpOpenRequest(
						hConnect,
						TEXT("GET"),
						TEXT(lp_string),
						NULL,
						NULL,
						0,
						INTERNET_FLAG_KEEP_CONNECTION,
						1);

				if (hRequest != NULL) {
					// посылаем запрос
					BOOL bSend = ::HttpSendRequest(hRequest, NULL, 0, NULL, 0);
					if (bSend) {
						while (1)
						{
							// читаем данные
							char  szData[9024];
							DWORD dwBytesRead;
							BOOL bRead =
								::InternetReadFile(
									hRequest,
									szData, sizeof(szData) - 1,
									&dwBytesRead);
							// выход из цикла при ошибке или завершении, чиска загрузки
							if (bRead == FALSE || dwBytesRead == 0)
							{
								strcpy_s(szData, "");
								//for (int i = 0; i < 1024; i++) szData[i] = NULL;
								dwBytesRead = NULL;
								bRead = NULL;
								bSend = NULL;
								hRequest=NULL;
								break;
							}

							// сохраняем результат
							szData[dwBytesRead] = 0;
							response = szData;

							ok = true;
						}
					}
					// закрываем запрос
					::InternetCloseHandle(hRequest);
				}
				// закрываем сессию
				::InternetCloseHandle(hConnect);
			}
			// закрываем WinInet
			::InternetCloseHandle(hInternet);
		}
		else
		{
			cout << "Ошибка иниациализации. Ошибка Winapi " << GetLastError;
		}
//		cout << response << endl;
		if (response == "")
		{
			cout << "Ответ не получен, проверьте подключение к интернету или настройки сети" << endl;
		}
		else
		{

			//версия на 1 сообщение
			/*

			json json_response = json::parse(response);
			json cache_response;
			json cache_response1;
			cout << json_response << endl;
			*/
			// версия на стопку
			json json_response;
			json cache_response;
			json cache_response1;



			//if (json_response["ok"] == true)
			if (response.substr(6, 4) == "true")
			{	//смотрим результат
//				cout << json_response["result"] << endl;	
			//	cache_response = json_response["result"];
				//избавляемся от [] в ответе и парсим по новой
			//	string aa = cache_response.dump();
				//aa = aa.substr(1, aa.size() - 2);
				//проверяем наличия результата

				//json_response = json::parse(response.substr(21, response.size()-23));
				int entered_messages = 0; // вошло сообщений
				int r_message = 21;// последняя точка захода
				vector<string> messages; // вектор хранящий в себе все сообщения

				cout <<endl<<endl <<"FFFFFF"<<endl<< response.substr(21, response.size() - 24).c_str();

			static	char response_c[] = "";
				strcpy(response_c, response.substr(21, response.size() - 24).c_str());


				for (int i = 0; i < response.size() - 24; i++)
				{
					if (response_c[i] == '}')
					{
						if (response_c[i + 1] == '}')
						{
							if (response_c[i + 2] == ',')
							{
								if (response_c[i + 3] == '{')
								{
									if (response_c[i + 4] == '"')
									{
										if (response_c[i + 5] == 'u')
										{
											if (response_c[i + 6] == 'p')
											{
												if (response_c[i + 7] == 'd')
												{
													if (response_c[i + 8] == 'a')
													{
														messages.push_back(response.substr(r_message, i+23-r_message));
														entered_messages++;
														r_message = i + 24;
														i = i + 8;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				messages.push_back(response.substr(r_message, response.size() - 2 - r_message));

				//работаем с векторами отдельных сообщений
				for (int i = 0; i < entered_messages; i++)
				{
					cout <<endl<<"вывод"<<endl<< messages[i]<<endl;
					json_response = json::parse(messages[i]);

					string aa;

					if (aa != "")
					{
						parser pars;
						string& ab = aa;
						static				string ao;
						ao.begin();

						//раскодировка в юникод
								//			ao= pars.rebuild(ab);

						cache_response1 = json::parse(aa);
						//		cout << cache_response1 << endl << endl;;
								//берем update_id
						update_id = cache_response1["update_id"].dump();

						//message
						cache_response = cache_response1["message"];
						message_text = cache_response["text"].dump();
						message_id = cache_response["message_id"].dump();
						date = cache_response["date"].dump();


						//from
						cache_response1 = cache_response["from"];
						from_id = cache_response1["id"].dump();
						first_name = cache_response1["first_name"].dump();
						last_name = cache_response1["last_name"].dump();
						username = cache_response1["username"].dump();
						language_code = cache_response1["language_code"].dump();
						if (cache_response1["is_bot"].dump() == "true")
							is_bot = true;
						else
							is_bot = false;

						//chat

						cache_response1 = cache_response["chat"];

						chat_id = cache_response1["chat_id"].dump();
						chat_type = cache_response1["type"].dump();



						cout << update_id << endl;
						cout << message_text << endl;
						cout << message_id << endl;
						cout << from_id << endl;
						cout << first_name << endl;
						cout << last_name << endl;
						cout << username << endl;
						cout << language_code << endl;
						cout << is_bot << endl;
						cout << chat_id << endl;
						cout << chat_type << endl;
						cout << date << endl;



						//cout<< отвечаем

						HINTERNET hInternet =
							::InternetOpen(
								TEXT("WinInet Test"),
								INTERNET_OPEN_TYPE_PRECONFIG,
								NULL, NULL,
								0);

						if (hInternet != NULL) {
							// открываем HTTP сессию
							HINTERNET hConnect =
								::InternetConnect(
									hInternet,
									TEXT("api.telegram.org"),
									INTERNET_DEFAULT_HTTP_PORT,
									NULL, NULL,
									INTERNET_SERVICE_HTTP,
									0,
									1u);


							//s_stream = "bot814664800:AAFCf9cmFhzoGNNq2kSIqU4xzvBFo2Bw3ng/sendmessage?chat_id=" + chat_id + "&text=" + message_text;
							s_stream = "bot814664800:AAFCf9cmFhzoGNNq2kSIqU4xzvBFo2Bw3ng/sendmessage?chat_id=" + from_id + "&text=" + message_text;
							LPCSTR lp_string = s_stream.c_str();
							if (hConnect != NULL) {
								// открываем запрос
								HINTERNET hRequest =
									::HttpOpenRequest(
										hConnect,
										TEXT("GET"),
										TEXT(lp_string),
										NULL,
										NULL,
										0,
										INTERNET_FLAG_KEEP_CONNECTION,
										1);

								if (hRequest != NULL) {
									// посылаем запрос
									BOOL bSend = ::HttpSendRequest(hRequest, NULL, 0, NULL, 0);
									if (bSend) {

										cout << "Отправлено сообщение " << from_id << " " << username;
										ok = true;
									}
								}
								// закрываем запрос
								::InternetCloseHandle(hRequest);
							}
							// закрываем сессию
							::InternetCloseHandle(hConnect);
						}
						// закрываем WinInet
						::InternetCloseHandle(hInternet);


					}
					else
						cout << "Обновления отсутствуют" << endl << endl;
				}
			}
			else
			{
				cout << "Ошибка обработки запроса"<<endl<<endl;
			}
		}
		
		cout << first_name << " " << last_name << endl;
		//cout << this_thread::get_id << endl;
		this_thread::sleep_for(chrono::seconds(20));
	}
}


void Server::start()
{ 
	cout << "Запуск сервера." << endl;
	char a='-';
	cout << "Для открытия меню нажмите на любую клавишу" << endl;;
	//auto sr = thread(&Server::server, this, update_id, message_id, from_id, is_bot, furst_name, last_name,
	//	username, language_code, chat_id, chat_type, date, message_text);
	//auto sr = thread(&Server::server, this);
	//thread tr(cutak);
	thread sr(server1);
	sr.detach();

	cout << "ID процесса сервера" << this_thread::get_id << endl;
	while (1)
	{
		a = _getch();
		if (a != '-')
		{
			break;
		}
	} 
	
	cout << "завершение работы";
	
	






}


