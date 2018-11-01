#include "mycalc.h"
#include <vector>

void read_input(char *);
void generate_ouput();

int main(int argc, char* argv){
	char * ifile = "";
	char * ofile = "";


	for (int i = 0; i < argc; i++){
		if (argv[i] == "-i"){
			ifile = argv[++i];
		}
		if (argv[i] == "-o"){
			ofile = argv[++i];
		}
	}

	if (ifile == "" || ofile == ""){
		std::cout << "mymachine-promt >> ./mycalc -i <inputfile> -o <outfile>"<<std::endl;
		return EXIT_FAILURE;
	}

	MyCalc mycalc(ifile, ofile);


	return 0;

}

