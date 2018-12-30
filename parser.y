%{
	#include <stdio.h>
	#include <stdarg.h> 
	#include <set>
	#include <string>
	#include <list>

	#include "common.h"

    extern int yylex();
	int yyerror(const char *s);

	extern ASTNode* program;
%}

/***********************************************/
/*                DATA TYPES                   */
/***********************************************/
%union 
{
    std::string* string;
	int token;
	ASTNode* ast_node;
	ASTNodeList* node_list;
}

/***********************************************/
/*                   TOKENS                    */
/***********************************************/
%token <token> TPROGR			"PROGR"
%token <token> TTACT			"TACT"	
%token <token> TCONST			"CONST"
%token <token> TENUM			"ENUM"	
%token <string> TINPUT			"INPUT"
%token <string> TOUTPUT			"OUTPUT"
%token <token> TPROC			"PROC"	
%token <string> TLOCAL			"LOCAL"
%token <string> TFOR			"FOR"	
%token <string> TALL			"ALL"	
%token <token> TFROM			"FROM"	
%token <token> TSTATE			"STATE"
%token <token> TSWITCH			"SWITCH"
%token <token> TCASE			"CASE"	
%token <token> TBREAK			"BREAK"
%token <token> TIF				"IF	"
%token <token> TELSE			"ELSE"	
%token <token> TSTART			"START"
%token <token> TSTOP			"STOP"	
%token <token> TERROR			"ERROR"
%token <token> TRESTART			"RESTART"
%token <token> TLOOP			"LOOP"		
%token <token> TSET				"SET"		
%token <token> TNEXT			"NEXT"		
%token <token> TRESET			"RESET"	
%token <token> TTIMEOUT			"TIMEOUT"	
%token <token> TIN				"IN"		
%token <token> TIS				"IS"		
%token <token> TACTIVE			"ACTIVE"	
%token <token> TINACTIVE		"INACTIVE"	

%token <string> TBOOL			"BOOL"		
%token <string> TVOID			"VOID"		
%token <string> TFLOAT			"FLOAT"	
%token <string> TDOUBLE			"DOUBLE"	
%token <string> TSIGNED			"SIGNED"
%token <string> TUNSIGNED		"UNSIGNED"	
%token <string> TSHORT			"SHORT"	
%token <string> TLONG			"LONG"		
%token <string> TINT				"INT"		

%token <string> TIDENTIFIER		"identifier"
%token <string> TFCONST			"floating-point constant"
%token <string> TICONST			"integer constant"

%token <token> TLPAREN			"left parentheses"
%token <token> TRPAREN			"right parentheses"
%token <token> TLBRACKET		"left bracket"
%token <token> TRBRACKET		"right bracket"
%token <token> TSEMIC			"semicolon"
%token <token> TLBRACE			"left brace"
%token <token> TRBRACE			"right brace"
%token <token> TCOLON			"colon"

%token <string> TASSGN			"="
%token <string> TCOMMA			"comma"
%token <string> TPERIOD			"."
%token <string> TAND			"&"
%token <string> TNOT			"!"
%token <string> TTILDE			"~"
%token <string> TMINUS			"-"
%token <string> TPLUS			"+"
%token <string> TMUL			"*"
%token <string> TDIV			"/"
%token <string> TPERC			"%"
%token <string> TLT				"<"
%token <string> TGT				">"
%token <string> TXOR			"^"
%token <string> TOR				"|"
%token <string> TQMARK			"?"
%token <string> TEQ				"=="
%token <string> TNEQ			"!="
%token <string> TLE				"<="
%token <string> TGE				">="
%token <string> TINC			"++"
%token <string> TDEC			"--"
%token <string> TRSHIFT			">>"
%token <string> TLSHIFT			"<<"
%token <string> TLOR			"||"
%token <string> TLAND			"&&"
%token <string> TR_ASSGN		">>="
%token <string> TL_ASSGN		"<<="
%token <string> TPLUS_ASSGN		"+="
%token <string> TMINUS_ASSGN	"-="
%token <string> TSTAR_ASSGN		"*="
%token <string> TDIV_ASSGN		"/="
%token <string> TPERC_ASSGN		"%="
%token <string> TAND_ASSGN		"&="
%token <string> TXOR_ASSGN		"^="
%token <string> TOR_ASSGN		"|="

