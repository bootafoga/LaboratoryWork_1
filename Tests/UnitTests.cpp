//
// Created by Мария on 23.02.2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "List.h"

using testing::Eq;

namespace {
    class ClassDeclaration: public testing::Test{
    public:
        List<int> obj;
        List<double > obj2;
        List<string> obj3;
        ClassDeclaration(){
            obj;
            obj2;
            obj3;
        }
    };
}

TEST_F(ClassDeclaration, PushBack_onInt){
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    ASSERT_EQ(1, obj.At(0));
    ASSERT_EQ(2, obj.At(1));
    ASSERT_EQ(3, obj.At(2));
}

TEST_F(ClassDeclaration, PushFront_onDoub){
    obj2.push_front(1.1);
    obj2.push_front(2.2);
    obj2.push_front(3.3);
    ASSERT_EQ(3.3, obj2.At(0));
    ASSERT_EQ(2.2, obj2.At(1));
    ASSERT_EQ(1.1, obj2.At(2));
}

TEST_F(ClassDeclaration, PopBack_onStr){
    obj3.push_back("str1");
    obj3.push_back("str2");
    obj3.push_back("str3");
    ASSERT_EQ(3, obj3.getSize());
    obj3.pop_back();
    ASSERT_EQ(2, obj3.getSize());

    ASSERT_EQ("str1", obj3.At(0));
    ASSERT_EQ("str2", obj3.At(1));

}

TEST_F(ClassDeclaration, PopFront_onStr){
    obj3.push_back("str1");
    obj3.push_back("str2");
    obj3.push_back("str3");
    ASSERT_EQ(3, obj3.getSize());
    obj3.pop_front();
    ASSERT_EQ(2, obj3.getSize());

    ASSERT_EQ("str2", obj3.At(0));
    ASSERT_EQ("str3", obj3.At(1));

}


TEST_F(ClassDeclaration, Insert_onInt_NegativeArg){
   try {
            obj.insert(-1, -19);
        }
        catch (exception& ex) {
            EXPECT_STREQ("Index must be >= 0", ex.what());
        }
}

TEST_F(ClassDeclaration, Insert_onInt_BiggerThanSizeArg){
    try {
        obj.push_back(1);
        obj.push_back(2);
        obj.push_back(3);
        obj.insert(-1, 10);
    }
    catch (exception& ex) {
        EXPECT_STREQ("Index is larger than size of list", ex.what());
    }
}


TEST_F(ClassDeclaration, Insert_onDoub_NormArg){
    obj2.push_back(1.1);
    obj2.push_back(2.2);
    obj2.insert(3.3, 1);

    ASSERT_EQ(1.1, obj2.At(0));
    ASSERT_EQ(3.3, obj2.At(1));
    ASSERT_EQ(2.2, obj2.At(2));
}