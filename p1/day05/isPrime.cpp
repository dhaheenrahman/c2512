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