#include <sstream>
#include "Study.h"

Study::Study(uint32_t startTime, uint32_t duration, Room* place,
             bool articles ) :
    Work(startTime, duration, place), articles (articles )
{
}

std::string Study::getInfo()
{
    std::stringstream ss;
    std::string article = articles  ? "and writing articles " : "";
    ss << "studying " << article << "in " << place->getInfo();
    ss << std::endl;

    return ss.str();
}
