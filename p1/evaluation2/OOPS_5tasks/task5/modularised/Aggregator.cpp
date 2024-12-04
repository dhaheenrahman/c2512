#include "Aggregator.h"

int findMinDoseIndex(Vaccination vaccinations[], int size){
    int minIndex = 0;
    for(int i = 1; i < size; i++){
        if(vaccinations[i].LessThan(vaccinations[minIndex])){
            minIndex = i;
        }
    }
    return minIndex;
}
int findMaxDoseIndex(Vaccination vaccinations[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (vaccinations[i].GreaterThan(vaccinations[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findSecondMinDoseIndex(Vaccination vaccinations[], int size)
{
    int minIndex = findMinDoseIndex(vaccinations, size);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < size; i++)
    {
        if (i != minIndex)
        {
            if (vaccinations[i].LessThan(vaccinations[secondMinIndex]))
            {
                secondMinIndex = i;
            }
        }
    }

    
    return secondMinIndex;
}

int findSecondMaxDoseIndex(Vaccination vaccinations[], int size)
{
    int maxIndex = findMaxDoseIndex(vaccinations, size);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < size; i++)
    {
        if (i != maxIndex)
        {
            if (vaccinations[i].GreaterThan(vaccinations[secondMaxIndex]))
            {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}