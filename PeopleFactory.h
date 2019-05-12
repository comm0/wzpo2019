#ifndef _PEOPLEFACTORY_H_
#define _PEOPLEFACTORY_H_

#include <vector>
#include "Doctor.h"
#include "Patient.h"

class AbstractPeopleFactory
{
    public:
        virtual Person* createPerson() = 0;

    protected:
        const static std::vector<std::string> femaleNames;
        const static std::vector<std::string> maleNames;

        Gender randomGender();
        uint32_t randomAge();
        std::string randomName(Gender);
};

class DoctorFactory : public AbstractPeopleFactory
{
    public:
        Person* createPerson();
    private:
        DoctorTitle randomDoctorTitle();
};

class PatientFactory : public AbstractPeopleFactory
{
    public:
        Person* createPerson();
    private:
        uint32_t randomWeek();
};

class PeopleFactory
{
    public:
        static
        std::unique_ptr<AbstractPeopleFactory> getFactory(std::string);
};

#endif
