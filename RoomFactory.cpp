#include <random>
#include <sstream>
#include <iomanip>
#include "RoomFactory.h"

const std::vector<std::string> AbstractRoomFactory::knownBuildings = 
{ "C2", "M11", "M6-bis" };

std::string AbstractRoomFactory::randomBuilding()
{
    size_t size = knownBuildings.size();

    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, size-1);

    return knownBuildings[dist(engine)];
}

std::string AbstractRoomFactory::randomNumber()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, 3);
    auto floor = dist(engine);
    dist = std::uniform_int_distribution<int>(1, 20);
    auto room = dist(engine);

    std::stringstream ss;
    ss << floor;
    ss << std::setfill('0') << std::setw(2) << room;
    return ss.str();
}

bool AbstractRoomFactory::randomBool()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist;
    return dist(engine) % 2;
}

Room* SurgeryFactory::createRoom()
{
    return new Surgery(randomNumber(), randomBuilding(),
                           randomCleanliness());
}

Room* HospitalRoomFactory::createRoom()
{
    return new HospitalRoom(randomNumber(), randomBuilding(),
                         randomBool());
}

float SurgeryFactory::randomCleanliness()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_real_distribution<float> dist(0.1, 0.95);
    return dist(engine);
}

Room* PrivateOfficeFactory::createRoom()
{
    return new PrivateOffice(randomNumber(), randomBuilding(),
                         randomBool());
}

std::unique_ptr<AbstractRoomFactory>
RoomFactory::getFactory(std::string type)
{
    if (type == "Surgery")
        return std::make_unique<SurgeryFactory>();
    else if (type == "HospitalRoom")
        return std::make_unique<HospitalRoomFactory>();
    else if (type == "PrivateOffice")
        return std::make_unique<PrivateOfficeFactory>();
    else
        return nullptr;
}
