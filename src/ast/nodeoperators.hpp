#ifndef nodeoperators_hpp
#define nodeoperators_hpp
#include <set>
#include <vector>
class Operator : public TreeNode
{
  protected:
    TreeNodePtr left;
    TreeNodePtr right;

  public:
    Operator(TreeNodePtr l, TreeNodePtr r)
    {
      left = l;
      right = r;
    }


    virtual ~Operator()
    {
      delete left;
      delete right;
    }
};

class AddOperator : public Operator
{
  public:
    AddOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
        std::string left_result = left->translate(0,global_variables);
        std::string right_result = right->translate(0,global_variables);
        return add_tabs(no_of_tabs)+"("+left_result + " + " + right_result+")";
      }
      virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      std::string left_type = most_recent_type;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "addu $2, $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "add $2, $2, $9\n";
      }

      return res;
    }

};

class SubOperator : public Operator
{
  public:
    SubOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
        std::string left_result = left->translate(0,global_variables);
        std::string right_result = right->translate(0,global_variables);
        return add_tabs(no_of_tabs)+"("+left_result + " - " + right_result+")";
      }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      std::string left_type = most_recent_type;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      std::string right_type = most_recent_type;
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "subu $2, $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "sub $2, $2, $9\n";
      }
      return res;
    }

};

class MultOperator : public Operator
{
  public:
    MultOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
        std::string left_result = left->translate(0,global_variables);
        std::string right_result = right->translate(0,global_variables);
        return add_tabs(no_of_tabs)+"("+left_result + " * " + right_result+")";
      }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      std::string left_type = most_recent_type;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      std::string right_type = most_recent_type;

      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "multu $2, $9\n";
        most_recent_type = "unsigned";

      }
      else{
        res += "mult $2, $9\n";
      }
      res += "mflo $2\n";
      return res;
    }
};

class DivOperator : public Operator
{
  public:
    DivOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
        std::string left_result = left->translate(0,global_variables);
        std::string right_result = right->translate(0,global_variables);
        return add_tabs(no_of_tabs)+"("+left_result + " / " + right_result+")";
      }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string left_type = most_recent_type;
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "divu $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "div $2, $9\n";
      }
      res += "mflo $2\n";
      return res;
    }
};

class BorOperator : public Operator
{
  public:
    BorOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " | " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "or $2, $2, $9\n";
      return res;
    }

};

class BandOperator : public Operator
{
  public:
    BandOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " & " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "and $2, $2, $9\n";
      return res;
    }

};

class XorOperator : public Operator
{
  public:
    XorOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " ^ " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "xor $2, $2, $9\n";
      return res;
    }

};

class ModOperator : public Operator
{
  public:
    ModOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " % " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      std::string left_type = most_recent_type;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      std::string right_type = most_recent_type;
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "divu $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "div $2, $9\n";
      }
      res += "mfhi $2\n";
      return res;
    }
};


class LessOperator : public Operator
{
  public:
    LessOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
              std::string left_result = left->translate(0,global_variables);
              std::string right_result = right->translate(0,global_variables);
              return add_tabs(no_of_tabs)+"("+left_result + " < " + right_result+")";
            }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string left_type = most_recent_type;
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "sltu $2, $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "slt $2, $2, $9\n";
      }

      return res;
    }
};

class GreatOperator : public Operator
{
  public:
    GreatOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " > " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string left_type = most_recent_type;

      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;

      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "sltu $2, $9, $2\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "slt $2, $9, $2\n";
      }
      //res += "slt $2, $9, $2\n";
      return res;
    }
};

class EqualOperator : public Operator
{
  public:
    EqualOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " == " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "add $10, $0, $0\n";
      res += "beq $2, $9, EQ_" + std::to_string(unique) + "\nadd $0, $0, $0\n";
      res += "addi $10, $10, -1\n";
      res += "EQ_" + std::to_string(unique) + ":\n";
      res += "addi $10, $10, 1\n";
      res += movreg("2", "10");
      ++unique;
      return res;
    }
};

class NequalOperator : public Operator
{
  public:
    NequalOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " != " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "add $10, $0, $0\n";
      res += "beq $2, $9, EQ_" + std::to_string(unique) + "\nadd $0, $0, $0\n";
      res += "addi $10, $10, 1\n";
      res += "EQ_" + std::to_string(unique) + ":\n";
      res += movreg("2", "10");
      ++unique;
      return res;
    }
};

