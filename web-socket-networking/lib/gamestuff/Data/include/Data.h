#include <string>
#include <ostream>
#include <list>
#include <vector>
#include <unordered_map>

using std::string;
using std::shared_ptr;
using std::unordered_map;
// Data
class Data
{
public:
    virtual void* getValue() = 0;
//    virtual std::ostream &output(std::ostream &out) const;
//    friend std::ostream &operator<<(std::ostream &out, Data const &data);
private:
};

// String
class StringObj : public Data
{
public:
    StringObj(const std::string &value);
    std::string getValue() const;
//    std::ostream &output(std::ostream &out) const override;
    //     bool comparator()
private:
    std::string value;
};

// Integer
class IntObj : public Data
{
public:
    IntObj(const int &value);
    int getValue() const;
    // std::ostream &output(std::ostream &out) const override;

private:
    int value;
};

// Float
class FloatObj : public Data
{
public:
    FloatObj(const float &value);
    float getValue() const;
    // std::ostream &output(std::ostream &out) const override;

private:
    float value;
};

// Boolean
class BoolObj : public Data
{
public:
    BoolObj(const bool &value);
    bool getValue() const;
    // std::ostream &output(std::ostream &out) const override;

private:
    bool value;
};

// Map
class MapObj : public Data
{
public:
    MapObj() = default;
    MapObj(unordered_map<string, shared_ptr<Data>> value);
    unordered_map<string, shared_ptr<Data>> getValue() const;

//private:
    unordered_map<string, shared_ptr<Data>> value;
};

// List
class VectorObj : public Data
{
public:
    VectorObj() = default;
    VectorObj(std::vector<shared_ptr<Data>> value);
    std::vector<shared_ptr<Data>> getValue() const;

//private:
    std::vector<shared_ptr<Data>> value;
};
