// selecting oranges
// converting vectors to multimaps
// Mikhail Nesterenko
// 9/26/2022


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout; using std::endl;
using std::string; using std::multimap;
using std::vector;

enum class Variety {orange, pear, apple};
vector<string> colors = {"red", "green", "yellow"};

struct Fruit{
   Variety v;
   string color; // red, green or orange
};


int main(){
    srand(time(nullptr));
    multimap <Variety, string> tree;
    int randomSize = (rand()%100+1);

    // random fruit and color selection
    for(int i = 0; i < randomSize; ++i){
        tree.emplace(static_cast<Variety>(rand() % 3),colors[rand()%3]);
    }


    // printing colors of oranges
    cout << "Colors of the oranges: ";
    for(auto i = tree.lower_bound(Variety::orange); i != tree.upper_bound(Variety::orange); ++i)
        cout << i->second << endl;
}
