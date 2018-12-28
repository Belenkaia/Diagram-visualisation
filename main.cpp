#include <iostream>
#include <sstream>
#include <stack>
#include <fstream>
#include "common.h"

extern int yyparse();
extern FILE *yyin;

std::string input_filename = "input.rsc";
std::string output_filename = "output.cpp";

ASTNode* program = NULL;

const std::string AST_NODE_NAMES[] = 
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
};

int main(int argc, char **argv)
{
	//1: Parse command line arguments
	if(argc <= 1)
	{
		std::cout<<"Error: no input file specified"<<std::endl;
		return -1;
	}
	input_filename = argv[argc-1];
	for(int i=1;i<argc-1;i++)
		if("-o" == std::string(argv[i]) && i+1 < argc)
			output_filename = argv[++i];

	//2: open a file handle to a particular file:
	FILE *myfile = fopen(input_filename.c_str(), "r");
	if (!myfile) // make sure it's valid:
	{
		std::cout << "Can't find " << input_filename << std::endl;
		return -1;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	yyin = myfile;// set flex to read from it instead of defaulting to STDIN:

	//3: parse the input source code
	std::cout<<"parsing..."<<std::endl;
    int parse_result = yyparse();
	fclose(myfile);

	std::cout<<"parser finished"<<std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////

	
	//output the AST as XML (pre-order iterative traversal)
	std::stack<ASTNode*> nodes_to_print;
	unsigned int indent = 0;
	nodes_to_print.push(program);
	while(!nodes_to_print.empty())
	{
		ASTNode* node = nodes_to_print.top();
		nodes_to_print.pop();

		if(NUM_AST_NODE_TYPES == node->type)//found terminator node - upping tree level
		{
			delete node; // delete the terminator
			node = nodes_to_print.top(); //pop the parent - they're always next to the terminator
			nodes_to_print.pop();
			indent--; // reduce indentation level
			for(int i=0;i<indent;i++) std::cout<<'\t'; // indent
			std::cout<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl; // print parent's tail
		}
		else
		{
			for(int i=0;i<indent;i++) std::cout<<'\t';
			std::cout<<"<"<<AST_NODE_NAMES[node->type];
			if(!node->children.empty() && NULL != node->val)
			{
				ICASSERT(false);
				std::cout<<" value=\""<<*(node->val)<<"\"";
			}
			std::cout<<">";
			if(!node->children.empty())
			{
				std::cout<<std::endl;
				indent++;
				nodes_to_print.push(node);//add self (for termination </node>)
				nodes_to_print.push(new ASTNode(NUM_AST_NODE_TYPES));//add terminator node
				for(ASTNodeList::reverse_iterator i = node->children.rbegin();i!=node->children.rend();++i)
				{
					nodes_to_print.push(*i);
				}
			}
			else // leaf node
			{
				if(NULL != node->val)
					std::cout<<*(node->val); // only leaf nodes have values
				std::cout<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl;
			}
		}
	}
	
	delete program;

#ifdef ICDEBUG
	std::cout<<"pointers still allocated: "<<get_num_allocs()<<std::endl;
#endif

    return 0;
}
