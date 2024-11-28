#pragma once

#include <string>

using std::string;

class HospitalStay
{
    private:
        string StayID;
        int NumberOfDays;
    public:
        //behaviours
        bool Equals(const HospitalStay& other);
        bool NotEquals(const HospitalStay& other);
        bool GreaterThan(const HospitalStay& other);
        bool GreaterThanEquals(const HospitalStay& other);
        bool LessThan(const HospitalStay& other);
        bool LessThanEquals(const HospitalStay& other);
        //constructor
        HospitalStay(string p_StayID, int p_NumberOfDays);
};
