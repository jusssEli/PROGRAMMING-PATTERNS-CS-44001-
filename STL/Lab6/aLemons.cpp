// picking the best quality lemons
// converting vectors to priority queue
// Elijah Rogers
// 9/27/2024


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>

using std::cin; using std::cout; using std::endl;
using std::string; using std::priority_queue;
using std::vector;

struct Lemon {
    double quality;
    friend bool operator<(const Lemon& left, const Lemon& right) {
        return left.quality < right.quality;
    }
};

const int maxBoxSize = 30;
const int highestQuality = 10;

int main() {
    srand(time(nullptr));
    priority_queue <Lemon> box; // box de lemon

    // random quality assingment
    int randSize = rand() % maxBoxSize + 1;
    for (int i = 0; i < randSize; ++i){
        Lemon tmp;
        tmp.quality = static_cast<double>(rand()) / RAND_MAX * highestQuality;
        box.push(tmp);
    }
    cout << "Here are the lemons (best first): ";

    while (!box.empty()) {
        cout << box.top().quality << endl;
        box.pop();
    }
    cout << endl;
}
