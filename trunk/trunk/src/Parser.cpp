#include <Parser.h>
#include <Splitter.h>

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
	name = "";
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

	

}

string Parser::getOutput()
{
	return out;
}
