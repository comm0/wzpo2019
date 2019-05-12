#ifndef _OPERATION_H_
#define _OPERATION_H_

#include "Work.h"

class Operation : public Work
{
    protected:
        bool teached;

    public:
        Operation(uint32_t startTime, uint32_t duration, Room* place,
                bool teached);
        std::string getInfo();
};

#endif
