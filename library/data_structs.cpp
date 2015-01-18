#include    <iostream>
#include    "data_structs.h"

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
