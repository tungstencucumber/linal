#include <iostream>

class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();

	double getX();
	double getY();
	double getZ();

	void setX(double X);
	void setY(double Y);
	void setZ(double Z);

	Vector3D operator* (double a);
	Vector3D operator+ (Vector3D& v2);
	Vector3D operator- (Vector3D& v2);
	double operator* (Vector3D& v2);
};

Vector3D operator* (Vector3D& v, double a);

std::ostream& operator<<(std::ostream& os, Vector3D& v);
std::istream& operator>>(std::istream& is, Vector3D& v);