#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

struct fourLong                 //data structure to save four double. use this because do not want to say too much in int main
{
     long double memory1;       //immediate
     long double memory2;
     long double memory3;       //memory
     long double memory4;
     int initialized1 = 0;
     int initialized2 = 0;
};
struct threePart                 //data structure to save four double. use this because do not want to say too much in int main
{
     std::string part1;
     std::string part2;
     std::string part3;
     int illegal = 1;
};

int main();

void interval_calculator();
threePart breakString(std::string userInput);
fourLong operate(std::string userInput, fourLong memory);
fourLong enter(std::string userInput, fourLong memory);
fourLong negate(std::string userInput, fourLong memory);
fourLong invert(std::string userInput, fourLong memory);
fourLong ms(std::string userInput, fourLong memory);
fourLong mr(std::string userInput, fourLong memory);
fourLong mc(std::string userInput, fourLong memory);
fourLong mplu(std::string userInput, fourLong memory);
fourLong msub(std::string userInput, fourLong memory);
fourLong scalar_add(std::string userInput, fourLong memory);
fourLong scalar_subtract(std::string userInput, fourLong memory);
fourLong scalar_multiply(std::string userInput, fourLong memory);
fourLong scalar_divide(std::string userInput, fourLong memory);
fourLong scalar_divide_by(std::string userInput, fourLong memory);
fourLong interval_add(std::string userInput, fourLong memory);
fourLong interval_subtract(std::string userInput, fourLong memory);
fourLong interval_multiply(std::string userInput, fourLong memory);
fourLong interval_divide(std::string userInput, fourLong memory);
fourLong intersect(std::string userInput, fourLong memory);
fourLong integers(std::string userInput, fourLong memory);
fourLong cartesian_integers(std::string userInput, fourLong memory);
void invalidInterval();
void printImmediate(long double a, long double b);

int main()
{
	interval_calculator();
	return 0;
}

threePart breakString(std::string userInput)
{
    threePart a;
	int i = 0;
	int numPoint = 0;

	for(i; i < userInput.length(); i++)                   //From here1 to
    {
    	if(userInput.at(i) != ' ')
    	{
            a.part1 = a.part1 + userInput.at(i);
    	}
    	else
    		break;
    }
	for(++i; i < userInput.length(); i++)
	{
	    if(userInput.at(i) != ' ')
	    {
	        a.part2 = a.part2 + userInput.at(i);
	    }
	    else
	        break;
	}
	for(++i; i < userInput.length(); i++)
    {
	    if(userInput.at(i) != ' ')
	    {
	        a.part3 = a.part3 + userInput.at(i);
	    }
	    else
	        break;
    }                                                       //here1 break the input into what we want.

    if(a.part1.compare("negate")==0||a.part1.compare("invert")==0||a.part1.compare("mr")==0||a.part1.compare("ms")==0||a.part1.compare("m+")==0||a.part1.compare("m-")==0||a.part1.compare("mc")==0||a.part1.compare("integers")==0)
    {
        if(a.part2.compare("")==0)
        {
        	a.illegal = 0;
        }
    }
    if(a.part1.compare("scalar_add")==0||a.part1.compare("scalar_subtract")==0||a.part1.compare("scalar_multiply")==0||a.part1.compare("scalar_divide")==0||a.part1.compare("scalar_divided_by")==0)
    {
    	for(int j = 0; j < a.part2.length(); j++)                   //From here1 to
        {
    	    if(a.part2.at(j) =='.')
    	    {
    	    	numPoint++;
    	    }
    		if(numPoint < 2 &&( a.part2.at(j) == '1'||a.part2.at(j) =='2'||a.part2.at(j) =='3'||a.part2.at(j) =='4'||a.part2.at(j) =='5'||a.part2.at(j) =='6'||a.part2.at(j) =='7'||a.part2.at(j) =='8'||a.part2.at(j) =='9'||a.part2.at(j) =='0'||a.part2.at(j) =='.'))
    	    {
    			a.illegal = 0;
    	    }
        }
    	if(a.part3.compare("")==0)
    	{
    		a.illegal = 0;
    	}
    }
    if(a.part1.compare("enter")==0||a.part1.compare("interval_add")==0||a.part1.compare("interval_subtract")==0||a.part1.compare("interval_multiply")==0||a.part1.compare("interval_divide")==0||a.part1.compare("intersect")==0||a.part1.compare("cartesian_integers")==0)
    {
        for(int j=0; j < a.part2.length(); j++)                   //From here1 to
        {
        	if(a.part2.at(j) =='.')
            {
        	  	numPoint++;
            }
            if(numPoint <2 && (a.part2.at(j) == '1'||a.part2.at(j) =='2'||a.part2.at(j) =='3'||a.part2.at(j) =='4'||a.part2.at(j) =='5'||a.part2.at(j) =='6'||a.part2.at(j) =='7'||a.part2.at(j) =='8'||a.part2.at(j) =='9'||a.part2.at(j) =='0'||a.part2.at(j) =='.'))
        	{
        		a.illegal = 0;
        	}
        }
        numPoint = 0;
        for(int j; j < a.part3.length(); j++)                   //From here1 to
        {
            if(a.part3.at(j) =='.')
            {
                numPoint++;
            }
            if(numPoint < 2 &&( a.part3.at(j) == '1'||a.part3.at(j) =='2'||a.part3.at(j) =='3'||a.part3.at(j) =='4'||a.part3.at(j) =='5'||a.part3.at(j) =='6'||a.part3.at(j) =='7'||a.part3.at(j) =='8'||a.part3.at(j) =='9'||a.part3.at(j) =='0'||a.part3.at(j) =='.'))
            {
                a.illegal = 0;
            }
        }
    }
    return a;
}

