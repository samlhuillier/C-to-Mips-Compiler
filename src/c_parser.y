%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern TreeNode* g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  TreeNode* node;
  std::string *string;
}

%token T_INT T_PP T_PE T_MM T_ME T_DE T_TE T_MODE T_AE T_OE T_RSE T_LSE T_XE
%token T_ASSIGN
%token T_BAND T_BOR T_NOT T_XOR T_LESS T_GREAT T_LAND T_LOR T_ARS T_ALS T_TWOLESS T_TWOGREAT T_LESSEQUAL T_GREATEQUAL
%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_MOD
%token T_LBRACKET T_RBRACKET T_OPEN T_CLOSE T_COMMA T_LSQ T_RSQ T_COLON T_DOT
%token T_NUMBER T_VARIABLE T_IF T_ELSE
%token T_EOL T_RETURN T_WHILE T_FOR T_BREAK T_CONT T_SWITCH T_CASE T_DEFAULT T_VOID T_UNSIGNED

%type <node> FUNCT EXPR TERM UNARY LINES LINE FACTOR E1 E2 E3 C1 C2 FUNCTIONS LINE2 SWITCH_BODY E12 E21 E4 EXPRS PARAMS  FINALPARAMS SHIFT PAR IDK
%type <string> T_VARIABLE T_NUMBER AN_UNSIGNED

%start ROOT

%%

ROOT : FUNCTIONS { g_root = $1; }

FUNCTIONS : FUNCT                                                 { $$ = new Body(NULL, $1, true); }
          | FUNCT FUNCTIONS                                       { $$ = new Body($2, $1); }
          | T_INT T_VARIABLE T_LSQ T_NUMBER T_RSQ T_EOL FUNCTIONS { $$ = new Body($7, new GlobArray(*$2, *$4)); }//declaring the array
          | T_INT T_VARIABLE T_ASSIGN E1 T_EOL FUNCTIONS                     { $$ = new Body($6, new Assign(*$2, $4, NULL,true)); }
          | T_VARIABLE T_ASSIGN E1 T_EOL FUNCTIONS                         { $$ = new Body($5, new Assign(*$1, $3, NULL,true)); }
          |T_INT T_VARIABLE T_EOL FUNCTIONS { $$ = new Body($4, new Assign(*$2, new Primitive(0, "0", NULL, NULL, NULL, NULL, NULL), NULL, true)); }
/*
FUNCT : T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                                                                                               { $$ = new Function(*$2, $6, "", "", "", "", NULL); }
      | T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                                                                                               { $$ = new Function(*$2, $6, "", "", "", "", NULL); }
      | T_VOID T_VARIABLE  FINALPARAMS  T_OPEN LINES T_CLOSE    { $$ = new Function(*$2, $5, "", "", "", "", $3); }
      | T_INT T_VARIABLE  FINALPARAMS  T_OPEN LINES T_CLOSE    { $$ = new Function(*$2, $5, "", "", "", "", $3); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                                                                              { $$ = new Function(*$2, $8, *$5, "", "", ""); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                                                     { $$ = new Function(*$2, $11, *$5, *$8, "", ""); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                            { $$ = new Function(*$2, $14, *$5, *$8, *$11, ""); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE   { $$ = new Function(*$2, $17, *$5, *$8, *$11, *$14); }
      | T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_EOL                                                                                                              { $$ = new Nothing(); }
      | T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_EOL             { $$ = new Nothing(); }
      | T_INT T_VARIABLE FINALPARAMS T_EOL {$$= new Nothing();}//maybe add translate functionality
      |   T_VOID T_VARIABLE FINALPARAMS T_EOL {$$= new Nothing();}
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_RBRACKET T_EOL                                                                                             { $$ = new Nothing(); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_EOL                                                                    { $$ = new Nothing(); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_EOL                                           { $$ = new Nothing(); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_EOL                  { $$ = new Nothing(); }*/
FUNCT : T_INT T_VARIABLE FINALPARAMS T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $5, $3); }
      | T_VOID T_VARIABLE FINALPARAMS T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $5, $3); }
      | T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $6, NULL); }
      | T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $6, NULL); }
      | T_INT T_VARIABLE FINALPARAMS T_EOL                                                                                                                                      { $$ = new Nothing();}
      | T_VOID T_VARIABLE FINALPARAMS T_EOL                                                                                                                                      { $$ = new Nothing();}
      | T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_EOL                                                                                                                                      { $$ = new Nothing();}
      | T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_EOL                                                                                                                                      { $$ = new Nothing();}
      | AN_UNSIGNED T_VARIABLE FINALPARAMS T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $5, $3); }
      | AN_UNSIGNED T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $6, NULL); }
      | AN_UNSIGNED T_VARIABLE FINALPARAMS T_EOL                                                                                                                                      { $$ = new Nothing();}
//T_INT T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                                                                                                             { $$ = new Function(*$2, $6, "", "", "", "", NULL); }
      //| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_OPEN LINES T_CLOSE                                                                                                            { $$ = new Function(*$2, $6, "", "", "", "", NULL); }
      //| T_VOID T_VARIABLE  FINALPARAMS  T_OPEN LINES T_CLOSE                                                                                                                    { $$ = new Function(*$2, $5, "", "", "", "", $3);}
      /*| T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                                                                                            { $$ = new Function(*$2, $8, *$5, "", "", "", NULL); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                                                                   { $$ = new Function(*$2, $11, *$5, *$8, "", "", NULL); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                                          { $$ = new Function(*$2, $14, *$5, *$8, *$11, "", NULL); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_RBRACKET T_OPEN LINES T_CLOSE                 { $$ = new Function(*$2, $17, *$5, *$8, *$11, *$14, NULL); }
      | T_INT T_VARIABLE T_LBRACKET T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA T_INT T_VARIABLE T_COMMA PAR T_RBRACKET T_OPEN LINES T_CLOSE     { $$ = new Function(*$2, $19, *$5, *$8, *$11, *$14, $16); }*/
      //| T_VOID T_VARIABLE T_LBRACKET T_RBRACKET T_EOL                                                                                                                           { $$ = new Nothing(); }
      //| T_INT T_VARIABLE FINALPARAMS T_EOL                                                                                                                                      { $$ = new Nothing();}//maybe add translate functionality
      //| T_VOID T_VARIABLE FINALPARAMS T_EOL                                                                                                                                     { $$ = new Nothing();}


LINES : LINE LINES                                { $$ = new Body($2, $1); }
      | LINE                                      { $$ = new Body(NULL, $1); }

LINE  : T_INT T_VARIABLE T_ASSIGN E1 T_EOL                                              { $$ = new Assign(*$2, $4, NULL); }
      | T_VARIABLE T_ASSIGN E1 T_EOL                                                    { $$ = new Assign(*$1, $3, NULL); }
      | AN_UNSIGNED T_VARIABLE T_ASSIGN E1 T_EOL                                         { $$ = new Assign(*$2, $4, NULL, false, "unsigned"); }
      | E1 T_EOL                                                                        { $$ = $1; }
      | T_INT T_VARIABLE T_EOL                                                          { $$ = new Assign(*$2, new Primitive(0, "0", NULL, NULL, NULL, NULL, NULL), NULL); }
      | T_RETURN E1 T_EOL                                                               { $$ = new Return($2); }
      | T_WHILE T_LBRACKET E1 T_RBRACKET LINE                                           { $$ = new While($3, $5); }
      | T_WHILE T_LBRACKET E1 T_RBRACKET T_OPEN LINES T_CLOSE                           { $$ = new While($3, $6); }
      | T_WHILE T_LBRACKET E1 T_RBRACKET T_OPEN T_CLOSE                                 { $$ = new While($3, NULL); }
      | T_IF T_LBRACKET E1 T_RBRACKET LINE                                              { $$ = new If($3, $5, NULL); }
      | T_IF T_LBRACKET E1 T_RBRACKET LINE T_ELSE LINE                                  { $$ = new If($3, $5, $7); }
      | T_IF T_LBRACKET E1 T_RBRACKET LINE T_ELSE T_OPEN LINES T_CLOSE                  { $$ = new If($3, $5, $8); }
      | T_IF T_LBRACKET E1 T_RBRACKET T_OPEN LINES T_CLOSE                              { $$ = new If($3, $6, NULL); }
      | T_IF T_LBRACKET E1 T_RBRACKET T_OPEN LINES T_CLOSE T_ELSE LINE                  { $$ = new If($3, $6, $9); }
      | T_IF T_LBRACKET E1 T_RBRACKET T_OPEN LINES T_CLOSE T_ELSE T_OPEN LINES T_CLOSE  { $$ = new If($3, $6, $10); }
      | T_INT T_VARIABLE T_LSQ T_NUMBER T_RSQ T_EOL                                     { $$ = new Array(*$2, *$4); }
      | T_VARIABLE T_LSQ E1 T_RSQ T_ASSIGN E1 T_EOL                                     { $$ = new Assign(*$1, $6, $3); }//REMOVE + [0]
      | %empty                                                                          { $$ = new Nothing(); }
      | T_FOR T_LBRACKET LINE LINE LINE2 T_RBRACKET LINE                                { $$ = new For($3, $4, $5, $7); }
      | T_FOR T_LBRACKET LINE LINE LINE2 T_RBRACKET T_OPEN LINES T_CLOSE                { $$ = new For($3, $4, $5, $8); }
      | T_CONT T_EOL                                                                    { $$ = new Continue(); }
      | T_BREAK T_EOL                                                                   { $$ = new Break(); }
      | T_VARIABLE T_PE E1 T_EOL                                                        { $$ = new Assign(*$1, new AddOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_ME E1 T_EOL                                                        { $$ = new Assign(*$1, new SubOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_TE E1 T_EOL                                                        { $$ = new Assign(*$1, new MultOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_DE E1 T_EOL                                                        { $$ = new Assign(*$1, new DivOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_MODE E1 T_EOL                                                      { $$ = new Assign(*$1, new ModOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_OE E1 T_EOL                                                        { $$ = new Assign(*$1, new BorOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_XE E1 T_EOL                                                        { $$ = new Assign(*$1, new XorOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_AE E1 T_EOL                                                        { $$ = new Assign(*$1, new BandOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_LSE E1 T_EOL                                                       { $$ = new Assign(*$1, new ALSOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_VARIABLE T_RSE E1 T_EOL                                                       { $$ = new Assign(*$1, new ARSOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), $3), NULL); }
      | T_SWITCH T_LBRACKET E1 T_RBRACKET T_OPEN SWITCH_BODY T_CLOSE                    { $$ = new Switch($6, $3); }
      | T_INT T_TIMES T_VARIABLE T_EOL                                                  { $$ = new Nothing(); }
      | T_INT T_TIMES T_VARIABLE T_ASSIGN T_BAND T_VARIABLE T_EOL                       { $$ = new Pointer(*$3, *$6); }
      | T_VARIABLE T_ASSIGN T_BAND T_VARIABLE T_EOL                                     { $$ = new Pointer(*$1, *$4); }
      | T_TIMES T_VARIABLE T_ASSIGN E1 T_EOL                                            { $$ = new PAss(*$2, $4); }

AN_UNSIGNED : T_UNSIGNED {;}
            | T_UNSIGNED T_INT {;}
SWITCH_BODY : T_CASE T_NUMBER T_COLON LINES SWITCH_BODY                                 { $$ = new SwitchBody($5, $4, *$2); }
            | T_CASE T_NUMBER T_COLON LINES                                             { $$ = new SwitchBody(NULL, $4, *$2); }
            | T_DEFAULT T_COLON LINES                                                   { $$ = new SwitchBody(NULL, $3, ""); }

LINE2 : T_VARIABLE T_ASSIGN E1                                                     { $$ = new Assign(*$1, $3, NULL); }
      | E1                                                                         { $$ = $1; }
      | T_VARIABLE T_LSQ E1 T_RSQ T_ASSIGN E1                                      { $$ = new Assign(*$1 + "[0]", $6, $3); }
      | %empty                                                                     { $$ = new Nothing(); }


EXPRS : E1 T_COMMA EXPRS    { $$ = new Exprset($3, $1); }
            | E1                          { $$ = new Exprset(NULL, $1); }

/*PAR   : T_INT T_VARIABLE              { $$ = new PAR(*$2); }
      | T_INT T_VARIABLE T_COMMA PAR  { $$ = new Body($4, new PAR(*$2)); }*/

FINALPARAMS : T_LBRACKET PARAMS T_RBRACKET {$$ = $2;}

PARAMS :  T_INT T_VARIABLE T_COMMA PARAMS         { $$ = new Paramset($4, new PAR(*$2)); }
        | T_INT T_VARIABLE             { $$ = new Paramset(NULL, new PAR(*$2) ); }




E1    : E12                                       { $$ = $1; }
      | E1 T_LOR E12                              { $$ = new LorOperator($1, $3); }//I DONT SEE THE POINT OF JUST one | in C

E12   : E21                                       { $$ = $1; }
      | E12 T_LAND E21                            { $$ = new LandOperator($1, $3); }


E21   : E2                                        { $$ = $1; }
      | E21 T_BOR E2                              { $$ = new BorOperator($1, $3); }

E2    : E3                                        { $$ = $1; }
      | E2 T_XOR E3                               { $$ = new XorOperator($1, $3); }

E3    : E4                                        { $$ = $1; }
      | E3 T_BAND E4                              { $$ = new BandOperator($1, $3); }

E4    : C1                                        { $$ = $1; }
      | E4 T_ALS C1                               { $$ = new ALSOperator($1, $3); }
      | E4 T_ARS C1                               { $$ = new ARSOperator($1, $3); }

C1    : C2                                        { $$ = $1; }
      | C1 T_ASSIGN T_ASSIGN C2                   { $$ = new EqualOperator($1, $4); }
      | C1 T_NOT T_ASSIGN C2                      { $$ = new NequalOperator($1, $4); }

C2    : EXPR                                      { $$ = $1; }
      | C2 T_LESS EXPR                            { $$ = new LessOperator($1, $3); }
      | C2 T_LESSEQUAL EXPR                   { $$ = new LequalOperator($1, $3); }
      | C2 T_GREAT EXPR                           { $$ = new GreatOperator($1, $3); }
      | C2 T_GREATEQUAL EXPR                  { $$ = new GequalOperator($1, $3); }



EXPR  : TERM                                      { $$ = $1; }
      | EXPR T_PLUS TERM                          { $$ = new AddOperator($1, $3); }
      | EXPR T_MINUS TERM                         { $$ = new SubOperator($1, $3); }

TERM  : UNARY                                     { $$ = $1; }
      | TERM T_TIMES UNARY                        { $$ = new MultOperator($1, $3); }
      | TERM T_DIVIDE UNARY                       { $$ = new DivOperator($1, $3); }
      | TERM T_MOD UNARY                          { $$ = new ModOperator($1, $3); }

UNARY : FACTOR                                    { $$ = $1; }
      | T_MINUS FACTOR                            { $$ = new NegOp($2); }

IDK   : E1                                        { $$ = new Idk($1); }
      | IDK T_COMMA E1                            { $$ = new Exprset($1, new Idk($3)); }

FACTOR: T_NUMBER                                                              { $$ = new Primitive(0, *$1, NULL, NULL, NULL, NULL, NULL); }
      | T_VARIABLE                                                            { $$ = new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL); }
      | T_VARIABLE T_LBRACKET T_RBRACKET                                      { $$ = new Primitive(2, *$1, NULL, NULL, NULL, NULL, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_RBRACKET                                   { $$ = new Primitive(2, *$1, $3, NULL, NULL, NULL, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_RBRACKET                        { $$ = new Primitive(2, *$1, $3, $5, NULL, NULL, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_COMMA E1 T_RBRACKET             { $$ = new Primitive(2, *$1, $3, $5, $7, NULL, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_COMMA E1 T_COMMA E1 T_RBRACKET  { $$ = new Primitive(2, *$1, $3, $5, $7, $9, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_COMMA E1 T_COMMA E1 T_COMMA IDK T_RBRACKET  { $$ = new Primitive(2, *$1, $3, $5, $7, $9, $11); }
      | T_LBRACKET E1 T_RBRACKET                                              { $$ = $2; }
      | T_VARIABLE T_LSQ E1 T_RSQ                                             { $$ = new Primitive(1, *$1, $3, NULL, NULL, NULL, NULL); }
      | T_PP T_VARIABLE                                                       { $$ = new Body(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Assign(*$2, new AddOperator(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_MM T_VARIABLE                                                       { $$ = new Body(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Assign(*$2, new SubOperator(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_VARIABLE T_PP                                                       { $$ = new Body(new SubOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), new Assign(*$1, new AddOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_VARIABLE T_MM                                                       { $$ = new Body(new AddOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), new Assign(*$1, new SubOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_TIMES T_VARIABLE                                                    { $$ = new Deref(*$2); }
      /*
FACTOR: T_NUMBER                                                              { $$ = new Primitive(0, *$1, NULL, NULL, NULL, NULL, NULL); }
      | T_VARIABLE                                                            { $$ = new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL); }
      | T_NUMBER T_DOT T_NUMBER                                               { $$ = new Float(*$1, *$3); }
      | T_VARIABLE T_LBRACKET T_RBRACKET                                      { $$ = new Primitive(2, *$1, NULL, NULL, NULL, NULL, NULL); }
      | T_VARIABLE T_LBRACKET EXPRS T_RBRACKET                                { $$ = new Primitive(2, *$1, $3, NULL, NULL, NULL, $3);}
      | T_VARIABLE T_LBRACKET E1 T_RBRACKET                                   { $$ = new Primitive(2, *$1, $3, NULL, NULL, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_RBRACKET                        { $$ = new Primitive(2, *$1, $3, $5, NULL, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_COMMA E1 T_RBRACKET             { $$ = new Primitive(2, *$1, $3, $5, $7, NULL); }
      | T_VARIABLE T_LBRACKET E1 T_COMMA E1 T_COMMA E1 T_COMMA E1 T_RBRACKET  { $$ = new Primitive(2, *$1, $3, $5, $7, $9); }
      | T_LBRACKET E1 T_RBRACKET                                              { $$ = $2; }
      | T_VARIABLE T_LSQ E1 T_RSQ                                             { $$ = new Primitive(1, *$1, $3, NULL, NULL, NULL, NULL); }
      | T_PP T_VARIABLE                                                       { $$ = new Body(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Assign(*$2, new AddOperator(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_MM T_VARIABLE                                                       { $$ = new Body(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Assign(*$2, new SubOperator(new Primitive(1, *$2, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_VARIABLE T_PP                                                       { $$ = new Body(new SubOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), new Assign(*$1, new AddOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_VARIABLE T_MM                                                       { $$ = new Body(new AddOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), new Assign(*$1, new SubOperator(new Primitive(1, *$1, NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
      | T_TIMES T_VARIABLE                                                     { $$ = new Deref(*$2); }*/


%%

TreeNode* g_root; // Definition of variable (to match declaration earlier)

TreeNode* parseAST(char* input_file)
{
  g_root = 0;
  yyin = fopen(input_file, "r");
  if (yyin){
    yyparse();
  }

  fclose(yyin);
  return g_root;
}
