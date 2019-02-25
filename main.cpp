#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../LaboratoryWork_1/List.h"
using namespace std;

int main(int argc, char* argv[]) {

    cout <<"\n~~~~~Char~~~~~";
    List<char> lstChar;

    lstChar.push_back('M');
    lstChar.push_back('a');
    lstChar.push_back('s');
    lstChar.push_back('h');
    lstChar.push_back('a');

    cout << "\n\nOriginal version:\n";
    cout << lstChar;

    cout << "\n\nNow using the set i add a new field to item #4 and using the remove i del item #1\n";

    lstChar.set('k', 3);
    lstChar.remove(0);

    cout << "\nNew version: \n";
    cout << lstChar;

    cout <<"\n\n~~~~~Int~~~~~";
    List<int> lstOfInt;

    lstOfInt.push_back(7);
    lstOfInt.push_back(3);
    lstOfInt.push_back(0);
    lstOfInt.push_back(2);

    cout << "\n\nOriginal version: \n";
    cout << lstOfInt;

    cout << "\n\nNow using the set i add a new field to item #4 and using the remove i del item #1\n";

    lstOfInt.set(7, 3);
    lstOfInt.remove(0);

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