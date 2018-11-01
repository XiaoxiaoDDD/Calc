#include "mycalc.h"

MyCalc::MaCalc(char * input_file, char * output_file,){
	read_input(input_file);
	for (std::string l in lines){
		process_line(l);
	}

}


void MyCalc::read_input(char * file_name, std::vector<std::string> & lines){
	std::string line;

	std::ifstream inputfile(file_name);

	if (inputfile.is_open()){
		while (std::getline(inputfile,line)){
			line =line.substr(0, line.length() - 1);
			lines.push_back(line);
		}
	}
	inputfile.close();
}

void MyCalc::process_line(std::string line){
	std::string name;
	int position;  //of '='
	for (int i = 0; i < line.length(); i++){
		if (line[i] == '='){
			position = i;
			break;
		}
	}
	name = line.substr(0, position);

	make_tree(line.substr(posiiton+1, line.length()-posiiton - 1));

	char * iterator;

}

void MyCalc::make_tree(std::string & instructions){
	std::string tmp, left, right;
	tmp = "";
	left = "";
	right = "";
	while (instructions.empty() != 1){
		if (instructions.begin().is_operator){
			Node * node;
			node = new Node (instructions.being());
			node -> left = Node (tmp, node);

		}
		else{
			tmp.push_back(instructions.begin());
		}


	}




}

void MyCalc::insert(){


}

void MyCalc::is_operator(char o){
	if (o =='' ||o =='-' ||o =='-' ||o =='-' ||o =='-' || \
		o =='+' || o =='-' || o =='*' || o =='/' || o =='%') return TRUE;
	else return FALSE;
}


void MyCalc::generate_ouput(){

}