#ifndef nodeif_hpp
#define nodeif_hpp

#include <string>
#include <set>
#include <vector>

class If : public TreeNode
{
  private:
    TreeNodePtr Condition;
    TreeNodePtr Sequence;
    TreeNodePtr Else;
  public:
    If(TreeNodePtr C, TreeNodePtr S, TreeNodePtr E)
    {
      Condition = C;
      Sequence = S;
      Else = E;
    }
    virtual ~If()
    {
      delete Condition;
      delete Sequence;
      delete Else;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string eval_condition = Condition->translate(0,global_variables);
      std::string true_code = Sequence->translate(no_of_tabs+1,global_variables);
      if (Else){
        std::string else_code = Else->translate(no_of_tabs+1,global_variables);
        return add_tabs(no_of_tabs)+"if ("+eval_condition+"): \n "+true_code+"\n"+add_tabs(no_of_tabs)+ "else:\n"+else_code;
      }
      else {
        return add_tabs(no_of_tabs)+"if ("+eval_condition+"): \n "+true_code;
      }
    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = Condition->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string tmp = "";
      if(Sequence != NULL){
        tmp += Sequence->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      }
      res += "beq $0, $2, else" + std::to_string(unique) + "\nadd $0, $0, $0\n";
      res += tmp;
      res += "beq $0, $0, if_end" + std::to_string(unique + 1) + "\nadd $0, $0, $0\nelse" + std::to_string(unique) + ":\n";
      ++unique;
      int uq = unique;
      ++unique;
      if(Else != NULL){
        res += Else->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      }
      res += "if_end" + std::to_string(uq) + ":\n";
      return res;
    }

};



#endif
