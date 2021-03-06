#include <iostream>
#include "Vector3D.h"

using namespace std;


Vector3D::Vector3D() {};
Vector3D::Vector3D(double x, double y, double z): x(x), y(y), z(z) {};
Vector3D::~Vector3D() {};


double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }


void Vector3D::setX(double X) { x = X; }
void Vector3D::setY(double Y) { y = Y; }
void Vector3D::setZ(double Z) { z = Z; }

Vector3D Vector3D::operator=(Vector3D& v2)
{
	Vector3D v;
	v.setX(v2.getX());
	v.setY(v2.getY());
	v.setZ(v2.getZ());
	return v;
}

Vector3D Vector3D::operator*(double a)
{
	return Vector3D(x*a, y*a, z*a);
}

Vector3D Vector3D::operator+ (Vector3D& v2)
{
	return Vector3D(x + v2.x, y + v2.y, z + v2.z);
}

Vector3D Vector3D::operator- (Vector3D& v2)
{
	return Vector3D(x - v2.x, y - v2.y, z - v2.z);
}

double Vector3D::operator* (Vector3D& v2)
{
	return x*v2.x + y*v2.y + z*v2.z;
}

Vector3D operator* (double a, Vector3D &v)
{
	return Vector3D(v.getX()*a, v.getY()*a, v.getZ()*a);
}

ostream& operator<<(ostream& os, const Vector3D& v)
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