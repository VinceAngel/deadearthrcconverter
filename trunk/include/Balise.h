#ifndef _BALISE_H_
#define _BALISE_H_

#include <string>
using std::string;

static string startBold()	{ return "[b]"; }
static string endBold()		{ return "[/b]";}

static string startCenter()	{ return "[center]"; }
static string endCenter()	{ return "[/center]"; }

static string startItal()	{ return "[i]"; }
static string endItal()		{ return "[/i]"; }

static string startUnd()	{ return "[u]"; }
static string endUnd()		{ return "[/u]"; }

static string startSize(int s)	{ return "[size="+Splitter::i_to_s(s)+"]"; }
static string endSize()		{ return "[/size]"; }

static string startColor(string c)	{ return "[color=\"#"+c+"\"]"; }
static string endColor()	{ return "[/color]"; }

static string col1 = "880000";
static string col2 = "A00000";
static string col3 = "CC0000";
static string col4 = "E00000";
static string col5 = "FF0000";

static string colbois		= "7F3F3F";
static string colpierre		= "EEEEEE";
static string colbrique		= "FF7F00";
static string colfer		= "DDDDDD";
static string coleau		= "7FFFFF";
static string colnourriture = "FF90FF";
static string color			= "FFFF50";
static string colhectare	= "7FFF7F";


#endif //_BALISE_H_
