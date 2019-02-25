#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../LaboratoryWork_1/List.h"
using namespace std;

int main(int argc, char* argv[]) {

    List<char> lstChar;

    cout <<"\n~~~~~Char~~~~~";
    lstChar.push_back('M');
    lstChar.push_back('a');
    lstChar.push_back('s');
    lstChar.push_back('h');
    lstChar.push_back('a');

    cout << "\n\nOriginal version:\n";
    cout << lstChar;
    cout << "\n\nNow using the remove i del item #2\n";
    lstChar.remove(1);
    cout << "\nNew version: \n";
    cout << lstChar;


    List<int> lstOfInt;

    lstOfInt.push_back(7);
    lstOfInt.push_back(3);
    lstOfInt.push_back(0);
    lstOfInt.push_back(2);

    cout <<"\n\n~~~~~Int~~~~~";
    cout << "\n\nOriginal version: \n";
    cout << lstOfInt;
    cout << "\n\nNow using the remove i del item #2\n";
    lstOfInt.remove(1);
    cout << "\nNew version: ";
    cout << lstOfInt;

    lstChar.clear();
    lstOfInt.clear();

   /*
    testing::InitGoogleTest(&argc, argv);
    int b = RUN_ALL_TESTS();
    */
    return 0;
}