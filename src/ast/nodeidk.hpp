#ifndef nodeidk_hpp
#define nodeidk_hpp

#include <string>
#include <set>

class Idk : public TreeNode
{
  private:
    TreeNodePtr P;
  public:
    Idk(TreeNodePtr tmp)
    {
      P = tmp;
    }
    virtual ~Idk()
    {
      delete P;
    }

    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      return add_tabs(no_of_tabs)+P->translate(0, global_variables);
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = P->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      return res;
    }

};



#endif
