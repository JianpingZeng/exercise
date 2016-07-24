#include <iostream>
using namespace std;

template<typename T>
T accumulate(T const* begin, T const* end)
{
	T total = T();
	while (begin != end)
	{
		total += *begin;
		++begin;
	}
	return total;
}

int main(int argc, char** argv)
{
	int test[] = {1, 2,3, 4, 5};
	char chartest[] ="template";
	int r = accumulate(test, test + 5);
	int r2 = accumulate(chartest, chartest + sizeof(chartest));	;
	cout <<"r is "<<r << endl;
	cout <<"r2 is "<<r2<<endl;
	return 0;
}
