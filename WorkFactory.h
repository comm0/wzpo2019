#ifndef _WORKFACTORY_H_
#define _WORKFACTORY_H_

#include <vector>
#include <memory>
#include "Operation.h"
#include "ConsultationWork.h"
#include "Study.h"

class AbstractWorkFactory
{
    public:
        virtual Work* createWork(Room* place) = 0;

    protected:
        bool randomBool();
        uint32_t randomStartTime();
        uint32_t randomDuration();
};

class OperationWorkFactory : public AbstractWorkFactory
{
    public:
        Work* createWork(Room* place);
};

class ConsultationWorkFactory : public AbstractWorkFactory
{
    public:
        Work* createWork(Room* place);
};

class StudyWorkFactory : public AbstractWorkFactory
{
    public:
        Work* createWork(Room* place);
};

class WorkFactory
{
    public:
        static
        std::unique_ptr<AbstractWorkFactory> getFactory(std::string);
};

#endif
