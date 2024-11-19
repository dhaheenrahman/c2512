bool isPrime(int age)
{
        if (age < 2)
        {
            return false;
        }

        int squareRoot = sqrt(age); // <cmath>

        for (int i = 0; i <= squareRoot; i++)
        {
            if ((age % i) == 0)
            {
                return false;
            }
        }
        
        return true;
}

// ===========================

int findSecondMaxAdultAge(int ages[], int size)
{
        int firstMax = 0, secondMax = 0;

        for (int i = 0; i < size; i++)
        {
            if (ages[i] >= 18 && ages[i] > firstMax)
            {
                firstMax = ages[i];
            }
        }
        
        for (int i = 0; i < size; i++)
        {
            if ((ages[i] >= 18) && (ages[i] > secondMax) && (ages[i] < firstMax))
            {
                secondMax = ages[i];
            }
        }	
        
        return secondMax;
}

//  --- single pass ---
//
// int findSecondMaxAdultAge(int ages[], int size)
// {
//         int firstMax = 0, secondMax = 0;

//         for (int i = 0; i < size; i++)
//         {
//             if (ages[i] >= 18)
//             {
//                 if (ages[i] > firstMax)
//                 {
//                     secondMax = firstMax;
//                     firstMax = ages[i];
//                 }
//                 else if(ages[i] > secondMax && ages[i] < firstMax)
//                 {
//                     secondMax = ages[i];
//                 }
//             }
//         }
        
//         return secondMax;
// }
