#include <iostream>
#include <cmath>

using namespace std;

class fraction
{
    private:
        long long int  numerator;
        long long int denominator;

    public:
        fraction();
        fraction(long long int,long long int);
        fraction AddedTo (fraction value) const;
        fraction MultipliedBy (fraction value) const; //binary observer type of operation
        fraction Subtract (fraction value) const;
        fraction DividedBy (fraction value) const;
        bool isGreaterThan (fraction value);
        bool isEqualTo(fraction value);
        fraction simplify(fraction value) const;
        void print();
};
fraction::fraction()
{
	numerator=0;
	denominator=1;
}

fraction::fraction(long long int newNumerator, long long int newDenominator)
{
	for(int counter=2;counter <= min(newNumerator,newDenominator);counter++)
	{
	    while(newNumerator%counter==0 && newDenominator%counter==0)
	    {
	    	newNumerator=(newNumerator/counter);
	        newDenominator=(newDenominator/counter);
	    }
    }
	numerator=newNumerator;
    denominator=newDenominator;
}

fraction fraction::AddedTo (fraction value) const
{
    fraction result;
    result.numerator = (numerator * value.denominator)+(value.numerator*denominator);
    result.denominator = denominator * value.denominator;
    return simplify(result);

}

fraction fraction::Subtract (fraction value) const
{
    fraction result;
    result.numerator = (numerator * value.denominator)-(value.numerator*denominator);
    result.denominator = denominator * value.denominator;
    return simplify(result);
}
fraction fraction::MultipliedBy (fraction value) const
{
    fraction result;
    result.numerator = numerator * value.numerator;
    result.denominator = denominator * value.denominator;
    return simplify(result);
}
fraction fraction::DividedBy (fraction value) const
{
    fraction result;
    result.numerator = numerator * value.denominator;
    result.denominator = denominator * value.numerator;
    return simplify(result);
}
bool fraction::isGreaterThan (fraction value)
{
    int fraction1;
    int fraction2;
    fraction1=(numerator/denominator);
    fraction2=(value.numerator/value.denominator);
    if(fraction1-fraction2 > 0)
	    return true;
    else
	    return false;
}

bool fraction::isEqualTo(fraction value)
{
    if((numerator/denominator)==(value.numerator/value.denominator))
        return true;
    else
    	return false;
}

fraction fraction::simplify(fraction b) const
{
    int num=b.numerator;
    int den=b.denominator;

    for(int counter=2;counter <= min(num,den);counter++)
    {
        while(num%counter==0 && den%counter==0)
        {
            num=(num/counter);
            den=(den/counter);
        }
    }
    fraction a = fraction(num,den);
    return a;
}

void fraction::print()
{
	cout << numerator << "/" << denominator;
}
