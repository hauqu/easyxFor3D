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
}//按比例缩小
inline Vect Vect::revluteVectorz(double angle_z)
{

	if (angle_z == 0)
		return *this;
	if (x == 0 && y == 0)
		return *this;

	Vect pp;
	pp.z = this->z;
	double r = sqrt((x * x + y * y));
	if (x == 0)//特殊处理
	{
		double angle_xy = 0.0;
		angle_xy += angle_z;
		pp.x = r * cos(angle_xy);
		pp.y = r * sin(angle_xy);
	}
	else
	{
		double angle_xy = atan(y / x);
		if (x < 0) angle_xy += P;//区分二四象限和一三象限的角度
		angle_xy += angle_z;
		pp.x = r * cos(angle_xy);
		pp.y = r * sin(angle_xy);
	}
	return pp;
}
inline Vect Vect::revluteVectxoy(double angle)
{
	Vect pp;
	double pr = this->norm();//原向量的模
	double pr_xy = sqrt(x * x + y * y);//原向量在xoy平面上的投影的模
	double angle_xy = atan(z / pr_xy);//向量与xoy面的夹角
	angle_xy += angle;
	double ppr_xy = pr * cos(angle_xy);//旋转后平面投影的模
	double k = ppr_xy / pr_xy;//缩放比例
	pp.x = x * k; pp.y = y * k;
	pp.z = pr * sin(angle_xy);
	return pp;


}






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
