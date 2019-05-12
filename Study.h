#ifndef _STUDY_H_
#define _STUDY_H_

#include "Work.h"

class Study : public Work
{
    protected:
        bool articles ;

    public:
        Study(uint32_t startTime, uint32_t duration, Room* place,
                bool articles );
        std::string getInfo();
};

#endif
