int foo(int a, int b, int c, int d)
{
	int e = a*b + c * d;
	return e + d;
}

int main()
{
	int a, b, c, d;
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	int res = foo(a, b, c, d);
	return res;
}
