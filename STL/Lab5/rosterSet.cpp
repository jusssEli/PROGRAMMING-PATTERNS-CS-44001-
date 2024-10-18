
//Elijah Rogers


#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <set>
using std::ifstream; using std::endl; 
using std::string; using std::getline;
using std::list; using std::vector;
using std::move; using std::cout; 
using std::cin; using std::set;
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


//reading and printing set functions
void readSet(set<Student>& roster, string fileName);
void printSet(const set<Student>& roster);


int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   // vector of courses of students
   vector <list<Student>> courseStudents;
   //think of map as an array of pairs
   set<Student> roster;
   for(int i = 1; i < argc-1; ++i){
      readSet(roster, argv[i]);
   }
   printSet(roster);

}

void readSet(set<Student>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   //string rmvTxt = fileName.substr(0, fileName.length()-4); //file name without .txt to get class
   while(course >> first >> last){
      Student name(first, last);
      roster.insert(name);
   }
   course.close();
}
// printing a list out
void printSet(const set<Student>& roster){
   for(const auto& e: roster) {
      cout << e.print(); cout << endl;
   }
   
   
}

