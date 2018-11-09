#include "mycalc.h"


MyCalc::MyCalc(char * input_file, char * output_file){
	read_input(input_file);
	for (int i = 0; i < lines.size(); i++){
		process_line(lines[i]);
	}

}


void MyCalc::read_input(char * file_name){ //read each line, break it into the name of the variable and its values
	std::string line;
	std::string processed_line;

	std::ifstream input(file_name);

	if (input.is_open()){
		while (std::getline(input,line)){
			line =line.substr(0, line.length() - 1);
			for (std::string::iterator it = line.begin(); it != line.end(); it++){ //to purge the unnecessary symbols and spaces
				if (*it !=' ' && *it != ';' && *it != '\0' && *it != '\r'){
					processed_line.push_back(*it);
				}
			}
			lines.push_back(processed_line);
			//std::cout << processed_line <<std::endl;
			processed_line = "";
		}
	}
	input.close();
}

void MyCalc::process_line(std::string& line){ //for each line, return the root of the tree
	std::string name;
	int position;  //of '='
	for (int i = 0; i < line.length(); i++){
		if (line[i] == '='){
			position = i;
			break;
		}
	}

	name = line.substr(0, position);
	std::cout << name <<std::endl;

	std::string instru;
	instru = line.substr(position+1,line.length()-position-1);

	std::vector< std::pair<Type,std::string> > elements;
	elements = sort_out(instru);

	stack< std::pair<Type,std::string> > pre_order;
	pre_order = in2pre(elements);

	//debug
	while (!pre_order.empty()){
		std::cout << pre_order.top().second<< " ";
		pre_order.pop();
	}
	std::cout <<std::endl;

	//return what

}

stack<std::pair<Type,std::string> > MyCalc::in2pre(std::vector<std::pair<Type,std::string> > & elements){ //convert from inorder to preorder
	//***citing Lab 5 solution's infix2postfix member function
	stack< pair <Type, string> > pre_order;
	stack< pair <Type, string> > tmp;
	std::pair<Type,std::string> p;
	p.first = bra2;
	p.second =")";
	elements.push_back(p);
	std::pair<Type,std::string> q;
	q.first = bra1;
	q.second ="(";
	tmp.push(q);

	int i = 0; 
	while (!tmp.empty()){
		std::pair <Type, string> ele = elements[i++];
		if (ele.first ==num || ele.first == var){
			pre_order.push(ele);
		}
		else if (ele.first == bra1 ){
			tmp.push(ele);
		}
		else if (ele.first == opt){
			while (tmp.top().first == opt && inferior(ele.second, tmp.top().second)){
				pre_order.push(tmp.top());
				tmp.pop(); 
			}
			tmp.push(ele);
		}
		else if (ele.first == bra2 ){
			while (tmp.top().first!= bra1){
				pre_order.push(tmp.top());
				tmp.pop();
			}
			tmp.pop();
		}
	}
	return pre_order;
}

int MyCalc::sequence(string o){
	if (o =="+" || o =="-") return 1;
	else if (o =="*" || o =="/"|| o =="%") return 2;
	else if (o =="++" || o =="--"|| o =="**") return 3;
	else return 0;
}

bool MyCalc::inferior(string a, string b){
	if (sequence(a)<= sequence(b)) return 1;
	else return 0;
}


std::vector< std::pair<Type,std::string> > MyCalc::sort_out(std::string & instructions){ //take the characters and sort them into var, num, baracketes and  operators
	//and return a pre-order list of all the elements

	std::string tmp;
	tmp = "";
	std::vector<std::pair<Type,std::string> > instruction_list;
	for (std::string::iterator it = instructions.begin(); it!=instructions.end(); it++){
		
		if (isalpha(*it)){
			while (isalpha(*it)){
				tmp.push_back(*it);
                it++;
			}
            it--;
			if (tmp !="mod"){
                std::pair<Type,std::string> p;
				p.first = var;
				p.second = tmp;
				instruction_list.push_back(p);
				tmp = "";
			}
			else{
                std::pair<Type,std::string> p;
				p.first = opt;
				p.second = '%';
				instruction_list.push_back(p);
				tmp = "";
			}
		}
		else if (isdigit(*it)){
			while (isdigit(*it)){
				tmp.push_back(*it);
                it++;
			}
            it--;
            std::pair<Type,std::string> p;
			p.first = num;
			p.second = tmp;
			instruction_list.push_back(p);
			tmp = "";

		}
		else if (is_operator(*it)){
			while(is_operator(*it)){
				tmp.push_back(*it);
                it++;
			}
            it--;
            std::pair<Type,std::string> p;
			p.first = opt;
			p.second = tmp;
			instruction_list.push_back(p);
			tmp = "";
		}
		else{
			if (*it=='('){
                std::pair<Type,std::string> p;
				p.first = bra1;
				p.second = "(";
				instruction_list.push_back(p);
				tmp = "";	
			}
			else if (*it== ')'){
                std::pair<Type,std::string> p;
				p.first = bra2;
				p.second = ")";
				instruction_list.push_back(p);
				tmp = "";
			}
		}
	}
	return instruction_list;
}


bool MyCalc::is_operator(char & o){
	if (o =='+' || o =='-' || o =='*' || o =='/' || o =='%') return 1;
	else return 0;
}