/***********************************************/
/*                   NODES                     */
/***********************************************/
%type <node_list>			program_body
%type <ast_node>			tact	
%type <node_list>			const_enum_list
%type <node_list>			func_decl_list
%type <node_list>			register_def_list	
%type <node_list>			proc_def_list

%type <ast_node>			const_or_enum_spec	
%type <ast_node>			const_spec			
%type <ast_node>			const_id			
%type <ast_node>			const_exp_body		
%type <node_list>			infix_term_list		
%type <ast_node>			const_pref_term		
%type <string>				const_prefix		
%type <string>				const_infix			
%type <ast_node>			const_term				

%type <ast_node>			proc_def
%type <ast_node>			proc_id

%type <node_list>			state_def_list
%type <ast_node>			state_def

%type <ast_node>			state_id 
%type <ast_node>			timeout_arg 
%type <ast_node>			timeout_statement 
%type <ast_node>			statement
%type <ast_node>			statements_list
%type <ast_node>			compound_statement

%type <ast_node>			start_statement
%type <ast_node>			stop_statement
%type <ast_node>			error_statement

%type <ast_node>			expr
%type <ast_node>			assignment_expr
%type <ast_node>			binary_expr
%type <string>				binary_op
%type <ast_node>			unary_expr
%type <string>				unary_op
%type <ast_node>			postfix_expr
%type <ast_node>			arg_expr_list
%type <ast_node>			primary_expr
%type <string>				assignement_op
%type <ast_node>			cast_expr
%type <string>				c_type_spec
%type <ast_node>			expression_statement
%type <string>				postfix_op
%type <ast_node>			if_statement
%type <ast_node>			switch_statement
%type <ast_node>			labeled_statement
%type <ast_node>			loop_statement
%type <ast_node>			state_transition
%type <ast_node>			restart_statement
%type <ast_node>			reset_statement
%type <string>				singness_spec
%type <string>				size_spec
//%type <string>				int_type_spec

%type <ast_node>			var_def
%type <ast_node>			phys_var_def
%type <ast_node>			var_id
%type <ast_node>			reg_id
%type <ast_node>			reg_bits_spec_list
%type <ast_node>			reg_bits_spec
%type <ast_node>			calc_var_def
%type <ast_node>			scope_spec
%type <ast_node>			proc_id_list
%type <ast_node>			var_list
%type <ast_node>			var_decl
%type <ast_node>			var_id_list

%type <ast_node>			register_def
%type <ast_node>			reg_addr
%type <ast_node>			register_size
%type <ast_node>			c_type_spec_list
%type <ast_node>			func_decl
%type <ast_node>			func_id

%type <ast_node>			enum_def	
%type <ast_node>			enum_list	
%type <ast_node>			enumerator	

/***********************************************/
/*                  DESTRUCTORS                */
/***********************************************/
//these are to tell Bison how to properly clean up any non-terminals that
//had been left astray after an error

%destructor {} <token>
%destructor 
{
	if(NULL != $$)
	{
		while(!$$->empty())
		{
			delete $$->back();
			$$->back() = NULL;
			$$->pop_back();
		}
		delete $$;
		$$ = NULL;
	}
}<node_list>
%destructor 
{
	if(NULL != $$)
	{
		for(ASTNodeList::iterator i=$$->children.begin();i!=$$->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete $$;
		$$ = NULL;
	}
}<ast_node> 

/***********************************************/
/*              MISC DEFINITIONS               */
/***********************************************/
%start program /*Start symbol*/
%error-verbose /*Extended error reporting*/

%nonassoc XIF
%nonassoc TELSE

%left TINC TDEC UMINUS TTILDE TNOT

//operator precedences
//%left TLOR TLAND TOR TXOR TAND TEQ TNEQ TLT TGT TLE TGE TLSHIFT TRSHIFT TPLUS TMINUS TMUL TDIV TPERC

%%
//////////////////////////////////////////////////////////////////////////////////////////////////

//Why is tact optional?
//				      1         2         3      4          5        6           7
program			:	TPROGR TIDENTIFIER TLBRACE tact program_body proc_def_list TRBRACE 
					{
						ASTNode* program_name = new ASTNode(ASTNODE_IDENTIFIER);
						program_name->val = $2;

						program = new ASTNode(ASTNODE_PROGRAM);
						program->children.push_back(program_name);
						if(NULL != $4) program->children.push_back($4);//tact

						//For lists - merge them with program's children
						//(no such nodes in AST as lists of items)
						if(NULL != $5) program->children.splice(program->children.end(), *$5); //program_body
						if(NULL != $6) program->children.splice(program->children.end(), *$6); //proc_def_list

						delete $5;
						delete $6;
						$1;$3;$7;
					}
				;

//Auxiliary node to resolve grammar conflicts caused by multiple consequent optional nodes in program
program_body	:	%empty {$$=NULL;}
				|	const_enum_list func_decl_list register_def_list
					{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);$$->splice($$->end(),*$3);delete $1;delete $2;delete $3;}
				|	const_enum_list func_decl_list		{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);delete $1;delete $2;}
				|	const_enum_list register_def_list	{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);delete $1;delete $2;}
				|	func_decl_list register_def_list	{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);delete $1;delete $2;}
				|	const_enum_list						{$$=new ASTNodeList;$$->splice($$->end(),*$1);delete $1;}
				|	func_decl_list						{$$=new ASTNodeList;$$->splice($$->end(),*$1);delete $1;}
				|	register_def_list					{$$=new ASTNodeList;$$->splice($$->end(),*$1);delete $1;}
				;

