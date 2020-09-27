#ifndef nodeprimitive_hpp
#define nodeprimitive_hpp

#include <string>
#include <set>
#include <vector>

class Primitive : public TreeNode
{
  private:
    int Type;// 0->number 1->variable 2->function call
    std::string Name;
    TreeNodePtr p1;
    TreeNodePtr p2;
    TreeNodePtr p3;
    TreeNodePtr p4;
    TreeNodePtr Expressions;

  public:
    Primitive(int t, std::string n, TreeNodePtr P1, TreeNodePtr P2, TreeNodePtr P3, TreeNodePtr P4, TreeNodePtr actual_expressions)
    {
      Type = t;
      Name = n;
      Expressions = actual_expressions;
      p1 = P1;
      p2 = P2;
      p3 = P3;
      p4 = P4;



    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      if (Type == 0 || Type == 1){
        return add_tabs(no_of_tabs)+Name;
      }
      else if (Type == 2) {
        std::string result = add_tabs(no_of_tabs)+Name + "(" ;
        if (p1){
          result += p1->translate(0, global_variables);
          if (p2){
            result += ", "+p2->translate(0, global_variables);
            if (p3){
              result += ", "+p3->translate(0, global_variables);
              if (p4){
                result += ", "+p4->translate(0, global_variables);
                if (Expressions){
                  result +=  ", "+Expressions->translate(0, global_variables);
                }
              }
            }
          }
        }

        result += ")";

        return result;


        /*if (Expressions){
          return add_tabs(no_of_tabs)+Name + "(" + Expressions->translate(0, global_variables) + ")";
        }
        else {
          return add_tabs(no_of_tabs)+Name + "()";
        }*/
      }
      return "error";

    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = "";
      if(Type == 0)
      {
        res = createint(Name);
        return res;
      }
      else if(Type == 1 and p1 == NULL)
      {
        //std::string tmp = where[Name];// in "where" we have location of our variable in memory

        for (int i = 0; i<new_where.size(); i++){
          if (new_where[i].name == Name){
            std::string tmp = new_where[i].location;
            res = memload(tmp);
            most_recent_type = new_where[i].type;
            return res;
          }
        }
      }
      else if(Type == 1 and p1 != NULL)
      {
        res += p1->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);//what's in the square brackets
        res += "sll $2, $2, 2\n";//times by 4
        std::string tmp;// = where[Name];//first index of array
        int base_index = -1;
        for (int i = 0; i<new_where.size(); i++){
          if ((new_where[i].name == Name)&&(new_where[i].index == 0)){
            tmp = new_where[i].location;
            base_index = i;
          }
        }
        bool GLOBAL = false;
        if(new_where[base_index].is_a_global == true)
        {
          GLOBAL = true;
          //tmp.pop_back();
          res += "add $24, $29, $0\nadd $29, $28, $0\n";
        }
        res += "addi $2, $2, " + tmp + "\n";
        res += "sub $29, $29, $2\n";
        res += movreg("12", "2");
        res += memload("0");
        res += "add $29, $29, $12\n";
        if(GLOBAL == true)
          res += "add $29, $24, $0\n";
        return res;
      }


      else if(Type == 2)
      {
        if(p1 != NULL)
        {
          res += p1->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
          res += movreg("4", "2");
          if(p2 != NULL)
          {
            res += p2->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
            res += movreg("5", "2");
            if(p3 != NULL)
            {
              res += p3->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
              res += movreg("6", "2");
              if(p4 != NULL)
              {
                res += p4->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
                res += movreg("7", "2");
              }
            }
          }
        }
        res += memstore("31", std::to_string(freemem));
        int freememcopy = freemem;
        freemem += 4;
        if(p4 != NULL and Expressions != NULL)
        {
          res += Expressions->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
          freemem += 12;
        }
        res += "addi $29, $29, -" + std::to_string(freemem) + "\n";
        res += "add $30, $29, $0\n";
        res += "jal " + Name + "\nadd $0, $0, $0\n";
        res += movreg("11", "2");
        res += "addi $29, $29, " + std::to_string(freemem) + "\n";
        res += "add $30, $29, $0\n";
        freemem = freememcopy;
        res += memload(std::to_string(freemem));
        res += movreg("31", "2");
        res += movreg("2", "11");
        freemem += 4;
        return res;
      }
    }

};

class Float : public TreeNode
{
  private:
    std::string first;
    std::string second;

  public:
    Float(std::string First, std::string Second)
    {
      first = First;
      second = Second;


    }

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      return "li.s $f0, "+first+"."+second+"\n";
    }

};







#endif
