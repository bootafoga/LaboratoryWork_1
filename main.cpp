#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../LaboratoryWork_1/List.h"
using namespace std;

int main(int argc, char* argv[]) {


    List<char> lstChar;

    lstChar.push_back('A');
    lstChar.push_back('B');
    lstChar.push_back('C');
    lstChar.push_front('D');
    lstChar.push_back('E');
    lstChar.push_front('F');
    lstChar.pop_back();
    lstChar.pop_front();
    lstChar.set('S', 2);
    lstChar.remove(0);



    cout <<"\n~~~~~Char~~~~~";
    cout << lstChar;



    List<int> lstOfInt;

    lstOfInt.push_back(1);
    lstOfInt.push_back(2);
    lstOfInt.push_back(3);
    lstOfInt.push_front(4);
    lstOfInt.push_back(5);
    lstOfInt.push_front(6);
    lstOfInt.pop_back();
    lstOfInt.pop_front();
    lstOfInt.set(100, 2);
    lstOfInt.remove(0);

    cout <<"\n\n~~~~~Int~~~~~";
    cout << lstOfInt;

    lstChar.clear();
    lstOfInt.clear();

    // cout << lstOfInt.isEmpty();


   /* testing::InitGoogleTest(&argc, argv);
    int b = RUN_ALL_TESTS(); */

    return 0;
}