tact			:	/*%empty {$$ = NULL;} // [tact] is optional
				|*/	TTACT TICONST TSEMIC
					{
						ASTNode* tact_const = new ASTNode(ASTNODE_ICONST);
						tact_const->val = $2;

						$$ = new ASTNode(ASTNODE_TACT);
						$$->children.push_back(tact_const);
						$1;$3;
					}
				;

//Auxiliary node for option and iteration, was "[{const_or_enum_spec}]" in original EBNF
const_enum_list	:	const_enum_list const_or_enum_spec {$1-> push_back($2); $$ = $1;}
				|	const_or_enum_spec
					{
						$$ = new ASTNodeList;
						$$->push_back($1);
					}
				;

//Might want to exclude this node from grammar
const_or_enum_spec	:	const_spec {$$ = $1;}
					|	enum_def {$$ = $1;}
					; 

const_spec			:	TCONST const_id const_exp_body TSEMIC
						{
							$$ = new ASTNode(ASTNODE_CONST_SPEC);
							$$->children.push_back($2); //const_id
							$$->children.push_back($3); //const_exp_body
							$1;$4;
						}
					;

const_id			:	TIDENTIFIER
						{
							$$ = new ASTNode(ASTNODE_IDENTIFIER);
							$$->val = $1;
						}
					;

const_exp_body		:	const_pref_term 
						{
							$$ = new ASTNode(ASTNODE_CONST_EXP_BODY);
							$$->children.push_back($1);
						}
					|	const_pref_term infix_term_list
						{
							$$ = new ASTNode(ASTNODE_CONST_EXP_BODY);
							$$->children.push_back($1);
							$$->children.splice($$->children.end(), *$2);//merge lists
							delete $2;
						}
					;

//Auxiliary node to resolve iteration
infix_term_list		:	infix_term_list const_infix const_pref_term
						{
							ASTNode* const_infix = new ASTNode(ASTNODE_CONST_INFIX);
							const_infix->val = $2;

							$1->push_back(const_infix);
							$1->push_back($3);
							$$ = $1;
						}
					|	const_infix const_pref_term
						{
							ASTNode* const_infix = new ASTNode(ASTNODE_CONST_INFIX);
							const_infix->val = $1;

							$$ = new ASTNodeList;
							$$->push_back(const_infix);
							$$->push_back($2);
						}
					;

const_pref_term		:	const_prefix const_term
						{
							ASTNode* const_prefix = new ASTNode(ASTNODE_CONST_PREFIX);
							const_prefix->val = $1;

							$$ = new ASTNode(ASTNODE_CONST_PREF_TERM);
							$$->children.push_back(const_prefix);
							$$->children.push_back($2);
						}
					|	const_term
						{
							$$ = new ASTNode(ASTNODE_CONST_PREF_TERM);
							$$->children.push_back($1);
						}
					;

//operator strings are transfered here with default action $$=$1;
const_prefix		:	TTILDE | TNOT | TPLUS | TMINUS;
const_infix			:	TPLUS | TMINUS | TMUL | TDIV | TPERC | TLSHIFT | TRSHIFT | TAND | TXOR | TOR | TLAND | TLOR;

const_term			:	TICONST {$$=new ASTNode(ASTNODE_CONST_TERM);$$->val=$1;}
					|	TFCONST {$$=new ASTNode(ASTNODE_CONST_TERM);$$->val=$1;}
					|	const_id {$$=$1;}
					//|	TLPAREN const_exp_body TRPAREN  
					;

