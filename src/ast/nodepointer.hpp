#ifndef nodepointer_hpp
#define nodepointer_hpp
#include <vector>

class Pointer : public TreeNode
{
  private:
    std::string var1;
    std::string var2;

  public:
    Pointer(std::string v1, std::string v2)
    {
      var1 = "*" + v1;
      var2 = v2;
    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "";
      std::string address;
      for (int i = 0; i< new_where.size(); i++){
        if (new_where[i].name == var2){

          address = new_where[i].location;
          break;
        }
      }
      res += "addi $2, $0, " + address + "\n";//address of where value is stored
      bool found = false;
      std::string loc;//address of where pointer is stored
      for (int i = 0; i<new_where.size(); i++){
        if (new_where[i].name == var1){
          found = true;
          loc = new_where[i].location;
          break;
        }
      }
      if (!found){//we haven't created the pointer before
        loc = std::to_string(freemem);
        var tmp;
        tmp.name = var1;
        tmp.location = loc;
        tmp.is_a_global = false;
        tmp.index = -1;
        tmp.type = "int";
        new_where.push_back(tmp);
        res += memstore("2", loc);
        freemem += 4;
        return res;
      }
      res += memstore("2", loc);
      return res;
      /*
      if(where.find(var1) == where.end())
      {
        std::string loc = std::to_string(freemem);
        where[var1] = loc;
        res += memstore("2", loc);
        freemem += 4;
        return res;
      }
      std::string loc = where[var1];
      res += memstore("2", loc);
      return res;*/
    }
};




#endif
