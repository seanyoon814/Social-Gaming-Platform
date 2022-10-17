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

template<typename T>
ListSort<T>::ListSort(vectorsData& list):list(&list) {
    runRule();
}
template<typename T>
ListSort<T>::ListSort(dataVector & datavctr):datavctr(&datavctr){
    runRule();
}
//template<typename T>
//ListSort<T>::ListSort(vectorsData& list, T key):list(&list),key(key),hasKey(true){
//    runRule();
//}
//template<typename T>
//ListSort<T>::ListSort(dataVector & datavctr, T key):datavctr(&datavctr),key(key),hasKey(true){
//    runRule();
//}

//template<typename T>
//void ListSort<T>::runRule() {
//    if(datavctr && !hasKey){
//        std::sort(datavctr->begin(), dataVector->end())
//    }
//}