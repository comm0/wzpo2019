#ifndef _SURGERY_H_
#define _SURGERY_H_

#include "Room.h"

class Surgery : public Room
{
    private:
        float cleanliness;

    public:
        Surgery(std::string number, std::string building, float cleanliness);
        std::string getInfo();
};

#endif
