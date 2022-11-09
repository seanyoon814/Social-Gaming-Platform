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



ListExtend::ListExtend(dataVector &target, dataVector& list)
{this->targetVector = &target; this->listVector = &list;}
ListExtend::ListExtend(dataMap &target, dataMap& list)
{this->targetMap = &target; this->listMap = &list;}

void ListExtend::runRule(){
    if(listVector && targetVector)
        targetVector->get()->insert(
                targetVector->get()->end(),
                listVector->get()->begin(),
                listVector->get()->end()
        );
    else if(listMap && targetMap)targetMap->get()->insert(listMap->get()->begin(),listMap->get()->end());
}


ListReverse::ListReverse(dataVector& list): list(&list) {}
ListReverse::ListReverse(dataMap& map): map(&map) {}
void ListReverse::runRule(){
//    if(map)std::reverse(map->get()->begin(),map->get()->end());
    if(list)std::reverse(list->get()->begin(), list->get()->end());
}


ListShuffle::ListShuffle(dataVector & datavctr) :datavctr(&datavctr) {}
void ListShuffle::runRule(){

    if(datavctr)std::shuffle(datavctr->get()->begin(),datavctr->get()->end(),std::random_device());
}


ListSort::ListSort(dataVector & vctr):vctr(&vctr){};
ListSort::ListSort(dataVector & vctr, string key):vctr(&vctr),key(std::move(key)),hasKey(false){};

bool mapComparator(dataMap& map1, dataMap& map2, const string& key){
    if(map1.get()->at(key) <= map2.get()->at(key)){
        return true;
    }
    return false;
}

void ListSort::runRule(){
  if(vctr && !hasKey)std::sort(vctr->get()->begin(),vctr->get()->end());
  else if(vctr && hasKey){
      const std::type_info& type = typeid(dataMap);
      bool allMap = true;
      for(const auto& ele : *vctr->get()){
          if(typeid(ele) != type){
              allMap = false;
              std::cout<<"Not all elements are map!"<<std::endl;
          }
          if(allMap){
              const string sortKey = this->key;
              std::sort(vctr->get()->begin(),
                        vctr->get()->end(),
                        [this](dataMap& map1, dataMap& map2){return mapComparator(map1,map2,key);});
          }
      }
  }
}

ListDeal::ListDeal(dataVectorContainer& list, dataVectorContainer& to, int ct) :list(&list), toList(&to),count(ct) {runRule();}
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
        //std::copy_n(list->begin(), count, toDatavctr->begin());
        //toDatavctr->resize(count);
        for(int i = 0; i < count; i ++) {
            //toDatavctr->push_back(list[i]);
        }
    }
    // if(list)std::copy_if(list->begin(), list->end(), toList, (count-- != 0));
    // if(list)std::copy_if(list->begin(), list->end(), toDatavctr,(count-- != 0));
}


ListDiscard::ListDiscard(dataVectorContainer& list, int ct) :list(&list), count(ct) {runRule();}
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

