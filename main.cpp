#include <iostream>
#include <sstream>
#include <stack>
#include <fstream>
#include<string.h>
#include "common.h"

extern int yyparse();
extern FILE *yyin;

ASTNode* program = NULL;

unsigned long line_num = 1;

int main(int argc, char **argv)
{
	std::string input_filename = "input.rsc";
	std::string output_filename = "ast.xml";
	std::string output_gml_filename = "activity_diagramm.gml";
	
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
	
	if(0 == parse_result)
	{
		std::ofstream output_file;
		output_file.open(output_filename.c_str());
		std::cout<<"generating xml..."<<std::endl;
		
		//XML header
		output_file<<"<?xml version=\"1.0\"?>"<<std::endl;

		//output the AST as XML (pre-order iterative traversal)
		std::stack<ASTNode*> nodes_to_print;
		unsigned int indent = 0;
		nodes_to_print.push(program);
		while(!nodes_to_print.empty())
		{
			ASTNode* node = nodes_to_print.top();
			nodes_to_print.pop();

			if(NULL == node) 
				continue;

			if(NUM_AST_NODE_TYPES == node->type)//found terminator node - upping tree level
			{
				delete node; // delete the terminator
				node = nodes_to_print.top(); //pop the parent - they're always next to the terminator
				nodes_to_print.pop();
				indent--; // reduce indentation level
				for(int i=0;i<indent;i++) output_file<<'\t'; // indent
				output_file<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl; // print parent's tail
			}
			else
			{
				for(int i=0;i<indent;i++) output_file<<'\t';
				output_file<<"<"<<AST_NODE_NAMES[node->type];
				if(!node->children.empty() && NULL != node->val)
				{
					ICASSERT(false);
					output_file<<" value=\""<<*(node->val)<<"\"";
				}
				output_file<<">";
				if(!node->children.empty())
				{
					output_file<<std::endl;
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
						output_file<<*(node->val); // only leaf nodes have values
					output_file<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl;
				}
			}
		}
		output_file.close();
	}
	int count_id = 0;
	int flag = 0;
    if(0 == parse_result)
	{
		std::ofstream output_file;
		output_file.open(output_gml_filename.c_str());
		std::cout<<"generating gml..."<<std::endl;
		
		//GML header
		output_file<<"Creator	\"tranlator\""<<std::endl;
		output_file<<"Version	\"2.15\" "<<std::endl;
		output_file<<"graph"<<std::endl;
		output_file<<"["<<std::endl;
		output_file<<"\thierarchic	1"<<std::endl;
		output_file<<"\tlabel	\"\""<<std::endl;
		output_file<<"\tdirected	1"<<std::endl;
	
		//output the AST as GML (pre-order iterative traversal)
		std::stack<ASTNode*> nodes_to_print_gml;
		unsigned int indent = 0;
		nodes_to_print_gml.push(program);
		while(!nodes_to_print_gml.empty())
		{
			ASTNode* node = nodes_to_print_gml.top();
			nodes_to_print_gml.pop();

			if(NULL == node) 
				continue; // strange

			if(NUM_AST_NODE_TYPES == node->type)//found terminator node - upping tree level
			{
				delete node; // delete the terminator
				node = nodes_to_print_gml.top(); //pop the parent - they're always next to the terminator
				nodes_to_print_gml.pop();
			//	indent--; // reduce indentation level
			///	for(int i=0;i<indent;i++) output_file<<'\t'; // indent
			//	output_file<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl; // print parent's tail
			}
			else
			{
				//for(int i=0;i<indent;i++) output_file<<'\t';
				//output_file<<"<"<<AST_NODE_NAMES[node->type];
				if(!node->children.empty() && NULL != node->val)
				{
					ICASSERT(false);
				//	output_file<<" value=\""<<*(node->val)<<"\"";
				}
				//output_file<<">";
				if(!node->children.empty())
				{
					//output_file<<std::endl;
					//indent++;
					nodes_to_print_gml.push(node);//add self (for termination </node>)
					nodes_to_print_gml.push(new ASTNode(NUM_AST_NODE_TYPES));//add terminator node
					for(ASTNodeList::reverse_iterator i = node->children.rbegin();i!=node->children.rend();++i)
					{
						nodes_to_print_gml.push(*i);
					}
					if(ASTNODE_PROCID == node->type)//found terminator node - upping tree level
					{
					flag = 2;
					}
				}
				else // leaf node
				{
				//	if(ASTNODE_PROCID == node->type)//found terminator node - upping tree level
				//	{
				//	flag = 2;
				//	}

			if(NULL != node->val)
			{

				if(flag==2)
				{
				flag = 0;
				//delete node; // delete the terminator
				//node = nodes_to_print_gml.top(); //pop the parent - they're always next to the terminator
				//nodes_to_print_gml.pop();
				output_file<<"\tnode"<<std::endl;
				output_file<<"\t["<<std::endl;
				output_file<<"\t\tid\t"<<count_id<< std::endl;
				count_id ++;
				output_file<<"\t\tlabel\t\""<<*(node->val)<<"\""<<std::endl;
				output_file<<"\t\tgraphics"<<std::endl;
				output_file<<"\t\t["<<std::endl;	
				output_file<<"\t\t\tw\t"<<strlen(node->val->c_str()) * 5 <<".0"<<std::endl;			
				output_file<<"\t\t\th\t48.0"<<std::endl;	
				output_file<<"\t\t\ttype\t\"roundrectangle\""<<std::endl;					
				output_file<<"\t\t\traisedBorder\t0"<<std::endl;
				output_file<<"\t\t\tfill\t\"#FFFFFF\""<<std::endl;
				output_file<<"\t\t\toutline\t\"#000000\""<<std::endl;
				output_file<<"\t\t]"<<std::endl;
				output_file<<"\t\tLabelGraphics"<<std::endl;
				output_file<<"\t\t["<<std::endl;
				output_file<<"\t\t\ttext\t\""<<*(node->val)<<"\""<<std::endl;
				output_file<<"\t\t\tfontSize\t12"<<std::endl;
				output_file<<"\t\t\tfontName\t\"Dialog\""<<std::endl;
				output_file<<"\t\t]"<<std::endl;
				output_file<<"\t]"<<std::endl;
				//indent--; // reduce indentation level
				//for(int i=0;i<indent;i++) output_file<<'\t'; // indent
				//output_file<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl; // print parent's tail
				}
			//	output_file<<*(node->val); // only leaf nodes have values
			}
					//output_file<<"</"<<AST_NODE_NAMES[node->type]<<">"<<std::endl;
				}
			}
			
		}
		output_file<<"]"<<std::endl;
		output_file.close();
	}

    delete program;
	return 0;
}


