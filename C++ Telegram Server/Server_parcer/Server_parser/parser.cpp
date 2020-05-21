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
	cout << "ID ïğîöåññà çàìåíû" << this_thread::get_id << endl;
	static char symbols[67];
	strcpy_s(symbols, "ÀàÁáÂâÃãÄäÅå¨¸ÆæÇçÈèÉéÊêËëÌìÍíÎîÏïĞğÑñÒòÓóÔôÕõÖö×÷ØøÙùÚúÛûÜüİıŞşßÿ");
	static	string	symbols_code[66] = {/*A*/"u0410", /*à*/"u0430", /*Á*/"u0411", /*á*/"u0431", /*Â*/"u0412",/*â*/"u0432",
		/*Ã*/"u0413", /*ã*/"u0433", /*Ä*/"u0414", /*ä*/"u0434", /*Å*/"u0415", /*å*/"u0435", /*¨*/"u0401",
		/*¸*/"u451", /*Æ*/"u0416", /*æ*/"u0436", /*Ç*/"u0417", /*ç*/"u0437", /*È*/"u0418", /*è*/"u0438", /*É*/"u0419",
		/*é*/"u0439", /*Ê*/"u041a", /*ê*/"u043a", /*Ë*/"u041b", /*ë*/"u043b", /*Ì*/"u041c", /*ì*/"u043c", /*Í*/"u041d",
		/*í*/"u043d", /*Î*/"u041e", /*î*/"u043e", /*Ï*/"u041F", /*ï*/"u043f", /*Ğ*/"u0420", /*ğ*/"u0440", /*Ñ*/"u0421", /*ñ*/"u0441",
		/*Ò*/"u0422", /*ò*/"u0442", /*Ó*/"u0423", /*ó*/"u0443", /*Ô*/"u0424", /*ô*/"u0444", /*Õ*/"u0425", /*õ*/"u0445", /*Ö*/"u0426",
		/*ö*/"u0446", /*×*/"u0427", /*÷*/"u0447", /*Ø*/"u0428", /*ø*/"u0448", /*Ù*/"u0429", /*ù*/"u0449", /*Ú*/"u042a", /*ú*/"u044a",
		/*Û*/"u042b", /*û*/"u044b", /*Ü*/"u042c", /*ü*/"u044c", /*İ*/"u042d", /*ı*/"u044d", /*Ş*/"u042e", /*ş*/"u044e", /*ß*/"u042f", /*ÿ*/"u044f" };

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

