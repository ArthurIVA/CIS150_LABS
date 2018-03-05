#include <iostream>

using namespace std;

int main()
{
	int x = 5, y = 10, a, b;

	a = x + (y++);
	b = (--x) + y;

	cout << "x = " << x << " y = " << y << " a = " << a << " b = " << b;

	system("pause");
	return 0;
}