// Framis.cc
// Local overloaded new and delete
#include <cstddef>
#include <fstream>
#include <iostream>
#include <new>
using namespace std;

class Framis 
{
	static const int sz = 10;
	char c[sz];	// to take up space, not used
	static uint8_t pool[];
	static bool alloc_map[];
	public:
		static const int PSIZE = 100;
		Framis()
		{
			cout << "Framis()\n";
		}
		~Framis() 
		{
			cout << "~Framis()\n";
		}
		void* operator new(size_t) throw (bad_alloc);
		void operator delete(void*);
};

uint8_t Framis::pool[Framis::PSIZE * sizeof(Framis)];
bool Framis::alloc_map[Framis::PSIZE] = {false};

void* Framis::operator new(size_t) throw (bad_alloc)
{
	for(int i = 0; i < Framis::PSIZE;i++)
	{
		if (!alloc_map[i])
		{
			cout << "using block "<< i << "..."<<endl;
			alloc_map[i] = true;
			return (pool + sizeof(Framis)*i);			
		}
	}	
	cout << "out of memory..."<<endl;
	throw bad_alloc();
}

void Framis::operator delete(void* m)
{
	// check out null pointer
	if (m == nullptr) return;

	unsigned long block = (unsigned long)m - (unsigned long)pool;
	block = block / sizeof(Framis);
	cout << "freeing block "<< block<<endl;
	
	// mark it as freed
	alloc_map[(uint32_t)block] = false;
	return;
}

int main()
{
	Framis* f[Framis::PSIZE];
	try
	{
		for (int i = 0; i < Framis::PSIZE; i++)
			f[i] = new Framis();
		new Framis; // out of memory		
	}
	catch(bad_alloc)
	{
		cout<<"out of memory..."<<endl;
	}

	delete f[10];
	f[10] = nullptr;
	//use released memory
	Framis* x = new Framis();
	delete x;
	for (int j = 0; j < Framis::PSIZE; j++)
		delete f[j];
	
	return 0;	
}
