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

using std::string;
using std::vector;
using std::ostream;
using std::shared_ptr;



class Data{
public:
    explicit Data(const std::string& name);
    std::string getName() const;
    virtual ostream& output(ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, Data const& data);
private:
    std::string name;
};

class StringObj : public Data{
public:
    StringObj(const std::string& name, const std::string&  value);
    string getValue() const;
    ostream& output(ostream& out) const override;
//     bool comparator()
private:
    std::string value;
};

class IntObj : public Data{
public:
    IntObj(const std::string& name, const int&  value);

private:
    int value;
};


class Rules{
public:
    virtual void runRule() = 0;
};


using dataVector = std::vector<std::shared_ptr<Data>>;
using vectorsData = vector<dataVector>;

class ListExtend : virtual Rules {
public:
    ListExtend(vectorsData& target, const dataVector& list);
    void runRule() override;
private:
    dataVector list;
    vectorsData* target = nullptr;
};

class ListReverse : virtual Rules {
public:
    ListReverse(vectorsData& list);
    ListReverse(dataVector& dataVector);

    void runRule() override;
private:
    vectorsData* list = nullptr;
    dataVector* datavctr = nullptr;
};

class ListShuffle : virtual Rules {
public:
    ListShuffle(vectorsData& list);
    ListShuffle(dataVector& datavctr);
    void runRule();
private:
    vectorsData* list = nullptr;
    dataVector* datavctr = nullptr;
};


template <typename T>
class ListSort : virtual Rules {
public:
    ListSort(vectorsData& list);
    ListSort(dataVector & datavctr);
//    ListSort(vectorsData& list, T key);
//    ListSort(dataVector & datavctr, T key);
    void runRule();
private:
    vectorsData* list = nullptr;
    dataVector* datavctr = nullptr;
    bool hasKey = false;
    T key;
};





////TODO: for deal and discard, how do you access the variable list if the parameter from and to is a "variable name"
//
//template <typename T>
//class ListDeal : virtual Rules {
//    ListDeal(const std::string& from, const std::string& to, const int& count, vectorsData list);
//    void runRule();
//private:
//    const string from;
//    const string to;
//    const int count;
//    vectorsData list;
//};
//
//template <typename T>
//class ListDiscard : virtual Rules {
//    ListDiscard(const std::string& from, const int& count);
//    void runRule();
//private:
//    const string from;
//    const string to;
//    const int count;
//    vectorsData list;
//};


template <typename T>
ostream& operator<<(ostream& out, const vector<shared_ptr<T>>& vectors){
    for(const auto& vector : vectors){
        out << *vector  << std::endl;
    }
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<vector<shared_ptr<T>>> & vectors){
for(const auto& vector : vectors){
out << vector << std::endl;
}
return out;
}