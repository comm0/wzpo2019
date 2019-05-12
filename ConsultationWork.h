#ifndef _CONSULTATIONWORK_H_
#define _CONSULTATIONWORK_H_

#include <vector>
#include "Patient.h"
#include "Work.h"

class ConsultationWork : public Work
{
    protected:
        bool prescibeMedicnal ;
        std::vector<Patient*> patients;

    public:
        ConsultationWork(uint32_t startTime, uint32_t duration, Room* place,
                   bool prescibeMedicnal  );
        std::string getInfo();
        void setPatients(std::vector<Patient*>&);
        const std::vector<Patient*>& getPatients();
};

#endif
