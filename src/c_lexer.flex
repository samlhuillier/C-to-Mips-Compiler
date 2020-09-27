%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
extern FILE *yyin;
#include "c_parser.tab.hpp"
%}

%%
[*]                             { return T_TIMES; }
[+]                             { return T_PLUS; }
[/]                             { return T_DIVIDE; }
[-]                             { return T_MINUS; }
[%]                             { return T_MOD; }
[&]                             { return T_BAND; }
[|]                             { return T_BOR; }
[!]                             { return T_NOT; }
[\^]                            { return T_XOR; }

[<]                             { return T_LESS; }
[>]                             { return T_GREAT; }
[<][<]                          {return T_TWOLESS;}
[>][>]                          {return T_TWOGREAT;}
[<][=]                          {return T_LESSEQUAL;}
[>][=]                          {return T_GREATEQUAL;}
[=]                             { return T_ASSIGN; }

[(]                             { return T_LBRACKET; }
[)]                             { return T_RBRACKET; }
[{]                             { return T_OPEN; }
[}]                             { return T_CLOSE; }
[;]                             { return T_EOL; }
[,]                             { return T_COMMA; }
[.]                             { return T_DOT; }
[[]                             { return T_LSQ; }
[]]                             { return T_RSQ; }
[:]                             { return T_COLON;}

[+][+]                          { return T_PP; }
[+][=]                          { return T_PE; }
[-][-]                          { return T_MM; }
[-][=]                          { return T_ME; }
[*][=]                          { return T_TE; }
[/][=]                          { return T_DE; }
[%][=]                          { return T_MODE; }
[&][=]                          { return T_AE; }
[|][=]                          { return T_OE; }
[<][<][=]                       { return T_LSE; }
[>][>][=]                       { return T_RSE; }
[\^][=]                         { return T_XE; }

[r][e][t][u][r][n]              { return T_RETURN; }
[i][n][t]                       { return T_INT; }
[w][h][i][l][e]                 { return T_WHILE; }
[i][f]                          { return T_IF; }
[e][l][s][e]                    { return T_ELSE; }
[f][o][r]                       { return T_FOR; }
[b][r][e][a][k]                 { return T_BREAK; }
[c][o][n][t][i][n][u][e]        { return T_CONT; }
[s][w][i][t][c][h]              { return T_SWITCH; }
[c][a][s][e]                    { return T_CASE; }
[d][e][f][a][u][l][t]           { return T_DEFAULT; }
[&][&]                          { return T_LAND; }
[|][|]                          { return T_LOR; }
[>][>]                          { return T_ARS; }
[<][<]                          { return T_ALS; }
[v][o][i][d]             {return T_VOID;}
[u][n][s][i][g][n][e][d]  {return T_UNSIGNED;}

[0-9]+                          { yylval.string = new std::string(yytext); return T_NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*          { yylval.string = new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		                  {;}

.                               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
