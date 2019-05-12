#include <sstream>
#include "PrivateOffice.h"

PrivateOffice::PrivateOffice(std::string number, std::string building,
                     float coffee) :
    Room(number, building), coffee(coffee)
{
}

std::string PrivateOffice::getInfo()
{
    std::stringstream ss;
    std::string freeCoffee = coffee ? "with free coffee " : "";
    ss << "PrivateOffice " << freeCoffee;
    ss << "located in " << building << ", room number " << number;
    ss << "." << std::endl;

    return ss.str();
}
