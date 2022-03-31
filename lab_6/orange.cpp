
#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>



using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::multimap;
using std::make_pair;


enum class Variety { orange, pear, apple };
vector<string> colors = { "red", "green", "yellow" };


struct Fruit
{
    Variety v;
    string color; // red, green or orange
};

int main() {
    int theSize = rand() % 100 + 1;
    srand(time(nullptr));
    multimap<Variety, string> theMap;

    cout << "Colors of the oranges: " << "\n";

    for (int i = 0; i < theSize; ++i)
        theMap.emplace(static_cast<Variety>(rand() % 3), colors[rand() % 3]);


    for (auto it = theMap.lower_bound(Variety::orange); it != theMap.upper_bound(Variety::or$
        cout << it -> second << endl;
}
