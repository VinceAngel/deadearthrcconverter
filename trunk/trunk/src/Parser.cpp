#include <Parser.h>
#include <Splitter.h>
#include <Balise.h>

#include <sstream>
#include <iostream>

using std::endl;

Parser::Parser(string input)
{
	status = PARSE_NO_ERROR;

	if(input.empty())
		status = PARSE_NO_DATA;

	init();

	in = input;
}

Parser::~Parser()
{
}

void Parser::init()
{
	in	= "";
	out	= "";
	won = false;
	name2 = "";
	name1 = "Moi";
	date = "";
	mode = "";

	bonus.defense = 0;
	bonus.formation = 0;
	bonus.general = 0;
	bonus.race = 0;

	troupesBefore1.defenses = 0;
	troupesBefore1.t1 = 0;
	troupesBefore1.t2 = 0;
	troupesBefore1.t3 = 0;
	troupesBefore1.t4 = 0;

	troupesBefore2.defenses = 0;
	troupesBefore2.t1 = 0;
	troupesBefore2.t2 = 0;
	troupesBefore2.t3 = 0;
	troupesBefore2.t4 = 0;

	troupesAfter1.defenses = 0;
	troupesAfter1.t1 = 0;
	troupesAfter1.t2 = 0;
	troupesAfter1.t3 = 0;
	troupesAfter1.t4 = 0;

	troupesAfter2.defenses = 0;
	troupesAfter2.t1 = 0;
	troupesAfter2.t2 = 0;
	troupesAfter2.t3 = 0;
	troupesAfter2.t4 = 0;

	gains1.bois = 0;
	gains1.brique = 0;
	gains1.eau = 0;
	gains1.fer = 0;
	gains1.hectares = 0;
	gains1.nourriture = 0;
	gains1.or = 0;
	gains1.pierre = 0;

	gains2.bois = 0;
	gains2.brique = 0;
	gains2.eau = 0;
	gains2.fer = 0;
	gains2.hectares = 0;
	gains2.nourriture = 0;
	gains2.or = 0;
	gains2.pierre = 0;

	nameTroupes1.namedef = "";
	nameTroupes1.name1 = "";
	nameTroupes1.name2 = "";
	nameTroupes1.name3 = "";
	nameTroupes1.name4 = "";

	nameTroupes2.namedef = "";
	nameTroupes2.name1 = "";
	nameTroupes2.name2 = "";
	nameTroupes2.name3 = "";
	nameTroupes2.name4 = "";

	ressources.clear();
	ressources.push_back("bois");
	ressources.push_back("pierre");
	ressources.push_back("brique");
	ressources.push_back("fer");
	ressources.push_back("eau");
	ressources.push_back("nourriture");
	ressources.push_back("Or");
	ressources.push_back("hectares");
}


void Parser::readAndParse()
{
	if(status != PARSE_NO_ERROR)
		return;

	//read the string and get the separate words
	Splitter splitter(in," ");
	w = splitter.getWords();
}

