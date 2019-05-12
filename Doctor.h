#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "Person.h"

class Doctor : public Person
{
    private:
        DoctorTitle title;

    public:
        Doctor(std::string name, uint32_t age, Gender gender, 
                DoctorTitle title);

        std::string getInfo();
};

#endif
