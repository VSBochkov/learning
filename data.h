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

template<class Type> class Factory_interface
{
public:
    virtual ~Factory_interface() {}
    virtual Type* create() const = 0;
};

template<class Type, class DerT>
class Factory_impl : public Factory_interface<Type> {
public:
    Type* create() const {
        return new DerT();
    }
};

template<class KeyType, class Type> class Data_factory
{
protected:
    typedef std::map<KeyType, Factory_interface<Type>*> FactoryMap;
    FactoryMap factory;
public:
    Data_factory() {}
    virtual ~Data_factory() {}
    template<class DeriveT> void add(KeyType &key) {
        typename FactoryMap::iterator it = factory.find(key);
        if(it == factory.end()) {
            factory[key] = new Factory_impl<Type, DeriveT>();
        }
    }
    Type* create_(KeyType &key) {
        typename FactoryMap::iterator it = factory.find(key);
        if(it != factory.end()) {
            return it->second->create();
        }
    }
};

#endif
