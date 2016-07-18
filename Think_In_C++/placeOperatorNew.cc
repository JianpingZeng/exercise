// PlaceOperationNew.cc
// constructs a object of type X in specified memory space, like array buffer

#include <cstddef>
#include <iostream>

class AllocateWithRelocation
{
	private:
		int x;
	public:
		AllocateWithRelocation(int i_) : x(i_)
		{
			std::cout <<"this = "<< this<<std::endl;
		}
		~AllocateWithRelocation()
		{
			std::cout <<"AllocateWithRelocation::~AllocateWithRelocation(): "<<this<<std::endl;
		}

		void* operator new(size_t, void* loc)
		{
			return loc;
		}
};

int main()
{
	int l[10];
	std::cout<<"l = "<< l<< std::endl;
	// 
	AllocateWithRelocation* xp = new(l) AllocateWithRelocation(47);
	xp->~AllocateWithRelocation(); 	// explicit calling to destructing
	return 0;
}

