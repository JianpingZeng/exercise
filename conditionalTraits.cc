#include <iostream>
#include<typeinfo>
using namespace std;
int main()
{
	using A = std::conditional<true, int, float>::type;
	using B = std::conditional<false, int, float>::type;
	using C = std::conditional<std::is_integral<A>::value, long, int>::type;
	using D = std::conditional<std::is_integral<B>::value, long, int>::type;
	cout<<typeid(A).name()<<endl;
	cout<<typeid(B).name()<<endl;
	cout<<typeid(C).name()<<endl;
	cout<<typeid(D).name()<<endl;
	return 0;
}
