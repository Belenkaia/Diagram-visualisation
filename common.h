#pragma once

#include "icmemory.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdarg.h>

const int ERR_MSG_BUFFER_SIZE = 1024;
class ASTNode;

enum AST_NODE_TYPE
{
	ASTNODE_PROGRAM,
	ASTNODE_TACT,
	ASTNODE_ICONST,
	ASTNODE_IDENTIFIER,
	ASTNODE_CONST_SPEC,
	ASTNODE_CONST_EXP_BODY,
	ASTNODE_CONST_INFIX,
	ASTNODE_CONST_PREFIX,
	ASTNODE_CONST_PREF_TERM,
	ASTNODE_CONST_TERM,
	NUM_AST_NODE_TYPES,
};


typedef std::list<ASTNode*> ASTNodeList;

class ASTNode
{
public:
	AST_NODE_TYPE type;
	std::string *val;
	ASTNodeList children;

	ASTNode(AST_NODE_TYPE type):type(type), val(NULL){}
	~ASTNode()
	{
		delete val;
		for(ASTNodeList::iterator i=children.begin();i!=children.end();i++)
			delete *i;
	}
};

