#include <map>
#include <string>
#include <ostream>
#include <list>
using std::string;
using std::shared_ptr;
using std::map;
// Data
class Data
{
public:
    virtual std::ostream &output(std::ostream &out) const;
    friend std::ostream &operator<<(std::ostream &out, Data const &data);
};

// String
class StringObj : public Data
{
public:
    StringObj(const std::string &value);
    std::string getValue() const;
    std::ostream &output(std::ostream &out) const override;
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
    MapObj(map<string, shared_ptr<Data>> value);
    map<string, shared_ptr<Data>> getValue() const;

private:
    map<string, shared_ptr<Data>> value;
};

// List
class ListObj : public Data
{
public:
    ListObj(const std::list<Data> &value);
    std::list<Data> getValue() const;

private:
    std::list<Data> value;
};
