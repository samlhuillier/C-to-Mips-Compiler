#ifndef nodearray_hpp
#define nodearray_hpp

#include <string>
#include <vector>

class Array : public TreeNode
{
  private:
    std::string Name;
    std::string Size;
    std::string Type;
  public:
    Array(std::string N, std::string S, std::string T = "int")
    {
      Name = N;
      Size = S;
      Type = T;
    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "";
      int s = std::atoi(Size.c_str());
      var tmp;
      tmp.name = Name;
      tmp.type = Type;
      tmp.is_a_global = false;
      for(int i = 0; i < s; ++i)
      {
        std::string loc = std::to_string(freemem);
        //where[Name + "[" + std::to_string(i) + "]"] = loc;

        tmp.location = loc;
        tmp.index = i;
        new_where.push_back(tmp);
        res += memstore("0", loc);
        freemem += 4;
      }
      return res;
    }

};



#endif
