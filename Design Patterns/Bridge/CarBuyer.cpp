// needed for lab -- Modified by Elijah Rogers


//goal of lab-- customer select company -- randomly select model to test drive

#include <iostream>
#include <vector>
#include <cstdlib>
#include "CarFactory.hpp"
#include <vector>
using std::cout; using std::endl; using std::vector;

class CarLot{
public:
   CarLot();
   // Car *testDriveCar(){return carsInLot[0];}

   // if a car is bought, requests a new one
   Car *buyCar(){ 
      Car *bought = carsInLot[nxt];
      carsInLot[nxt] = 
        factories_[rand()%factories_.size()]->requestCar();
      return bought;
   }
   Car* nextCar(){
      //return the index of the car bought in the vector
      ++nxt;
      nxt = nxt % lotSize();
      return carsInLot[nxt];
   };
   int lotSize(){ return maxLotSize; }
		     
private:
   const static int maxLotSize = 8;
   int nxt = 0;
   Car* carsInLot[maxLotSize]; // array of cars to allow multiple cars to be sold
   vector<CarFactory *> factories_; // allows for multiple factories with the vector
};


CarLot::CarLot(){
   // creates 2 Ford factories and 2 Toyota factories 
   factories_.push_back(new FordFactory());   
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   // gets the first car for sale
   for(int i = 0; i < maxLotSize; ++i)
      carsInLot[i] = factories_[rand() % factories_.size()] -> requestCar();
}



CarLot *carLotPtr = nullptr; // global pointer instantiation

// test-drives a car
// buys it if Toyota -- 
void toyotaLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();
   std::string fav = toyModels[rand()%toyModels.size()]; //said like a white girl
   for(int i = 0; i < carLotPtr -> lotSize(); ++i){
      Car *toBuy = carLotPtr -> nextCar();
      cout << "Test Dummy " << id << endl;
      cout << " test driving "
      << toBuy->getMake() << " "
         << toBuy->getModel();
      if (toBuy->getMake() == "Toyota" && toBuy->getModel() == fav){                         //toBuy->getMake() == "Ford"
         cout << " love it! buying it!" << endl; //<-- my question lies here as to how to determine if a customer liked it
         carLotPtr -> buyCar();
         break;
      } else{
         cout << " did not like it!" << endl;
      }
   }
    
}

// test-drives a car
// buys it if Ford
void fordLover(int id){
   //for(size_t i = 0; i < maxLotSize; ++i){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();
   std::string fav = fordModels[rand() % fordModels.size()]; //said like a white girl
   for(int i = 0; i < carLotPtr -> lotSize(); ++i){
      Car *toBuy = carLotPtr -> nextCar();
      cout << "Test Dummy " << id << endl;
      cout << " test driving "
      << toBuy->getMake() << " "
         << toBuy->getModel();
      if (toBuy->getMake() == "Ford" && toBuy->getModel() == fav){                         //toBuy->getMake() == "Ford"
         cout << " love it! buying it!" << endl; //<-- my question lies here as to how to determine if a customer liked it
         carLotPtr -> buyCar();
         break;
      } else{
         cout << " did not like it!" << endl;
      }
   }
}



int main() {
   srand(time(nullptr));

   const int numBuyers=20;
   for(int i=0; i < numBuyers; ++i)
      if(rand()% 2 == 0)
	 toyotaLover(i);
      else
	 fordLover(i);
  
}