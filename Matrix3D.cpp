#include <iostream>
#include "Matrix3D.h"

using namespace std;

Matrix3D::Matrix3D() {}
Matrix3D::Matrix3D(double a11, double a12, double a13,
				   double a21, double a22, double a23,
				   double a31, double a32, double a33)
{
	a[0][0] = a11;
	a[0][1] = a12;
	a[0][2] = a13;
	a[1][0] = a21;
	a[1][1] = a22;
	a[1][2] = a23;
	a[2][0] = a31;
	a[2][1] = a32;
	a[2][2] = a33;
}
Matrix3D::~Matrix3D() {}

double Matrix3D::getAij(int i, int j) const { return a[i][j]; }

void Matrix3D::setAij(int i, int j, double x) { a[i][j] = x; }

Matrix3D Matrix3D::operator* (double l)
{
	Matrix3D m(0,0,0,0,0,0,0,0,0);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m.a[i][j] = a[i][j]*l;
	return m;
}

Matrix3D Matrix3D::operator+ (Matrix3D& m2)
{
	Matrix3D m;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m.a[i][j] = a[i][j] + m2.a[i][j];
	return m;
}

Matrix3D Matrix3D::operator- (Matrix3D& m2) {
	Matrix3D m;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m.a[i][j] = a[i][j] - m2.a[i][j];
	return m;
}


Matrix3D Matrix3D::operator* (Matrix3D& m2) {
	Matrix3D m(0,0,0,0,0,0,0,0,0);
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				m.a[i][j] += a[i][k]*m2.a[k][j];
	return m;
}

Vector3D Matrix3D::operator* (Vector3D& v)
{
	Vector3D res(0,0,0);
	res.setX(a[0][0]*v.getX() + a[0][1]*v.getY() + a[0][2]*v.getZ());
	res.setY(a[1][0]*v.getX() + a[1][1]*v.getY() + a[1][2]*v.getZ());
	res.setZ(a[2][0]*v.getX() + a[2][1]*v.getY() + a[2][2]*v.getZ());
	return res;
}

double Matrix3D::det()
{
	return    a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
			- a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
			+ a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
}

Matrix3D operator* (double l, Matrix3D& m2)
{
	Matrix3D m(0,0,0,0,0,0,0,0,0);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m.setAij(i, j, m2.getAij(i,j)*l);
	return m;
}

std::ostream& operator<<(std::ostream& os, const Matrix3D& v)
{
	os << "| " << v.getAij(0, 0) << " " << v.getAij(0, 1) << " " << v.getAij(0, 2) << " |" << endl;
	os << "| " << v.getAij(1, 0) << " " << v.getAij(1, 1) << " " << v.getAij(1, 2) << " |" << endl;
	os << "| " << v.getAij(2, 0) << " " << v.getAij(2, 1) << " " << v.getAij(2, 2) << " |";
	return os;
}	

std::istream& operator>>(std::istream& is, Matrix3D& m)
{
	double t;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			is >> t;
			m.setAij(i, j, t);
		}
	return is;
}