#include    "data.h"
#include    "data_structs.h"

int main() {
    Data_factory<Enum_Types, Data> factory;
    Enum_Types keyDouble = ArrayDoubleType;
    Enum_Types keyInt = ArrayIntType;
    factory.add<ArrayDouble>(keyDouble);
    factory.add<ArrayInt>(keyInt);
    Data* ArrInt = factory.create_(keyInt);
    Data* ArrDb = factory.create_(keyDouble);
    ArrInt->print();
    ArrDb->print();
    delete ArrInt;
    delete ArrDb;
    return 0;
}
