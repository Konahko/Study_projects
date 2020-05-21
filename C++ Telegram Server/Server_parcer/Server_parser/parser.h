#pragma once
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class parser
{
public:
	parser();
	~parser();
	int parenthesis;
	//static vector<string> symbols_code{};
	
//	string symbols_code[66];

//	std::string input;
//	std::string output;

	string rebuild(string);
	string kutak(string);

private:
	static char symbols[66];
	string symbols_code[66];
};

