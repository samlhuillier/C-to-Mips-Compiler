#ifndef nodederef_hpp
#define nodederef_hpp
#include <vector>

class Deref : public TreeNode
{
  private:
    std::string var1;

  public:
    Deref(std::string v1)
    {
      var1 = "*" + v1;
    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      for (int i = 0; i< new_where.size(); i++){
        if (new_where[i].name == var1){
          std::string res = memload(new_where[i].location);
          res += movreg("9", "2");
          res += "sub $29, $29, $9\n";
          res += memload("0");
          res += "add $29, $29, $9\n";
          return res;
        }
      }

    }
};




#endif
