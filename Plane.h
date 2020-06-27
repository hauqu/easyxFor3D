#pragma once
#include"3DElement.h"
class Plane
{
public:
	Plane(Point3D _A, Point3D B, Point3D C);
	Point3D O;
	Vect N;//平面法向量
	//平面上的三个点，用于确定平面法向量
	Point3D A;
	Point3D B;
	Point3D C;

	Point3D subPoint(Point3D p);
	
};
inline Plane::Plane(Point3D _A, Point3D _B, Point3D _C)
{
	A = _A;
	B = _B;
	C = _C;
	//计算法向量
}
Point3D Plane::subPoint(Point3D p)
{
	Point3D pp;//所求投影点坐标
	double temp_n = (N.x * N.x + N.y * N.y + N.z * N.z);
	pp.x = (N.x * N.y * O.y + N.y * N.y * p.x - N.x * N.y * p.y + N.x * N.z * O.z + N.z * N.z * p.x - N.x * N.z * p.z + N.x * N.x * O.x)
		/ temp_n;
	pp.y = (N.y * N.z * O.z + N.z * N.z * p.y - N.y * N.z * p.z + N.y * N.x * O.x + N.x * N.x * p.y - N.x * N.y * p.x + N.y * N.y * O.y)
		/ temp_n;
	pp.z = (N.x * O.x * N.z + N.x * N.x * p.z - N.x * p.x * N.z + N.y * O.y * N.z + N.y * N.y * p.z - N.y * p.y * N.z + N.z * N.z * O.z)
		/ temp_n;
	return pp;
}
class Camera:public Plane
{

};