enum_def			:	TENUM TLBRACE enum_list TRBRACE
						{
							$$ = new ASTNode(ASTNODE_ENUM_DEF);
							$$->children.push_back($3);
							$1;$2;$4;
						}
					;

enum_list			:	enum_list TCOMMA enumerator
						{
							$$ = $1;
							$1->children.push_back($3);
							delete $2;
						}
					|	enumerator
						{
							$$ = new ASTNode(ASTNODE_ENUM_LIST);
							$$->children.push_back($1);
						}
					;

enumerator			:	const_id 
						{
							$$ = new ASTNode(ASTNODE_ENUM);
							$$->children.push_back($1);
						}
					|	const_id TASSGN const_exp_body
						{
							$$ = new ASTNode(ASTNODE_ENUM);
							$$->children.push_back($1);
							$$->children.push_back($3);
							delete $2;
						}
					;



//Auxiliary node for iteration, not present in original grammar
func_decl_list	:	func_decl_list func_decl 
					{
						$$ = $1;
						$1->push_back($2);
					}
				|	func_decl
					{
						$$ = new ASTNodeList;
						$$->push_back($1);
					}
				;

//Auxiliary node for iteration, not present in original grammar
register_def_list	:	register_def_list register_def
						{
							$$ = $1;
							$1->push_back($2);
						}
					|	register_def
						{
							$$ = new ASTNodeList;
							$$->push_back($1);
						}
					;

//Auxiliary node for iteration, not present in original grammar
proc_def_list	:	proc_def
					{
						$$ = new ASTNodeList;
						$$->push_back($1);
					}
				|	proc_def_list proc_def
					{
						$1->push_back($2);
						$$ = $1;
					}
				;

//						  1      2      3       4            5          6
proc_def			:	TPROC proc_id TLBRACE var_list state_def_list TRBRACE
						{
							$$ = new ASTNode(ASTNODE_PROC_DEF);
							$$->children.push_back($2); //proc_id
							$$->children.push_back($4); //var_list
							$$->children.splice($$->children.end(), *$5);//add state defs as children
							delete $5; //state_def_list
							$1;$3;$6;
						}
//						  1      2      3           4          5
					|	TPROC proc_id TLBRACE state_def_list TRBRACE
						{
							$$ = new ASTNode(ASTNODE_PROC_DEF);
							$$->children.push_back($2); //proc_id
							$$->children.splice($$->children.end(), *$4);//add state defs as children
							delete $4; //state_def_list
							$1;$3;$5;
						}
					;

proc_id				:	TIDENTIFIER 
						{
							ASTNode* proc_id = new ASTNode(ASTNODE_IDENTIFIER);
							proc_id->val = $1;

							$$ = new ASTNode(ASTNODE_PROCID);
							$$->children.push_back(proc_id);
						}
					;


var_list			:	var_list var_def 
						{
							$$ = $1;
							$1->children.push_back($2);
						}
					|	var_list var_decl
						{
							$$ = $1;
							$1->children.push_back($2);
						}
					|	var_def 
						{
							$$ = new ASTNode(ASTNODE_VAR_LIST);
							$$->children.push_back($1);
						}
					|	var_decl
						{
							$$ = new ASTNode(ASTNODE_VAR_LIST);
							$$->children.push_back($1);
						}
					;


//Auxiliary list
state_def_list		:	state_def
						{
							$$ = new ASTNodeList;
							$$->push_back($1);
						}
					|	state_def_list state_def
						{
							$1->push_back($2);
							$$ = $1;
						}
					;

//						   1       2       3         4            5             6
state_def			:	TSTATE state_id TLBRACE statements_list timeout_statement TRBRACE
						{
							$$ = new ASTNode(ASTNODE_STATE_DEF);
							$$->children.push_back($2); //state_id
							$$->children.push_back($4); //statements_list
							$$->children.push_back($5); //timeout_statement
							$1;$3;$6;
						}
					|	TSTATE state_id TLBRACE statements_list TRBRACE
						{
							$$ = new ASTNode(ASTNODE_STATE_DEF);
							$$->children.push_back($2); //state_id
							$$->children.push_back($4); //statements_list
							$1;$3;$5;
						}
					;

state_id			:	TIDENTIFIER
						{
							$$ = new ASTNode(ASTNODE_STATE_ID);
							$$->val = $1;
						}
					;

