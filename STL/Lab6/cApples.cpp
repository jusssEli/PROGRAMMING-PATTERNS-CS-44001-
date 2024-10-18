// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 09/26/2022


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

struct Apples{
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
};



int main(){
   srand(static_cast<unsigned>(time(nullptr)));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector<Apples> crate(size);

   // Assign random weight and color to apples in the crate
   generate(crate.begin(), crate.end(), [&]() {
      Apples apple;
      apple.weight = minWeight + static_cast<double>(rand()) / RAND_MAX * (maxWeight - minWeight);
      apple.color = rand() % 2 == 0 ? "red" : "green";
      return apple;
   });

   // Print all apples
   cout << "All apples:" << endl;
   for (const auto& e : crate) {
      e.print();
   }

   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

   // Count apples heavier than the specified weight
   int cnt = count_if(crate.begin(), crate.end(), [toFind](const Apples& apple) {
      return apple.weight > toFind;
   });
   cout << "There are " << cnt << " apples heavier than " << toFind << " oz" << endl;

   // Print positions of apples heavier than the specified weight
   cout << "At positions: ";
   for (size_t i = 0; i < crate.size(); ++i) {
      if (crate[i].weight > toFind) {
         cout << i << " ";
      }
   }
   cout << endl;

   // Find the heaviest apple
   auto heaviest = std::max_element(crate.begin(), crate.end(), [](const Apples& a, const Apples& b) {
      return a.weight < b.weight;
   });
   cout << "Heaviest apple weighs: " << heaviest->weight << " oz" << endl;

   // Calculate total weight
   double sum = accumulate(crate.begin(), crate.end(), 0.0, [](double total, const Apples& apple) {
      return total + apple.weight;
   });
   cout << "Total apple weight is: " << sum << " oz" << endl;

   // Increase weight of all apples
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;
   std::transform(crate.begin(), crate.end(), crate.begin(), [toGrow](Apples apple) {
      apple.weight += toGrow;
      return apple;
   });

   // Remove apples below minimum acceptable weight
   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;

   crate.erase(std::remove_if(crate.begin(), crate.end(), [minAccept](const Apples& apple) {
      return apple.weight < minAccept;
   }), crate.end());
   cout << "Removed " << size - crate.size() << " elements" << endl;

   // Sort apples by weight
   std::sort(crate.begin(), crate.end(), [](const Apples& a, const Apples& b) {
      return a.weight < b.weight;
   });



// for_each() possibly
cout << "sorted remaining apples"<< endl;
for(const auto &e: crate) {
   e.print();
}

}
