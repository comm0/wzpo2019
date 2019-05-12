#include <sstream>
#include "Operation.h"

Operation::Operation(uint32_t startTime, uint32_t duration, Room* place,
                   bool teached) :
    Work(startTime, duration, place), teached(teached)
{
}

std::string Operation::getInfo()
{
    std::stringstream ss;
    std::string teach = teached ? " and teaching new doctors" : "";
    ss << "operation" << teach;
    ss << " at " << startTime << " for " << duration << " hours";
    ss <<" in " << place->getInfo();

    return ss.str();
}