statements_list		:	statements_list statement
						{
							$$ = $1;
							$1->children.push_back($2);
						}
					|	statement
						{
							$$ = new ASTNode(ASTNODE_STATEMENTS_LIST);
							$$->children.push_back($1);
						}
					;

//=============================================================================
//                           STATEMENTS 
//=============================================================================
timeout_statement	:	TTIMEOUT timeout_arg statement
						{
							$$ = new ASTNode(ASTNODE_TIMEOUT);
							$$->children.push_back($2);
							$$->children.push_back($3);
							$1;
						}
					;

timeout_arg			:	TICONST
						{
							$$ = new ASTNode(ASTNODE_ICONST);
							$$->val = $1;
						}
						|	const_id {$$ = $1;}
					//	|	var_id
					;

statement			:	compound_statement
					|	start_statement 
					|	stop_statement 
					|	error_statement 
					|	if_statement
					|	switch_statement
					|	labeled_statement
					|	loop_statement
					|	state_transition
					|	restart_statement
					|	reset_statement
					|	expression_statement
					;

restart_statement	:	TRESTART TSEMIC
						{
							$$ = new ASTNode(ASTNODE_RESTART_STATEMENT);
							$1;$2;
						}
					;

reset_statement		:	TRESET TTIMEOUT TSEMIC
						{
							$$ = new ASTNode(ASTNODE_RESET_STATEMENT);
							$1;$2;$3;
						}
					;

state_transition	:	TSET TSTATE state_id TSEMIC
						{
							$$ = new ASTNode(ASTNODE_STATE_TRANSITION);
							$$->children.push_back($3);
							$1;$2;$4;
						}
					|	TSET TNEXT TSEMIC
						{
							$$ = new ASTNode(ASTNODE_NEXT_STATEMENT);
							$1;$2;$3;
						}
					;

expression_statement:	expr TSEMIC
						{
							$$ = new ASTNode(ASTNODE_EXPRESSION_STATEMENT);
							$$->children.push_back($1);
							$2;
						}
					|	TSEMIC {$$ = new ASTNode(ASTNODE_EXPRESSION_STATEMENT);$1;}
					;

//						 1     2     3      4        5      6       7
if_statement		:	TIF TLPAREN expr TRPAREN statement TELSE statement
						{
							$$ = new ASTNode(ASTNODE_IF_STATEMENT);
							$$->children.push_back($3);
							$$->children.push_back($5);
							$$->children.push_back($7);
							$1;$2;$4;$6;
						}
					|	TIF TLPAREN expr TRPAREN statement %prec XIF
						{
							$$ = new ASTNode(ASTNODE_IF_STATEMENT);
							$$->children.push_back($3);
							$$->children.push_back($5);
							$1;$2;$4;
						}
					;

switch_statement	:	TSWITCH TLPAREN expr TRPAREN statement
						{
							$$ = new ASTNode(ASTNODE_SWITCH_STATEMENT);
							$$->children.push_back($3);
							$$->children.push_back($5);
							$1;$2;$4;
						}
					;

labeled_statement	:	TCASE expr TCOLON statement
						{
							$$ = new ASTNode(ASTNODE_CASE_STATEMENT);
							$$->children.push_back($2);
							$$->children.push_back($4);
							$1;$3;
						}
					/*|	TDEFAULT TCOLON statement
						{
							$$ = new ASTNode(ASTNODE_DEFAULT_STATEMENT);
							$$->children.push_back($3);
							$1;$2;
						}*/
					;
loop_statement		:	TLOOP TSEMIC
						{
							$$ = new ASTNode(ASTNODE_LOOP_STATEMENT);
							$1;$2;
						}
					;

compound_statement	:	TLBRACE statements_list TRBRACE
						{
							$$ = new ASTNode(ASTNODE_COMPOUND_STATEMENT);

							///version 1: with statements_list node
							$$->children.push_back($2);

							///version 2: without statements_list in AST
							//$$->children.splice($$->children.end(), *$2);
							//delete $2;
							//

							$1;$3;
						}
					|	TLBRACE TRBRACE // this one is not in Reflex
						{
							$$ = new ASTNode(ASTNODE_COMPOUND_STATEMENT);
							$1;$2;
						}
					;

start_statement		:	TSTART proc_id TSEMIC
						{
							$$ = new ASTNode(ASTNODE_START_STATEMENT);
							$$->children.push_back($2);
							$1;$3;
						}
					;

