//
// Created by Sarah on 2022-10-10.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Data{
    std::string name;
    data(const std::string& name);
    virtual ~data();
};

class TestObj : public Data{
    TestObj(const std::string& name, const std::string& value);
private:
    std::string value;
};

class Rules{
public:
    virtual void runRule() = 0;
};

using dataVectorSharedPtr = std::shared_ptr<vector<std::shared_ptr<Data>>>;
template <type T> using TVectorSharedPtr = std::shared_ptr<std::vector<T>>;

template <type T>
class ListExtend : virtual Rules {
public:
    ListExtend(dataVectorSharedPtr<T> target, const TVectorSharedPtr<T> list);
    void runRule();
private:
    dataVectorSharedPtr target;
    TVectorSharedPtr<T> list;
};

template <type T>
class ListReverse : virtual Rules {
    ListReverse(TVectorSharedPtr<T> list);
    void runRule();
private:
    TVectorSharedPtr<T> list;
};

template <type T>
class ListShuffle : virtual Rules {
    ListShuffle(const TVectorSharedPtr<T> list);
    void runRule();
private:
    TVectorSharedPtr<T> list;
};

template <type T>
class ListSort : virtual Rules {
    ListSort(TVectorSharedPtr<T> list);
    ListSort(TVectorSharedPtr<T> list, T key);
    void runRule();
private:
    TVectorSharedPtr<T> list;
    T key;
};

//TODO: for deal and discard, how do you access the variable list if the parameter from and to is a "variable name"

template <type T>
class ListDeal : virtual Rules {
    ListDeal(const std::string& from, const std::string& to, const int& count, TVectorSharedPtr<T> list);
    void runRule();
private:
    const string from;
    const string to;
    const int count;
    TVectorSharedPtr<T> list;
};

template <type T>
class ListDiscard : virtual Rules {
    ListDiscard(const std::string& from, const int& count);
    void runRule();
private:
    const string from;
    const string to;
    const int count;
    TVectorSharedPtr<T> list;
};