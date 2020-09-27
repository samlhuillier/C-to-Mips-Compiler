#ifndef treenode_hpp
#define treenode_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <set>

struct var {
  std::string name;
  std::string location;
  std::string type;
  int index;//set to -1 if not array
  bool is_a_global;
};
class TreeNode;

typedef TreeNode* TreeNodePtr;

class TreeNode
{
  public:
    virtual ~TreeNode()
    {}
    // "where" keeps track where a variable is stored. REGXX -> it's in register XX; MEMXXXXXX -> it's it memory location XXXXXX

    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables){
      throw std::runtime_error("Something went very wrong translate.");

    }
    std::string add_tabs(int no_of_tabs){
      std::string ans;
      for (int i = 0; i<no_of_tabs; i++){
        ans += '\t';
      }
      return ans;
    }
    virtual TreeNodePtr get_next(){//MAYBE WE DONT NEED THESE FUNCTIONS IF I ACTUALLY UNDERSTOOD HOW VIRTUAL FUNCTIONS WORK
      throw std::runtime_error("Something went very wrong next.");
    }
    virtual TreeNodePtr get_relevant(){
      throw std::runtime_error("Something went very wrong relevant.");

    }

    // this function returns a string -> our program in MIPS
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type)
    { throw std::runtime_error("Something went very wrong."); }

    std::string createint(std::string val)
    {
      int value = std::stoi(val);
      std::string res;
      if(value >= (1 << 16))
      {
        res = "addi $2, $0, " + std::to_string(value >> 16) + "\n";
        res += "sll $2, $2, 16\n";
        res += "addi $2, $2, " + std::to_string((value & ((1 << 16) - 1))) + "\n";
        return res;
      }
      res = "addi $2, $0, " + val + "\n";
      return res;
    }

    std::string movreg(std::string dest, std::string src)
    {
      std::string res;
      res = "add $" + dest + ", $0, $" + src + "\n";
      return res;
    }

    std::string memload(std::string loc)
    {
      std::string res = createint(loc);
      std::string tmploc = "";
      for(int i = 1; i < loc.size(); ++i)
        tmploc.push_back(loc[i]);
      if(loc[0] == '-')
        res += "lw $2, " + tmploc + "($29)\n";
      else
        res += "lw $2, -" + loc + "($29)\n";
      return res;
    }

    std::string memstore(std::string src, std::string loc)
    {
      std::string res = movreg("9", src);
      std::string tmploc = "";
      for(int i = 1; i < loc.size(); ++i)
        tmploc.push_back(loc[i]);
      if(loc[0] == '-')
        res += "sw $9, " + tmploc + "($29)\n";
      else
        res += "sw $9, -" + loc + "($29)\n";
      return res;
    }
};


#endif
