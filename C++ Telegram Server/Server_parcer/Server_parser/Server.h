#pragma once
#include "string"
#include "thread"

class Server
{
public:
	Server();
	~Server();
	void start();
	void server();

	std::string token;
	std::string url;
	bool work;
	char Url;
	char Token;


	std::string update_id;

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
};

