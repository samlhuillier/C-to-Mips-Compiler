#ifndef nodeunary_hpp
#define nodeunary_hpp
#include <set>
#include <vector>

class NegOp : public TreeNode
{
  private:
    TreeNodePtr Expression;

  public:
    NegOp(TreeNodePtr e)
    {
      Expression = e;
    }
    virtual ~NegOp()
    {
      delete Expression;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      return add_tabs(no_of_tabs)+"(-"+Expression->translate(0, global_variables)+")";
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = Expression->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += "sub $2, $0, $2\n";
      return res;
    }
};




#endif
