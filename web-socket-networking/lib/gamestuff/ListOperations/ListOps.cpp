//
// Created by Sarah on 2022-10-10.
//

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include <iterator>

#include "include/ListOps.h"
#include <random>

using std::cout;
using std::endl;
using std::ostream;
using std::shared_ptr;



ListExtend::ListExtend(dataVector &target, dataVector& list)
{this->targetVector = &target; this->listVector = &list;}

ListExtend::ListExtend(dataMap &target, dataMap& map)
{this->targetMap = &target; this->listMap = &map;}

void ListExtend::runRule(){
    if(listVector && targetVector)
        targetVector->value.insert(
                targetVector->value.end(),
                listVector->value.begin(),
                listVector->value.end()
        );
    else if(listMap && targetMap)targetMap->value.insert(listMap->value.begin(),listMap->value.end());
}


ListReverse::ListReverse(dataVector& list): list(&list) {}
void ListReverse::runRule(){
    std::reverse(list->value.begin(), list->value.end());
}


ListShuffle::ListShuffle(dataVector & datavctr) :datavctr(&datavctr) {}
void ListShuffle::runRule(){

    if(datavctr)std::shuffle(datavctr->value.begin(),datavctr->value.end(),std::random_device());
}


ListSort::ListSort(dataVector & vctr):vctr(&vctr){};
ListSort::ListSort(dataVector & vctr, string key):vctr(&vctr),key(std::move(key)),hasKey(true){};

struct mapComparator{
    const string key;
    explicit mapComparator(const string& newKey):key(newKey){};
    bool operator()(const shared_ptr<Data>& map1,const shared_ptr<Data>& map2) const{
        auto map1Ptr = (dataMap*)(map1.get());
        auto map2Ptr = (dataMap*)(map1.get());
        if(map1Ptr->value.at(key) <= map2Ptr->value.at(key)){
            return true;
        }
        return false;
    }

};

void ListSort::runRule(){
  if(hasKey)std::sort(vctr->value.begin(),vctr->value.end(),
[](const shared_ptr<Data>& data1,const shared_ptr<Data>& data2) -> bool{

  });
  else{
      bool allMap = true;
      for(const auto& ele : vctr->value){
          if(typeid(ele) != typeid(dataMap)){
              allMap = false;
              std::cout<<"Not all elements are map!"<<std::endl;
          }
          if(allMap){
              const string sortKey = this->key;
              std::sort(vctr->value.begin(),
                        vctr->value.end(),
                        mapComparator(key));
          }
      }
  }
}


ListDeal::ListDeal(dataVector &list, dataVector &to, int ct):datavctr(&list),toDatavctr(&to) {}

void ListDeal::runRule(){
    std::move(datavctr->value.begin(), datavctr->value.begin()+5, toDatavctr->value.end());
}

ListDiscard::ListDiscard(dataVector &list, int ct):list(&list),count(ct) {}

void ListDiscard::runRule() {
    if(list->value.size() < count){
        cout << "Number of elements requested to be removed is bigger than the container itself!"<<std::endl;
    }
    for (auto i = 0 ; i++; i < count){
        list->value.pop_back();
    }
}
