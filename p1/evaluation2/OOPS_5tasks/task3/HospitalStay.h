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
	friend bool Equals(const HospitalStay& first, const HospitalStay& second);
	friend bool NotEquals(const HospitalStay& first, const HospitalStay& second);
	friend bool GreaterThan(const HospitalStay& first, const HospitalStay& second);
	friend bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second);
	friend bool LessThan(const HospitalStay& first, const HospitalStay& second);
	friend bool LessThanEquals(const HospitalStay& first, const HospitalStay& second);
        HospitalStay(string p_StayID, int p_NumberOfDays);
};

bool Equals(const HospitalStay& first, const HospitalStay& second);
bool NotEquals(const HospitalStay& first, const HospitalStay& second);
bool GreaterThan(const HospitalStay& first, const HospitalStay& second);
bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second);
bool LessThan(const HospitalStay& first, const HospitalStay& second);
bool LessThanEquals(const HospitalStay& first, const HospitalStay& second);
