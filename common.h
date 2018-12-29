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
	ASTNODE_PROC_DEF,
	ASTNODE_PROCID,
	ASTNODE_STATE_DEF,
	ASTNODE_STATE_ID,
	ASTNODE_STATEMENTS_LIST,
	ASTNODE_TIMEOUT,
	ASTNODE_EMPTY_STATEMENT,
	ASTNODE_COMPOUND_STATEMENT,
	ASTNODE_START_STATEMENT,
	ASTNODE_STOP_STATEMENT,
	ASTNODE_ERROR_STATEMENT,
	ASTNODE_ASSIGNMENT_EXPRESSION,
	ASTNODE_BINARY_EXPRESSION,
	ASTNODE_UNARY_EXPRESSION,
	ASTNODE_FUNCTION_CALL,
	ASTNODE_POSTFIX_OP,
	ASTNODE_POSTFIX_EXPRESSION ,
	ASTNODE_BINARY_OP,
	ASTNODE_UNARY_OP,
	ASTNODE_ASSIGNMENT_OP,
	ASTNODE_ARG_EXPR_LIST,
	ASTNODE_PRIMARY_EXPRESSION,
	NUM_AST_NODE_TYPES,
};

const char* const AST_NODE_NAMES[NUM_AST_NODE_TYPES] = 
{
	"program",
	"tact",
	"int_constant",
	"identifier",
	"const_spec",
	"const_spec_body",
	"const_infix",
	"const_prefix",
	"const_pref_term",
	"const_term",
	"proc_def",
	"proc_id",
	"state_def",
	"state_id",
	"statements_list",
	"timeout",
	"empty_statement",
	"compound_statement",
	"start_statement",
	"stop_statement",
	"error_statement",
	"assignment_expression",
	"binary_expression",
	"unary_expression",
	"function_call",
	"postfix_operator",
	"postfix_expression",
	"binary_operator",
	"unary_operator",
	"assignment_operator",
	"arg_expr_list",
	"primary_expression",
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