stop_statement		:	TSTOP proc_id TSEMIC
						{
							$$ = new ASTNode(ASTNODE_STOP_STATEMENT);
							$$->children.push_back($2);
							$1;$3;
						}
					|	TSTOP TSEMIC
						{
							$$ = new ASTNode(ASTNODE_STOP_STATEMENT);
							$1;$2;
						}
					;

error_statement		:	TERROR proc_id TSEMIC
						{
							$$ = new ASTNode(ASTNODE_ERROR_STATEMENT);
							$$->children.push_back($2);
							$1;$3;
						}
					|	TERROR TSEMIC
						{
							$$ = new ASTNode(ASTNODE_ERROR_STATEMENT);
							$1;$2;
						}
					;

//=============================================================================
//                            EXPRESSIONS 
//=============================================================================
expr 		: assignment_expr 
	 		;
	 
assignment_expr	:	binary_expr
				|	unary_expr assignement_op assignment_expr 
					{
						ASTNode* assignment_op = new ASTNode(ASTNODE_ASSIGNMENT_OP);
						assignment_op->val = $2;

						$$ = new ASTNode(ASTNODE_ASSIGNMENT_EXPRESSION);
						$$->children.push_back($1);
						$$->children.push_back(assignment_op);
						$$->children.push_back($3);
					}
				;
				
binary_expr	:	cast_expr 
			|	binary_expr binary_op cast_expr
				{
					ASTNode* binary_op = new ASTNode(ASTNODE_BINARY_OP);
					binary_op->val = $2;

					$$ = new ASTNode(ASTNODE_BINARY_EXPRESSION);
					$$->children.push_back($1);
					$$->children.push_back(binary_op);
					$$->children.push_back($3);
				}
			;

unary_expr 	:	postfix_expr 
			|	unary_op unary_expr 
				{
					ASTNode* unary_op = new ASTNode(ASTNODE_UNARY_OP);
					unary_op->val = $1;

					$$ = new ASTNode(ASTNODE_UNARY_EXPRESSION);
					$$->children.push_back(unary_op);
					$$->children.push_back($2);
				}
		   	;

postfix_expr	:	primary_expr 
				|	TIDENTIFIER TLPAREN TRPAREN // function call w/o arguments
					{
						ASTNode* func_id = new ASTNode(ASTNODE_IDENTIFIER);
						func_id->val = $1;

						$$ = new ASTNode(ASTNODE_FUNCTION_CALL);
						$$->children.push_back(func_id);
						$2;$3;
					}
				|	TIDENTIFIER TLPAREN arg_expr_list TRPAREN // function call w/ arguments
					{
						ASTNode* func_id = new ASTNode(ASTNODE_IDENTIFIER);
						func_id->val = $1;

						$$ = new ASTNode(ASTNODE_FUNCTION_CALL);
						$$->children.push_back(func_id);
						$$->children.push_back($3); //arg_expr_list
						$2;$4;
					}
				|	postfix_expr postfix_op 
					{
						ASTNode* postfix_op = new ASTNode(ASTNODE_POSTFIX_OP);
						postfix_op->val = $2;

						$$ = new ASTNode(ASTNODE_POSTFIX_EXPRESSION);
						$$->children.push_back($1);
						$$->children.push_back(postfix_op);
					}
				;

arg_expr_list	:	arg_expr_list TCOMMA assignment_expr
					{
						$$ = $1;
						$1->children.push_back($3);
						delete $2;
					}
				|	assignment_expr
					{
						$$ = new ASTNode(ASTNODE_ARG_EXPR_LIST);
						$$->children.push_back($1); 
					}
				;

