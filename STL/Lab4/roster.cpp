
// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
 using std::endl; using std::cout;
using std::move;

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName);  
void readStudentRoster(list<list<string>>& roster, string fileName);
// printing a list out
void printRoster(const list<string>& roster);
void printStudentRoster(list<list<string>>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ 
      cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" 
      << endl;
      exit(1);
   }


   //list of Student entries in a list of list of strings
   list<list<string>> studentEntries;
      // starts at one to avoid argv[0] that is null
   for (int i = 1; i < argc; ++i) { 
      string csClass = argv[i];
      if (csClass.substr(csClass.size() - 4) == ".txt") // if class file ends in .txt removes .txt
            csClass.erase(csClass.size() - 4); // erase last 4 characters. (.txt)
      list<string> people; // creates a list of all people in the class
      readRoster(people, argv[i]);
      cout << csClass << endl;
      
      for (auto name_ : people) { // for each student in the class
            //check if studentEntries contains that student then if not in list adds to new list
            bool added = false;
             // -- adding to student entries
            // find out if student already exists by looping through the student entries-- if the name DNE in class -- add new empty element to back list  
            for (auto &exists: studentEntries) {
               if (name_ == exists.front()) {
                  exists.push_back(csClass);
                  added = true;
                  break;
               }
            }
            // list<string>::iterator<string> it;
            if(!added){
               list<string> newPerson;
               newPerson.push_back(name_);
               newPerson.push_back(csClass);
               studentEntries.push_back(newPerson);
            }
      }
   }
   printStudentRoster(studentEntries);
   
}

// reading in a file of names into a list of strings
void readRoster(list<string>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   while(course >> first >> last)
      roster.push_back(first + ' ' + last);
   course.close();
}
void readStudentRoster(list<list<string>>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   list<string> name;    
   while(course >> first >> last){
      name.push_back(first + ' ' + last);
      roster.push_back(name);
   }
   course.close();
}

// printing a list out
void printStudentRoster( list<list<string>>& roster){
   for(auto& str : roster){
      for(auto& str2 : str)
         cout << str2 << ' ';
      cout << endl;
   }
}
void printRoster(const list<string>& roster){
   for(const auto& str : roster)
      cout << str << endl;
}
