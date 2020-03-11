#include <iostream>
#include "Vector3D.h"

using namespace std;

class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D() {};
	Vector3D(double x, double y, double z): x(x), y(y), z(z);
	~Vector3D() {};


	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }


	void setX(double X) { x = X; }
	void setY(double Y) { y = Y; }
	void setZ(double Z) { z = Z; }


	Vector3D operator* (double a)
	{
		return Vector3D(x*a, y*a, z*a);
	}

	Vector3D operator+ (Vector3D v2)
	{
		return Vector3D(x + v2.x, y + v2.y, z + v2.z);
	}

	Vector3D operator- (Vector3D v2)
	{
		return Vector3D(x - v2.x, y - v2.y, z - v2.z);
	}

	double operator* (Vector3D v2)
	{
		return x*v2.x + y*v2.y + z*v2.z;
	}
}

Vector3D operator* (Vector3D& v, double a)
{
	return Vector3D(x*a, y*a, z*a);
}

ostream& operator<<(ostream& os, Vector3D& v)
{
	os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
	return os;
}

istream& operator>>(istream& is, Vector3D& v)
{
	double a, b, c;
	is >> a >> b >> c;
	v.setX(a); v.setY(b); v.setZ(c);
	return is;
}