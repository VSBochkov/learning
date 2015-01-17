#include    "data.h"
#include    <iostream>

ArrayInt::ArrayInt(int size) :
    array(size)
{
    std::cout << "construct Array int\n";
}

ArrayDouble::ArrayDouble(int size) :
    array(size)
{
    std::cout << "construct Array double\n";
}

ArrayInt::~ArrayInt()
{
    std::cout << "destruct Array int\n";
}

ArrayDouble::~ArrayDouble()
{
    std::cout << "destruct Array double\n";
}


void ArrayInt::print() const
{
    std::cout << "Array int\n";
    for(int i = 0; i < array.size(); i++) {
        std::cout << " " << array[i];
    }
    std::cout << "\n";
}

void ArrayDouble::print() const
{
    std::cout << "Array double\n";
    for(int i = 0; i < array.size(); i++) {
        std::cout << " " << array[i];
    }
    std::cout << "\n";
}

Data* Data_factory::create_(std::string &key) {
    std::map<std::string, Factory_interface*>::iterator it = factory.find(key);
    if(it != factory.end()) {
        return it->second->create();
    }
}

Data_factory::Data_factory() {

}

Data_factory::~Data_factory() {

}
