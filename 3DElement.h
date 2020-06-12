#pragma once
#include<cmath>
#include<iostream>
extern const double P=3.1415926;//圆周率
extern const double KP=180/P;//弧度转角度
extern const double PK=P/180;//角度转弧度

typedef int weight;
class Edge
{
public:
	int p1;
	int p2;
	weight w;
	Edge(int p1, int p2, weight we)
	{
		this->p1 = p1;
		this->p2 = p2;
		w = we;
	};
	Edge(int p1, int p2)
	{
		this->p1 = p1;
		this->p2 = p2;
		w = 1;
	};
	~Edge() {};
};

class Point2D
{
public:
	double x;
	double y;
	void show()
	{
		std::cout
			<< "(" << x <<
			"," << y <<
			"," << ")"
			<< std::endl;
	}
	Point2D() { x = 0.0; y = 0.0; }
	~Point2D() {}

};//对2维点进行定义

class Point3D
{
public:
	double x;
	double y;
	double z;

	Point3D();
	Point3D(double _x, double _y, double _z) :x(_x), y(_y), z(_z), visable(true) {}
	double norm(void);//求模
	void show();
	Point3D operator*(double k);
	bool operator==(Point3D p);
	bool isVisable();
	void setVisable(bool v);
	//Point3D revlutePointz(double angle_z);
	//Point3D revlutePointxoy(double angle);

	~Point3D() {};
public:
	bool visable;
};//三维点定义


class Vect :public Point3D
{
public:
	Vect() { x = 0.0; y = 0.0; z = 0.0; }
	Vect(Point3D p1, Point3D p2);//默认p2-p1
	
	Vect(Point3D p);
	
	~Vect() {};
	double norm(void);//求模
	
	void show();
	Vect operator+(Vect v);//加
	Vect operator-(Vect v);//减
	double operator*(Vect v);//点乘
	Vect operator^(Vect v);//叉乘
	Vect operator/(double k);//按比例缩小

	Vect revluteVectorz(double angle_z);
	Vect revluteVectxoy(double angle);//绕z轴旋转后的旋转，参数大于0 ，接近z轴正方向

};//三维向量定义
//向量可以由两点定义，可以由两外两个向量定义
