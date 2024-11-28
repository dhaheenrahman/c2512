#pragma once
#include<string>

using std::string;

class Vaccination{
        private:
                //members
                string VaccinationID;
                int DosesAdministered;

        public:
		friend class VaccinationComparison; 		
		//constructor
		Vaccination(string p_VaccinationID, int p_DosesAdministered);
};

class VaccinationComparison{
	public:
		static bool Equals(const Vaccination& first, const Vaccination& second);
		static bool NotEquals(const Vaccination& first, const Vaccination& second);
		static bool GreaterThan(const Vaccination& first, const Vaccination& second);
		static bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
		static bool LessThan(const Vaccination& first, const Vaccination& second);
		static bool LessThanEquals(const Vaccination& first, const Vaccination& second);
};
