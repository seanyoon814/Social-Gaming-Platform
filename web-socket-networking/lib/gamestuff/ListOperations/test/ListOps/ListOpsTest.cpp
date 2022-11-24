#include <gtest/gtest.h>
#include "ListOps.h"
//#include "Data.h"

#include <memory>
#include <iostream>
#include <vector>

using std::vector;
using std::make_shared;
using std::shared_ptr;
using std::cout;



TEST(assertExtend,extendList){
    dataVector winners;
    unordered_map<string, shared_ptr<Data>> player{{"name", make_shared<StringObj>("Sarah")},
                                                    {"weapon", make_shared<StringObj>("Macemaker")}};
    dataMap playerMap(player);
    vector<shared_ptr<Data>> vctr{make_shared<MapObj>(playerMap)};
    VectorObj vctrObj(vctr);
    ListExtend(winners, vctrObj).runRule();
    EXPECT_EQ(winners.getValue(),vctrObj.getValue());

}

TEST(assertExtend, extendMap){
    dataMap nameValue{unordered_map<string, shared_ptr<Data>>{{"name", make_shared<StringObj>("Sarah")}}};
    dataMap weaponValue{unordered_map<string,shared_ptr<Data>>{{"weapon", make_shared<StringObj>("Macemaker")}}};
    dataMap completeMap{unordered_map<string, shared_ptr<Data>> {{"name", make_shared<StringObj>("Sarah")},
                                                                 {"weapon", make_shared<StringObj>("Macemaker")}}};

    ListExtend(nameValue, weaponValue).runRule();
    EXPECT_EQ(nameValue.getValue(), completeMap.getValue());
}

TEST(assertReverse, reverseList){
    dataVector vectorExpected{{{make_shared<StringObj>("Hello")},
                                      {make_shared<StringObj>("World")}}};
    dataVector vectorTest{{{make_shared<StringObj>("World")},{make_shared<StringObj>("World")}}};
    ListReverse(vectorTest).runRule();

    EXPECT_EQ(vectorExpected.getValue(), vectorTest.getValue());


}

TEST(assertShuffle, shuffleList){
    dataVector vectorShuffled{{{make_shared<StringObj>("World")},{make_shared<StringObj>("World")}}};
    dataVector const vectorNotShuffled = vectorShuffled;
    ListShuffle(vectorShuffled).runRule();

    EXPECT_TRUE(vectorShuffled.getValue() != vectorNotShuffled.getValue());
}
TEST(assertSort, sortSimpleList){
    dataVector vectorExpected{
        {make_shared<IntObj>(1),make_shared<IntObj>(2),make_shared<IntObj>(3)}
    };
    dataVector vectorResult{
            {make_shared<IntObj>(2),make_shared<IntObj>(1),make_shared<IntObj>(3)}
    };
    ListSort(vectorResult).runRule();

    EXPECT_TRUE(vectorExpected.getValue() != vectorResult.getValue());
}

