#include <sstream>
#include "HospitalRoom.h"

HospitalRoom::HospitalRoom(std::string number, std::string building, 
                     bool proDevices) :
    Room(number, building), proDevices(proDevices)
{
}

std::string HospitalRoom::getInfo()
{
    std::stringstream ss;
    std::string seats = proDevices ? "equipped with professional devices" : 
                                              "without professional devices";
    ss << "HospitalRoom (" << seats << ") located";
    ss << " in " << building << ", room number " << number << ".";
    ss << std::endl;

    return ss.str();
}
