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

static string startColor(string c)	{ return "[color=\"#"+c+"\"]"; }
static string endColor()	{ return "[/color]"; }


#endif //_BALISE_H_
