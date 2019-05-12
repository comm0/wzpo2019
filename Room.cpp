#include "Room.h"

Room::Room() : number(""), building("")
{
}


Room::Room(std::string number, std::string building) :
    number(number), building(building)
{
}

Room::~Room()
{
}
