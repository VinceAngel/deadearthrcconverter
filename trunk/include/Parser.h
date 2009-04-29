#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
using std::string;

class Parser
{

public :
	Parser(string input);
	~Parser();

	void readAndParse();
	void compil();
	string getOutput();

	//bonus attaquant
	struct sBonus
	{
		int race;
		int general;
		int defense;
		int formation;
	};

	//troupes
	struct sTroupe
	{
		unsigned int t1;
		unsigned int t2;
		unsigned int t3;
		unsigned int t4;
		unsigned int defenses;
	};

	struct sGains
	{
		unsigned long bois;
		unsigned long pierre;
		unsigned long brique;
		unsigned long fer;
		unsigned long eau;
		unsigned long nourriture;
		unsigned long or;
		unsigned long hectares;
	};

private:

	//nom de l'adversaire
	string name;
	//date
	string date;
	//mode
	string mode;
	//bonus
	sBonus bonus;
	//troupes du joueur 1 avant le combat
	sTroupe troupesBefore1;
	//troupes du joueur 2 avant le combat
	sTroupe troupesBefore2;
	//troupes du joueur 1 apres le combat
	sTroupe troupesAfter1;
	//troupes du joueur 2 apres le combat
	sTroupe troupesAfter2;
	//gains joueur 1
	sGains gains1;
	//gains joueur 2
	sGains gain2;	

};

#endif //_PARSER_H_