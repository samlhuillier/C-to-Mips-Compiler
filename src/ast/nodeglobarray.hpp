#ifndef nodeglobarray_hpp
#define nodeglobarray_hpp

#include <string>
#include <vector>

class GlobArray : public TreeNode
{
  private:
    std::string Name;
    std::string Size;
    std::string Type;
  public:
    GlobArray(std::string N, std::string S, std::string T="int")
    {
      Name = N;
      Size = S;
      Type = T;
    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "";
      int s = std::atoi(Size.c_str());
      res = "add $24, $29, $0\nadd $29, $28, $0\n";//move sp to reg 24 to store and move globpointer to $29
      var tmp;
      tmp.name = Name;
      tmp.type = Type;
      tmp.is_a_global = true;
      for(int i = 0; i < s; ++i)//cycle through the size
      {
        std::string loc = std::to_string(freemem);
        //where[Name + "[" + std::to_string(i) + "]"] = loc + "g";
        tmp.location = loc;
        tmp.index = i;
        new_where.push_back(tmp);
        res += memstore("0", loc);//store 0's in each location based on glob pointer so it's in a different place
        freemem += 4;
      }
      res += "add $29, $24, $0\n";
      return res;
    }

};



#endif
