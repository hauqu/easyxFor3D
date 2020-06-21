#pragma once
#include"3DElement.h"

class Screen
{
public:
	Point3D O;//ƽ�����ĵ�
	Vect N;//ƽ�淨����
	Vect X;//ƽ��x�᷽��
	Vect Y;//ƽ��y�᷽��
	int ScreenW;
	int ScreenH;
	Screen();//Ĭ�Ϲ���45
	Screen(Point3D o, Vect n, Vect x, Vect y, int sw, int sh);
	void show()
	{
		std::cout << "O:"; O.show();
		std::cout << "N:"; N.show();
		std::cout << "X:"; X.show();
		std::cout << "Y:"; Y.show();
		std::cout << "W:" << ScreenW << std::endl;
		std::cout << "H:" << ScreenH << std::endl;
	}
	Point3D subPoint(Point3D p)
	{
		Point3D pp;//����ͶӰ������


		double temp_n = (N.x * N.x + N.y * N.y + N.z * N.z);
		pp.x = (N.x * N.y * O.y + N.y * N.y * p.x - N.x * N.y * p.y + N.x * N.z * O.z + N.z * N.z * p.x - N.x * N.z * p.z + N.x * N.x * O.x)
			/ temp_n;
		pp.y = (N.y * N.z * O.z + N.z * N.z * p.y - N.y * N.z * p.z + N.y * N.x * O.x + N.x * N.x * p.y - N.x * N.y * p.x + N.y * N.y * O.y)
			/ temp_n;
		pp.z = (N.x * O.x * N.z + N.x * N.x * p.z - N.x * p.x * N.z + N.y * O.y * N.z + N.y * N.y * p.z - N.y * p.y * N.z + N.z * N.z * O.z)
			/ temp_n;
		return pp;
	}
	Point2D dropShadow(Point3D p)
	{
		Point3D pp;//����ͶӰ������


		double temp_n = (N.x * N.x + N.y * N.y + N.z * N.z);
		pp.x = (N.x * N.y * O.y + N.y * N.y * p.x - N.x * N.y * p.y + N.x * N.z * O.z + N.z * N.z * p.x - N.x * N.z * p.z + N.x * N.x * O.x)
			/ temp_n;
		pp.y = (N.y * N.z * O.z + N.z * N.z * p.y - N.y * N.z * p.z + N.y * N.x * O.x + N.x * N.x * p.y - N.x * N.y * p.x + N.y * N.y * O.y)
			/ temp_n;
		pp.z = (N.x * O.x * N.z + N.x * N.x * p.z - N.x * p.x * N.z + N.y * O.y * N.z + N.y * N.y * p.z - N.y * p.y * N.z + N.z * N.z * O.z)
			/ temp_n;
		Vect Opp(O, pp);
		Point2D draw;
		draw.x = (Opp * X / X.norm()) * (1000.0 / ScreenW);
		draw.y = (Opp * Y / Y.norm() * (1000.0 / ScreenH));
		/*
		a * b =|a| * |b|cos <a,b>;
		*/
		return draw;
	}

	Screen revlutePlanez(double angle_z);
	Screen revlutePlanexOy(double angle);
	Screen	movePlane(Vect v);



	Screen operator*(double k)//��Ļ����
	{

		return Screen(O, N, X, Y, k * ScreenW, k * ScreenH);

	}
	Screen operator+(double k)
	{
		return Screen(O, N, X, Y, ScreenW + k, ScreenH + k);
	}
	Screen operator-(double k)
	{
		return Screen(O, N, X, Y, ScreenW - k, ScreenH - k);
	}
	~Screen() {};
};
Screen::Screen()
{
	N = Vect(Point3D(1.0, 1.0, 1.0));
	O = Point3D(0.0, 0.0, 0.0);
	X = Vect(Point3D(0.0, 1.0, 0.0), Point3D(1.0, 0.0, 0.0));
	Y = Vect(Point3D(5, 5, 0), Point3D(0.0, 5, 5));
	ScreenW = 1000;
	ScreenH = 1000;
}
Screen::Screen(Point3D o, Vect n, Vect x, Vect y, int sw, int sh)
{
	O = o;
	N = n;
	X = x;
	Y = y;
	ScreenW = sw;
	ScreenH = sh;
}
Screen Screen::revlutePlanez(double angle_z)
{
	Screen fs;
	fs.O = O.revlutePointz(angle_z);
	fs.N = N.revluteVectorz(angle_z);
	fs.X = X.revluteVectorz(angle_z);
	fs.Y = Y.revluteVectorz(angle_z);
	fs.ScreenW = this->ScreenW;
	fs.ScreenH = this->ScreenH;
	return  fs;
}
Screen Screen::revlutePlanexOy(double angle)
{
	Screen fs;
	if (fs.O.x == 0 && fs.O.y == 0 && fs.O.z == 0)
		fs.O = O;
	else
		fs.O = O.revlutePointxoy(angle);


	fs.N = N.revluteVectxoy(angle);
	fs.X = X;
	fs.Y = Y.revluteVectxoy(-angle);
	fs.ScreenW = this->ScreenW;
	fs.ScreenH = this->ScreenH;
	return  fs;
}
Screen Screen::movePlane(Vect v)
{
	Screen fs;
	fs.ScreenW = this->ScreenW;
	fs.ScreenH = this->ScreenH;
	fs.O = (Vect)this->O + v;
	fs.X = this->X;
	fs.Y = this->Y;
	return fs;

}