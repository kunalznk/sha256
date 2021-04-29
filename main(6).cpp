#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<typeinfo>
#include <regex>

using namespace std;

class Symbol
{

public:
  string tok;
  string cls;
  string value;
  string addr;
  string seg;

public:
    Symbol ()
  {
    tok = " ";
    cls = " ";
    value = " ";
    addr = " ";
    seg = " ";
  }

  Symbol (string t, string c, string v, string a, string s)
  {

    tok = t;
    cls = c;
    value = v;
    addr = a;
    seg = s;
  }

  string toString ()
  {
    if (cls.compare ("<numLit>"))
      {
	return tok + "\t\t" + cls + "\t" + value + "\t\t" + addr + "\t\t" +
	  seg;
      }
    else
      {
	return tok + "\t\t" + cls + "\t\t" + value + "\t\t" + addr + "\t\t" +
	  seg;
      }
  }

public:
  void setToken (string t)
  {
    tok = t;
  }

  void setCls (string c)
  {
    cls = c;
  }

  void setValue (string v)
  {
    value = v;
  }

  void setAddress (string a)
  {
    addr = a;
  }

  void setSegment (string s)
  {
    seg = s;
  }

  string getToken ()
  {
    return tok;
  }

  string getCls ()
  {
    return cls;
  }

  string getValue ()
  {
    return value;
  }

  string getAddress ()
  {
    return addr;
  }

  string getSegment ()
  {
    return seg;
  }


  // to string method for printing purposes
};

class Token
{

private:
  string tok;
  string cls;


public:
    Token ()
  {
    tok = "";
    cls = "";


  }

  Token (string tok, string cls)
  {

    this->tok = tok;
    this->cls = cls;
  }

  string getToken ()
  {
    return tok;
  }

  string getCls ()
  {
    return cls;
  }

  void setToken (string t)
  {
    tok = t;
  }
  void setCls (string c)
  {
    cls = c;
  }


  string toString ()
  {
    return tok + "\t\t" + cls + "\t\t";
  }

  void show ()
  {
    cout << "Output of begin and end: ";
  }
};

class Quads
{
private:
  string sym;
  string arg1;
  string arg2;
  string arg3;

public:
    Quads ()
  {
    sym = "|--|";
    arg1 = "|--|";
    arg2 = "|--|";
    arg3 = "|--|";
  }

  Quads (string s)
  {
    sym = s;
    arg1 = "|--|";
    arg2 = "|--|";
    arg3 = "|--|";
  }

  Quads (string s1, string s2)
  {
    sym = s1;
    arg1 = s2;
    arg2 = "|--|";
    arg3 = "|--|";
  }

  Quads (string s1, string s2, string s3)
  {
    sym = s1;
    arg1 = s2;
    arg2 = s3;
    arg3 = "|--|";
  }

  Quads (string s1, string s2, string s3, string s4)
  {
    sym = s1;
    arg1 = s2;
    arg2 = s3;
    arg3 = s4;
  }

  string getSym ()
  {
    return sym;
  }

  string getArg1 ()
  {
    return arg1;
  }

  string getArg2 ()
  {
    return arg2;
  }

  string getArg3 ()
  {
    return arg3;
  }

  void setSymbol (string s)
  {
    sym = s;
  }

  void setArg1 (string s)
  {
    arg1 = s;
  }

  void setArg2 (string s)
  {
    arg2 = s;
  }

  void setArg3 (string s)
  {
    arg3 = s;
  }

  string toString ()
  {
    return sym + " " + arg1 + " " + arg2 + " " + arg3;
  }
};

int
getLoc (char c, char *chars)
{

  if (isalpha (c))
    {
      // process through fsa array looking from perspective of L
      return 0;
    }
  else if (isdigit (c))
    {
      // process through fsa array looking from perspective of D
      return 1;
    }
  // loop through chars array to find index for fas table
  for (int i = 2; i < 19; i++)
    {
      if (c == chars[i])
	{
	  return i;
	}
    }
  return -1;
};

int
getLoc1 (string s)
{

  string ops[26] =
    { ";", "=", "+", "-", "(", ")", "*", "/", "WRITE", "READ", "IF", "THEN",
"ODD",
    "==", "!=", ">", "<", ">=", "<=", "{", "}", "CALL", "WHILE", "DO", "ELSE"
  };
  for (int i = 0; i < 26; i++)
    {
      if (s == ops[i])
	{
	  return i;
	}
    }
  // if location not found then error occurs
  return -1;
}

