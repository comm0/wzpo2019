#include <sstream>
#include "Patient.h"

Patient::Patient(std::string name, uint32_t age, Gender gender, 
                uint32_t week) : 
    Person(name, age, gender), week(week)
{
}

std::string Patient::getInfo()
{
    std::stringstream ss;
    ss << this->name << " (Patient, " << this->age << " y.o.)";
    ss << " identifies as " << EnumToString::GenderToString(this->gender);
    ss << " and currently is curing on week number " << week;
    ss << "." << std::endl;

    return ss.str();
}
