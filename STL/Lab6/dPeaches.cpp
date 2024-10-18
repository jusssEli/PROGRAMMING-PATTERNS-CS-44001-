// jamming peaches
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 9/30/2021

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;

struct Peaches {
    double weight; // oz
    bool ripe;     // ripe or not
    void print() const { cout << (ripe ? "ripe" : "green") << ", " << weight << " oz" << endl; }
};

int main() {
   srand(static_cast<unsigned int>(time(nullptr)));
   const double minWeight = 3.0;
   const double maxWeight = 8.0;

   cout << "Input basket size: ";
   int size;
   cin >> size;

   vector<Peaches> basket(size);
   
   // Assign random weight and ripeness to peaches in the basket
   generate(basket.begin(), basket.end(), [&]() {
      return Peaches{ minWeight + static_cast<double>(rand()) / RAND_MAX * (maxWeight - minWeight), rand() % 2 == 0};
   });

   cout << "All peaches:" << endl;
   for_each(basket.cbegin(), basket.cend(), [](const auto& peach) { peach.print(); });

   // Move all ripe peaches from basket to peck
   deque<Peaches> peck;
   for (auto it = basket.begin(); it != basket.end(); ) {
      if (it->ripe) {
         peck.push_back(std::move(*it));
         it = basket.erase(it); // Erase the peach and update iterator
      } else {
         ++it; // Move to the next peach
      }
   }

   cout << "Peaches remaining in the basket:" << endl;
   for_each(basket.cbegin(), basket.cend(), [](const auto& peach) { peach.print(); });
   cout << endl;

   cout << "Peaches moved to the peck:" << endl;
   for_each(peck.cbegin(), peck.cend(), [](const auto& peach) { peach.print(); });

   // Print every 3rd peach in the peck
   const int space = 3; 
   cout << "\nEvery " << space << "'d peach in the peck:" << endl;

   for (auto it = peck.cbegin(); it != peck.cend(); advance(it, space)) {
      if (distance(peck.cbegin(), it) < peck.size()) {
         it->print();
      }
   }
   std::cerr << "Coding sucks" << endl;

   // Putting all small ripe peaches in a jam
   const double weightToJam = 10.0;
   double jamWeight = 0.0;
   
   // Use remove_if to filter out small ripe peaches and accumulate their weight
   auto new_end = remove_if(peck.begin(), peck.end(), [&](Peaches& peach) {
      if (peach.weight < weightToJam) {
         jamWeight += peach.weight;
         return true;
      }
      return false;
   });

   peck.erase(new_end, peck.end());

   cout << "Weight of jam is: " << jamWeight << " oz" << endl;
}