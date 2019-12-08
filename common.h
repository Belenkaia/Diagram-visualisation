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

extern unsigned long line_num;

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
	//ASTNODE_EMPTY_STATEMENT,
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
	ASTNODE_EXPRESSION_STATEMENT,
	ASTNODE_CAST_EXPRESSION,
	ASTNODE_TYPE_SPEC,
	ASTNODE_IF_STATEMENT,
	ASTNODE_SWITCH_STATEMENT,
	ASTNODE_CASE_STATEMENT,
	//ASTNODE_DEFAULT_STATEMENT,
	ASTNODE_LOOP_STATEMENT,
	ASTNODE_STATE_TRANSITION,
	ASTNODE_NEXT_STATEMENT,
	ASTNODE_RESTART_STATEMENT,
	ASTNODE_RESET_STATEMENT,
	ASTNODE_STOP_CHECK,
	ASTNODE_ERROR_CHECK,
	ASTNODE_ACTIVE_CHECK,
	ASTNODE_INACTIVE_CHECK,
	ASTNODE_PROC_ID_LIST,
	ASTNODE_SCOPE_SPEC,
	ASTNODE_CALC_VAR_DEF,
	ASTNODE_PHYS_VAR_DEF,
	ASTNODE_REG_BITS_SPEC,
	ASTNODE_REG_BITS_SPEC_LIST,
	ASTNODE_VAR_DEF,
	ASTNODE_VAR_LIST,
	ASTNODE_VAR_DECL,
	ASTNODE_VAR_ID_LIST,
	ASTNODE_REGISTER_DEF,
	ASTNODE_DIR_SPEC,
	ASTNODE_REG_ADDR,
	ASTNODE_REG_SIZE,
	ASTNODE_FUNC_DECL,
	ASTNODE_TYPE_SPEC_LIST,
	ASTNODE_ENUM_DEF,
	ASTNODE_ENUM_LIST,
	ASTNODE_ENUM,

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
	"timeout_statement",
	//"empty_statement",
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
	"expression_statement",
	"cast_expression",
	"type_spec",
	"if_statement",
	"switch_statement",
	"case_statement",
	//"default_statement",
	"loop_statement",
	"state_transition",
	"next_statement",
	"restart_statement",
	"reset_statement",
	"stop_check",
	"error_check",
	"active_check",
	"inactive_check",
	"proc_id_list",
	"scope_spec",
	"calc_var_def",
	"phys_var_def",
	"reg_bits_spec",
	"reg_bits_spec_list",
	"var_def",
	"var_list",
	"var_decl",
	"var_id_list",
	"register_def",
	"direction_spec",
	"reg_addr",
	"reg_size",
	"func_decl",
	"type_spec_list",
	"enum_def",
	"enum_list",
	"enum",
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

