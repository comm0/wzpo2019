#include <random>
#include "WorkFactory.h"

bool AbstractWorkFactory::randomBool()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist;
    return dist(engine) % 2;
}

uint32_t AbstractWorkFactory::randomStartTime()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(7, 16);
    return dist(engine);
}

uint32_t AbstractWorkFactory::randomDuration()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(1, 3);
    return dist(engine);
}

Work* OperationWorkFactory::createWork(Room* place)
{
    return new Operation(randomStartTime(), randomDuration(),
                        place, randomBool());
}

Work* ConsultationWorkFactory::createWork(Room* place)
{
    return new ConsultationWork(randomStartTime(), randomDuration(),
                           place, randomBool());
}

Work* StudyWorkFactory::createWork(Room* place)
{
    return new Study(randomStartTime(), randomDuration(),
                     place, randomBool());
}

std::unique_ptr<AbstractWorkFactory>
WorkFactory::getFactory(std::string type)
{
    if (type == "Operation")
        return std::make_unique<OperationWorkFactory>();
    else if (type == "Consultation")
        return std::make_unique<ConsultationWorkFactory>();
    else if (type == "Study")
        return std::make_unique<StudyWorkFactory>();
    else
        return nullptr;
}
