#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>

class Room
{
    protected:
        std::string number;
        std::string building;

    public:
        Room();
        Room(std::string number, std::string building);
        virtual ~Room();

        virtual std::string getInfo() = 0;
};

#endif
