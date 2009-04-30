#ifndef _SPLITTER_H_
#define _SPLITTER_H_

#include <define.h>

class Splitter
{
public:
	
	Splitter(string in, string separator);
	~Splitter(){}

	string removeSpace(string);

	static int		s_to_i(string s);
	static string	i_to_s(int i);

	words getWords()
	{
		return _w;
	}

private :
	words _w;

};

#endif //_SPLITTER_H_