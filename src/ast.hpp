#ifndef ast_hpp
#define ast_hpp

#include "ast/treenode.hpp"
#include "ast/nodeassign.hpp"
#include "ast/nodebody.hpp"
#include "ast/nodefunction.hpp"
#include "ast/nodeoperators.hpp"
#include "ast/nodeprimitive.hpp"
#include "ast/nodereturn.hpp"
#include "ast/nodeunary.hpp"
#include "ast/nodewhile.hpp"
#include "ast/nodeif.hpp"
#include "ast/nodearray.hpp"
#include "ast/nodenothing.hpp"
#include "ast/nodefor.hpp"
#include "ast/nodebreak.hpp"
#include "ast/nodecontinue.hpp"
#include "ast/nodeswitch.hpp"
#include "ast/nodeswitchbody.hpp"
#include "ast/nodeglobarray.hpp"
#include "ast/nodepointer.hpp"
#include "ast/nodepass.hpp"
#include "ast/nodederef.hpp"
#include "ast/nodeparamset.hpp"
#include "ast/nodeexprset.hpp"
#include "ast/nodeargument.hpp"
#include "ast/nodeidk.hpp"


extern TreeNode* parseAST(char* input_file);

#endif
