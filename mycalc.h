#include <iostream>
#include <queue>
#include <string>


class MyCalc
{
public:
	MyCalc(char *, char *);

private:
	std::vector<std::string> lines;
	std::vector <Variable> solved;
	std::vector <Variable> unsolved;
	read_input(char *, std::vector<std::string> &);
	process_line(std::string);
	generate_output();

};

class Variable
{
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
	Node * parent;
	Node * left;
	Node * right
	Node(std::string value)
	:value(value){
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	Node(std::string value, Node * parent)
	:value(value), parent(parent){
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
