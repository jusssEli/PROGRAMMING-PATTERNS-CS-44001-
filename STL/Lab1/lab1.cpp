//Elijah Rogers
//CSIII Lab1
//8/23/2024
#include <iostream>
#include <fstream>
#include <string>
using std::cout; using std::endl;
// void lineCounted(int);

int main(int argc, char* argv[]){
    //argc 'if' statements are agument checks to ensure the amount is correct, otherwise errors in logic
    if(argc < 3)
        cout << "Unfortunately you do not meet the necessary requirements to run this program" << endl;
    if(argc > 3)
        cout << "Unfortunately you do not meet the necessary requirements to run this program" << endl;
    if(argc == 3){
        std::ifstream file1(argv[1]);
        std::ifstream file2(argv[2]);
        //adding 1 to number of lines to increment while searching through file
        int numLines = 1;

        //Checking files open properly
        if (!file1.is_open() || !file2.is_open()) {
		    std::cerr << "Dude.. files broke.. good luck tho" << std::endl;
	    }
        //searching through files loop
            while (!(file1.eof() && file2.eof())) {
                std::string firstLine, nextLine;

                // if eof, assumes empty string -- basically checks which file is longer by setting the file line of the shorter file to empty string as other file keeps looping
                if (file1.eof()) 
                    firstLine = "";
                else 
                    getline(file1, firstLine);

                if (file2.eof()) 
                    nextLine = "";
                else 
                    getline(file2, nextLine);

                // Prints the lines if not equal 
                if (firstLine != nextLine) {
                    std::cout << argv[1] << ": " << numLines << ": " << firstLine << std::endl;
                    std::cout << argv[2] << ": " << numLines << ": " << nextLine << std::endl;

                    //loop variable
                    int i = 0;
                    //indexes until there's different character and adds carrot '^'
                    // looping through the line until difference is found
                    while (firstLine[i] == nextLine[i]) {
                        ++i;
                    }
                    //Spacing of lines dependant on line number difference is found on
                    if(numLines < 10)
                        for(int j = 0; j < 14; ++j){
                            std::cout << ' ';
                        }
                    else if( numLines > 9 && numLines < 100)
                            for(int j = 0; j < 15; ++j){
                                std::cout << ' ';
                            }
                    else
                        for(int j = 0; j < 16; ++j){
                            std::cout << ' ';
                        }
                    //use i an an argument for function to account for spaces dependent on line number
                    for(int j = 0; j < i; ++j){
                        std::cout << ' ';
                    }
                    std::cout << "^" << std::endl;
                }
                numLines++;
        }

    }
}
// void lineCounted(int i){
//     if(i > 0 && i < 10)
//         for(int j = 0; j < 14; ++j){
//             std::cout << ' ';
//         }
//     if(i > 9 && i < 100)
//         for(int j = 0; j < 15; ++j){
//             std::cout << ' ';
//         }
//     if(i > 100)
//         for(int j = 0; j < 16; ++j){
//             std::cout << ' ';
//         }
// }
