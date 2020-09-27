#ifndef nodeswitchbody_hpp
#define nodeswitchbody_hpp

#include <string>
#include <vector>

class SwitchBody : public TreeNode
{
  private:
    TreeNodePtr Next;
    TreeNodePtr Relevant;
    std::string Value;
  public:
    SwitchBody(TreeNodePtr N, TreeNodePtr R, std::string V)
    {
      Next = N;
      Relevant = R;
      Value = V;
    }
    virtual ~SwitchBody()
    {
      delete Next;
      delete Relevant;
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "switch_" + std::to_string(loopid) + "_" + Value + ":\n";
      if(Value == "")
        jumps = jumps + "j " + "switch_" + std::to_string(loopid) + "_" + Value + "\nadd $0, $0, $0\n";
      else
        jumps = jumps + "addi $9, $0, " + Value + "\nbeq $2, $9, " + "switch_" + std::to_string(loopid) + "_" + Value + "\nadd $0, $0, $0\n";
      res += Relevant->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      if(Next != NULL)
        res += Next->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      return res;
    }

};



#endif