void interval_calculator()
{
	std::string userInput;
	fourLong memory;
	std::cout.precision(15);

	memory.memory1 = 0;      //to use max of doulbe is more reasonable to
	memory.memory2 = 0;      //represent undefined but it won't compile in marmoset
	memory.memory3 = 0;
	memory.memory4 = 0;

	std::cout << "input :> ";
	std::getline (std::cin,userInput);                                      //use getline because I want to get " "
	while (userInput.compare("exit") != 0)
	{
	    memory = operate(userInput, memory);                       //do the operation and change memory status.
	    std::cout << "input :> ";
	    std::getline (std::cin,userInput);
	}
    std::cout << "Bye bye: Terminating interval calculator program.";
}

fourLong operate(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
    std::string part1 = a.part1;
    fourLong operatememory = memory;
    if(a.illegal == 0)
    {
        if(part1.compare("enter") == 0)
        {
        	operatememory = enter(userInput, memory);
        }
        else if(part1.compare("negate") == 0)                         //part1 is negate.
        {
        	operatememory = negate(userInput, memory);
        }
        else if(part1.compare("invert") == 0)
        {
        	operatememory = invert(userInput, memory);
        }
        else if(part1.compare("ms") == 0)                         //part1 is ms.
        {
        	operatememory = ms(userInput, memory);
        }
        else if(part1.compare("mr") == 0)                         //part1 is mr.
        {
        	operatememory = mr(userInput, memory);
        }
        else if(part1.compare("mc") == 0)                         //part1 is mc.
        {
        	operatememory = mc(userInput, memory);
        }
        else if(part1.compare("m+") == 0)                         //part1 is m+.
        {
        	operatememory = mplu(userInput, memory);
        }
        else if(part1.compare("m-") == 0)                         //part1 is m-.
        {
        	operatememory = msub(userInput, memory);
        }
        else if(part1.compare("scalar_add") == 0)                         //part1 is scalar_add.
        {
        	operatememory = scalar_add(userInput, memory);
        }
        else if(part1.compare("scalar_subtract") == 0)                         //part1 is scalar_subtract.
        {
        	operatememory = scalar_subtract(userInput, memory);
        }
    	else if(part1.compare("scalar_multiply") == 0)                         //part1 is scalar_multiply.
    	{
    	    operatememory = scalar_multiply(userInput, memory);
    	}
    	else if(part1.compare("scalar_divide") == 0)                         //part1 is scalar_divide.
    	{
    		operatememory = scalar_divide(userInput, memory);
    	}
    	else if(part1.compare("scalar_divide_by") == 0)                         //part1 is scalar_divide_by.
    	{
    		operatememory = scalar_divide_by(userInput, memory);
    	}
    	else if(part1.compare("interval_add") == 0)                         //part1 is interval_add.
    	{
    		operatememory = interval_add(userInput, memory);
    	}
    	else if(part1.compare("interval_subtract") == 0)                         //part1 is interval_subtract.
    	{
    		operatememory = interval_subtract(userInput, memory);
    	}
    	else if(part1.compare("interval_multiply") == 0)                         //part1 is interval_multiply.
    	{
    		operatememory = interval_multiply(userInput, memory);
    	}
    	else if(part1.compare("interval_divide") == 0)                         //part1 is interval_divide.
    	{
    		operatememory = interval_divide(userInput, memory);
    	}
    	else if(part1.compare("intersect") == 0)                         //part1 is intersect.    need to debug
    	{
    	   	operatememory = intersect(userInput, memory);
    	}
    	else if(part1.compare("integers") == 0)   //part1 is integers.
    	{
   		    operatememory = integers(userInput, memory);
    	}
     	else if(part1.compare("cartesian_integers") == 0)   //part1 is cartesian_integers.
      	{
   		    operatememory = cartesian_integers(userInput, memory);
   	    }
    }
    else
    {
    	std::cout << "Error: illegal command"<<std::endl;
    }
    return operatememory;
}




