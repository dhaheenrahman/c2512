#pragma once
#include<string>

using std::string;

class Vaccination{
	private:
		//members
		string VaccinationID;
		int DosesAdministered;

	public:
		//behaviour
		bool Equals(const Vaccination& other);
		bool NotEquals(const Vaccination& other);
		bool GreaterThan(const Vaccination& other);
		bool GreaterThanEquals(const Vaccination& other);
		bool LessThan(const Vaccination& other);
		bool LessThanEquals(const Vaccination& other);
		//constructor
		Vaccination(string p_VaccinationID, int p_DosesAdministered);
};
