#ifndef nodeswitch_hpp
#define nodeswitch_hpp

#include <string>
#include <vector>

class Switch : public TreeNode
{
  private:
    TreeNodePtr Next;
    TreeNodePtr Relevant;
  public:
    Switch(TreeNodePtr N, TreeNodePtr R)
    {
      Next = N;
      Relevant = R;
    }
    virtual ~Switch()
    {
      delete Next;
      delete Relevant;
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string copy = jumps;
      std::string res = Relevant->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int unq = unique;
      ++unique;
      std::string tmp = Next->compile(where, freemem, unique, unq, ending, jumps, new_where, most_recent_type);
      res += jumps;
      res += tmp;
      res += "while_end" + std::to_string(unq) + ":\n";
      jumps = copy;
      return res;
    }

};



#endif
