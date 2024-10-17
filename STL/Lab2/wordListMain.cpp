//Elijah Rogers
//CSIII Lab2
//8/30/2024
#include "WordList.hpp"

int main(int argc, char* argv[]){

    std::ifstream file1(argv[1]);
    // Checks to see if files are open
	if (!file1.is_open()) {
		std::cerr << "Ur files are screwy, go somewhere else with that!!!" << std::endl;
		return 0;
	}
	WordList w;
	string buffer = "";
	char c;
	while(file1.get(c)){
		if(isspace(c) || ispunct(c)){
			if(buffer.size() > 0){
				w.addWord(buffer);
			}
			buffer = ""; continue;
		}
		buffer+=c;

	}
	// while( file1 >> buffer){
	// 	if(c == isspace(c) || ispunct(c)){
	// 		if(buffer.size() > 0){
	// 			w.addWord(buffer);
	// 			buffer = "";
	// 		}
	// 	}
	// 	// w.addWord(buffer);
	// }
	w.sorterer();
	w.print();

}