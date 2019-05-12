#include <sstream>
#include "Doctor.h"

Doctor::Doctor(std::string name, uint32_t age, Gender gender, 
                    DoctorTitle title) : 
    Person(name, age, gender), title(title)
{
}

std::string Doctor::getInfo()
{
    std::stringstream ss;
    ss << this->name << " (Doctor, " << this->age << " y.o.)";
    ss << " identifies as " << EnumToString::GenderToString(this->gender);
    ss << " and holds the title of ";
    ss << EnumToString::DoctorTitleToString(this->title);
    ss << "." << std::endl;

    return ss.str();
}
