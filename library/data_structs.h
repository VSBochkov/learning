#ifndef     __DATA_STRUCTS
#define     __DATA_STRUCTS

#include    <vector>

enum Enum_Types
{
    DataType,
    ArrayIntType,
    ArrayDoubleType
};

class Data
{
public:
    virtual void print() const = 0;
    virtual ~Data() {};
};

class ArrayInt : public Data
{
private:
    std::vector<int> array;
public:
    ArrayInt(int size = 0);
    ~ArrayInt();
    void print() const;
};

class ArrayDouble : public Data
{
private:
    std::vector<double> array;
public:
    ArrayDouble(int size = 0);
    ~ArrayDouble();
    void print() const;
};

#endif
