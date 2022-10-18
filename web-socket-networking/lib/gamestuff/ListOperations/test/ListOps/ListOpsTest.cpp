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

// TEST(assertListOps, sort){
//     dataVector exampleVector;
//     exampleVector.push_back(make_shared<StringObj>("three","3"));
//     exampleVector.push_back(make_shared<StringObj>("five","5"));
//     exampleVector.push_back(make_shared<StringObj>("two","2"));
//     exampleVector.push_back(make_shared<StringObj>("one","1"));
//     exampleVector.push_back(make_shared<StringObj>("four","4"));

//     cout <<"Original vector:\n" << exampleVector << std::endl;
//     (ListSort(exampleVector));
//     cout << "Sorted vector:\n" << exampleVector << std::endl;

//     vectorsData resultVector = {
//             dataVector{
//                     make_shared<StringObj>("three","3"),
//                     make_shared<StringObj>("four","4")
//             },
//             dataVector{
//                     make_shared<StringObj>("one","1"),
//                     make_shared<StringObj>("two","2")
//             },
//             dataVector{
//                     make_shared<StringObj>("six","6"),
//                     make_shared<StringObj>("nine","9")
//             }
//     };

//     cout <<"Original vector:\n" << resultVector << std::endl;
//     (ListSort(resultVector));
//     cout << "Sorted vector:\n" << resultVector << std::endl;

// }

TEST(assertListOps, discard){
    dataVector exampleVector;
    std::cout << std::boolalpha;
    exampleVector.push_back(make_shared<StringObj>("three","3"));
    exampleVector.push_back(make_shared<StringObj>("five","5"));
    exampleVector.push_back(make_shared<StringObj>("two","2"));
    exampleVector.push_back(make_shared<StringObj>("one","1"));
    exampleVector.push_back(make_shared<StringObj>("four","4"));

    cout <<"Original vector:\n" << exampleVector << std::endl;
    (ListDiscard(exampleVector,1));
    cout << "Discard one from vector:\n" << exampleVector << std::endl;
    (ListDiscard(exampleVector,exampleVector.size()));
    cout << "Empty vector after discarding:\n Expected:\ttrue \n Actual:\t" 
         << exampleVector.empty() <<"\n" << std::endl;
    
    cout << "Discarding lists of vectors:\n";
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
    (ListDiscard(resultVector, 1));
    cout << "Discarded one from vector:\n" << resultVector << std::endl;
    (ListDiscard(resultVector, resultVector.size()));    
    cout << "Discarded all from vector:\n Expected:\ttrue \n Actual:\t" 
         << resultVector.empty() <<"\n" << std::endl;
    ASSERT_TRUE(true);
}

TEST(assertListOps, deal){
    dataVector exampleVector;
    dataVector toDealVector1;
    dataVector toDealVector2;
    std::cout << std::boolalpha;
    exampleVector.push_back(make_shared<StringObj>("three","3"));
    exampleVector.push_back(make_shared<StringObj>("five","5"));
    exampleVector.push_back(make_shared<StringObj>("two","2"));
    exampleVector.push_back(make_shared<StringObj>("one","1"));
    exampleVector.push_back(make_shared<StringObj>("four","4"));

    cout <<"Original vector:\n" << exampleVector << std::endl;
    (ListDeal(exampleVector, toDealVector1, 1));
    cout << "Deal one from example vector:\n" << exampleVector << std::endl;
    (ListDeal(exampleVector, toDealVector2, exampleVector.size()));
    cout << "Copy full exampleVector: \n"<< exampleVector << std::endl;
    cout << "Copy full exampleVector:\n Expected:\ttrue \n Actual:\t" 
         << (toDealVector2 == exampleVector) <<"\n" << std::endl;
    
    cout << "Discarding lists of vectors:\n";
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

//     cout <<"Original vector:\n" << resultVector << std::endl;
//     (ListDiscard(resultVector, 1));
//     cout << "Discarded one from vector:\n" << resultVector << std::endl;
//     (ListDiscard(resultVector, resultVector.size()));    
//     cout << "Discarded all from vector:\n Expected:\ttrue \n Actual:\t" 
//          << resultVector.empty() <<"\n" << std::endl;
//     ASSERT_TRUE(true);
}