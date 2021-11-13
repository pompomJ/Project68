#include <iostream>

using namespace std;

//���N���XFigure
class Figure {
public:
	virtual void area() = 0; 
	virtual void around() = 0; 

	void GetMeasure() {
		area();
		around();
	}
};

//�h���N���XSquare
class Square : public Figure {
public:
	Square(double s);
	Square(double s, double h);
	void area() {
		cout << "�l�p�`�̖ʐ�:" << side * height << endl;
	}
	void around() {
		cout << "�l�p�`�̊O��:" << 2 * (side + height) << endl;
	}
private:
	double side;
	double height;
};

//Square�N���X�̃R���X�g���N�^
Square::Square(double s) {
	side = height = s;
}

Square::Square(double s, double h) {
	side = s;
	height = h;
}

//�h���N���XCircle
class Circle : public Figure {
public:
	Circle(double r);
	void area() {
		cout << "�~�̖ʐ�:" << radius * radius * pi << endl;
	}
	void around() {
		cout << "�~�̊O��:" << 2 * (radius * pi) << endl;
	}
private:
	const double pi;
	double radius;
};

//Circle�N���X�̃R���X�g���N�^
Circle::Circle(double r) : pi(3.14) {
	radius = r;
}

int main()
{
	Figure *pFig1;
	Figure *pFig2;
	Figure *pFig3;
	Square mySquare1(2.5);
	Square mySquare2(2.3, 3.7);
	Circle myCircle(3.6);

	pFig1 = &mySquare1;
	pFig2 = &mySquare2;
	pFig3 = &myCircle;

	pFig1 -> GetMeasure();
	pFig2 -> GetMeasure();
	pFig3 -> GetMeasure();

	return 0;
}