string
getsymme (string s)
{
  return s;

}

bool
opCheck (string s)
{

  string ops[26] =
    { ";", "=", "+", "-", "(", ")", "*", "/", "WRITE", "READ", "IF", "THEN",
"ODD",
    "==", "!=", ">", "<", ">=", "<=", "{", "}", "CALL", "WHILE", "DO", "ELSE"
  };

  for (int i = 0; i < 26; i++)
    {
      if (ops[i] == s)
	{
	  return true;
	}
    }
  return false;
}

void
addReswords (string s, vector < Token > &als)
{
  string resw[][10] =
    { {"CONST", "$Const"}, {"IF", "$If"}, {"DO", "$Do"}, {"CLASS", "$Class"},
    {"PROC", "$Proc"}, {"VAR", "$Var"}, {"WHILE", "$While"}, {"THEN",
							      "$Then"},
    {"CALL", "$Call"}, {"ODD", "$Odd"} };

  string keyword;
  string classWord;
  int id = 0;
  // take string s and compare it to resw array
  for (int i = 0; i < 10; i++)
    {
      keyword = resw[i][0];


      // compare s to each position in array
      if (s == keyword)
	{
	  classWord = resw[i][1];
	  id = 1;
	  break;

	  // add to token array list
	  //als.add(new Token(keyword, classWord));
	}
    }

  if (id)
    {
      als.push_back (Token (keyword, classWord));
    }
  else
    {
      als.push_back (Token (s, "<var>"));
    }
}

int
getSymLoc (string s)
{

  string clsTypes[10] =
    { "$Class", "<var>", "$Const", "<assign>", "<int>", "<comma>", "<semi>",
"$Var", "$LB", "$RB" };

  string temp;
  for (int i = 0; i < 10; i++)
    {
      // loop through all items in clsTypes array
      temp = clsTypes[i];

      if (s == temp)
	{
	  return i;
	}
    }

  return 0;
}

vector < Symbol > getSymTab (vector < Symbol > &sym)
{
  return sym;
}

vector < Token > getTokenList (vector < Token > &als)
{
  return als;
}

int
getTokenSize (vector < Token > &als)
{
  return als.size ();
}

int
getSymbolSize (vector < Token > &sym)
{
  return sym.size ();
}

vector < Token > getModTokList (vector < Token > &modToks)
{
  return modToks;
}

int
getModSize (vector < Token > &modToks)
{
  return modToks.size ();
}

void
processSymbolTable (vector < Token > &als, vector < Symbol > &sym)
{
  int symState[12][10] = { {1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, 3, -1},
  {-1, 10, 4, -1, -1, -1, -1, 8, -1, -1},
  {-1, 5, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, 6, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, 7, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, 4, 3, -1, -1, -1},
  {-1, 9, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, 8, 3, -1, -1, -1},
  {10, 10, 10, 10, 11, 10, 10, 10, 10, 10},
  {-1, 10, 10, 10, -1, -1, 10, -1, 10, 12}
  };
  // loop through token array list
  Token tok;
  string tempCls = "";
  string tempTok = "";
  int state = 0;
  int locate = 0;
  int codeAddr = 0;
  int dataAddr = 0;
  string SEGS[2] = { "DS", "CS" };
  cout << "Symobl Table" << endl;

  for (int i = 0; i < als.size (); i++)
    {
      tok.setToken (als[i].getToken ());
      tok.setCls (als[i].getCls ());
      locate = getSymLoc (tok.getCls ());

      switch (state)
	{
	case 0:
	  state = symState[state][locate];
	  break;
	case 1:
	  state = symState[state][locate];
	  tempTok = tok.getToken () + ": ";
	  // store class name var (token, class, value, addr, seg)
	  sym.
	    push_back (Symbol
		       (tok.getToken (), "<CName>", tempTok,
			to_string (codeAddr), SEGS[1]));
	  cout << "Added" << endl;
	  codeAddr += 2;
	  break;
	case 2:
	  state = symState[state][locate];
	  break;
	case 3:
	  state = symState[state][locate];
	  break;
	case 4:
	  state = symState[state][locate];
	  tempTok = tok.getToken ();
	  tempCls = tok.getCls ();
	  break;
	case 5:
	  state = symState[state][locate];
	  break;
	case 6:
	  state = symState[state][locate];
	  // add new Const (token, class, value, addr, seg)
	  sym.
	    push_back (Symbol
		       (tempTok, tempCls, tok.getToken (),
			to_string (dataAddr), SEGS[0]));
	  dataAddr += 2;
	  break;
	case 7:
	  state = symState[state][locate];
	  break;
	case 8:
	  state = symState[state][locate];
	  // store variable name
	  sym.
	    push_back (Symbol
		       (tok.getToken (), tok.getCls (), "",
			to_string (dataAddr), SEGS[0]));
	  dataAddr += 2;
	  break;
	case 9:
	  state = symState[state][locate];
	  break;
	case 10:
	  state = symState[state][locate];
	  if (state == 11)
	    {
	      tempTok = "lit" + tok.getToken ();
	      tempCls = "<numLit>";
	      sym.
		push_back (Symbol
			   (tempTok, tempCls, tok.getToken (),
			    to_string (dataAddr), SEGS[0]));
	      dataAddr += 2;
	    }
	  else
	    {
	      continue;
	    }
	  break;
	case 11:
	  state = symState[state][locate];
	  break;
	case 12:
	  state = symState[state][locate];
	  return;
	case -1:
	  //throw new WrongItemException(tok.getToken() + "\nThis is unexpected token!!");
	  //System.err.println("Error");
	  break;
	default:
	  state = 10;
	}
    }
  int symLen;
  string tempHold;
  symLen = sym.size () / 2 + 1;
  for (int i = 1; i < symLen; i++)
    {
      tempHold = "t" + i;
      sym.
	push_back (Symbol
		   (tempHold, "<temp_int>", "?", to_string (dataAddr),
		    SEGS[0]));
      dataAddr += 2;
    }
}

