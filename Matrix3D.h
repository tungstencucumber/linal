#include <iostream>

class Matrix3D
{
private:
	double a[3][3];
public:
	Matrix3D();
	Matrix3D(double a11, double a12, double a13,
			double a21, double a22, double a23,
			double a31, double a32, double a33);
	~Matrix3D();

	double getAij(int i, int j);

	void setAij(int i, int j, double a);

	Matrix3D operator* (double a);
	Matrix3D operator+ (Matrix3D& m2);
	Matrix3D operator- (Matrix3D& m2);
	Matrix3D operator* (Matrix3D& m2);
	Vector3D operator* (Vector3D& v);

	double det();
};

Matrix3D operator* (Matrix3D& m, double a);

std::ostream& operator<<(std::ostream& os, Matrix3D& v);
std::istream& operator>>(std::istream& is, Matrix3D& v);