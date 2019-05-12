#include <iostream>
#include <algorithm>
#include <random>
#include "PeopleFactory.h"
#include "RoomFactory.h"
#include "WorkFactory.h"

int main(int argc, char** argv)
{
    auto doctor = PeopleFactory::getFactory("Doctor")->createPerson();

    std::vector<Patient*> patients(12);
    std::generate(std::begin(patients), std::end(patients),
    []() { return (Patient*)PeopleFactory::getFactory("Patient")->
                  createPerson(); });

    std::vector<Room*> rooms(6);
    std::generate(std::begin(rooms), std::begin(rooms) + 3,
    []() { return RoomFactory::getFactory("PrivateOffice")->
                  createRoom(); });
    std::generate(std::begin(rooms) + 2, std::begin(rooms) + 5,
    []() { return RoomFactory::getFactory("HospitalRoom")->
                  createRoom(); });
    std::generate(std::begin(rooms) + 4, std::end(rooms),
    []() { return RoomFactory::getFactory("Surgery")->
                  createRoom(); });

    auto randomSurgery = [&rooms]()
    {
        std::random_device random_device;
	    std::mt19937 engine{random_device()};
	    std::uniform_int_distribution<int> dist(4, rooms.size()-1);
        return rooms[dist(engine)];
    };

    auto randomRoom = [&rooms]()
    {
        std::random_device random_device;
	    std::mt19937 engine{random_device()};
	    std::uniform_int_distribution<int> dist(0, rooms.size()-1-2);
        return rooms[dist(engine)];
    };

    std::cout << doctor->getInfo() << " and does following work: ";

    for(int i = 1; i < 6; i++)
    {
        std::cout << std::endl << "*** Day " << i << std::endl;

        // create some work
        std::vector<Work*> work(4);
        std::generate(std::begin(work), std::begin(work) + 3,
        [&]() { return WorkFactory::getFactory("Operation")->
                      createWork(randomSurgery()); });
        std::generate(std::begin(work) + 2, std::end(work),
        [&]() { return WorkFactory::getFactory("Consultation")->
                      createWork(randomRoom()); });

        // add some patients to didactic work
        std::for_each(std::begin(work) + 2, std::end(work),
        [&patients](Work* w)
        {
            std::random_shuffle(std::begin(patients),
                                std::end(patients));

            std::random_device random_device;
	        std::mt19937 engine{random_device()};
	        std::uniform_int_distribution<int> dist(0, patients.size()-1);
            auto count = dist(engine);

            ConsultationWork* cons  = (ConsultationWork*)w;
            auto tmp = std::vector<Patient*>(std::begin(patients),
                       std::begin(patients) + count);
            cons ->setPatients(tmp);
        });

        // sort the work
        std::sort(work.begin(), work.end(),
        [](Work *w1, Work *w2)
        {
            return w1->getStartTime() < w2->getStartTime();
        });

        // now, finally, do it
        doctor->addWork(work);
        while(doctor->hasMoreWork())
        {
            auto futureWork = doctor->nextWorkItem();
            std::cout << "trying to perform work: ";
            std::cout << futureWork->getInfo();

            auto didactic = dynamic_cast<ConsultationWork*>(futureWork);
            if(didactic != nullptr)
            {
                std::cout << "with following patients: " << std::endl;
                for(auto s: didactic->getPatients())
                    std::cout << "   " << s->getInfo();
            }

            try {
                doctor->doWork();
                std::cout << "work done.";
            }
            catch(const std::logic_error& e)
            {
                std::cout << std::endl << "exception caught: ";
                std::cout << e.what() << std::endl;
                std::cout << "removing this work item and moving on";
                std::cout << std::endl;
                doctor->removeWork(1);
            }

            std::cout << std::endl;
        }

        for(auto& w: work)
            delete w;
    }

    for(auto& s: patients)
        delete s;
    for(auto& r: rooms)
        delete r;

    return 0;
}
