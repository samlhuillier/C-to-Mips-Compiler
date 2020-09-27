#ifndef nodepass_hpp
#define nodepass_hpp
#include <vector>

class PAss : public TreeNode
{
  private:
    std::string var1;
    TreeNodePtr Expr;

  public:
    PAss(std::string v1, TreeNodePtr e)
    {
      var1 = "*" + v1;
      Expr = e;
    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "";
      res += Expr->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      std::string address;
      for (int i = 0; i<new_where.size(); i++){
        if (new_where[i].name == var1){
          address = new_where[i].location;
        }
      }
      res += memload(address);
      res += "sub $29, $29, $2\n";
      res += movreg("10", "2");
      res += memstore("9", "0");
      res += "add $29, $29, $2\n";
      return res;
    }
};




#endif
