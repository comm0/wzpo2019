#include <algorithm>
#include "Person.h"

std::string EnumToString::GenderToString(Gender g)
{
    switch(g)
    {
        case Gender::Male:
            return "male";
        case Gender::Female:
            return "female";
        default:
            return "other";
    }
}

std::string EnumToString::DoctorTitleToString(DoctorTitle t)
{
    switch(t)
    {
        case DoctorTitle::Cardiolog:
            return "Cardiolog";
        case DoctorTitle::Endocrinolog:
            return "Endocrinolog";
        case DoctorTitle::Neurologist:
            return "Neurologist";
        case DoctorTitle::Internist:
            return "Internist";
        default:
            return "Internist";
    }
}

Person::Person() : name(""), age(0), gender(Gender::Other)
{
}

Person::Person(std::string name, uint32_t age, Gender gender) :
    name(name), age(age), gender(gender)
{
}

Person::~Person()
{
}

void Person::addWork(std::vector<Work*>& w)
{
    this->work.insert(this->work.end(), w.begin(), w.end());
}

void Person::removeWork(size_t n)
{
    this->work.erase(this->work.begin(), this->work.begin() + n);
}

Work* Person::nextWorkItem()
{
    return this->work.front();
}

bool Person::hasMoreWork()
{
    return this->work.size() != 0;
}

void Person::doWork()
{
    if(!hasMoreWork())
        return;

    // check for time collisions
    if (work.size() > 1)
    {
        uint32_t earliestStartTime = work.front()->getStartTime() + 
                                     work.front()->getDuration();
        if (work[1]->getStartTime() < earliestStartTime)
        {
            throw std::logic_error("At least two work items are "
                                "scheduled to occur at the same time.");
        }
    }

    // and now do the job
    removeWork(1);
}