void invalidInterval()
{
	std::cout << "--" << std::endl;     //if not defined, --
}

void printImmediate(long double a, long double b)
{
	std::cout.precision(15);
	std::cout << "[" << a << ", " << b << "]" << std::endl;
}
fourLong enter(std::string userInput, fourLong memory)

{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;

	if(std::stold(part2.c_str()) > std::stold(part3.c_str()))
	{
		std::cout << "Error: invalid interval as " << std::stold(part2.c_str()) <<" > " << std::stold(part3.c_str()) << std::endl;
		if(memoryuse.initialized1 == 0)
		{
			invalidInterval();
		}
		else
		{
			printImmediate(memoryuse.memory1, memoryuse.memory2);
		}   //print out last one in instance slot
	}
	else
	{
		memoryuse.memory1 = std::stold(part2.c_str());     //user input is now in the new instant slot
		memoryuse.memory2 = std::stold(part3.c_str());     //
		memoryuse.initialized1 = 1;
		printImmediate(memoryuse.memory1, memoryuse.memory2);

	}
	return memoryuse;
}
fourLong negate(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0)
	{
		invalidInterval();             //if not defined, --
	}
	else
	{
		double temp =  memoryuse.memory1;
	    memoryuse.memory1 = -1*memoryuse.memory2;
	    memoryuse.memory2 = -1*temp;
	    printImmediate(memoryuse.memory1, memoryuse.memory2);
	}            //instance must be valid to be saved  negate must return a valid result
	return memoryuse;
}

fourLong invert(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0)
	{
		invalidInterval();
	}
	else if((memoryuse.memory1 < 0) && (memoryuse.memory2 > 0))
	{
		memoryuse.memory1 = 0;                     //uninitialized the instance
		memoryuse.memory2 = 0;
		std::cout << "Error: division by zero" << std::endl;
		invalidInterval();
		memoryuse.initialized1 = 0;
	}
	else
	{
	    double temp=  memoryuse.memory1;
        memoryuse.memory1 = 1/memoryuse.memory2;
		memoryuse.memory2 = 1/temp;
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}   //do standard invert operation
	return memoryuse;
}

