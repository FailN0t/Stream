#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
#pragma warning(disable : 4996)

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

class ArrPoint {
	char pach[255];
	char pachC[10] = "Count.bin";
	static int count;
	Point* pnt;
	int size;
	void name() {
		string ph = "pach" + to_string(count) + ".bin";
		strncpy(pach, ph.c_str(), ph.length() + 1);
	}
	bool wrtPach() {
		ofstream fout;
		fout.open(pach, ofstream::out);
		fout.close();
		fout.open(pach, ofstream::app);
		if (!fout.is_open()) {
			cout << "err " << pach << endl;
			return false;
		}
		else
		{
			fout.write((char*)&size, sizeof(int));
			fout.write((char*)&pnt, sizeof(Point) * size);

		}
		fout.close();
		return true;
	}
	bool wrtPachC() {
		ofstream fout;
		fout.open(pachC, ofstream::out);
		fout.close();
		fout.open(pachC, ofstream::app);
		if (!fout.is_open()) {
			cout << "err " << pachC << endl;
			return false;
		}
		else
		{
			fout.write((char*)&count, sizeof(int));

		}
		fout.close();
		return true;
	}

public:
	ArrPoint(int i) : pnt{ new Point[i] }, size{ i } {
		count++;
		name();
		for (size_t i = 0; i < size; i++)
		{

		}
		if (!wrtPach())
		{
			cout << "constr " << endl;
		}
		if (!wrtPachC())
		{
			cout << "constr " << endl;
		}

	}
};


int main() {
	



}