#include <sstream>
#include "Surgery.h"

Surgery::Surgery(std::string number, std::string building, 
                         float cleanliness) :
    Room(number, building), cleanliness(cleanliness)
{
}

std::string Surgery::getInfo()
{
    std::stringstream ss;
    ss << "Surgery (cleanliness level: " << cleanliness << ") located";
    ss << " in " << building << ", room number " << number << ".";
    ss << std::endl;

    return ss.str();
}
