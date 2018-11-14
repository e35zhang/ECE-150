#include<iostream>
#include<cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

struct poly_t
{
    double * a_coeffs;
    unsigned int degree;
};

void init_poly( poly_t &p, double const init_coeffs[], unsigned int const init_degree );
void destroy_poly( poly_t &p );
unsigned int poly_degree( poly_t const &p );
double poly_coeff( poly_t const &p, unsigned int n );
double poly_val( poly_t const &p, double const x );
void poly_add( poly_t &p, poly_t const &q );
void poly_subtract( poly_t &p, poly_t const &q );
void poly_multiply( poly_t &p, poly_t const &q );
double poly_divide( poly_t &p, double r );
void poly_diff( poly_t &p );
double poly_approx_int( poly_t const &p,double a, double b, unsigned int n );



void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree)
{
    if(p.a_coeffs != nullptr) //check deallocate
    {
    	destroy_poly(p);
    }
    p.a_coeffs= new double[init_degree+1];
    for(std::size_t i = 0; i <= init_degree; ++i) // {}++i
    {
        p.a_coeffs[i]= init_coeffs[i];
    }
    p.degree = init_degree;
}
void destroy_poly(poly_t &p)
{
	    delete[] p.a_coeffs;
	    p.a_coeffs = nullptr;
}
unsigned int poly_degree(poly_t const &p)
{
    if(p.a_coeffs == nullptr)
    {
    	throw 0;   //not sure throw?
    }
    return p.degree;
}
double poly_coeff(poly_t const &p, unsigned int n)
{
	if(p.a_coeffs == nullptr)
	{
		throw 0;    //not sure throw?
	}
	if(p.degree >= n)
	{
		return p.a_coeffs[n];
	}
	else
	{
		return 0;
	}
}
double poly_val( poly_t const &p, double const x )
{
	if(p.a_coeffs == nullptr)
    {
		throw 0;    //not sure throw?
	}
	double result = p.a_coeffs[p.degree];
	for(unsigned int i = p.degree; i > 0; i--)
	{
		result = result*x + p.a_coeffs[i-1];
	}
	return result;
}
/*void poly_add( poly_t &p, poly_t const &q )
{
	if(p.a_coeffs == nullptr)
	{
		throw 1;	    //not sure throw?
    }
	else
	{
        for(unsigned int i = 0; i <= std::max(p.degree,q.degree); i++)
        {
            if(i<=p.degree)
            {
                *p.a_coeffs[i] += *q.a_coeffs[i];
            }
            else
            {
            	p.a_coeffs[i]= new double;
            	*p.a_coeffs[i]= *q.a_coeffs[i];
            }
        }
        p.degree = std::max(p.degree,q.degree);
        for(unsigned int i = p.degree; i >= 0; i--)
        {
            if(*p.a_coeffs[i] == 0)
            {
            	p.degree--;
            }
            else
            {
            	break;
            }
        }
    }
}
void poly_subtract( poly_t &p, poly_t const &q )
{
	if(p.a_coeffs == nullptr)
	{
		throw 1;	    //not sure throw?
	}
	else
	{
	    for(unsigned int i = 0; i <= std::max(p.degree,q.degree); i++)
	    {
	        if(i<=p.degree)
	        {
	            *p.a_coeffs[i] -= *q.a_coeffs[i];
	        }
	        else
	        {
	            p.a_coeffs[i]= new double;
	            *p.a_coeffs[i]= *q.a_coeffs[i];
	        }
	    }
	    p.degree = std::max(p.degree,q.degree);
	    for(unsigned int i = p.degree; i >= 0; i--)
	    {
	        if(*p.a_coeffs[i] == 0)
	        {
	            p.degree--;
	        }
	        else
	        {
	            break;
	        }
	    }
	}
}*/
void poly_add( poly_t &p, poly_t const &q )
{
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr)
	{
		throw 0;	    //not sure throw?
    }

	double *pnew= new double[std::max(p.degree,q.degree)+1];
		for(unsigned int i = 0; i <= std::max(p.degree,q.degree); i++)
        {
            if(i<=std::min(p.degree,q.degree))
			{
				pnew[i] = p.a_coeffs[i] + q.a_coeffs[i];
			}
			else 
			{
				if(p.degree >=q.degree)
				{
					pnew[i] = p.a_coeffs[i];
				}
                else
				{
                    pnew[i] = q.a_coeffs[i];
				}
			}
        }
        p.degree = std::max(p.degree,q.degree);
		delete[] p.a_coeffs;
        p.a_coeffs = pnew;
        for(unsigned int i = p.degree; i >= 0; i--)
        {
            if(p.a_coeffs[i] == 0)
            {
            	p.degree--;
            }
            else
            {
            	break;
            }
        }
		

}
void poly_subtract( poly_t &p, poly_t const &q )
{
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr)
	{
		throw 0;	    //not sure throw?
    }

	double *pnew= new double[std::max(p.degree,q.degree)+1];
		for(unsigned int i = 0; i <= std::max(p.degree,q.degree); i++)
        {
			if(i<=std::min(p.degree,q.degree))
			{
				pnew[i] = p.a_coeffs[i] - q.a_coeffs[i];
			}
			else 
			{
				if(p.degree >=q.degree)
				{
					pnew[i] = p.a_coeffs[i];
				}
                else
				{
                    pnew[i] = -q.a_coeffs[i];
				}
			}
        }
        p.degree = std::max(p.degree,q.degree);
		delete[] p.a_coeffs;
        p.a_coeffs = pnew;
        for(unsigned int i = p.degree; i >= 0; i--)
        {
            if(p.a_coeffs[i] == 0)
            {
            	p.degree--;
            }
            else
            {
            	break;
            }
        }
		

}
void poly_multiply( poly_t &p, poly_t const &q )
{
    if(p.a_coeffs == nullptr || q.a_coeffs == nullptr)
    {
    	throw 0;
    }

    double *pnew= new double[p.degree+q.degree+2];
        for (unsigned int i = 0; i <= p.degree+q.degree; i++)
        {
	       pnew[i] = 0;
        }
        for (unsigned int i = 0; i <= p.degree; i++)
        {
            for (unsigned int j = 0; j <= q.degree; j++)
            {
                int power =i + j;
                double coeff = (p.a_coeffs[i])*(q.a_coeffs[j]);
                pnew[power] += coeff;
             }
        }
		delete[] p.a_coeffs;
        p.a_coeffs = pnew;
    	p.degree = p.degree+q.degree;
	
}


