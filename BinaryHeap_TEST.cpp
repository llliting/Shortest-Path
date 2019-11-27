#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BinaryHeap.hpp"
#include <string>
#include <iostream>

using namespace std;


TEST_CASE("TESTING BinaryHeap Class ")
{

    SECTION("TESTING BinaryHeap")
    {   
        double prio[7] = {9.0, 4.0, 2.0, 3.0, 7.0, 8.0, 2.0};
        BinaryHeap bh = BinaryHeap(prio, 7);
        cout << "items: ";
        for(int i = 0; i < 7; i++){
            cout << bh.items[i] << " ";
        }
        cout << endl;
    }
}