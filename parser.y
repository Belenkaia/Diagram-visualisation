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
%token <token> TINPUT			"INPUT"
%token <token> TOUTPUT			"OUTPUT"
%token <token> TPROC			"PROC"	
%token <token> TLOCAL			"LOCAL"
%token <token> TFOR				"FOR"	
%token <token> TALL				"ALL"	
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
%token <token> TBOOL			"BOOL"		
%token <token> TVOID			"VOID"		
%token <token> TFLOAT			"FLOAT"	
%token <token> TDOUBLE			"DOUBLE"	
%token <token> TSIGNED			"SIGNED"
%token <token> TUNSIGNED		"UNSIGNED"	
%token <token> TSHORT			"SHORT"	
%token <token> TLONG			"LONG"		
%token <token> TINT				"INT"		

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
%token <string> TTILDA			"~"
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
%type <node_list>			register_spec_list	
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
%type <ast_node>			enumerator_spec			

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
				|	const_enum_list func_decl_list register_spec_list
					{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);$$->splice($$->end(),*$3);delete $1;delete $2;delete $3;}
				|	const_enum_list func_decl_list		{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);delete $1;delete $2;}
				|	const_enum_list register_spec_list	{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);delete $1;delete $2;}
				|	func_decl_list register_spec_list	{$$=new ASTNodeList;$$->splice($$->end(),*$1);$$->splice($$->end(),*$2);delete $1;delete $2;}
				|	const_enum_list						{$$=new ASTNodeList;$$->splice($$->end(),*$1);delete $1;}
				|	func_decl_list						{$$=new ASTNodeList;$$->splice($$->end(),*$1);delete $1;}
				|	register_spec_list					{$$=new ASTNodeList;$$->splice($$->end(),*$1);delete $1;}
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
					|	enumerator_spec {$$ = $1;}
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
const_prefix		:	TTILDA | TNOT | TPLUS | TMINUS;
const_infix			:	TPLUS | TMINUS | TMUL | TDIV | TPERC | TLSHIFT | TRSHIFT | TAND | TXOR | TOR | TLAND | TLOR;

const_term			:	TICONST {$$=new ASTNode(ASTNODE_CONST_TERM);$$->val=$1;}
					|	TFCONST {$$=new ASTNode(ASTNODE_CONST_TERM);$$->val=$1;}
					|	const_id {$$=$1;}
					//|	TLPAREN const_exp_body TRPAREN  
					;

enumerator_spec			:	"enumerator_spec" {$$ = NULL;};//STUB

/*
enumerator_spec		:	TENUM TLBRACE enumerator_list TRBRACE
						{
							
						}
					;

enumerator_list		:	enumerator 
					|	enumerator TCOMMA enumerator_list
					;

enumerator			:	const_id 
					|	const_id TASSGN const_exp_body
					;
*/


//Auxiliary node for iteration, not present in original grammar
func_decl_list	:	"func_decl_list" {$$ = NULL;}//STUB
				;

//Auxiliary node for iteration, not present in original grammar
register_spec_list	:	"register_spec_list" {$$ = NULL;}//STUB
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

