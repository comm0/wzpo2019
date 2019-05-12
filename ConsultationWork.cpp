#include <sstream>
#include "ConsultationWork.h"

ConsultationWork::ConsultationWork(uint32_t startTime, uint32_t duration, 
                           Room* place, bool prescibeMedicnal  ) :
    Work(startTime, duration, place), prescibeMedicnal  (prescibeMedicnal  )
{
}

std::string ConsultationWork::getInfo()
{
    std::stringstream ss;
    std::string prescribe  = prescibeMedicnal   ? 
        "and prescribe a medicinal  " : "";
    ss << "consultation work " << prescribe ;
    ss << "at " << startTime << " for " << duration << " hours";
    ss << " with " << patients.size() << " patients";
    ss << " in " << place->getInfo();

    return ss.str();
}

void ConsultationWork::setPatients(std::vector<Patient*>& patients)
{
    this->patients.clear();
    this->patients = patients;
}

const std::vector<Patient*>& ConsultationWork::getPatients()
{
    return patients;
}
