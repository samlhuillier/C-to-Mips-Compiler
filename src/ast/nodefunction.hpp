#ifndef nodefunction_hpp
#define nodefunction_hpp

#include <string>
#include <set>
#include <vector>

class Function : public TreeNode
{
  private:
    TreeNodePtr Seq;
    std::string Name;
    std::string p1;
    std::string p2;
    std::string p3;
    std::string p4;
    TreeNodePtr the_paramset;
    TreeNodePtr copy_paramset_for_python;


  public:

    Function(std::string _Name, TreeNodePtr _Seq, TreeNodePtr a_paramset)
    {
      Name = _Name;
      Seq = _Seq;
      the_paramset = a_paramset;
      copy_paramset_for_python = the_paramset;
        //here we need to put the actual values
        std::set<std::string> empty_vect;
        if (the_paramset){
          p1 = the_paramset->get_relevant()->translate(0,empty_vect);//ok but jozef wants it in string format these p1's and so on what we are currently returning is a treeptr to a
          the_paramset = the_paramset->get_next();
          if (the_paramset){
            p2 = the_paramset->get_relevant()->translate(0,empty_vect);
            the_paramset = the_paramset->get_next();
            if (the_paramset){
              p3 = the_paramset->get_relevant()->translate(0,empty_vect);
              the_paramset = the_paramset->get_next();
              if (the_paramset){
                p4 = the_paramset->get_relevant()->translate(0,empty_vect);
                the_paramset = the_paramset->get_next();
              }
              else {
                p4 = "";
              }
            }
            else {
              p3 = "";
              p4 = "";
            }
          }
          else {
            p2 = "";
            p3 = "";
            p4 = "";
          }
        }
        else {
          p1 = "";
          p2 = "";
          p3 = "";
          p4 = "";
        }





    }

    virtual ~Function()
    {
      delete Seq;
    }
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string global_input = "";
      std::string arguments = "";
      if (copy_paramset_for_python){
        arguments = copy_paramset_for_python->translate(0, global_variables);

      }
      std::string func_body = Seq->translate(no_of_tabs+1, global_variables);

      for (std::set<std::string>::iterator ptr = global_variables.begin(); ptr != global_variables.end(); ++ptr){
        global_input = global_input + add_tabs(no_of_tabs+1)+"global "+*ptr+"\n";
      }

      return add_tabs(no_of_tabs)+ "def "+Name+"(" + arguments + "):\n"+global_input+func_body;



    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res = ".globl " + Name + "\n" + Name + ":\n";
      if(p4 != "" and the_paramset != NULL)
      {
        freemem = 16;
        res += the_paramset->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      }
      if(p1 != "")
      {
        bool tc = false;
        std::string loc1;
        for(int i = 0; i < new_where.size(); ++i)
          if(new_where[i].name == p1)
          {
            loc1 = new_where[i].location;
            tc = true;
            break;
          }
        if(tc == false)
          loc1 =  std::to_string(freemem);
        var tmp;
        tmp.name = p1;
        tmp.type = "int";
        tmp.location = loc1;
        tmp.index = -1;
        tmp.is_a_global = false;
        if(tc == false)
        {
          new_where.push_back(tmp);
          freemem += 4;
        }
        //where[p1] = loc1;
        res += memstore("4", loc1);

        if(p2 != "")
        {
          bool tc2 = false;
          std::string loc2;
          for(int i = 0; i < new_where.size(); ++i)
            if(new_where[i].name == p2)
            {
              loc2 = new_where[i].location;
              tc2 = true;
              break;
            }
          if(tc2 == false)
            loc2 =  std::to_string(freemem);
          var tmp;
          tmp.name = p2;
          tmp.type = "int";
          tmp.location = loc2;
          tmp.index = -1;
          tmp.is_a_global = false;
          if(tc2 == false)
          {
            new_where.push_back(tmp);
            freemem += 4;
          }
          //where[p1] = loc1;
          res += memstore("5", loc2);
          if(p3 != "")
          {
            bool tc3 = false;
            std::string loc3;
            for(int i = 0; i < new_where.size(); ++i)
              if(new_where[i].name == p3)
              {
                loc3 = new_where[i].location;
                tc3 = true;
                break;
              }
            if(tc3 == false)
              loc3 =  std::to_string(freemem);
            var tmp;
            tmp.name = p3;
            tmp.type = "int";
            tmp.location = loc3;
            tmp.index = -1;
            tmp.is_a_global = false;
            if(tc3 == false)
            {
              new_where.push_back(tmp);
              freemem += 4;
            }
            //where[p1] = loc1;
            res += memstore("6", loc3);
            if(p4 != "")
            {
              bool tc4 = false;
              std::string loc4;
              for(int i = 0; i < new_where.size(); ++i)
                if(new_where[i].name == p4)
                {
                  loc4 = new_where[i].location;
                  tc4 = true;
                  break;
                }
              if(tc4 == false)
                loc4 =  std::to_string(freemem);
              var tmp;
              tmp.name = p4;
              tmp.type = "int";
              tmp.location = loc4;
              tmp.index = -1;
              tmp.is_a_global = false;
              if(tc4 == false)
              {
                new_where.push_back(tmp);
                freemem += 4;
              }
              //where[p1] = loc1;
              res += memstore("7", loc4);
            }
          }
        }
      }

      res += Seq->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);// we compile the body of the function

      //now we need to compile Return
      return res;
    }

};


#endif
