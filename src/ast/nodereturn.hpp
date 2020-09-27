#ifndef nodereturn_hpp
#define nodereturn_hpp
#include <set>
#include <vector>


class Return : public TreeNode
{
  private:
    TreeNodePtr Expression;

  public:
    Return(TreeNodePtr e)
    {
      Expression = e;
    }
    virtual ~Return()
    {
      delete Expression;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string eval_expr = Expression->translate(0,global_variables);
      return add_tabs(no_of_tabs)+"return "+eval_expr;
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = Expression->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += "jr $31\nadd $0, $0, $0\n";
      return res;
    }
};


#endif
