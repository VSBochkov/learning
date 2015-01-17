#ifndef     __DATA_H
#define     __DATA_H

#include    <map>
#include    <string>
#include    <vector>


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

class Factory_interface
{
public:
    virtual Data* create() const = 0;
};

template<class T> class Factory_impl : public Factory_interface
{
public:
    Data* create() const {
        return new T();
    }
};

class Data_factory
{
protected:
    typedef std::map<std::string, Factory_interface*> FactoryMap;
    FactoryMap factory;
public:
    Data_factory();
    virtual ~Data_factory();
    template<class Type> void add(std::string &key) {
        std::map<std::string, Factory_interface*>::iterator it = factory.find(key);
        if(it == factory.end()) {
            factory[key] = new Factory_impl<Type>();
        }
    }
    Data* create_(std::string &key);
};

#endif