double poly_divide( poly_t &p, double r )
{
    if(p.a_coeffs == nullptr)
    {
    	throw 0;
    }
	if(p.degree == 0)
	{
        return p.a_coeffs[0];
	}
	double *pnew = new double[p.degree];
	double result = p.a_coeffs[p.degree];
	for(unsigned int i = p.degree; i >= 1; i--)
	{
        pnew[i-1] = result;
		result = result*r+p.a_coeffs[i-1];
	}
	delete[] p.a_coeffs;
    p.a_coeffs = pnew;
    p.degree = p.degree-1;
	return result;
}

void poly_diff( poly_t &p )
{
    if((p.a_coeffs == nullptr) || (p.degree == 0))
    {
    	throw 0;
    }
	double *pnew= new double[p.degree+1];
    for (unsigned int i = 0; i < p.degree; i++)
    {
	    pnew[i] = p.a_coeffs[i+1]*(i+1);
    }
	delete[] p.a_coeffs;
	p.a_coeffs = pnew;
	p.degree--;
	
}
double poly_approx_int( poly_t const &p,double a, double b, unsigned int n )
{
    if(p.a_coeffs == nullptr)
    {
    	throw 0;
    }
	double h = (b-a)/n;
	double sum = poly_val(p,a) + poly_val(p,b);
	for(unsigned int i = 1; i < n; ++i)
	{
        sum += 2*poly_val(p,a+i*h);
	}
	return sum*h/2;
}