int
processQuad (int tc, stack < Token > &opStk, vector < Quads > &alq,
	     stack < Token > &varStk)
{

  int iCount = 1;
  int wCount = 1;
  string sym = getsymme (opStk.top ().getToken ());
  opStk.pop ();
  string cases[17] = { "READ", "WRITE", "IF", "THEN", "WHILE", "!=",
    "==",
    ">",
    "<",
    ">=",
    "<=",
    "DO",
    "=",
    "+",
    "-",
    "/",
    "*",
  };
  int swtch = 0;

  for (int i = 0; i < 17; i++)
    {
      if (sym == cases[i])
	{
	  swtch = i + 1;
	  break;
	}
    }



  string arg1, arg2;
  string arg3 = "";
  switch (swtch)
    {
    case 1:
    case 2:
      arg1 = varStk.top ().getToken ();
      varStk.pop ();
      alq.push_back (Quads (sym, arg1));
      break;
    case 3:
      arg1 = "If" + iCount;
      iCount++;
      alq.push_back (Quads (sym, arg1));
      break;
    case 4:
      alq.push_back (Quads (sym));
      break;
    case 5:
      arg1 = "While" + wCount;
      wCount++;
      alq.push_back (Quads (sym, arg1));
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
      if (opStk.top ().getToken () == "IF")
	{
	  arg3 = "If" + to_string (iCount);
	}
      else if (opStk.top ().getToken () == "WHILE")
	{
	  arg3 = "While" + to_string (wCount);
	}
      arg2 = varStk.top ().getToken ();
      varStk.pop ();
      arg1 = varStk.top ().getToken ();
      varStk.pop ();
      alq.push_back (Quads (sym, arg1, arg2, arg3));
      break;
    case 12:
      alq.push_back (Quads (sym));
      break;
    case 13:
      arg2 = varStk.top ().getToken ();
      varStk.pop ();
      arg1 = varStk.top ().getToken ();
      varStk.pop ();
      alq.push_back (Quads (sym, arg1, arg2));
      break;
    case 14:
    case 15:
    case 16:
    case 17:
      arg2 = varStk.top ().getToken ();
      varStk.pop ();
      arg1 = varStk.top ().getToken ();
      varStk.pop ();
      string temp = "__t" + to_string (tc) + "__";

      alq.push_back (Quads (sym, arg1, arg2, temp));
      varStk.push (Token (temp, "<temp>"));
      return tc % 4 + 1;
    }
  return tc;
}


void
basicOpt (vector < Quads > &alq)
{
  string symbol;
  string arg1;
  string arg2;
  for (int i = 0; i < alq.size (); i++)
    {
      symbol = alq[i].getSym ();
      arg2 = alq[i].getArg2 ();
      regex b ("__t[0-9]+__");
      if (symbol == "=" && regex_match (arg2, b))
	{
	  arg1 = alq[i].getArg1 ();
	  alq[i - 1].setArg3 (arg1);
	  alq.erase (alq.begin () + i);
	}
    }
}

