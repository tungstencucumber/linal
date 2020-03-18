#include <iostream>
#include "Matrix3D.h"
#include "Vector3D.h"

using namespace std;

Matrix3D::Matrix3D() {};
Matrix3D::Matrix3D(double a11, double a12, double a13,
				   double a21, double a22, double a23,
				   double a31, double a32, double a33):
				{ a[0][0], a[0][1], a[0][2], 
				  a[1][0], a[1][1], a[1][2], 
				  a[2][0], a[2][1], a[2][2] };
Matrix3D::~Matrix3D() {};

double Matrix3D::getAij(int i, int j) { return a[i][j]; }

void Matrix3D::setAij(int i, int j, double x) { a[i][j] = x; }

Matrix3D Matrix3D::operator* (double a)
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			a[i][j] *= a;
}

Matrix3D Matrix3D::operator+ (Matrix3D& m2)
{
	Matrix3D m;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m.a[i][j] = a[i][j] + m2.a[i][j];
	return m;
}

Matrix3D Matrix3D::operator- (Matrix3D& m2)
{

}
Matrix3D Matrix3D::operator* (Matrix3D& m2)
{

}
Vector3D Matrix3D::operator* (Vector3D& v)
{

}

double Matrix3D::det()
{

}

Matrix3D operator* (Matrix3D& m, double a)
{

}

std::ostream& operator<<(std::ostream& os, Matrix3D& v)
{

}
std::istream& operator>>(std::istream& is, Matrix3D& v)
{
	
}