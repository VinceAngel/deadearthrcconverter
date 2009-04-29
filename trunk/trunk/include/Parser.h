#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>

class Parser
{

public :
	Parser(std::string input);
	~PArser();

	void readAndParse();
	void compil();
	std::string getOutput();


};

#endif //_PARSER_H_