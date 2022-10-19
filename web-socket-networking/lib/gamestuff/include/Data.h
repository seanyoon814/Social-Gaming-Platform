#include <map>
#include <string>
#include <ostream>
#include <list>

// Data
class Data
{
public:
    // virtual std::ostream &output(std::ostream &out) const;
    // friend std::ostream &operator<<(std::ostream &out, Data const &data);
};

// String
class StringObj : public Data
{
public:
    StringObj(const std::string &value);
    std::string getValue() const;
    // std::ostream &output(std::ostream &out) const override;
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
    MapObj(const std::map<Data, Data> &value);
    std::map<Data, Data> getValue() const;

private:
    std::map<Data, Data> value;
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