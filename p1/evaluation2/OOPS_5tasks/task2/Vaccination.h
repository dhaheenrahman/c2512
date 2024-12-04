#pragma once
#include<string>

using std::string;

class Vaccination{
        private:
                //members
                string VaccinationID;
                int DosesAdministered;

        public:
		friend bool Equals(const Vaccination& first, const Vaccination& second);
		friend bool NotEquals(const Vaccination& first, const Vaccination& second);
		friend bool GreaterThan(const Vaccination& first, const Vaccination& second);
		friend bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
		friend bool LessThan(const Vaccination& first, const Vaccination& second);
		friend bool LessThanEquals(const Vaccination& first, const Vaccination& second);
		//constructor
		Vaccination(string p_VaccinationID, int p_DosesAdministered);
};

bool Equals(const Vaccination& first, const Vaccination& second);
bool NotEquals(const Vaccination& first, const Vaccination& second);
bool GreaterThan(const Vaccination& first, const Vaccination& second);
bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
bool LessThan(const Vaccination& first, const Vaccination& second);
bool LessThanEquals(const Vaccination& first, const Vaccination& second);
