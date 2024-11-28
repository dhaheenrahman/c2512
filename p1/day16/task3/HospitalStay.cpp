#include <string>

#include "HospitalStay.h"

using std::string;

//behaviours
bool HospitalStay::Equals(const HospitalStay& other)
{
    return (NumberOfDays == other.NumberOfDays);
}

bool HospitalStay::NotEquals(const HospitalStay& other)
{
    return (NumberOfDays != other.NumberOfDays);
}

bool HospitalStay::GreaterThan(const HospitalStay& other)
{
    return (NumberOfDays > other.NumberOfDays);
}

bool HospitalStay::GreaterThanEquals(const HospitalStay& other)
{
    return (NumberOfDays >= other.NumberOfDays);
}

bool HospitalStay::LessThan(const HospitalStay& other)
{
    return (NumberOfDays < other.NumberOfDays);
}

bool HospitalStay::LessThanEquals(const HospitalStay& other)
{
    return (NumberOfDays <= other.NumberOfDays);
}

//constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}