//						  1      2      3           4              5          6
proc_def			:	TPROC proc_id TLBRACE /*var_list*/{} state_def_list TRBRACE
						{
							$$ = new ASTNode(ASTNODE_PROC_DEF);
							$$->children.push_back($2); //proc_id
							$$->children.splice($$->children.end(), *$5);//add state defs as children
							delete $5; //state_def_list
							$1;$3;$6;
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

/*
var_list			:	%empty {$$ = NULL;}
					|	{var_spec | var_decl}
					;
*/

//Auxilisry list
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

statement			:	TSEMIC {$$ = new ASTNode(ASTNODE_EMPTY_STATEMENT);$1;}
					|	compound_statement
					//|	switch_spec 
					//|	event_react_spec 
					//|	start_spec 
					//|	stop_spec 
					//|	error_spec 
					//|	loop_decl 
					//|	set_cur_sf_spec 
					//|	restart_cur_proc_spec 
					//|	reset_timer_spec 
					//|	var_equation
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


//var_spec			:	(phys_var_spec | calc_var_spec), visibility_spec, TSEMIC;
//phys_var_spec		:	int_type_spec, var_id, TEQ, TLBRACE, reg_bits_spec_list, TRBRACE; 
//reg_bits_spec_list	:	reg_bits_spec | (reg_bits_spec, TCOMMA, reg_bits_spec_list);
//reg_bits_spec		:	reg_id, TLBRACKET, int_num, TRBRACKET; 
//calc_var_spec		:	(c_type_spec | TBOOL), var_id; 
//visibility_spec		:	TLOCAL | (TFOR, TALL) | (TFOR, proc_id_list);
//proc_id_list		:	proc_id | (proc_id, TCOMMA , proc_id_list);

//var_decl			:	TFROM, TPROC, proc_id, var_id_list, TSEMIC;
//var_id_list			:	var_id | (var_id, TCOMMA, var_id_list);


/*

function_decl		:	c_type_spec, func_id, TLPAREN, c_type_spec_list, TRPAREN, TSEMIC; 
c_type_spec_list	:	c_type_spec | (c_type_spec, TCOMMA, c_type_spec_list);
func_id				:	TIDENTIFIER;

register_spec		:	(TINPUT | TOUTPUT), reg_id, addr_1, addr_2, register_size; 
addr_1				:	int_num;
addr_2				:	int_num;
register_size		:	"8" | "16";
reg_id				:	TIDENTIFIER;

react_spec			:	TSEMIC | (TLBRACE, func_state_body, TRBRACE) | switch_spec | event_react_spec | start_spec | stop_spec | error_spec | loop_decl | set_cur_sf_spec | restart_cur_proc_spec | reset_timer_spec | var_equation;

switch_spec			:	TSWITCH, TLPAREN, event, TRPAREN, TLBRACE, {case_spec}, TRBRACE;
case_spec			:	TCASE, int_num, TCOLON, func_state_body, [TBREAK, TSEMIC];

event_react_spec	:	event_react_body, [rev_event_react_body];
event_react_body	:	TIF, TLPAREN, event, TRPAREN, react_spec;

rev_event_react_body:	TELSE, react_spec;

start_spec			:	TSTART, proc_id, TSEMIC;
stop_spec			:	TSTOP, [proc_id], TSEMIC;
error_spec			:	TERROR, [proc_id], TSEMIC;
loop_decl			:	TLOOP, TSEMIC;
set_cur_sf_spec		:	TSET, (TSTATE, func_state_id) | TNEXT, TSEMIC;
restart_cur_proc_spec:	TRESTART, TSEMIC;
reset_timer_spec	:	TRESET, TTIMEOUT, TSEMIC;

var_equation		:	var_id, TASSGN, event, TSEMIC);

event				:	var_pref_post_term | var_pref_post_term, {var_infix, var_pref_post_term};
var_pref_post_term	:	var_prefix, term, [var_postfix];
var_prefix			:	[(TTILDA | TNOT | TINC | TDEC | TPLUS | TMINUS | TMUL | TAND)], [TLPAREN, c_type_spec,TRPAREN];
var_postfix			:	TINC | TDEC;
var_infix			:	TPLUS | TMINUS | TMUL | TDIV | TPERC | TLSHIFT | TRSHIFT | TAND | TXOR | TOR | TLAND | TLOR | TASSGN | TSTAR_ASSGN | TDIV_ASSGN | TPERC_ASSGN | TPLUS_ASSGN | TMINUS_ASSGN | TLASSGN, | TR_ASSGN | TAND_ASSGN | TXOR_ASSGN | TOR_ASSGN | TLT | TGT | TLEQ | TGEQ | TEQ | TNEQ; 
term				:	number | const_id | var_id | function | situation | TLPAREN, event, TRPAREN;
function			:	func_id, TLPAREN, func_param_list, TRPAREN; 
func_param_list		:	event | (event, {TCOMMA, event});

situation			:	TPROC, proc_id, ((TIN, TSTATE, (TSTOP | TERROR)) | (TIS, (TACTIVE | TINACTIVE)));

var_id				:	TIDENTIFIER;

c_type_spec			:	TVOID | TFLOAT | TDOUBLE | TSIGNED | TUNSIGNED | TSHORT | TINT | TLONG;
int_type_spec		:	TBOOL | TSHORT | TINT | TLONG;
*/

%%

int yyerror(const char *s) 
{
	//parser_context->err_msg(s);
	std::cout<<s<<std::endl;
	return 0;
}

