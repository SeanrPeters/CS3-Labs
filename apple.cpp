#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;

struct Apples {
        double weight; // oz
        string color;  // red or green
        void print() const { cout << color << ", " << weight << endl; }
};


int main() {
        srand(time(nullptr));
        const double minWeight = 8.;
        const double maxWeight = 3.;

        cout << "Input crate size: ";
        int size;
        cin >> size;

        vector <Apples> crate(size);

        // assign random weight and color to apples in the crate
        // replace with generate()

        std::generate(crate.begin(), crate.end(), [=]() {Apples apple1; apple1.weight = minW$
        apple1.color = rand() % 2 == 1 ? "green" : "red"; return apple1; });


        cout << "Enter weight to find: ";
        double toFind;
        cin >> toFind;
        // count_if()

        int cnt = std::count_if(crate.begin(), crate.end(), [=](Apples theApples)
                {             //count_if if the weight is greater than the input
                return theApples.weight > toFind;});

        cout << "There are " << cnt << " apples heavier than "
                << toFind << " oz" << endl;


        // find_if()
        cout << "at positions ";
         auto it=crate.begin();
   do
   {
   it=std::find_if(++it, crate.end(), [=](Apples apple1)
           {return apple1.weight > toFind;});
   if(it == crate.end()) break;
   cout << it - crate.begin() << ", ";
   }
   while(it != crate.end());
   cout << endl;


        // max_element()
        auto theMax = std::max_element(crate.begin(), crate.end(),
                [=](Apples apple1, Apples apple2)
                {     // returns an iterator to the position of the heaviest object
                return apple1.weight < apple2.weight;});

        cout << "Heaviest apple weights:" << theMax->weight << "oz" << endl;




        // for_each() or accumulate()
        double sum = 0;             // intial value

        auto theTotal = std::accumulate(crate.begin(), crate.end(), sum,
                [=](double apple1, Apples apple2)
                {  // returns the total weight into double total

                return apple1 + apple2.weight;});
   cout << "Total apple weight is: " << theTotal << " oz" << endl;

        //transform()
        cout << "How much should they grow: ";
        double toGrow;
        cin >> toGrow;
        std::transform(crate.begin(), crate.end(), crate.begin(), [=](Apples theApple)->Appl$
                {           //transforms the weight of the apples and inserts back into crate
                theApple.weight = theApple.weight + toGrow;
                return theApple;
                });



        // remove_if()
        cout << "Input minimum acceptable weight: ";
        double minAccept;
        cin >> minAccept;

        crate.erase(std::remove_if (crate.begin(), crate.end(), [=](Apples theApple)
                {
                return theApple.weight < minAccept;}), crate.end());

        cout << "removed " << size - crate.size() << " elements" << endl;



        // bubble sort, replace with sort()
        std::sort(crate.begin(), crate.end(), [=](Apples apple1, Apples apple2)
                {
                return apple1.weight < apple2.weight;});

        deque<Apples> thePeck;
        crate.erase(std::remove_if(crate.begin(), crate.end(), [=](Apples theApple)
                {
                return theApple.color == "red";}), crate.end());

        std::remove_copy_if(crate.begin(), crate.end(), std::front_inserter(thePeck), [=](Ap$
                {
                return theApple.color != "red";});

        // for_each() possibly
        cout << "the apples in the crate " << endl;
 std::for_each(crate.begin(), crate.end(), [=](Apples theApple)
                {
                theApple.print();});
        cout << endl;

        // for_each() possibly
        cout << "sorted remaining apples " << endl;std::for_each(thePeck.begin(),
                thePeck.end(), [=](Apples theApple)
                {
                theApple.print();});
        cout << endl;


        // for_each() possibly
        cout << "all appleas" << endl;
        for (const auto& e : crate)
        {
                e.print();
        }


