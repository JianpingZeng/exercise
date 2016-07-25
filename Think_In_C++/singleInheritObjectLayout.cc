#include <iostream>
using namespace std;

class Base
{
	public:
		Base() :x(1), y(2) {}
		virtual void f()
		{
			cout<<"void Base::f() was called."<<endl;
		}
		virtual void g()
		{
			cout<<"void Base::g() was called."<<endl;
		}
	private:
		int x;
		int y;
}__attribute__((packed));

class Derived: public Base
{
	public:
		Derived() : Base() {}
		virtual void f()
		{
			cout <<"void Derived::f() was called."<<endl;
		}
		virtual void h()
		{
			cout << "void Derivied::h() was called."<<endl;
		}
};

using pFunc = void (*)(void);

int main()
{
	// delcares a object of type Base
	Derived obj;
	cout<<"The address of obj is: "<< (long*)&obj <<endl;
	cout<<"The address of virtual table is: "<< (long*)*((long*)&obj) <<endl;
	
	long** funcTable = (long**)&obj;
	for (int i = 0; (pFunc)funcTable[0][i] != NULL; i++)
	{
		((pFunc)funcTable[0][i])();
	}
	int* header = (int*)(funcTable + 1);
	cout <<"Base::x = "<< header[0]<<endl;
	cout <<"Base::y = "<< header[1]<<endl;
	return 0;
}