primary_expr	:	TICONST 
					{
						ASTNode* iconst = new ASTNode(ASTNODE_CONST_TERM);
						iconst->val = $1;

						$$ = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						$$->children.push_back(iconst);
					}
				|	TFCONST 
					{
						ASTNode* fconst = new ASTNode(ASTNODE_CONST_TERM);
						fconst->val = $1;

						$$ = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						$$->children.push_back(fconst);
					}
				|	TIDENTIFIER
					{
						//$$ = NULL;
						///*
						ASTNode* id = new ASTNode(ASTNODE_IDENTIFIER);
						id->val = $1;

						$$ = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						$$->children.push_back(id);
						//*/
					}
				|	TLPAREN expr TRPAREN
					{
						$$ = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						$$->children.push_back($2);
						$1;$3;
					}
				|	TPROC proc_id TIN TSTATE TSTOP
					{
						$$ = new ASTNode(ASTNODE_STOP_CHECK);
						$$->children.push_back($2);
						$1;$3;$4;$5;
					}
				|	TPROC proc_id TIN TSTATE TERROR
					{
						$$ = new ASTNode(ASTNODE_ERROR_CHECK);
						$$->children.push_back($2);
						$1;$3;$4;$5;
					}
				|	TPROC proc_id TIS TACTIVE
					{
						$$ = new ASTNode(ASTNODE_ACTIVE_CHECK);
						$$->children.push_back($2);
						$1;$3;$4;
					}
				|	TPROC proc_id TIS TINACTIVE
					{
						$$ = new ASTNode(ASTNODE_INACTIVE_CHECK);
						$$->children.push_back($2);
						$1;$3;$4;
					}
				;

cast_expr		:	unary_expr 
				|	TLPAREN c_type_spec TRPAREN cast_expr 
				{
					ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
					c_type_spec->val = $2;

					$$ = new ASTNode(ASTNODE_CAST_EXPRESSION);
					$$->children.push_back(c_type_spec);
					$$->children.push_back($4); //cast_expr
					$1;$3;
				}
		  		;

postfix_op		:	TINC | TDEC;
binary_op		:	TLOR | TLAND | TOR | TXOR | TAND | TEQ | TNEQ | TLT | TGT | TLE | TGE | TLSHIFT | TRSHIFT | TPLUS | TMINUS | TMUL | TDIV | TPERC;
unary_op		:	TINC | TDEC | TMINUS | TTILDE | TNOT;	   	
assignement_op	:	TASSGN | TR_ASSGN | TL_ASSGN | TPLUS_ASSGN | TMINUS_ASSGN | TSTAR_ASSGN | TDIV_ASSGN | TPERC_ASSGN | TAND_ASSGN | TXOR_ASSGN | TOR_ASSGN;

c_type_spec		:	TBOOL | TVOID |	TFLOAT | TDOUBLE 
				|	singness_spec size_spec {$$ = new std::string(*$1 + *$2);delete $1;delete $2;}
				|	size_spec 
				;
singness_spec	:	TSIGNED | TUNSIGNED ;
size_spec		:	TSHORT | TINT | TLONG ;
//int_type_spec	:	TBOOL | TSHORT | TINT | TLONG;

//=============================================================================
//                   VAR DECLARATIONS AND DEFINITIONS  
//=============================================================================


var_def				:	phys_var_def scope_spec TSEMIC
						{
							$$ = new ASTNode(ASTNODE_VAR_DEF);
							$$->children.push_back($1);
							$$->children.push_back($2);
							$3;
						}
					|	calc_var_def scope_spec TSEMIC
						{
							$$ = new ASTNode(ASTNODE_VAR_DEF);
							$$->children.push_back($1);
							$$->children.push_back($2);
							$3;
						}
					;

//						       1      2     3     4           5             6
phys_var_def		:	c_type_spec var_id TASSGN TLBRACE reg_bits_spec_list TRBRACE
						{
							ASTNode* int_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							int_type_spec->val = $1;

							$$ = new ASTNode(ASTNODE_PHYS_VAR_DEF);
							$$->children.push_back(int_type_spec);
							$$->children.push_back($2);
							$$->children.push_back($5);
							delete $3;
							$4;$6;
						}
					;

var_id				:	TIDENTIFIER
						{
							$$ = new ASTNode(ASTNODE_IDENTIFIER);
							$$->val = $1;
						}
					;

reg_id				:	TIDENTIFIER
						{
							$$ = new ASTNode(ASTNODE_IDENTIFIER);
							$$->val = $1;
						}
					;

reg_bits_spec_list	:	reg_bits_spec_list TCOMMA reg_bits_spec
						{
							$$ = $1;
							$1->children.push_back($3);
							delete $2;
						}
					|	reg_bits_spec
						{
							$$ = new ASTNode(ASTNODE_REG_BITS_SPEC_LIST);
							$$->children.push_back($1);
						}
					;

reg_bits_spec		:	reg_id TLBRACKET TICONST TRBRACKET
						{
							ASTNode* reg_index = new ASTNode(ASTNODE_ICONST);
							reg_index->val = $3;

							$$ = new ASTNode(ASTNODE_REG_BITS_SPEC);
							$$->children.push_back($1);
							$$->children.push_back(reg_index);
							$2;$4;
						}
					;

