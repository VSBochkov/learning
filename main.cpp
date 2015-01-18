#include    "data.h"

int main() {
    Data_factory<std::string, Data> factory;
    std::string keyDouble("Data");
    std::string keyInt("Data");
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
