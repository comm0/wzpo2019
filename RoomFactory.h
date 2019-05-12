#ifndef _ROOMFACTORY_H_
#define _ROOMFACTORY_H_

#include <vector>
#include <memory>
#include "Surgery.h"
#include "PrivateOffice.h"
#include "HospitalRoom.h"

class AbstractRoomFactory
{
    public:
        virtual Room* createRoom() = 0;

    protected:
        const static std::vector<std::string> knownBuildings;

        bool randomBool();
        std::string randomBuilding();
        std::string randomNumber();
};

class SurgeryFactory : public AbstractRoomFactory
{
    public:
        Room* createRoom();
    protected:
        float randomCleanliness();
};

class HospitalRoomFactory : public AbstractRoomFactory
{
    public:
        Room* createRoom();
};

class PrivateOfficeFactory : public AbstractRoomFactory
{
    public:
        Room* createRoom();
};

class RoomFactory
{
    public:
        static
        std::unique_ptr<AbstractRoomFactory> getFactory(std::string);
};

#endif
