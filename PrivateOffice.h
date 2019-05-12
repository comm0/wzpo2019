#ifndef _PRIVATEOFFICE_H_
#define _PRIVATEOFFICE_H_

#include "Room.h"

class PrivateOffice : public Room
{
    private:
        float coffee;

    public:
        PrivateOffice(std::string number, std::string building,
                  float coffee);
        std::string getInfo();
};

#endif