class LequalOperator : public Operator
{
  public:
    LequalOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " <= " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string left_type = most_recent_type;
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "add $10, $0, $0\n";
      res += "beq $2, $9, EQ_" + std::to_string(unique) + "\nadd $0, $0, $0\n";
      res += "addi $10, $10, -1\n";
      res += "EQ_" + std::to_string(unique) + ":\n";
      res += "addi $10, $10, 1\n";
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "sltu $2, $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "slt $2, $2, $9\n";
      }
      //res += "slt $2, $2, $9\n";
      res += "or $2, $2, $10\n";
      ++unique;
      return res;
    }
};

class GequalOperator : public Operator
{
  public:
    GequalOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
      virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
          std::string left_result = left->translate(0,global_variables);
          std::string right_result = right->translate(0,global_variables);
          return add_tabs(no_of_tabs)+"("+left_result + " >= " + right_result+")";
        }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string left_type = most_recent_type;
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "add $10, $0, $0\n";
      res += "beq $2, $9, EQ_" + std::to_string(unique) + "\nadd $0, $0, $0\n";
      res += "addi $10, $10, -1\n";
      res += "EQ_" + std::to_string(unique) + ":\n";
      res += "addi $10, $10, 1\n";
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "sltu $2, $9, $2\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "slt $2, $9, $2\n";
      }
      //res += "slt $2, $9, $2\n";
      res += "or $2, $2, $10\n";
      ++unique;
      return res;
    }
};

class LorOperator : public Operator
{
  public:
    LorOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
        std::string left_result = left->translate(0,global_variables);
        std::string right_result = right->translate(0,global_variables);
        return add_tabs(no_of_tabs)+"("+left_result + " or " + right_result+")";
      }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "or $2, $2, $9\n";
      res += "sltu $2, $0, $2\n";//as long as it's not 0
      return res;
    }

};

class LandOperator : public Operator
{
  public:
    LandOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}
    virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
        std::string left_result = left->translate(0,global_variables);
        std::string right_result = right->translate(0,global_variables);
        return add_tabs(no_of_tabs)+"("+left_result + " and " + right_result+")";
      }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += "sltu $2, $0, $2\n";
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += "sltu $2, $0, $2\n";
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "and $2, $2, $9\n";
      return res;
    }

};

class ALSOperator : public Operator
{
  public:
    ALSOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "sllv $2, $2, $9\n";
      return res;
    }

};

class ARSOperator : public Operator
{
  public:
    ARSOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
    {}

    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string left_type = most_recent_type;
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      std::string right_type = most_recent_type;
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      if (left_type == "unsigned" || right_type == "unsigned"){
        res += "srlv $2, $2, $9\n";
        most_recent_type = "unsigned";
      }
      else{
        res += "srav $2, $2, $9\n";
      }
      res += "srav $2, $2, $9\n";
      return res;
    }

};
/*
class ShiftLeftOperator : public Operator
{
public:
  ShiftLeftOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
  {}
  virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string left_result = left->translate(0,global_variables);
      std::string right_result = right->translate(0,global_variables);
      return add_tabs(no_of_tabs)+"("+left_result + " << " + right_result+")";
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "sllv $2, $2, $9\n";
      return res;
    }
};
class ShiftRightOperator : public Operator
{
public:
  ShiftRightOperator(TreeNodePtr l, TreeNodePtr r) : Operator(l, r)
  {}
  virtual std::string translate(int no_of_tabs, std::set<std::string>& global_variables) override{
      std::string left_result = left->translate(0,global_variables);
      std::string right_result = right->translate(0,global_variables);
      return add_tabs(no_of_tabs)+"("+left_result + " >> " + right_result+")";
    }
    virtual std::string compile(std::map < std::string, std::string > &where, int &freemem, int &unique, int loopid, TreeNodePtr ending, std::string &jumps, std::vector<var> &new_where, std::string &most_recent_type) override
    {
      std::string res;
      res = left->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      int tmploc = freemem;
      res += memstore("2", std::to_string(freemem));
      freemem += 4;
      res += right->compile(where, freemem, unique, loopid, ending, jumps, new_where, most_recent_type);
      res += movreg("9", "2");
      res += memload(std::to_string(tmploc));
      res += "srlv $2, $2, $9\n";
      return res;
    }
};*/
#endif
