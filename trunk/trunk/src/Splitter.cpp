#include <Splitter.h>

Splitter::Splitter(string in, string separator)
{
	_w.clear();
	
	size_t begin = 0;
	size_t length = 0;

	while(begin != string::npos && begin < in.size())
	{
		size_t index = in.find(separator,begin);
		size_t end_l = in.find("\n",begin);
		index = std::min(index, end_l);

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
