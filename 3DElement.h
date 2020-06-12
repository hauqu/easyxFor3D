#pragma once
#include<cmath>
#include<iostream>
extern const double P=3.1415926;//Բ����
extern const double KP=180/P;//����ת�Ƕ�
extern const double PK=P/180;//�Ƕ�ת����

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

};//��2ά����ж���

class Point3D
{
public:
	double x;
	double y;
	double z;

	Point3D();
	Point3D(double _x, double _y, double _z) :x(_x), y(_y), z(_z), visable(true) {}
	double norm(void);//��ģ
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
};//��ά�㶨��


class Vect :public Point3D
{
public:
	Vect() { x = 0.0; y = 0.0; z = 0.0; }
	Vect(Point3D p1, Point3D p2);//Ĭ��p2-p1
	
	Vect(Point3D p);
	
	~Vect() {};
	double norm(void);//��ģ
	
	void show();
	Vect operator+(Vect v);//��
	Vect operator-(Vect v);//��
	double operator*(Vect v);//���
	Vect operator^(Vect v);//���
	Vect operator/(double k);//��������С

	Vect revluteVectorz(double angle_z);
	Vect revluteVectxoy(double angle);//��z����ת�����ת����������0 ���ӽ�z��������

};//��ά��������
//�������������㶨�壬����������������������
