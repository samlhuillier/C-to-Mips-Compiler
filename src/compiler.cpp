#include <set>
#include <iterator>
#include "ast.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
//using namespace std;
/*
int main(int argc, char *argv[])
{

  //TreeNodePtr f = parseAST();
  //string res = f->compile(locations, mem, unique, 0, NULL, temp);

  //cout << res << "\n";
  /*set<string> global_variables;
  string trans_result = f->translate(0, global_variables);
  cout<<trans_result<<endl;*/
/*
  if (strcmp( argv[1], "--translate") == 0){
    //std::ifstream cc_code(argv[2]);
    TreeNodePtr parse_out = parseAST(argv[2]);
    set<string> global_variables;
    cout<<"hola baby"<<"\n";
    string trans_result = parse_out->translate(0, global_variables);
    cout<<trans_result<<"\n";

  }
  else if (strcmp( argv[1], "--S") == 0){
    map <string, string> locations;
    int mem = 0;
    int unique = 0;
    string temp = "";
    TreeNodePtr f = parseAST(argv[2]);
    string res = f->compile(locations, mem, unique, 0, NULL, temp);
    cout << res << "\n";
  }
}*/




//using namespace std;

int main(int argc, char *argv[])
{

  //TreeNodePtr f = parseAST();
  //string res = f->compile(locations, mem, unique, 0, NULL, temp);

  //cout << res << "\n";
  /*set<string> global_variables;
  string trans_result = f->translate(0, global_variables);
  cout<<trans_result<<endl;*/

  if (strcmp( argv[1], "--translate") == 0){
    //std::ifstream cc_code(argv[2]);
    TreeNodePtr parse_out = parseAST(argv[2]);
    std::set<std::string> global_variables;
    std::string trans_result = parse_out->translate(0, global_variables);
    //std::cout<<trans_result<<"\n";
    std::ofstream output(argv[4]);

    output<<trans_result;
    output.close();//we need to look at opening and closing files errors opening and so on.

  }
  else if (strcmp( argv[1], "-S") == 0){
    std::map <std::string, std::string> locations;
    std::vector<var> new_where;
    std::string most_recent_type;
    int mem = 0;
    int unique = 0;
    std::string temp = "";
    TreeNodePtr f = parseAST(argv[2]);
    std::string res = f->compile(locations, mem, unique, 0, NULL, temp, new_where, most_recent_type);
    std::ofstream output(argv[4]);
    output<<res;
    output.close();
  }
}
