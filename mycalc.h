#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <ctype.h>
#include <locale>


using namespace std;

class Variable;
class Node;

enum Type
{
    var, num, opt, bra1, bra2
    
};

class MyCalc{
public:
	MyCalc(char *, char *);

private:
	std::vector<std::string> lines;
	std::vector <Variable> solved;
	std::vector <Variable> unsolved;
	void read_input(char *);
	void process_line(std::string &);
	std::stack<std::pair<Type,std::string> > in2pre(std::vector<std::pair<Type,std::string> > &);
    int sequence(std::string);
    bool inferior(std::string , std::string );
    std::vector< std::pair<Type,std::string> > sort_out(std::string &);
    bool is_operator(char &);
	void generate_output();
  
};


class Variable{
public:
	std::string name;
	std::string status;
	int value;
	Variable(std::string name, std::vector<Node> tree);
	Variable(std::string name, int value);
	

private:

};



struct Node
{
	std::string value;
	Type type; //numeric, var; or 
	bool external; //also means that it has a numeric value, rather than being an operator
	Node * parent=NULL;
	Node * left = NULL;
	Node * right= NULL;
	Node(std::string value, Type type)
	:value(value), type (type){

	}
	Node(std::string value, Node * parent, Type type)
	:value(value), parent(parent), type(type){
	}
};
