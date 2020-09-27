#ifndef nodebody_hpp
#define nodebody_hpp

#include <string>
#include <set>

class Body : public TreeNode
{
  private:
    TreeNodePtr Next;
    TreeNodePtr Relevant;
    bool is_end_of_file;
  public:
    Body(TreeNodePtr N, TreeNodePtr R, bool is_end = false)
    {
      Next = N;
      Relevant = R;
      is_end_of_file = is_end;
    }
    virtual ~Body()
    {
      delete Next;
      delete Relevant;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      if (Next){

        return Relevant->translate(no_of_tabs,global_variables)+ "\n"+Next->translate(no_of_tabs,global_variables);
      }
      else {
        if (is_end_of_file){
          return Relevant->translate(no_of_tabs,global_variables)+"\n"+add_tabs(no_of_tabs)+"if __name__ == \"__main__\":\n"+add_tabs(no_of_tabs+1)+"import sys\n"+add_tabs(no_of_tabs+1)+"ret=main()\n"+add_tabs(no_of_tabs+1)+"sys.exit(ret)";

        }
        else {
          return Relevant->translate(no_of_tabs,global_variables);
        }
      }
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      if(Relevant == NULL)
        return res;
      res = Relevant->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      if(Next != NULL)
        res += Next->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      return res;
    }

};



#endif
