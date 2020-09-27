#ifndef nodeexprset.hpp
#define nodeexprset_hpp

#include <string>
#include <set>

class Exprset : public TreeNode
{
  private:
    TreeNodePtr Next;
    TreeNodePtr Relevant;

  public:
    virtual TreeNodePtr get_relevant() override{
      return Relevant;
    }
    virtual TreeNodePtr get_next() override {
      return Next;
    }

    Exprset(TreeNodePtr N, TreeNodePtr R)
    {

      Next = N;
      Relevant = R;

    }
    virtual ~Exprset()
    {
      delete Next;
      delete Relevant;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      if (Next){
        std::string ints_next = Next->translate(no_of_tabs, global_variables);
        return Relevant->translate(no_of_tabs, global_variables)+ ", "+ints_next;
      }
      else {
        return Relevant->translate(no_of_tabs, global_variables);
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
