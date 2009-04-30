#include <Splitter.h>

#include <sstream>

Splitter::Splitter(string in, string separator)
{
	_w.clear();
	
	size_t begin = 0;
	size_t length = 0;

	while(begin != string::npos && begin < in.size())
	{
		size_t index = in.find(separator,begin);
		size_t end_l = in.find("\n",begin);
		size_t tab = in.find("\t",begin);
		index = std::min(index, end_l);
		index = std::min(index, tab);

		string word = in.substr(begin,index-begin);
		//word = removeSpace(word);
		
		if(!word.empty())
			_w.push_back(word);
		
		if(index == string::npos)
			break;
		else
			begin = index+1;
	}


}


string Splitter::removeSpace(string in)
{
	size_t index = 0;
	while(index != string::npos)
	{
		index = in.find(" ");

		if(index != string::npos)
			in = in.substr(0,index) + in.substr(index+1,string::npos);
	}
	return in;
}


string Splitter::i_to_s(int i)
{
	std::stringstream out;
	out << i;
	return out.str();
}

int Splitter::s_to_i(string s)
{
	int i = 0;
	std::istringstream myStream(s);
	myStream >> i;
	return i;
}
