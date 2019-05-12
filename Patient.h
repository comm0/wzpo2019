#ifndef _Patient_H_
#define _Patient_H_

#include "Person.h"

class Patient : public Person
{
    private:
        uint32_t week; // is 32-bit int large enough?

    public:
        Patient(std::string name, uint32_t age, Gender gender,
                uint32_t week);

        std::string getInfo();
};

#endif
