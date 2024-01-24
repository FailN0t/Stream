#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Point {
	int x, y, z;
public:
	Point(int x, int y, int z) :x{ x }, y{ y }, z{ z } {}
	Point():Point(0, 0, 0){}
	void print(ostream & ost) {
		ost << "\t X: " << x << "\t Y: " << y << "\t Z: " << z << endl;
		

	}
	void print2() {
		cout << "\t X: " << x << "\t Y: " << y << "\t Z: " << z << endl;


	}
	friend ostream& operator<< (ostream& ost, Point& pnt) {
		pnt.print(ost);
		return ost;
	}
	void setXYZ(int x = 0, int y = 0, int z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void operator=(Point* pnt2) {
		x = pnt2->x;
		y = pnt2->y;
		z = pnt2->z;
	}
};




int main() {
	
	


}