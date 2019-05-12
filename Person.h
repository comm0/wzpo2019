#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <vector>
#include <memory>

#include "Work.h"

enum class DoctorTitle
{
    Cardiolog,
    Endocrinolog,
    Neurologist,
    Internist
};

enum class Gender
{
    Female,
    Male,
    Other
};

class EnumToString
{
    public:
        static std::string GenderToString(Gender);
        static std::string DoctorTitleToString(DoctorTitle);
};

class Person
{
    protected:
        std::string name;
        uint32_t age;
        Gender gender;
        std::vector<Work*> work;

    public:
        Person();
        Person(std::string name, uint32_t age, Gender gender);
        virtual ~Person();

        virtual std::string getInfo() = 0;

        void addWork(std::vector<Work*>&);
        void removeWork(size_t);
        Work* nextWorkItem();
        bool hasMoreWork();
        void doWork();
};

#endif
