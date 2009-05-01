#ifndef _PARSER_H_
#define _PARSER_H_

#include <define.h>

class Parser
{

public :
	Parser(string input);
	~Parser();

	//init the fields
	void init();

	// Read the data parse it in separate field;
	void readAndParse();
	//Read the Field and create output string
	void compil();
	//return output string;
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

		unsigned int sum(){ return t1+t2+t3+t4+defenses;}
	};

	//nom troupes
	struct snTroupes
	{
		string name1;
		string name2;
		string name3;
		string name4;
		string namedef;
	};

	//gains
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

	//erreurs
	enum eError
	{
		PARSE_NO_ERROR = 0,
		PARSE_NO_DATA,
		PARSE_NO_WORDS,
		PARSE_NO_ENOUGHT_WORDS
	};


	string getErrorString(){
		switch (status)
		{
		case PARSE_NO_DATA:
		case PARSE_NO_WORDS:
			return "Error : No Data to convert ! ";
		case PARSE_NO_ENOUGHT_WORDS:
			return "Error : Incomplete Entry, please paste a complete report ! ";
		default:
			return "Done";
		}
	}


protected:

	//perdu/gagné
	bool won;
	//nom de l'adversaire
	string name;
	//versu
	string versus;
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
	sGains gains2;
	//nom troupes
	snTroupes nameTroupes1;
	snTroupes nameTroupes2;


	//status
	eError status;

	//input
	string in;
	//output
	string out;

	//words
	words w;

	words ressources;
};

#endif //_PARSER_H_