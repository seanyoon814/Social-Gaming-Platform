#include <gtest/gtest.h>
#include "Arithmetic.h"
TEST(assertArithmetic,add){
    int sumOne = 5 + 5; //Equals 10;
    Add addSystem;
    Vars first{5};

    addSystem.add(first, 5); //should be 10;

    EXPECT_EQ(first.numb, sumOne);
}

TEST(assertArithmetic,numericalNormal){
    int ct = 10; 
    Numerical numba = Numerical(ct);
    std::vector<int> expected{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> result = numba.upfrom(1);
    //ASSERT_TRUE(true);
    EXPECT_EQ(expected, result);
}

TEST(assertArithmetic,numericalEqual){
    int ct = 21; 
    Numerical numba = Numerical(ct);
    std::vector<int> expected{21};
    std::vector<int> result = numba.upfrom(21);
    //ASSERT_TRUE(true);
    EXPECT_EQ(expected, result);
}

TEST(assertArithmetic,numericalBigger){
    int ct = 50; 
    Numerical numba = Numerical(ct);
    std::vector<int> expected{};
    std::vector<int> result = numba.upfrom(51);
    //ASSERT_TRUE(true);
    EXPECT_EQ(expected, result);
}