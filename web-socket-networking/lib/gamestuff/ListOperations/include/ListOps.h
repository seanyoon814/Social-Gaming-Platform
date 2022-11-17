//
// Created by Sarah on 2022-10-10.
//

//
// Created by Sarah on 2022-10-10.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include "Data.h"

using std::string;
using std::vector;
using std::ostream;
using std::shared_ptr;
using std::vector;






class Rules{
public:
    virtual void runRule() = 0;
};


using dataVector = VectorObj;
using dataMap = MapObj;


class ListExtend : virtual Rules {
public:
    ListExtend(dataVector &target, dataVector& list);
    ListExtend(dataVector &target, dataMap& list);
    ListExtend(dataMap &target, dataMap& list);
    void runRule() override;
private:
    dataVector* listVector = nullptr;
    dataVector* targetVector = nullptr;
    dataMap * listMap = nullptr;
    dataMap* targetMap = nullptr;
};

class ListReverse : virtual Rules {
public:
    ListReverse(dataVector& list);
    ListReverse(dataMap& map);

    void runRule() override;
private:
    dataVector* list = nullptr;
    dataMap* map = nullptr;
};

class ListShuffle : virtual Rules {
public:
    ListShuffle(dataVector& datavctr);
    void runRule() override;
private:
    dataVector* datavctr = nullptr;
};


class ListSort : virtual Rules {
public:
    ListSort(dataVector & vctr);
    ListSort(dataVector & vctr, string  key);
    void runRule() override;
private:
    dataVector* vctr = nullptr;
    bool hasKey = false;
    string key;
};

class ListDeal : virtual Rules {
public:
    ListDeal(dataVector& list, dataVector& to, int ct);
    void runRule();
private:
    dataVector* datavctr = nullptr;
    dataVector* toDatavctr = nullptr;
    int count;
};

class ListDiscard : virtual Rules {
public:
    ListDiscard(dataVector& list,int ct);
    void runRule();
private:
    dataVector* list = nullptr;
    int count;
};






//////TODO: for deal and discard, how do you access the variable list if the parameter from and to is a "variable name"
////
//// from and to are both lists, so when the discard keyword is called we know that from and to will be lists.
//// In the JSON file rules handler, we will call functions according to their respective names
////
////template <typename T>
////class ListDeal : virtual Rules {
////    ListDeal(const std::string& from, const std::string& to, const int& count, dataVectorContainer list);
////    void runRule();
////private:
////    const string from;
////    const string to;
////    const int count;
////    dataVectorContainer list;
////};
////
////template <typename T>
////class ListDiscard : virtual Rules {
////    ListDiscard(const std::string& from, const int& count);
////    void runRule();
////private:
////    const string from;
////    const string to;
////    const int count;
////    dataVectorContainer list;
////};
//
//
//template <typename T>
//ostream& operator<<(ostream& out, const vector<shared_ptr<T>>& vectors){
//    for(const auto& vector : vectors){
//        out << *vector  << std::endl;
//    }
//    return out;
//}
//
//template <typename T>
//ostream& operator<<(ostream& out, const vector<vector<shared_ptr<T>>> & vectors){
//for(const auto& vector : vectors){
//out << vector << std::endl;
//}
//return out;
//}