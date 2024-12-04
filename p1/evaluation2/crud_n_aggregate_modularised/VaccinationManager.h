#pragma once

class VaccinationManager{
    friend class VaccinationAggregator;
    friend int main();
    private:
        Vaccination vaccinations[MAX_SIZE];
        int numOfVaccinations;

    public:
        void create();
        void displayAll();
        void editByID();
        void deleteByID();

        int findIndexById(string id);
        
        VaccinationManager();
};