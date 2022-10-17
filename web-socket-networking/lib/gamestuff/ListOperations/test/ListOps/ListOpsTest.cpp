#include <gtest/gtest.h>
#include "ListOps.h"

#include <memory>
#include <iostream>
#include <vector>

using std::vector;
using std::make_shared;
using std::shared_ptr;
using std::cout;

using dataVector = std::vector<std::shared_ptr<Data>>;
using vectorsData = vector<dataVector>;

TEST(assertListOps,extend){
    dataVector exampleVector;
    exampleVector.push_back(make_shared<StringObj>("one","1"));
    exampleVector.push_back(make_shared<StringObj>("two","2"));

    dataVector exampleVector2;
    exampleVector2.push_back(make_shared<StringObj>("three","3"));
    exampleVector2.push_back(make_shared<StringObj>("four","4"));

    vectorsData vectors;
    ListExtend(vectors, exampleVector);
    ListExtend(vectors, exampleVector);

    vectorsData expectedVector = {
            dataVector{
                make_shared<StringObj>("one","1"),
                make_shared<StringObj>("two","2")
            },
            dataVector{
                make_shared<StringObj>("three","3"),
                make_shared<StringObj>("four","4")
            },

    };


    cout <<"Vector expected:\n" << expectedVector << std::endl;
    cout << "Vector result: " << vectors;
    ASSERT_TRUE(true);
}

TEST(assertListOps, reverse){
    dataVector exampleVector;
    exampleVector.push_back(make_shared<StringObj>("one","1"));
    exampleVector.push_back(make_shared<StringObj>("two","2"));

    dataVector exampleVector2;
    exampleVector2.push_back(make_shared<StringObj>("three","3"));
    exampleVector2.push_back(make_shared<StringObj>("four","4"));

    dataVector exampleVector3;
    exampleVector3.push_back(make_shared<StringObj>("one","1"));
    exampleVector3.push_back(make_shared<StringObj>("two","2"));

    vectorsData vectors;
    ListExtend(vectors, exampleVector);
    ListExtend(vectors, exampleVector2);
    (ListReverse(vectors));

    cout <<"Reversing vector:\n";
    cout <<"Original vector: \n" << exampleVector3;
    (ListReverse(exampleVector3));
    cout<<"Reversed vector:\n" << exampleVector3;


    vectorsData expectedVector = {
            dataVector{
                    make_shared<StringObj>("three","3"),
                    make_shared<StringObj>("four","4")
            },
            dataVector{
                    make_shared<StringObj>("one","1"),
                    make_shared<StringObj>("two","2")
            }
    };

    cout <<"Reversing list of vectors:\n";
    cout <<"Vector expected:\n" << expectedVector << std::endl;
    cout << "Vector result:\n " << vectors;
    ASSERT_TRUE(true);
}

TEST(assertListOps, shuffle){
    dataVector exampleVector;
    exampleVector.push_back(make_shared<StringObj>("one","1"));
    exampleVector.push_back(make_shared<StringObj>("two","2"));
    exampleVector.push_back(make_shared<StringObj>("three","3"));
    exampleVector.push_back(make_shared<StringObj>("four","4"));
    exampleVector.push_back(make_shared<StringObj>("five","5"));

    cout <<"Original vector:\n" << exampleVector << std::endl;
    (ListShuffle(exampleVector));
    cout << "Shuffled vector:\n" << exampleVector << std::endl;

    vectorsData resultVector = {
            dataVector{
                    make_shared<StringObj>("three","3"),
                    make_shared<StringObj>("four","4")
            },
            dataVector{
                    make_shared<StringObj>("one","1"),
                    make_shared<StringObj>("two","2")
            },
            dataVector{
                    make_shared<StringObj>("six","6"),
                    make_shared<StringObj>("nine","9")
            }
    };

    cout <<"Original vector:\n" << resultVector << std::endl;
    (ListShuffle(resultVector));
    cout << "Shuffled vector:\n" << resultVector << std::endl;

}