void
setUpMod (vector < Token > &als, vector < Token > &modToks)
{
  bool flag = true;
  for (int i = 0; i < als.size (); i++)
    {
      if (als[i].getCls () == "$Const" || als[i].getCls () == "$Var")
	{
	  flag = true;
	}
      if (!flag)
	{
	  modToks.push_back (als[i]);
	}
      if (als[i].getCls () == "<semi>")
	{
	  flag = false;
	}
    }
}

void
process (vector < Token > &modToks, stack < Token > &varStk,
	 vector < Quads > &alq)
{
  stack < Token > opStk;
  char table[25][25] = { {' ', '<', ' ', ' ', ' ', ' ', ' ', ' ', '<', '<', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', '<', ' ', '<'},	//  ;
  {'>', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' '},	//  =
  {'>', ' ', '>', '>', '<', '>', '<', '<', ' ', ' ', ' ', '>', ' ', '>', '>', '>', '>', '>', '>', ' ', '>', ' ', ' ', ' ', ' '},	//  +
  {'>', ' ', '>', '>', '<', '>', '<', '<', ' ', ' ', ' ', '>', ' ', '>', '>', '>', '>', '>', '>', ' ', '>', ' ', ' ', ' ', ' '},	//  -
  {' ', ' ', '<', '<', '<', '=', '<', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  (
  {'>', ' ', '>', '>', ' ', '>', '>', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' '},	//  )
  {'>', ' ', '>', '>', '<', '>', '>', '>', ' ', ' ', ' ', '>', ' ', '>', '>', '>', '>', '>', '>', ' ', '>', ' ', ' ', ' ', ' '},	//  *
  {'>', ' ', '>', '>', '<', '>', '>', '>', ' ', ' ', ' ', '>', ' ', '>', '>', '>', '>', '>', '>', ' ', '>', ' ', ' ', ' ', ' '},	//  /
  {'>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' '},	//  WRITE
  {'>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' '},	//  READ
  {'>', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '=', '<', '<', '<', '<', '<', '<', '<', ' ', '>', ' ', '<', ' ', ' '},	//  IF
  {'>', '<', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', '>', '<', ' ', ' ', ' '},	//  THEN
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  ODD
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  ==
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  !=
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  >
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  <
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  >=
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  <=
  {' ', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', '=', ' ', ' ', ' ', ' '},	//  {
  {'>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', '>', ' ', ' ', ' ', '>'},	//  }
  {'>', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//  CALL
  {'>', ' ', '<', '<', '<', ' ', '<', '<', ' ', ' ', ' ', '=', '<', '<', '<', '<', '<', '<', '<', ' ', ' ', ' ', ' ', '=', ' '},	//  WHILE
  {'>', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ', '<', '<', ' ', ' '},	//  DO
  {'>', '<', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', '<', ' ', ' ', ' ', ' ', ' '}
  };				// ELSE

  // initialize stack
  opStk.push (Token (";", "<semi>"));
  int row, col;
  int tempC = 1;

  for (int i = 0; i < modToks.size (); i++)
    {
      if (!opCheck (modToks[i].getToken ()))
	{
	  varStk.push (modToks[i]);
	}
      else
	{
	  row = getLoc1 (opStk.top ().getToken ());
	  col = getLoc1 (modToks[i].getToken ());

	  switch (table[row][col])
	    {
	    case '<':
	    case '=':
	      opStk.push (modToks[i]);
	      break;
	    case '>':
	      do
		{
		  tempC = processQuad (tempC, opStk, alq, varStk);
		  row = getLoc1 (opStk.top ().getToken ());
		}
	      while (table[row][col] == '>');
	      if (modToks[i].getToken () != ";")
		{
		  opStk.push (modToks[i]);
		}
	      break;
	    default:
            cout<<"\n";
    	    }
	}

    }

}

void
processAssemble (vector < Symbol > &sym, vector < Quads > &alq)
{
  fstream code_file;
  code_file.open ("code.asm", ios::out);
  if (!code_file)
    {
      cout << "File not created!";
    }
  else
    {
      code_file << "";
    }
  string save = "\r\n";
  string data = "";
  string arg1, arg2, arg3;
  string symbol;

  // initialize statement
  data += "%include 'IO.asm'" + save;
  data += "Section .data" + save;
  code_file << data;
  data = "";
  // process data section
  for (int i = 0; i < sym.size (); i++)
    {
      if (sym[i].getSegment () == "DS")
	{
	  arg1 = sym[i].getToken ();
	  arg2 = sym[i].getValue ();
	  if (arg2 == "?")
	    {
	      data += arg1 + " resw 1" + save;
	    }
	  else
	    {
	      code_file << arg1 + " DW " + arg2 + save;
	    }
	}
    }
  // initialize .bss section
  code_file << "section .bss" + save;
  code_file << data;
  code_file << "global  _start" + save;
  data = "";
  // initialize code section
  data += "Section .code" + save;
  data += "_start:  nop" + save;
  code_file << data;
  data = "";

  // process code section
  for (int i = 0; i < alq.size (); i++)
    {
      string symbols[16] = { "READ", "WRITE", "=", "+", "-", "/", "*", "%",
	"==", ">", "<", ">=", "<=", "!=", "IF", "WHILE"
      };
      symbol = alq[i].getSym ();
      arg1 = alq[i].getArg1 ();
      arg2 = alq[i].getArg2 ();
      arg3 = alq[i].getArg3 ();
      int swtch;
      for (int i = 0; i < 16; i++)
	{
	  if (symbols[i] == symbol)
	    {
	      swtch = i + 1;
	      break;
	    }

	}

      switch (swtch)
	{
	case 1:
	  data += "call PrintString" + save;
	  data += "call GetAnInteger" + save;
	  data += "mov  eax,[ReadInt]" + save;
	  data += "mov  [" + arg1 + "],eax" + save;
	  break;
	case 2:
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "call ConvertIntegerToString" + save;
	  data += "mov  eax, 4" + save;
	  data += "mov  ebx, 1" + save;
	  data += "mov  ecx, Result" + save;
	  data += "mov  edx, ResultEnd" + save;
	  data += "int 80h" + save;
	  break;
	case 3:
	  data += "mov  eax,[" + arg2 + "]" + save;
	  data += "mov  [" + arg1 + "],eax" + save;
	  break;
	case 4:
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "add  eax,[" + arg2 + "]" + save;
	  data += "mov  [" + arg3 + "],eax" + save;
	  break;
	case 5:
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "sub  eax,[" + arg2 + "]" + save;
	  data += "mov  [" + arg3 + "],eax" + save;
	  break;
	case 6:
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "idiv word[" + arg2 + "]" + save;
	  data += "mov  [" + arg3 + "],eax" + save;
	  break;
	case 7:
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "imul word[" + arg2 + "]" + save;
	  data += "mov  [" + arg3 + "],eax" + save;
	  break;
	case 8:
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "idiv word[" + arg2 + "]" + save;
	  data += "mov  [" + arg3 + "],edx" + save;
	  break;
	case 9:
	  data += arg3 + ": nop" + save;
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "cmp  eax,[" + arg2 + "]" + save;
	  data += "jne  end" + arg3 + save;
	  break;
	case 10:
	  data += arg3 + ": nop" + save;
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "cmp  eax,[" + arg2 + "]" + save;
	  data += "jle  end" + arg3 + save;
	  break;
	case 11:
	  data += arg3 + ": nop" + save;
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "cmp  eax,[" + arg2 + "]" + save;
	  data += "jge  end" + arg3 + save;
	  break;
	case 12:
	  data += arg3 + ": nop" + save;
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "cmp  eax,[" + arg2 + "]" + save;
	  data += "jl   end" + arg3 + save;
	  break;
	case 13:
	  data += arg3 + ": nop" + save;
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "cmp  eax,[" + arg2 + "]" + save;
	  data += "jg   end" + arg3 + save;
	  break;
	case 14:
	  data += arg3 + ": nop" + save;
	  data += "mov  eax,[" + arg1 + "]" + save;
	  data += "cmp  eax,[" + arg2 + "]" + save;
	  data += "je   end" + arg3 + save;
	  break;
	case 15:
	  data += "end" + arg1 + ": nop" + save;
	  break;
	case 16:
	  data += "j  " + arg1 + save;
	  data += "end" + arg1 + ": nop" + save;
	  break;
	default:
	  continue;
	}
      code_file << data + save;
      data = "";
    }
  data += "mov  ah,04Ch" + save;
  data += "xor  al,al" + save;
  data += "int  21h" + save;
  code_file << data;
  code_file.close ();


}

int
main ()
{

  cout << " Analyzer started " << endl;

  vector < char >buff;
  char ch;
  //   {'L','D','=',',',';','+','b ','*','/','(',')','<','>','{','}','!','\t','\n',' '};
  char chars[19] =
    { 'L', 'D', '=', ',', ';', '+', '-', '*', '/', '(', ')', '<', '>', '{',
'}', '!', '\t', '\n', ' ' };

  int stateTab[10][19] =
    { {1, 2, 3, 23, 24, 21, 22, 10, 4, 25, 26, 8, 9, 27, 28, 7, 0, 0, 0},
  {1, 1, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12},
  {1, 2, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
  {14, 14, 15, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
   14},
  {13, 13, 13, 13, 13, 13, 13, 5, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13},
  {5, 5, 5, 5, 5, 5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
  {5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
  {29, 29, 20, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
   29},
  {16, 16, 17, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 16, 16,
   16},
  {18, 18, 19, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 18, 18, 18}
  };

  int state = 0;
  int locate = 0;
  string item = "";
  string s = "";
  bool tab = false;

  ifstream file ("input");
  while (!file.eof ())
    {

      file.get (ch);
      buff.push_back (ch);
    }
  cout << endl;
  file.close ();

  vector < int >mem;
  vector < Token > als;
  vector < Token > modToks;
  vector < Quads > alq;
  vector < Symbol > sym;
  stack < Token > opStk;
  stack < Token > varStk;	// Create an object of MyClass  Call the method

  for (int i = 0; i < buff.size (); i++)
    {

      locate = getLoc (buff[i], chars);


      if (locate < 0)
	{
	  cout << " start Error occurred" << endl;
	  return 0;
	}
      do
	{
	  tab = false;
	  switch (state)
	    {
	    case 0:
	      state = stateTab[state][locate];
	      break;
	    case 1:
	      state = stateTab[state][locate];
	      break;
	    case 2:
	      state = stateTab[state][locate];
	      break;
	    case 3:
	      state = stateTab[state][locate];
	      break;
	    case 4:
	      state = stateTab[state][locate];
	      break;
	    case 5:
	      state = stateTab[state][locate];
	      break;
	    case 6:
	      state = stateTab[state][locate];
	      break;
	    case 7:
	      state = stateTab[state][locate];
	      break;
	    case 8:
	      state = stateTab[state][locate];
	      break;
	    case 9:
	      state = stateTab[state][locate];
	      break;
	    case 10:
	      als.push_back (Token (item, "<mop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 11:
	      als.push_back (Token (item, "<int>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 12:
	      addReswords (item, als);
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 13:
	      als.push_back (Token (item, "<mop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 14:
	      als.push_back (Token (item, "<assign>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 15:
	      als.push_back (Token (item, "<relop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 16:
	      als.push_back (Token (item, "<relop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 17:
	      als.push_back (Token (item, "<relop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 18:
	      als.push_back (Token (item, "<relop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 19:
	      als.push_back (Token (item, "<relop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 20:
	      als.push_back (Token (item, "<relop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 21:
	      als.push_back (Token (item, "<addop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 22:
	      als.push_back (Token (item, "<addop>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 23:
	      als.push_back (Token (item, "<comma>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 24:
	      als.push_back (Token (item, "<semi>"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 25:
	      als.push_back (Token (item, "$LP"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 26:
	      als.push_back (Token (item, "$RP"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 27:
	      als.push_back (Token (item, "$LB"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    case 28:
	      als.push_back (Token (item, "$RB"));
	      mem.push_back (i);
	      item = "";
	      state = 0;
	      tab = false;
	      break;
	    default:
	      cout << "Error occurred end" << endl;
	    }
	  if (locate < 16 && !tab)
	    {
	      item += buff[i];
	    }
	  else if (state > 9)
	    {
	      tab = true;
	    }
	}
      while (tab);
    }

  processSymbolTable (als, sym);
  setUpMod (als, modToks);
  process (modToks, varStk, alq);
  basicOpt (alq);
  processAssemble (sym, alq);
  
  
  cout<<"Generating Quads"<<endl;
  for (int i = 0; i < alq.size(); i++)
      {  cout<<alq[i].toString()<<endl;  }
      
      
  cout<<"Generating Assembly Code"<<endl;
      
    ifstream file1 ("code.asm");
  while (!file1.eof ())
    {

      file1.get (ch);
      cout<<ch;
    }
  cout << endl;
  file1.close ();  
      
  
  



  return 0;
}
