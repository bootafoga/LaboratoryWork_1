#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../LaboratoryWork_1/List.h"
using namespace std;

int main(int argc, char* argv[]) {


    List<string> lst;


    lst.push_back("str1");
    lst.push_back("str2");
    lst.push_back("str3");
    lst.push_back( "str4");
    lst.push_back("str5");

    cout << endl << "Original version: " << endl << endl;
    cout << lst << endl;

    cout << "Now using the remove i del item #2" << endl << endl;

    lst.remove(2);

    cout << "New version: " << endl << endl;
    cout << lst << endl;


    List<int> lst2;


    lst2.push_back(7);
    lst2.push_back(3);
    lst2.push_back(0);
    lst2.push_back(2);

    cout << endl << "Another list of int:" << endl;
    cout << lst2 << endl;

  /* testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS(); */

    return 0;
}