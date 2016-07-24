#include <iostream>
using namespace std;

/**
 * This class is the base template class of trait, but it isn't needed to define
 * since it doesn't be used.
 */ 
template<typename T>
class AccumulateTrait;

template<> class AccumulateTrait<char>
{
	public:
		typedef int AccT;		  	
};

template<>
class AccumulateTrait<int>
{
	public:
		typedef long long AccT;
};

template<>
class AccumulateTrait<short>
{
	public:
		typedef int AccT;		  	
};
template<>
class AccumulateTrait<unsigned>
{
	public:
		typedef long long AccT;		  	
};

template<>
class AccumulateTrait<float>
{
	public:
		typedef double AccT;		  	
};

template<typename T>
typename AccumulateTrait<T>::AccT accumulate(T const* begin, T const* end)
{
	typedef typename  AccumulateTrait<T>::AccT AccT;
	AccT total = AccT();
	while (begin != end)
	{
		total += *begin;
		++begin;
	}
	return total;
}


int main(void)
{
	int test[] = {1, 2,3, 4, 5};
	char chartest[] ="template";
	int r = accumulate(test, test + 5);
	int r2 = accumulate(chartest, chartest + sizeof(chartest));	;
	cout <<"r is "<<r << endl;
	cout <<"r2 is "<<r2<<endl;
	return 0;
}
