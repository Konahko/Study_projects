#include "parser.h"
#include "string"
#include "thread"
#include "iostream"

using namespace std;

parser::parser()
{
	
 
}


parser::~parser()
{
}

string parser::rebuild(static string input)
{
	cout << "ID �������� ������" << this_thread::get_id << endl;
	static char symbols[67];
	strcpy_s(symbols, "�����������娸����������������������������������������������������");
	static	string	symbols_code[66] = {/*A*/"u0410", /*�*/"u0430", /*�*/"u0411", /*�*/"u0431", /*�*/"u0412",/*�*/"u0432",
		/*�*/"u0413", /*�*/"u0433", /*�*/"u0414", /*�*/"u0434", /*�*/"u0415", /*�*/"u0435", /*�*/"u0401",
		/*�*/"u451", /*�*/"u0416", /*�*/"u0436", /*�*/"u0417", /*�*/"u0437", /*�*/"u0418", /*�*/"u0438", /*�*/"u0419",
		/*�*/"u0439", /*�*/"u041a", /*�*/"u043a", /*�*/"u041b", /*�*/"u043b", /*�*/"u041c", /*�*/"u043c", /*�*/"u041d",
		/*�*/"u043d", /*�*/"u041e", /*�*/"u043e", /*�*/"u041F", /*�*/"u043f", /*�*/"u0420", /*�*/"u0440", /*�*/"u0421", /*�*/"u0441",
		/*�*/"u0422", /*�*/"u0442", /*�*/"u0423", /*�*/"u0443", /*�*/"u0424", /*�*/"u0444", /*�*/"u0425", /*�*/"u0445", /*�*/"u0426",
		/*�*/"u0446", /*�*/"u0427", /*�*/"u0447", /*�*/"u0428", /*�*/"u0448", /*�*/"u0429", /*�*/"u0449", /*�*/"u042a", /*�*/"u044a",
		/*�*/"u042b", /*�*/"u044b", /*�*/"u042c", /*�*/"u044c", /*�*/"u042d", /*�*/"u044d", /*�*/"u042e", /*�*/"u044e", /*�*/"u042f", /*�*/"u044f" };

	static string output="{";
	static string compare;
	char char_massive_input[]="";
	bool swap;
	int massive_size = input.size();
	strcpy(char_massive_input, input.c_str());
//	input = "";
	for (int i = 1; i < massive_size-2; i++)
	{
		swap = false;
		if (char_massive_input[i] == '\\')
		{
			if (char_massive_input[i + 1] == 'u')
			{
				if (char_massive_input[i + 2] == '0')
				{
					if (char_massive_input[i + 3] == '4')
					{
						compare = "u04";
						compare += char_massive_input[i + 4];
						compare += char_massive_input[i + 5];
						
						for (int ii = 0; ii < 66; ii++)
						{
							if (symbols_code[ii]==compare)
							{
								output = output + symbols[ii];
								swap = true;
								i = i + 5;
								compare = "";
								break;
							}
						}
					}
				}
			}
		}
		if (swap == false)
			output += char_massive_input[i];		
	}


	return output;
}

