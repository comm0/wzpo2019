#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Doctor.h"
#include "Operation.h"
#include "PrivateOffice.h"
#include "Surgery.h"

TEST_CASE("Basic object creation")
{
    SECTION("Person creation")
    {
        Doctor p("Alfred", 44, Gender::Male, DoctorTitle::Cardiolog);
        auto info = p.getInfo();
        REQUIRE(info == "Alfred (Doctor, 44 y.o.) identifies as male and holds the title of Cardiolog.\n");
    }

    SECTION("Room creation")
    {
        PrivateOffice r("001", "M-11", 0.5);
        auto info = r.getInfo();
        REQUIRE(info == "PrivateOffice with free coffee located in M-11, room number 001.\n");
    }

    SECTION("Work creation")
    {
        Surgery r("001", "M-11", 0.5);
        Operation w(12, 2, &r, true);
        auto info = w.getInfo();
        REQUIRE(info == "operation and teaching new doctors at 12 for 2 hours in Surgery (cleanliness level: 0.5) located in M-11, room number 001.\n");
    }
}

TEST_CASE("EnumToString")
{
    SECTION("GenderToString")
    {
        REQUIRE(EnumToString::GenderToString(Gender::Other) == "other");
    }

    SECTION("DoctorTitleToString")
    {
        REQUIRE(EnumToString::DoctorTitleToString(DoctorTitle::Neurologist) == "Neurologist");
    }
}