calc_var_def		:	c_type_spec var_id 
						{
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = $1;

							$$ = new ASTNode(ASTNODE_CALC_VAR_DEF);
							$$->children.push_back(c_type_spec);
							$$->children.push_back($2);
						}
					/*|	TBOOL var_id
						{
							ASTNode* bool_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							bool_spec->val = $1;

							$$ = new ASTNode(ASTNODE_CALC_VAR_DEF);
							$$->children.push_back(bool_spec);
							$$->children.push_back($2);
						}*/
					;

scope_spec			:	TLOCAL 
						{
							$$ = new ASTNode(ASTNODE_SCOPE_SPEC);
							$$->val = $1;
						}
					|	TFOR TALL 
						{
							$$=new ASTNode(ASTNODE_SCOPE_SPEC);
							$$->val = new std::string(*$1 + *$2);
							delete $1;
							delete $2;
						}
					|	TFOR proc_id_list 
						{
							$$ = new ASTNode(ASTNODE_SCOPE_SPEC);
							$$->children.push_back($2);
							delete $1;
						}
					;

proc_id_list		:	proc_id_list TCOMMA proc_id
						{
							$$ = $1;
							$1->children.push_back($3);
							delete $2;
						}
					|	proc_id
						{
							$$ = new ASTNode(ASTNODE_PROC_ID_LIST);
							$$->children.push_back($1);
						}
					;

var_decl			:	TFROM TPROC proc_id var_id_list TSEMIC
						{
							$$ = new ASTNode(ASTNODE_VAR_DECL);
							$$->children.push_back($3);
							$$->children.push_back($4);
							$1;$2;$5;
						}
					;

var_id_list			:	var_id_list TCOMMA var_id
						{
							$$ = $1;
							$1->children.push_back($3);
							delete $2;
						}
					|	var_id
						{
							$$ = new ASTNode(ASTNODE_VAR_ID_LIST);
							$$->children.push_back($1);
						}

//						  1      2       3        4        5            6
register_def		:	TINPUT reg_id reg_addr reg_addr register_size TSEMIC
						{
							ASTNode* dir_spec = new ASTNode(ASTNODE_DIR_SPEC);
							dir_spec->val = $1;

							$$ = new ASTNode(ASTNODE_REGISTER_DEF);
							$$->children.push_back(dir_spec);
							$$->children.push_back($2);
							$$->children.push_back($3);
							$$->children.push_back($4);
							$$->children.push_back($5);
							$6;
						}
					|	TOUTPUT reg_id reg_addr reg_addr register_size TSEMIC
						{
							ASTNode* dir_spec = new ASTNode(ASTNODE_DIR_SPEC);
							dir_spec->val = $1;

							$$ = new ASTNode(ASTNODE_REGISTER_DEF);
							$$->children.push_back(dir_spec);
							$$->children.push_back($2);
							$$->children.push_back($3);
							$$->children.push_back($4);
							$$->children.push_back($5);
							$6;
						}
					;

reg_addr			:	TICONST {$$ = new ASTNode(ASTNODE_REG_ADDR);$$->val=$1;};
register_size		:	TICONST {$$ = new ASTNode(ASTNODE_REG_SIZE);$$->val=$1;}

//						     1          2      3         4              5      6
func_decl			:	c_type_spec func_id TLPAREN c_type_spec_list TRPAREN TSEMIC
						{
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = $1;

							$$ = new ASTNode(ASTNODE_FUNC_DECL);
							$$->children.push_back(c_type_spec);
							$$->children.push_back($2);
							$$->children.push_back($4);
							$3;$5;$6;
						}
					;

func_id				:	TIDENTIFIER
						{
							$$ = new ASTNode(ASTNODE_IDENTIFIER);
							$$->val = $1;
						}
					;

c_type_spec_list	:	c_type_spec_list TCOMMA c_type_spec
						{
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = $3;

							$$ = $1;
							$1->children.push_back(c_type_spec);
							delete $2;
						}
					|	c_type_spec
						{
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = $1;

							$$ = new ASTNode(ASTNODE_TYPE_SPEC_LIST);
							$$->children.push_back(c_type_spec);
						}
					;

%%

int yyerror(const char *s) 
{
	//parser_context->err_msg(s);
	std::cout<<line_num<<": "<<s<<std::endl;
	return 0;
}

