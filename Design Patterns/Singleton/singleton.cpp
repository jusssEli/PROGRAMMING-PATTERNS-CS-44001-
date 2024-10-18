// example opening file for appending Modified by Elijah Rogers
// Elijah Rogers

#include <fstream>    
#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::endl; using std::vector; using std::string;
class Logger{
public:
    void report(const string& nextPart){
         
        output << nextPart << std::endl;
    }
    static Logger& instance(){
        static Logger s;
        return s;
    }
    ~Logger(){
        output.close();
    }
private:
    std::ofstream output;
    Logger(){
        output.open("log.txt", std::fstream::out | std::fstream::app); //app == append  <-- code given to us -- needs modified for strings
    };
    Logger(const Logger&){};// protects against client copy
};

int main () {
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time."); 
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");//object doesnt need declared before use -- done in function //Logger variable can also be used but all well
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");
   Logger::instance().report("This is an arbitrary sentence. Stop reading as its a waste of time.");

    //outputs the string within the file
}
