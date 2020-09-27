#ifndef nodeargument_hpp
#define nodeargument_hpp

#include <string>
#include <set>

class PAR : public TreeNode
{
  private:
    std::string Name;
  public:
    PAR(std::string N)
    {
      Name = N;
    }

    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      return add_tabs(no_of_tabs)+Name;
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      var tmp;
      tmp.name = Name;
      tmp.location = std::to_string(-freemem);
      tmp.is_a_global = false;
      tmp.type = "int";
      new_where.push_back(tmp);
      freemem += 4;
      return "";

    }

};



#endif
