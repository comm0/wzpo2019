#ifndef _WORK_H_
#define _WORK_H_

#include "Room.h"

class Work
{
    protected:
        uint32_t startTime;
        uint32_t duration;
        Room* place;

    public:
        Work();
        Work(uint32_t startTime, uint32_t duration, Room* place);
        virtual ~Work();

        virtual std::string getInfo() = 0;

        uint32_t getStartTime();
        uint32_t getDuration();
};

#endif
