#ifndef nodewhile_hpp
#define nodewhile_hpp

#include <string>
#include <set>
#include <vector>
class While : public TreeNode
{
  private:
    TreeNodePtr Condition;
    TreeNodePtr Sequence;
  public:
    While(TreeNodePtr C, TreeNodePtr S)
    {
      Condition = C;
      Sequence = S;
    }
    virtual ~While()
    {
      delete Condition;
      delete Sequence;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string eval_cond = Condition->translate(0, global_variables);
      std::string seq_eval = Sequence->translate(no_of_tabs+1, global_variables);
      return add_tabs(no_of_tabs)+"while ("+eval_cond+"):\n"+seq_eval;
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      int unq = unique;
      std::string res = "while_" + std::to_string(unique) + ":\n";
      ++unique;
      res += Condition->compile(where, freemem, unique, unq, ending, jumps, new_where, most_recent_type);
      if(Sequence == NULL)
        return res;
      std::string tmp = Sequence->compile(where, freemem, unique, unq, ending, jumps, new_where, most_recent_type);
      res += "beq $0, $2, while_end" + std::to_string(unq) + "\nadd $0, $0, $0\n";
      res += tmp;
      res += "beq $0, $0, while_" + std::to_string(unq) + "\nadd $0, $0, $0\nwhile_end" + std::to_string(unq) + ":\n";

      return res;
    }

};



#endif
