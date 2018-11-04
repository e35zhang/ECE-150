#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
// I am not sure that I should write my function declarations here or not.
int main();
#endif

double horizontal_velocity(double Vi, double Fi);
double vertical_velocity(double Vi, double Fi);
double gravity();                                         // double g = 9.80665;
double computed_range(double Vi, double Fi, double h);



#ifndef MARMOSET_TESTING

int main()
{
	double Vi = 600;
	double h = 10;
	double angles[12] = {10,20,25.5,30,40,50,55.5,60,70,75.5,80,90};      //I am using an array to store all Fi I want to use

	for(int i = 0; i <= 11; i++)                                          //A for loop access all the Fi in array angles[]
	{
		if(angles[i] != 90)
	    {
		    std::cout << "The range the banana reaches for the launch angle of " << angles[i] <<
	        " degrees is " << computed_range(Vi, angles[i],h) <<std::endl;     //Print the string. By the way, unit m?
	    }
		else
		{
			std::cout << "The range the banana reaches for the launch angle of " << angles[i] <<
				        " degrees is 0" <<std::endl;
		}
	}
	/*Part B
	h = 0;
	double max = 0;
	for(int i = 0; i <= 11; i++)
	{
		if(angles[i] != 90)
			    {
				    std::cout << "The range the banana reaches for the launch angle of " << angles[i] <<
			        " degrees is " << computed_range(Vi, angles[i],h) <<std::endl;     //Print the string. By the way, unit m?
			    }
				else
				{
					std::cout << "The range the banana reaches for the launch angle of " << angles[i] <<
						        " degrees is 0"  <<std::endl;
				}
		//Print the string. By the way, unit m?
		if(computed_range(Vi, angles[i],h) >= max)
	    {
	    	max = computed_range(Vi, angles[i],h);
	    }
	}
	std::cout << "The maximum range discovered is " << max << std::endl;  //Should I write part b here or in a new .cpp?
	return 0;*/
}

#endif





double horizontal_velocity(double Vi, double Fi)   //Fi is in degrees
{
    return Vi*cos(Fi*M_PI/180);
}

double vertical_velocity(double Vi, double Fi)  //Fi is in degrees
{
    return Vi*sin(Fi*M_PI/180);
}

double gravity()
{
    return 9.80665;                           //Asked me to give a function, why not just double g = 9.80665?
}

double computed_range(double Vi, double Fi, double h)
{
    return horizontal_velocity(Vi, Fi)/gravity()*(vertical_velocity(Vi, Fi)
    	   +sqrt(vertical_velocity(Vi, Fi)*vertical_velocity(Vi, Fi)+2*gravity()*h));
    // This is the expression of Vx/g*(Vy+(Vy^2+2*g*h)^(1/2))

    //faster than vx*vy/g+sqrt(vy^2 +2gh)*vx/g
}
