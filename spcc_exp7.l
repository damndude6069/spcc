%{
#include<stdio.h>
%}
LETTER[a-z][A-Z]
DIGIT[0-9]
%%
begin { printf("Recognized Keyword: %s\n", yytext);}
if {printf("Recognised Keyword: %s\n", yytext);}
{LETTER}({LETTER}|{DIGIT})* {printf("Recognized ID: %s\n",yytext);}
%%
int main()
{
yylex();
}

/* commands:
lex filename.l
gcc lex.yy.c -ll
./a.out
*/