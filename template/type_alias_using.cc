#include <string>
#include <ios>
#include <type_traits>
#include <iostream>

/**
 *type alias, identical to typedef std::ios_base::fmtflags flags 
 */ 
using flags = std::ios_base::fmtflags;

// the name 'flags' now denotes a type 
flags fl = std::ios_base::dec;

/**
 * type alias, identical to typedef void (*func) (int, int);
 * 
 */
using func = void (*) (int, int);
void example(int a, int b)
{
	std::cout<<a << ","<<b<<std::endl;
}

func f = example;

// alias template
template<class T>
using ptr = T*;
// the name 'ptr<T>' is now an alias for pointer of type T.
ptr<int> x;

int main()
{
	int a = 1;
	f(1, 2);
	x = &a;
	*x = 2;
	f(*x, *x);
	return 0;
}
