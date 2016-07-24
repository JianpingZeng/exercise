#include <stdio.h>

typedef struct
{
	char ch;
	int a;
}__attribute__((packed))my;

int main()
{
	printf("sizeof(my)=%lu\n", sizeof(my));
	return 0;
}
