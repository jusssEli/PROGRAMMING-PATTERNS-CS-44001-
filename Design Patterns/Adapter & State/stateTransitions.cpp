// demonstrates state design pattern

#include <iostream>
#include <string>
#include <queue>
using std::cin; using std::cout; using std::endl; using std::string; using std::queue;

class State;
int currentProcess = 0;
// context
class Process{
public:
   Process();

   // behaviors
   void dispatch();
   void suspend();
   void block();
   void unblock();
   int getID(){return ID;};
   Process* newProcess();
   string report();

   // part of implementation of state pattern
   void changeState(State* state){state_=state;}
private:
   State* state_;
   int ID;
};


// absract state
class State{
public:
   // provides default implementation
    virtual void dispatch(Process*){};
    virtual void suspend(Process*){};
    virtual void block(Process*){};
    virtual void unblock(Process*){};
    virtual string report() =0;
    void changeState(Process* c, State* s){
    c->changeState(s);
   }
};

class Ready: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Ready;
      return onlyInstance;
   }
   virtual void dispatch(Process*) override;
   string report() override {return " is ready";}
private:
   // here and elsewhere should be stated private constructor/assignment
   // to correctly implement singleton, skipped to simplify code
};
Process::Process(){
    changeState(Ready::instance());
    ID = currentProcess;
    ++currentProcess;
}

class Running: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Running;
      return onlyInstance;
   }
   virtual void suspend(Process*)override;
   virtual void block(Process*)override;
   string report() override {return " is running";}
};


class Blocked: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Blocked;
      return onlyInstance;
   }
   virtual void unblock(Process*)override;
   string report() override {return " is blocked";}
};





// state transitions member functions
// Ready
Process* Process::newProcess(){                                                     //too much green and yellow fk the packers
    return new Process();
}
void Ready::dispatch(Process *c){
    changeState(c, Running::instance());
}
void Running::suspend(Process *c){
    changeState(c, Ready::instance());
}
void Running::block(Process *c){
    changeState(c, Blocked::instance());
}
void Blocked::unblock(Process *c){
    changeState(c, Ready::instance());
}

// handles/behaviors
void Process::dispatch(){state_->dispatch(this);}
void Process::suspend(){state_->suspend(this);}
void Process::block(){state_->block(this);}
void Process::unblock(){state_->unblock(this);}
string Process::report(){return state_->report();}

int main(){
    srand(time(nullptr));
    queue<Process*> ready;
    queue<Process*> blocked;
    Process p1; //original
    //clones and filling queues
    ready.push(p1.newProcess());
    ready.push(p1.newProcess());
    ready.push(p1.newProcess());
    ready.push(p1.newProcess());
    while(!ready.empty() || !blocked.empty()){
        ready.front()->changeState(Running::instance());
        cout << "Running " << ready.front()->getID() << endl;
        int possi = rand()%3;
        if (possi == 0){
            //exit
            cout << "A process has exited " << ready.front()->getID() <<endl;
            ready.pop();
        }
        else if (possi == 1){
            //suspension
            cout << "Suspending " << ready.front()->getID() << endl;
            ready.front()->suspend();
            ready.push(ready.front());
            cout << "moved to back " << ready.front()->getID() << std::endl;
            ready.pop();
        }
        else if (possi == 2){
            //blocking
            cout << "Blocking " << ready.front()->getID() << endl;
            ready.front()->block();
            blocked.push(ready.front());
            ready.pop();
        }
        if(!blocked.empty()){
            int rnd = rand()%2;
            if(rnd == 0){
                ready.push(blocked.front());
                cout << "Process Unblocked " << blocked.front()->getID() << endl;
                blocked.pop();
            }
        }   
        
    }
    cout << "ALL PROCESSES ARE GONE AHAHAHAHAHAHAH!!!!!!" << endl;
   
}
