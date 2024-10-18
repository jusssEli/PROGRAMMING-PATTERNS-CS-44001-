
//Elijah Rogers

// vector and list algorithms with objects in containers
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <map>

using std::ifstream; using std::cin;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::map;
//made map, key is student, use read RosterFunction take in map ref

class Student{
public:
   Student(string firstName, string lastName): 
      firstName_(firstName), lastName_(lastName) {}
 
   // move constructor, not really needed, generated automatically
   Student(Student && org) noexcept:
      firstName_(move(org.firstName_)),
      lastName_(move(org.lastName_))
   {}
  
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
   string print() const {return firstName_ + ' ' + lastName_;}
   // const string getName (){ return firstName_ + lastName_; };
    // needed for unique() and for remove()
   friend bool operator== (Student left, Student right){
      return left.lastName_ == right.lastName_ &&
	     left.firstName_ == right.firstName_;
   }

   // needed for sort()
   friend bool operator< (Student left, Student right){
      return left.lastName_ < right.lastName_ ||
	     (left.lastName_ == right.lastName_ && 
	      left.firstName_ < right.firstName_);
   }
private:
   string firstName_;
   string lastName_;
};


//reading and printing map functions
void readMap(map<Student, list<string>>& sNameClass, string fileName);
void printMap(const map<Student, list<string>>& sNameClass);
// reading a list from a fileName
void readRoster(list<Student>& roster, string fileName);  
// printing a list out
void printRoster(const list<Student>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   
 
   //think of map as an array of pairs
   map<Student, list<string>> sNameClass;
   for(int i = 1; i < argc-1; ++i){
      readMap(sNameClass, argv[i]);
   }
   printMap(sNameClass);

}

void readMap(map<Student, list<string>>& sNameClass, string fileName){
   ifstream course(fileName);
   string first, last;
   string rmvTxt = fileName.substr(0, fileName.length()-4); //file name without .txt to get class
   while(course >> first >> last){
      Student name(first, last);
      auto ret = sNameClass.insert(make_pair(name,list<string>())); //if insertion successful --- returns true
      sNameClass[name].push_back(rmvTxt); //push back string using key -- pushing back the name with the class(es) the Student is in
      //Line above determines if name is in map, yes? none No? safe insert
   }
   course.close();
}
// printing a list out
void printMap(const map<Student, list<string>>& sNameClass){
   for(auto it = sNameClass.cbegin(); it != sNameClass.cend(); ++it){
      cout << it->first.print() << " "; //prints the first element in the map -- Student name
      for(auto it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2)
         cout << *it2 << " "; //prints second element in map -- student class
      cout << endl;
   }
   
}

void readRoster(list<Student>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   while(course >> first >> last)
      roster.push_back(Student(first, last));
   course.close();
}

// printing a list out
void printRoster(const list<Student>& roster){
   for(const auto& student : roster)
      cout << student.print() << endl;
}
