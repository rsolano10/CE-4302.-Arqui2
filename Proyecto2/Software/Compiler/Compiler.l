%{
  /*_____Definition section_____literal c++ code between single "%"_____*/


  /*Necesary files to work.*/
  #include "y.tab.h" //yacc output file. Necesary to work.

  /*Necesary imports*/
  #include <string>
  #include <string.h>
  #include <stdlib.h>

  /*Function declaration*/
  void yyerror(std::string S); // Define error message
%}

%option yylineno 

comment ;.+ 
imme   \#-?(0x)?[a-fA-F0-9_]+
numero [a-fA-F0-9_]+ 

%%
  /*_____Rules section_____*/
  /*defined Operation keywords*/
(a|A)(d|D)(d|D)          {yylval.id=strdup(yytext); return addition;} //Add = addition
(s|S)(u|U)(b|B)          {yylval.id=strdup(yytext); return subtra;} //sub = substraction
(m|M)(u|U)(l|L)          {yylval.id=strdup(yytext); return multiple;} //mul = multiplication  
(l|L)(d|D)(r|R)          {yylval.id=strdup(yytext); return load;} //ldr = load from memory
(s|S)(t|T)(r|R)          {yylval.id=strdup(yytext); return store;}  //str = store in memory
(c|C)(m|M)(p|P)          {yylval.id=strdup(yytext); return comp;} //cmp = compare
(m|M)(o|O)(v|V)          {yylval.id=strdup(yytext); return mv;} //mov = move data to register
(x|X)(o|O)(r|R)          {yylval.id=strdup(yytext); return xorop;} //xor = xor operation between registers
(c|C)(s|S)(l|L)          {yylval.id=strdup(yytext); return circularleft;} //circular shift left
(c|C)(s|S)(r|R)          {yylval.id=strdup(yytext); return circularright;} //circular shift right
(l|L)(s|S)(l|L)          {yylval.id=strdup(yytext); return linealleft;} //lineal shift left
(l|L)(s|S)(r|R)          {yylval.id=strdup(yytext); return linealright;} //lineal shift right
(b|B)(r|R)(t|T)          {yylval.id=strdup(yytext); return brepeat;} //begin repeat
(e|E)(r|R)(t|T)          {yylval.id=strdup(yytext); return erepeat;} //end repeat

  /*Registers*/
(r|R)[0-9][0-5]?         {yylval.id=strdup(yytext); return reg;} //registers
    
  /*Immediate*/
{imme}                  {yylval.id=strdup(yytext); return immediate;}

  /*Comments*/
{comment}                {yylval.id=strdup(yytext); return commentary;}
  
  /*Numbers*/
{numero}                {yylval.num=atoi(yytext); return number;}

  /*White Spaces*/
[,\[\]\n\=\!]                 {return yytext[0];}
[\t \s]                   {;}
.                  {yyerror("caracter invalido");}
%%
int yywrap(void){
  return 1;
}