fourLong ms(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0)
	{
		invalidInterval();
	}
	else
	{
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	    memoryuse.memory3 = memoryuse.memory1;   // copy instance to the memory
	    memoryuse.memory4 = memoryuse.memory2;
	    memoryuse.initialized2 = 1;
	}

	return memoryuse;
}

fourLong mr(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0&&memoryuse.initialized2 == 0)
	{
		invalidInterval();
	}
	else if(memoryuse.initialized2 != 0)
	{
		memoryuse.memory1 = memoryuse.memory3;
		memoryuse.memory2 = memoryuse.memory4;
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	else
	{
		memoryuse.initialized2 = 0;
		if(memoryuse.initialized1 == 1)
		{
			printImmediate(memoryuse.memory1, memoryuse.memory2);
		}
		else
		{
			invalidInterval();
		}
	}    //recover memory to the instance slot
	return memoryuse;
}

fourLong mc(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	memoryuse.initialized2 = 0;
	if(memoryuse.initialized1 == 0&&memoryuse.initialized2 == 0)
	{
		invalidInterval();
	}
	else
	{
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}          //set memory to be uninitialized
	return memoryuse;
}

fourLong mplu(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0 || memoryuse.initialized2 == 0)
	{
		invalidInterval();
	}
	else
	{
		memoryuse.memory3 += memoryuse.memory1;    //add
		memoryuse.memory4 += memoryuse.memory2;
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong msub(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0 || memoryuse.initialized2 == 0)
	{
		invalidInterval();
	}
	else
	{
		memoryuse.memory3 -= memoryuse.memory1;    //minus
		memoryuse.memory4 -= memoryuse.memory2;
		printImmediate(memoryuse.memory1, memoryuse.memory2);   //
	}
	return memoryuse;
}
fourLong scalar_add(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	if(memoryuse.initialized1 == 0 )
	{
		invalidInterval();
	}
	else
	{
		memoryuse.memory1 += std::stold(part2.c_str());   //add input
		memoryuse.memory2 += std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong scalar_subtract(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	if(memoryuse.initialized1 == 0 )
	{
		invalidInterval();
	}
	else
	{
		memoryuse.memory1 -= std::stold(part2.c_str());   //add input
		memoryuse.memory2 -= std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong scalar_multiply(std::string userInput, fourLong memory)
{
	fourLong memoryuse = memory;
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	if(memoryuse.initialized1 == 0)
	{
		invalidInterval();
	}
	else if(std::stold(part2.c_str()) == 0)
	{
		memoryuse.memory1 = 0;        //*0=0
		memoryuse.memory2 = 0;
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	else if(std::stold(part2.c_str()) > 0)
	{
		memoryuse.memory1 *= std::stold(part2.c_str());
		memoryuse.memory2 *= std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	else if(std::stold(part2.c_str()) < 0)
	{
		long double temp = memoryuse.memory1;            //use temp to swap and save
		memoryuse.memory1 = memoryuse.memory2*std::stold(part2.c_str());
		memoryuse.memory2 = temp*std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong scalar_divide(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
    std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0 )
	{
		invalidInterval();
	}
	else if(std::stold(part2.c_str()) == 0)
	{
		std::cout << "Error: division by zero" << std::endl;
		invalidInterval();
		memoryuse.initialized1 = 0;
	}
	else if(std::stold(part2.c_str()) > 0)
	{
		memoryuse.memory1 /= std::stold(part2.c_str());    //do operation for > 0
		memoryuse.memory2 /= std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	else if(std::stold(part2.c_str()) < 0)
	{
		long double temp = memoryuse.memory1;
		memoryuse.memory1 = memoryuse.memory2/std::stold(part2.c_str());
		memoryuse.memory2 = temp/std::stold(part2.c_str());    //do operation for < 0
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong scalar_divide_by(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
    std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 == 0 )
	{
		invalidInterval();
	}
	else if((memoryuse.memory1 < 0) && (memoryuse.memory2 > 0))
	{
		memoryuse.initialized1 = 0;
		std::cout << "Error: division by zero" << std::endl;
		invalidInterval();
	}
	else if(atof(part2.c_str()) > 0)
	{
		memoryuse.memory1 /= std::stold(part2.c_str());
		memoryuse.memory2 /= std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	else if(std::stold(part2.c_str()) < 0)
	{
		long double temp = memoryuse.memory1;
		memoryuse.memory1 = std::stold(part2.c_str())/memoryuse.memory2;
		memoryuse.memory2 = std::stold(part2.c_str())/temp;
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong interval_add(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
    std::string part3 = a.part3;
    fourLong memoryuse = memory;
	if((memoryuse.initialized1 == 0)&&(!(std::stold(part2.c_str()) > std::stold(part3.c_str()))))
	{
		invalidInterval();
	}
	else if(std::stold(part2.c_str()) > std::stold(part3.c_str()))
	{
		std::cout << "Error: invalid interval as " << std::stold(part2.c_str()) <<" > " << std::stold(part3.c_str()) << std::endl;
		if(memoryuse.initialized1 ==0)
		{
			invalidInterval();
		}
		else
		{
			printImmediate(memoryuse.memory1, memoryuse.memory2);
		}
	}
	else
	{
		memoryuse.memory1 += std::stold(part2.c_str());
		memoryuse.memory2 += std::stold(part3.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong interval_subtract(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(memoryuse.initialized1 ==0)
	{
		invalidInterval();
	}
	else if(std::stold(part2.c_str()) > std::stold(part3.c_str()))
	{
		std::cout << "Error: invalid interval as " << std::stold(part2.c_str()) <<" > " << std::stold(part3.c_str()) << std::endl;
		if(memoryuse.initialized1 ==0)
	    {
			invalidInterval();
		}
		else
		{
			printImmediate(memoryuse.memory1, memoryuse.memory2);
		}
	}
	else
	{
		memoryuse.memory1 -= std::stold(part3.c_str());
		memoryuse.memory2 -= std::stold(part2.c_str());
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong interval_multiply(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(std::stold(part2.c_str()) > std::stold(part3.c_str()))
	{
		std::cout << "Error: invalid interval as " << std::stold(part2.c_str()) <<" > " << std::stold(part3.c_str()) << std::endl;
		if(memoryuse.initialized1 ==0)
		{
			invalidInterval();
		}
		else
		{
			printImmediate(memoryuse.memory1, memoryuse.memory2);
		}
	}
	else if(memoryuse.initialized1 ==0)
	{
		invalidInterval();
	}
	else
	{
		long double a, b, c, d;
		a = memoryuse.memory1;
		b = memoryuse.memory2;
		c = std::stold(part2.c_str());
		d = std::stold(part3.c_str());
		memoryuse.memory1 = std::min(std::min(a*c, a*d),std::min(b*c, b*d));
		memoryuse.memory2 = std::max(std::max(a*c, a*d),std::max(b*c, b*d));
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong interval_divide(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(std::stold(part2.c_str()) > std::stold(part3.c_str()))
	{
		std::cout << "Error: invalid interval as " << std::stold(part2.c_str()) <<" > " << std::stold(part3.c_str()) << std::endl;
		if(memoryuse.initialized1 == 0)
		{
			invalidInterval();
		}
		else
				{
					printImmediate(memoryuse.memory1, memoryuse.memory2);
				}
	}
	else if(memoryuse.initialized1 == 0)
	{
		invalidInterval();
	}
	else if((std::stold(part2.c_str()) < 0) && (std::stold(part3.c_str()) > 0))
	{
		memoryuse.initialized1 = 0;
		std::cout << "Error: division by zero" << std::endl;
		invalidInterval();
	}
	else
	{
		double a, b, c, d;
		a = memoryuse.memory1;
		b = memoryuse.memory2;
		c = std::stold(part2.c_str());
		d = std::stold(part3.c_str());
		memoryuse.memory1 = std::min(std::min(a/c, a/d),std::min(b/c, b/d));
		memoryuse.memory2 = std::max(std::max(a/c, a/d),std::max(b/c, b/d));
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong intersect(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(std::stold(part2.c_str()) > std::stold(part3.c_str()))  //part 2 > part3
	{
		std::cout << "Error: invalid interval as " << std::stold(part2.c_str()) <<" > " << std::stold(part3.c_str()) << std::endl;
	}
	else if(memoryuse.memory1<=std::stold(part2.c_str())&&std::stold(part2.c_str())<=memoryuse.memory2&&memoryuse.memory2<=std::stold(part3.c_str()))
	{
		memoryuse.memory1 = std::stold(part2.c_str());  // m1<p2<m2<p3  pick p2 m2 change m1 to p2
	}
	else if(std::stold(part2.c_str())<=memoryuse.memory1&&memoryuse.memory1<=std::stold(part3.c_str())&&std::stold(part3.c_str())<=memoryuse.memory2)
	{
		memoryuse.memory2 = std::stold(part3.c_str());        // m2>p3>m1>p2
	}
	else if(memoryuse.memory1<= std::stold(part2.c_str())&&std::stold(part3.c_str())<=memoryuse.memory2)
	{
		memoryuse.memory1 = std::stold(part2.c_str());   //m1<p2<p3<m2     pick p2 ps change m12 to p23
		memoryuse.memory2 = std::stold(part3.c_str());
	}
	else if(memoryuse.memory1>= std::stold(part2.c_str())&&std::stold(part3.c_str())>=memoryuse.memory2)
	{
		//do nothing   still interval m1 m2
	}
	else
	{
		memoryuse.initialized1=0;
	}
	if(memoryuse.initialized1==0)
	{
		invalidInterval();
	}
	else
	{
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong integers(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
    std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;
	if(memoryuse.initialized1==0)
	{
		invalidInterval();
	}
	else
	{
		int a = ceil(memoryuse.memory1);
		int b = floor(memoryuse.memory2);
	    while(a < b)
		{
            std::cout << a << ", ";
            a++;
	    }
		std::cout << b;
	    std::cout << std::endl;
		printImmediate(memoryuse.memory1, memoryuse.memory2);
	}
	return memoryuse;
}
fourLong cartesian_integers(std::string userInput, fourLong memory)
{
	threePart a = breakString(userInput);
	std::string part2 = a.part2;
	std::string part3 = a.part3;
	fourLong memoryuse = memory;

	if(std::stold(part2.c_str()) > std::stold(part3.c_str()))
	{
		std::cout << "Error: invalid interval as " << part2 << " > " << part3 << std::endl;
	}
	else
	{
	       int min = ceil(memoryuse.memory1);
	       int mini = ceil(std::stold(part2.c_str()));
	       int max = floor(memoryuse.memory2);
	       int maxi = floor(std::stold(part3.c_str()));


	            for(int i = min; i < max; i++)
	            {
	                for(int j = mini; j <= maxi; j++)
	                {
	                    std::cout << "(" << i << ", " << j << "),";
	                }
	            }
	            for(int j = mini; j < maxi; j++)
	            	                {
	            	                    std::cout << "(" << max << ", " << j << "),";
	            	                }
	            std::cout << "(" <<  max << ", " << maxi << ")" <<std::endl;

	}
	if(memoryuse.initialized1 == 0)
			{
				invalidInterval();
			}
			else
			{
				printImmediate(memoryuse.memory1, memoryuse.memory2);
			}

	return memoryuse;   //pass the memory and instance slot in form of struct fourDouble
}
