#ifndef nodebreak_hpp
#define nodebreak_hpp

#include <vector>

class Break : public TreeNode
{
  public:
    Break()
    {}

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "j while_end" + std::to_string(loopid) + "\nadd $0, $0, $0\n";
      return res;
    }
};


#endif
