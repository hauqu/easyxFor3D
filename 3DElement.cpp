#include"3DElement.h"
Vect::Vect(Point3D p1, Point3D p2)
{
	x = p2.x - p1.x;
	y = p2.y - p1.y;
	z = p2.z - p1.z;
}
Vect::Vect(Point3D p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}
double Vect::norm(void)
{
	return  sqrt(x * x + y * y + z * z);
}
void Vect::show()
{
	std::cout
		<< "(" << x <<
		"," << y <<
		"," << z << ")"
		<< std::endl;
}
inline Vect Vect::operator+(Vect v)
{
	Vect p;
	p.x = this->x + v.x;
	p.y = this->y + v.y;
	p.z = this->z + v.z;
	return p;
}
inline Vect Vect::operator-(Vect v)
{
	Vect p;
	p.x = this->x - v.x;
	p.y = this->y - v.y;
	p.z = this->z - v.z;
	return p;
}
inline double Vect::operator*(Vect v)
{
	return (this->x * v.x + this->y * v.y + this->z * v.z);
}
inline Vect Vect::operator^(Vect v)
{
	Vect p;
	p.x = (this->y * v.z - v.y * this->z);
	p.z = (this->x * v.y - v.x * this->y);
	p.y = (this->x * v.z - v.x * this->z);
	return p;
}
inline Vect Vect::operator/(double k)
{
	Vect nn;
	nn.x = this->x / k;
	nn.y = this->y / k;
	nn.z = this->z / k;
	return nn;
}//∞¥±»¿˝Àı–°

Point3D::Point3D()
{
	x = 0.0; y = 0.0; z = 0.0; visable = true;
}

double Point3D::norm(void)
{
	return  sqrt(x * x + y * y + z * z);
}

void Point3D::show()
{
	std::cout
		<< "(" << x <<
		"," << y <<
		"," << z << ")"
		<< std::endl;
}

Point3D Point3D::operator*(double k)
{
	return Point3D(x * k, y * k, z * k);
}

bool Point3D::operator==(Point3D p)
{
	if (x == p.x)
		if (y == p.y)
			if (z == p.z)
				return true;
	return false;
}

bool Point3D::isVisable()
{
	return visable;
}

void Point3D::setVisable(bool v)
{
	visable = v;
}
