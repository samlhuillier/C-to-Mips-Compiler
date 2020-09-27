#ifndef nodefor_hpp
#define nodefor_hpp

#include <string>
#include <vector>

class For : public TreeNode
{
  private:
    TreeNodePtr Init;
    TreeNodePtr Condition;
    TreeNodePtr End;
    TreeNodePtr Sequence;
  public:
    For(TreeNodePtr I, TreeNodePtr C, TreeNodePtr E, TreeNodePtr S)
    {
      Init = I;
      Condition = C;
      End = E;
      Sequence = S;
    }
    virtual ~For()
    {
      delete Condition;
      delete Sequence;
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      int unq = unique;
      std::string res = Init->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += "while_" + std::to_string(unique) + ":\n";
      ++unique;
      res += Condition->compile(where, freemem, unique, unq, End, jumps, new_where, most_recent_type);
      std::string tmp = Sequence->compile(where, freemem, unique, unq, End, jumps, new_where, most_recent_type);
      res += "beq $0, $2, while_end" + std::to_string(unq) + "\nadd $0, $0, $0\n";
      res += tmp;
      res += End->compile(where, freemem, unique, unq, End, jumps, new_where, most_recent_type);
      res += "beq $0, $0, while_" + std::to_string(unq) + "\nadd $0, $0, $0\nwhile_end" + std::to_string(unq) + ":\n";

      return res;
    }

};



#endif
