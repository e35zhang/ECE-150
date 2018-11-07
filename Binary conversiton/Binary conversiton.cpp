#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif

void transform(int aDecimal);


#ifndef MARMOSET_TESTING
int main()
{
    std::cout << "Enter a decimal number" <<std::endl;
    int numIn = 0;
    std::cin >> numIn;
    transform(numIn);
}

#endif

    void transform(int n)
    {
    	int binaryNum[8] = {0,0,0,0,0,0,0,0};       //array to store
        int i = 0;
    	while (n > 0)
    	{
    	    binaryNum[i] = n % 2;          //store from back to front
    	    n = n / 2;
    	    i++;
    	}

    	for (int j = 7; j >= 0; j--)
    	{
    		std::cout << (binaryNum[j]);
        }
    	std::cout << std::endl;
    }
/*
#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

void transform(int aDecimal);


#ifndef MARMOSET_TESTING
int main()
{
    std::cout << "Enter a decimal number" <<std::endl;
    int numIn = 0;
    std::cin >> numIn;
    int binaryNum[8] = {0,0,0,0,0,0,0,0};       //array to store
    int i = 0;
    transform(numIn);
}

#endif

    void transform(int n)
    {
        if (n / 2 != 0)           //when =0, the function operates k times where k = digit
    	{
      		transform(n / 2);
 	   	}
    }
*/
