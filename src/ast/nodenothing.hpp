#ifndef nodenothing_hpp
#define nodenothing_hpp

#include <string>
#include <vector>

class Nothing : public TreeNode
{

  public:
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      return "add $0, $0, $0\n";
    }

};



#endif
