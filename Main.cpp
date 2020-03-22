#include <iostream>
#include "Matrix3D.h"

using namespace std;

int main()
{
	Matrix3D test;
	cin >> test;
	cout << "Hello, world!" << endl;
	Vector3D x(1, 0, 0);
	x = test*x;
	cout << x;
	return 0;
}