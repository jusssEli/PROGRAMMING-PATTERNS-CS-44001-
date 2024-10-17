// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::list;
using std::move;
using std::string;
using std::vector;

class Student
{
public:
   Student(string firstName, string lastName) : firstName_(firstName), lastName_(lastName) {}

   // move constructor, not really needed, generated automatically
   Student(Student &&org) noexcept : firstName_(move(org.firstName_)),
                                     lastName_(move(org.lastName_))
   {
   }

   // force generation of default copy constructor
   Student(const Student &org) = default;
   void print() const
   {
      cout << firstName_ + ' ' + lastName_ << " ";
      for (auto &theClass : courses)
         cout << theClass << ' ';
      cout << endl;
   }
   string getName() const { return firstName_ + ' ' + lastName_; };

   // needed for unique() and for remove()
   friend bool operator==(Student left, Student right)
   {
      return left.lastName_ == right.lastName_ &&
             left.firstName_ == right.firstName_;
   }

   // needed for sort()
   friend bool operator<(Student left, Student right)
   {
      return left.lastName_ < right.lastName_ ||
             (left.lastName_ == right.lastName_ &&
              left.firstName_ < right.firstName_);
   }
   void addClass(string cName)
   {
      courses.push_back(cName);
   }

private:
   string firstName_;
   string lastName_;
   list<string> courses;
};

// reading a list from a fileName
void readRoster(list<Student> &roster, string fileName);
// printing a list out
void printRoster(const list<Student> &roster);

int main(int argc, char *argv[])
{

   if (argc <= 1)
   {
      cout << "usage: " << argv[0]
           << " list of courses, dropouts last" << endl;
      exit(1);
   }
   list<Student> studentEntries;
   for (int i = 1; i < argc; ++i)
   {
      readRoster(studentEntries, argv[i]);
      cout << argv[i] << endl;
   }
   printRoster(studentEntries);
}
void readRoster(list<Student> &roster, string fileName)
{
   ifstream course(fileName);
   string first, last, courseName = fileName.substr(0, fileName.size() - 4); // if class file ends in .txt removes .txt
   bool added = false;
   while (course >> first >> last)
   {
      for (Student &aStudent : roster)
         if (aStudent.getName() == first + " " + last)
         {
            added = true;
            aStudent.addClass(courseName);
         }

      if (!added)
      {
         Student newPerson(first, last);
         newPerson.addClass(courseName);
         roster.push_back(newPerson);
      }
   }
   course.close();
}
// printing a list out
void printRoster(const list<Student> &roster)
{
   for (const auto &aStudent : roster)
      aStudent.print();
}
