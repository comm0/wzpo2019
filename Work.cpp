#include "Work.h"

Work::Work() : startTime(0), duration(0), place(nullptr)
{
}

Work::Work(uint32_t startTime, uint32_t duration, Room* place) :
    startTime(startTime), duration(duration), place(place)
{
}

Work::~Work()
{
}

uint32_t Work::getStartTime()
{
    return this->startTime;
}

uint32_t Work::getDuration()
{
    return this->duration;
}
