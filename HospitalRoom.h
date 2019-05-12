#ifndef _HOSTPIALROOM_H_
#define _HOSTPIALROOM_H_

#include "Room.h"

class HospitalRoom : public Room
{
    private:
        bool proDevices;

    public:
        HospitalRoom(std::string number, std::string building,
                  bool proDevices);
        std::string getInfo();
};

#endif
