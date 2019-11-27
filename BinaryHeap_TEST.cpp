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
        REQUIRE(bh.getMin() == 2);
        REQUIRE(bh.contains(3));
        REQUIRE(!bh.contains(20));
        REQUIRE(bh.getItem(0) == 2);
        bh.popMin();
        REQUIRE(bh.getPriority(0) == 9);
        REQUIRE(bh.getSize() == 6);
        REQUIRE(bh.getPos(0) == 5);
        bh.decreasePriority(0,0);
    
    }
}