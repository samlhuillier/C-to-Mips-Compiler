#ifndef nodeassign_hpp
#define nodeassign_hpp
#include <set>
#include <vector>

class Assign : public TreeNode
{
  private:
    std::string Name;
    TreeNodePtr Expression;
    TreeNodePtr Address;
    bool is_global;
    std::string Type;

  public:
    Assign(std::string n, TreeNodePtr e, TreeNodePtr a, bool isglobal = false, std::string type = "int")
    {
      Name = n;
      Expression = e;
      Address = a;
      is_global=isglobal;
      Type = type;
    }
    virtual ~Assign()
    {
      delete Expression;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string eval_expr = Expression->translate(0,global_variables);
      if (is_global){
        global_variables.insert(Name);
      }

      return add_tabs(no_of_tabs)+Name + " = " + eval_expr;


    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = Expression->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);

      std::string loc;
      int found_index= -1;
      for (int i = 0; i< new_where.size(); i++){
        if ((new_where[i].name == Name)&&(new_where[i].index <=0)){//if it's in there and is either variable or index 0 of array

          loc = new_where[i].location;//will be base location of array
          found_index = i;
        }
      }
      if (found_index==-1){//not found in memory
        loc = std::to_string(freemem);
        var tmp;
        tmp.name = Name;
        tmp.location = loc;
        tmp.type = Type;
        tmp.index = -1;
        new_where.push_back(tmp);
        res += memstore("2", loc);
        freemem += 4;
        return res;
      }
      else {//it is already in memory
        if (Address == NULL){
          res += memstore("2", loc);
          new_where[found_index].type = Type;
          return res;
        }
        int tmploc = freemem;
        res += memstore("2", std::to_string(freemem));
        freemem += 4;
        res += Address->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
        bool GLOBAL = false;
        if (new_where[found_index].is_a_global){
          GLOBAL = true;
        }
        res += "sll $2, $2, 2\n";
        res += "addi $2, $2, " + loc + "\n";
        res += movreg("12", "2");//$12 now stores our location of index
        res += memload(std::to_string(tmploc));//load initial result of expression
        if(GLOBAL == true)
          res += "add $24, $29, $0\nadd $29, $28, $0\n";//if global array we store sp in $24 and then make sp $28 so that we store in right place
        res += "sub $29, $29, $12\n";
        res += memstore("2", "0");
        res += "add $29, $29, $12\n";
        if(GLOBAL == true)
          res += "add $29, $24, $0\n";
      }




      /*
      if(where.find(Name) == where.end())// we don't have this variable in memory
      {
        std::string loc = std::to_string(freemem);
        where[Name] = loc;
        res += memstore("2", loc);
        freemem += 4;
        return res;
      }
      else
      {
        std::string loc = where[Name];
        if(Address == NULL)
        {
          res += memstore("2", loc);
          return res;
        }
        int tmploc = freemem;
        res += memstore("2", std::to_string(freemem));
        freemem += 4;
        res += Address->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
        bool GLOBAL = false;
        if(loc[loc.size() - 1] == 'g')//I think this just checks whether it is global
        {
          GLOBAL = true;
          loc.pop_back();
        }
        res += "sll $2, $2, 2\n";
        res += "addi $2, $2, " + loc + "\n";
        res += movreg("12", "2");
        res += memload(std::to_string(tmploc));
        if(GLOBAL == true)
          res += "add $24, $29, $0\nadd $29, $28, $0\n";
        res += "sub $29, $29, $12\n";
        res += memstore("2", "0");
        res += "add $29, $29, $12\n";
        if(GLOBAL == true)
          res += "add $29, $24, $0\n";
      }*/
    }

};



#endif
