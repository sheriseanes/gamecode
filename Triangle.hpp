/*
version 0.1
*/
#include <math>

/*
use: get the triangle's area
parameter: triangle's side
*/
template <class A>
A heronFormula(A a, A b, A c)
{
	A p = (a+b+c)/2;
	A temp = p*(p-a)*(p-b)*(p-c);
	return sqrt(temp);
}