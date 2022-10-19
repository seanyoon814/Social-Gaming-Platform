//
// Created by Sarah on 2022-10-10.
//

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <string>


#include "include/ListOps.h"
#include <random>

using std::cout;
using std::endl;
using std::ostream;
using std::shared_ptr;



Data::Data(const string &name) :name(name) {}


string Data::getName() const {
    return name;
}

ostream& Data::output(ostream& out) const{
    return out << "[Name: " << name;
}

std::ostream &operator<<(ostream &out, const Data &data) {
    return data.output(out);
}


StringObj::StringObj(const string &name, const string& value) : Data(name), value(value) {}

string StringObj::getValue() const {
    return value;
}

ostream& StringObj::output(ostream& out) const{
    return Data::output(out)<< "\tValue: " << getValue() << "], ";
}



IntObj::IntObj(const string &name, const int& value) : Data(name), value(value) {}




ListExtend::ListExtend(vectorsData& target, const dataVector& list)
{this->target = &target; this->list = list;runRule();}

void ListExtend::runRule(){
    target->emplace_back(list);
}


ListReverse::ListReverse(vectorsData& list):list(&list){runRule();};

ListReverse::ListReverse(dataVector& datavctr):datavctr(&datavctr) {runRule();}

void ListReverse::runRule(){
    if(list)std::reverse(list->begin(), list->end());
    if(datavctr)std::reverse(datavctr->begin(), datavctr->end());
}

ListShuffle::ListShuffle(vectorsData& list) :list(&list) {runRule();}
ListShuffle::ListShuffle(dataVector & datavctr) :datavctr(&datavctr) {runRule();}


void ListShuffle::runRule(){

    if(list)std::shuffle(list->begin(),list->end(),std::random_device());
    if(datavctr)std::shuffle(datavctr->begin(),datavctr->end(),std::random_device());
}

//template<typename T>
ListSort::ListSort(vectorsData& list):list(&list) {
    runRule();
}
//template<typename T>
ListSort::ListSort(dataVector & datavctr):datavctr(&datavctr){
    runRule();
}
// bool comparatorF (auto objE1, auto objE2) {
//     auto a; 
//     auto b; 
//     a << objE1;
//     b << objE2;
//     return a.getValue() < b.getValue();
// }
void ListSort::runRule(){
    // if(list)std::sort(list->begin(),list->end(), comparatorF());
    // if(datavctr)std::sort(datavctr->begin(),datavctr->end(). comparatorF());
    if(list)std::sort(list->begin(),list->end());
    if(datavctr)std::sort(datavctr->begin(),datavctr->end());
}

// template<typename T>
// ListSort::ListSort(vectorsData& list, T key):list(&list),key(key),hasKey(true){
//    runRule();
// }
// template<typename T>
// ListSort::ListSort<T>(dataVector& datavctr, T key):datavctr(&datavctr),key(key),hasKey(true){
//    runRule();
// }

// template<typename T>
// void ListSort::runRule() {
//    if(datavctr && !hasKey){
//        std::sort(datavctr->begin(), datavctr->end());
//    }
// }
ListDeal::ListDeal(vectorsData& list, vectorsData& to, int ct) :list(&list), toList(&to),count(ct) {runRule();}
ListDeal::ListDeal(dataVector & datavctr, dataVector& to,int ct) :datavctr(&datavctr), toDatavctr(&to),count(ct) {runRule();}


void ListDeal::runRule(){
    if(list) {
        //std::copy_n(list->begin(), count, toList->begin());
        //toList->resize(count);
        for(int i = 0; i < count; i ++) {
            //toList->push_back(list[i]);
        }
    }
    if(datavctr) {
        //std::copy_n(datavctr->begin(), count, toDatavctr->begin());
        //toDatavctr->resize(count);
        for(int i = 0; i < count; i ++) {
            //toDatavctr->push_back(datavctr[i]);
        }
    }
    // if(list)std::copy_if(list->begin(), list->end(), toList, (count-- != 0));
    // if(datavctr)std::copy_if(datavctr->begin(), datavctr->end(), toDatavctr,(count-- != 0));
}


ListDiscard::ListDiscard(vectorsData& list, int ct) :list(&list), count(ct) {runRule();}
ListDiscard::ListDiscard(dataVector & datavctr, int ct) :datavctr(&datavctr), count(ct) {runRule();}


void ListDiscard::runRule(){

    if(list) {
        while(count != 0) {
            list->pop_back();
            count--;
        }
    }
    if(datavctr) {
        while(count != 0) {
            datavctr->pop_back();
            count--;
        }
    }
}

