// implementation of carFactory -- Modified by Elijah Rogers


#include <array>
#include <cstdlib>
#include "CarFactory.hpp"


// product methods

Ford::Ford(){
   make_ = "Ford";
   model_ = fordModels[rand() % fordModels.size()];
}


Toyota::Toyota(){
   make_ = "Toyota";
   model_ = toyModels[rand() % toyModels.size()];
}


// factory methods
Car* CarFactory::requestCar() {
	++numCarsInProduction_;
	return makeCar();
}

Car* FordFactory::makeCar() {
	return new Ford();
}

Car* ToyotaFactory::makeCar() {
	return new Toyota();
}