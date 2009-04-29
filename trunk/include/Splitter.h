#ifndef _SPLITTER_H_
#define _SPLITTER_H_

#include <define.h>

class Splitter
{
public:
	
	Splitter(string in, string separator);
	~Splitter(){}

	string removeSpace(string);

	words getWords()
	{
		return _w;
	}

private :
	words _w;

};

#endif //_SPLITTER_H_