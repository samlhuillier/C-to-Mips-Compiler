#ifndef nodecontinue_hpp
#define nodecontinue_hpp

#include <vector>

class Continue : public TreeNode
{
  public:
    Continue()
    {}

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "";
      if(ending != NULL)
        res += ending->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += "j while_" + std::to_string(loopid) + "\nadd $0, $0, $0\n";
      return res;
    }
};


#endif