void Parser::compil()
{
	if(status != PARSE_NO_ERROR)
		return;

	if(w.empty())
	{
		status = PARSE_NO_WORDS;
		return;
	}

	int begin = 0;

	int my_nb = -1;

	try{

		//search the begining
		for(unsigned int i=0 ; i < w.size() ; ++i)
		{
			if(w.at(i).compare("Perdu") ==0 || w.at(i).compare("Gagné") ==0)
			{
				begin = i-1;
				if(w.at(i-1).compare("a") == 0)
					name1 = w.at(i-2);
				break;
			}
		}

		//get the result
		if(w.at(begin+1).compare("Perdu") == 0)
			won = false;
		else if(w.at(begin+1).compare("Gagné") == 0)
			won = true;

		//names
		name2 = w.at(begin+5); 

		my_nb = Splitter::s_to_i(w.at(begin+6).substr(1));//get the nb of my troup to check later

		versus = w.at(begin+6)+" "+w.at(begin+7)+" "+w.at(begin+8);

		date = w.at(begin+11)+" "+w.at(begin+12)+" "+w.at(begin+13);

		mode = w.at(begin + 17);

		if(w.at(begin+24).compare("Aucun")== 0)
			bonus.race = 0;
		else
			bonus.race = Splitter::s_to_i(w.at(begin + 24));

		bonus.general = Splitter::s_to_i(w.at(begin + 27));
		bonus.defense = Splitter::s_to_i(w.at(begin + 31));
		bonus.formation = Splitter::s_to_i(w.at(begin + 35));

		//search the begining
		for(unsigned int i=begin+1 ; i < w.size() ; ++i)
		{
			if(w.at(i).compare("Début") ==0)
			{
				begin = i;
				break;
			}
		}

		//troups before

		troupesBefore1.t1 = Splitter::s_to_i(w.at(begin + 6));
		nameTroupes1.name1 = w.at(begin + 7);
		troupesBefore2.t1 = Splitter::s_to_i(w.at(begin + 9));
		nameTroupes2.name1 = w.at(begin + 10);

		troupesBefore1.t2 = Splitter::s_to_i(w.at(begin + 11));
		nameTroupes1.name2 = w.at(begin + 12);
		troupesBefore2.t2 = Splitter::s_to_i(w.at(begin + 14));
		nameTroupes2.name2 = w.at(begin + 15);

		troupesBefore1.t3 = Splitter::s_to_i(w.at(begin + 16));
		nameTroupes1.name3 = w.at(begin + 17);
		troupesBefore2.t3 = Splitter::s_to_i(w.at(begin + 19));
		nameTroupes2.name3 = w.at(begin + 20);

		troupesBefore1.t4 = Splitter::s_to_i(w.at(begin + 21));
		nameTroupes1.name4 = w.at(begin + 22);
		troupesBefore2.t4 = Splitter::s_to_i(w.at(begin + 24));
		nameTroupes2.name4 = w.at(begin + 25);

		if(w.at(begin + 26).compare("-") == 0)
			troupesBefore1.defenses = 0;
		else
			troupesBefore1.defenses = Splitter::s_to_i(w.at(begin + 26));
		nameTroupes1.namedef = w.at(begin + 27);

		if(w.at(begin + 29).compare("-") == 0)
			troupesBefore2.defenses = 0;
		else
			troupesBefore2.defenses = Splitter::s_to_i(w.at(begin + 29));
		nameTroupes2.namedef = w.at(begin + 30);


		//careful of the the long number separation 


		//troups after
		troupesAfter1.t1 = Splitter::s_to_i(w.at(begin + 31));
		troupesAfter2.t1 = Splitter::s_to_i(w.at(begin + 34));

		troupesAfter1.t2 = Splitter::s_to_i(w.at(begin + 36));
		troupesAfter2.t2 = Splitter::s_to_i(w.at(begin + 39));

		troupesAfter1.t3 = Splitter::s_to_i(w.at(begin + 41));
		troupesAfter2.t3 = Splitter::s_to_i(w.at(begin + 44));

		troupesAfter1.t4 = Splitter::s_to_i(w.at(begin + 46));
		troupesAfter2.t4 = Splitter::s_to_i(w.at(begin + 49));

		if(w.at(begin + 51).compare("-") == 0)
			troupesAfter1.defenses = 0;
		else
			troupesAfter1.defenses = Splitter::s_to_i(w.at(begin + 51));

		if(w.at(begin + 54).compare("-") == 0)
			troupesAfter2.defenses = 0;
		else
			troupesAfter2.defenses = Splitter::s_to_i(w.at(begin + 54));


		//search the begining
		for(unsigned int i=begin+55 ; i < w.size() ; ++i)
		{
			if(w.at(i).compare("l'adversaire") ==0)
			{
				begin = i;
				break;
			}
		}

		//gains 1

		int next = begin;
		for(unsigned int r = 0 ; r < ressources.size() ; r++)
		{

			begin = next;
			string s = "";
			for(unsigned int i=begin+1 ; i < w.size() ;++i)
			{
				if(w.at(i).compare(ressources.at(r))==0)
				{
					next = i;
					break;
				}
				else
					s = s + w.at(i);

			}

			switch (r)
			{
			case 0:
				gains1.bois		= Splitter::s_to_i(s);
				break;
			case 1:
				gains1.pierre	 = Splitter::s_to_i(s);
				break;
			case 2:
				gains1.brique	 = Splitter::s_to_i(s);
				break;
			case 3:
				gains1.fer		= Splitter::s_to_i(s);
				break;
			case 4:
				gains1.eau		= Splitter::s_to_i(s);
				break;
			case 5:
				gains1.nourriture = Splitter::s_to_i(s);
				break;
			case 6:
				gains1.or		= Splitter::s_to_i(s);
				break;
			case 7:
				gains1.hectares	= Splitter::s_to_i(s);
				break;
			default:
				break;
			}

		}
			
		//gains 2

		//next = begin+2;
		for(unsigned int r = 0 ; r < ressources.size() ; r++)
		{

			begin = next;
			string s = "";
			for(unsigned int i=begin+1 ; i < w.size() ;++i)
			{
				if(w.at(i).compare(ressources.at(r))==0)
				{
					next = i;
					break;
				}
				else
					s = s + w.at(i);

			}

			switch (r)
			{
			case 0:
				gains2.bois		= Splitter::s_to_i(s);
				break;
			case 1:
				gains2.pierre	 = Splitter::s_to_i(s);
				break;
			case 2:
				gains2.brique	 = Splitter::s_to_i(s);
				break;
			case 3:
				gains2.fer		= Splitter::s_to_i(s);
				break;
			case 4:
				gains2.eau		= Splitter::s_to_i(s);
				break;
			case 5:
				gains2.nourriture = Splitter::s_to_i(s);
				break;
			case 6:
				gains2.or		= Splitter::s_to_i(s);
				break;
			case 7:
				gains2.hectares	= Splitter::s_to_i(s);
				break;
			default:
				break;
			}

		}

	}
	catch(std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		status = PARSE_NO_ENOUGHT_WORDS;
	}



	//== Check if the troup one is the good one, if not, exchange ==//
	if(my_nb != troupesBefore1.sum())
	{
		//switch the datas
		sTroupe temp;
		temp = troupesBefore1;
		troupesBefore1 = troupesBefore2;
		troupesBefore2 = temp;

		temp = troupesAfter1;
		troupesAfter1 = troupesAfter2;
		troupesAfter2 = temp;
	}



	//== Write the output string ==//
	std::stringstream ss;
	ss.clear();

	if(status != PARSE_NO_ERROR)
		return;

#ifdef VERTICAL_REPORT

	ss << startQuote() << startCenter() << endl
	<< startItal() << "Le " << date << endItal() << endl
	<< endl
	<< startColor(yellow) << startSize(3) << name1 << endSize() << endColor() << " VS " << startColor(yellow) << startSize(3) << name2 << endSize() << endColor() << endl
	<< startBold() << versus << endBold() << endl
	<< endl;

	string vs = "perdu ";
	if(won) vs = "gagné "; 

	
	ss << "Attaque de type " << mode << endl
	<< endl
	<< "Race [" << bonus.race << "]  -  "
	<< "General [" << bonus.general << "]" << endl
	<< "Défense [" << bonus.defense << "]  -  "
	<< "Formation [" << bonus.formation << "]" << endl
	<< endl
	<< "___________________________________________________" << endl

	<< startSize(2) << startBold() << "Avant le combat : " << endBold() << endSize() << endl
	<< startUnd() << startBold() << name1 << endBold() << endUnd() << endl
	<< startColor(col1) << troupesBefore1.t1 << " " << nameTroupes1.name1 << endColor() << endl
	<< startColor(col2) << troupesBefore1.t2 << " " << nameTroupes1.name2 << endColor() << endl
	<< startColor(col3) << troupesBefore1.t3 << " " << nameTroupes1.name3 << endColor() << endl
	<< startColor(col4) << troupesBefore1.t4 << " " << nameTroupes1.name4 << endColor() << endl
	<< startColor(col5) << troupesBefore1.defenses<< " " << nameTroupes1.namedef << endColor() << endl
	<< endl
	<< startUnd() << startBold() << name2 << endBold() << endUnd() << endl
	<< startColor(col1) << troupesBefore2.t1 << " " << nameTroupes2.name1 << endColor() << endl
	<< startColor(col2) << troupesBefore2.t2 << " " << nameTroupes2.name2 << endColor() << endl
	<< startColor(col3) << troupesBefore2.t3 << " " << nameTroupes2.name3 << endColor() << endl
	<< startColor(col4) << troupesBefore2.t4 << " " << nameTroupes2.name4 << endColor() << endl
	<< startColor(col5) << troupesBefore2.defenses<< " " << nameTroupes2.namedef << endColor() << endl
	<< endl

	<< "___________________________________________________" << endl
	<< "J'ai " << startSize(4) << startBold() << startColor("FFFFFF") << vs << endColor() << endBold() << endSize() << endl
	<< "___________________________________________________" << endl << endl


	<< startSize(2) << startBold() << "Apres le combat : " << endBold() << endSize() << endl
	<< startUnd() << startBold() << name1 << endBold() << endUnd() << endl
	<< startColor(col1) << troupesAfter1.t1 << " " << nameTroupes1.name1 << " (-" << Splitter::i_to_s(troupesBefore1.t1 - troupesAfter1.t1) << ")" << endColor() << endl
	<< startColor(col2) << troupesAfter1.t2 << " " << nameTroupes1.name2 << " (-" << Splitter::i_to_s(troupesBefore1.t2 - troupesAfter1.t2) << ")" << endColor() << endl
	<< startColor(col3) << troupesAfter1.t3 << " " << nameTroupes1.name3 << " (-" << Splitter::i_to_s(troupesBefore1.t3 - troupesAfter1.t3) << ")" << endColor() << endl
	<< startColor(col4) << troupesAfter1.t4 << " " << nameTroupes1.name4 << " (-" << Splitter::i_to_s(troupesBefore1.t4 - troupesAfter1.t4) << ")" << endColor() << endl
	<< startColor(col5) << troupesAfter1.defenses<< " " << nameTroupes1.namedef << " (-" << Splitter::i_to_s(troupesBefore1.defenses - troupesAfter1.defenses) << ")" << endColor() << endl
	<< endl
	<< startUnd() << startBold() << name2 << endBold() << endUnd() << endl
	<< startColor(col1) << troupesAfter2.t1 << " " << nameTroupes2.name1 << " (-" << Splitter::i_to_s(troupesBefore2.t1 - troupesAfter2.t1) << ")" << endColor() << endl
	<< startColor(col2) << troupesAfter2.t2 << " " << nameTroupes2.name2 << " (-" << Splitter::i_to_s(troupesBefore2.t2 - troupesAfter2.t2) << ")" << endColor() << endl
	<< startColor(col3) << troupesAfter2.t3 << " " << nameTroupes2.name3 << " (-" << Splitter::i_to_s(troupesBefore2.t3 - troupesAfter2.t3) << ")" << endColor() << endl
	<< startColor(col4) << troupesAfter2.t4 << " " << nameTroupes2.name4 << " (-" << Splitter::i_to_s(troupesBefore2.t4 - troupesAfter2.t4) << ")" << endColor() << endl
	<< startColor(col5) << troupesAfter2.defenses<< " " << nameTroupes2.namedef << " (-" << Splitter::i_to_s(troupesBefore2.defenses - troupesAfter2.defenses) << ")" << endColor() << endl
	<< endl
	<< "___________________________________________________" << endl

	<< "Gains" << endl
	<< startUnd() << startBold() << name1 << endBold() << endUnd() << endl
	<< startColor(colbois) << gains1.bois << " bois" << endColor() << "  -  "
	<< startColor(colpierre) << gains1.pierre << " pierre" << endColor() << endl
	<< startColor(colbrique) << gains1.brique << " brique" << endColor() << "  -  "
	<< startColor(colfer) << gains1.fer << " fer" << endColor() << endl
	<< startColor(coleau) << gains1.eau << " eau" << endColor() << "  -  "
	<< startColor(colnourriture) << gains1.nourriture << " nourriture" << endColor() << endl
	<< startColor(color) << gains1.or << " or" << endColor() << "  -  "
	<< startColor(colhectare) << gains1.hectares << " hectares" << endColor() << endl
	<< endl
	<< startUnd() << startBold() << name2 << endBold() << endUnd() << endl
	<< startColor(colbois) << gains2.bois << " bois" << endColor() << "  -  "
	<< startColor(colpierre) << gains2.pierre << " pierre" << endColor() << endl
	<< startColor(colbrique) << gains2.brique << " brique" << endColor() << "  -  "
	<< startColor(colfer) << gains2.fer << " fer" << endColor() << endl
	<< startColor(coleau) << gains2.eau << " eau" << endColor() << "  -  "
	<< startColor(colnourriture) << gains2.nourriture << " nourriture" << endColor() << endl
	<< startColor(color) << gains2.or << " or" << endColor() << "  -  "
	<< startColor(colhectare) << gains2.hectares << " hectares" << endColor() << endl
	<< endl
	<< startSize(1) << startItal() << "RC generated by [url=\"http://code.google.com/p/deadearthrcconverter/\"]DeadEarthRCConverter [/url] - Made by Ange " << endItal()<< endSize() << endl

	<< endCenter() << endQuote() << endl;


#endif
	out = ss.str();

}

string Parser::getOutput()
{
	return out;
}
