#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
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
	char pachF[11] = "CountF.bin";
	static int count;
	static int countF;
	Point* pnt;
	int size;
	void name() {
		string ph = "pach" + to_string(count) + ".bin";
		strncpy(pach, ph.c_str(), ph.length() + 1);
	}
	bool rdPach1(string pach) {
		ifstream fin;
		fin.open(pach);
		if (!fin.is_open()) {
			cout << "err " << pach << endl;
			return false;
		}
		else
		{
			fin.read((char*)&size, sizeof(int));
		}
		fin.close();
		return true;
	}
	bool rdPach2(string pach) {
		Point* pnt2 = new Point[size];
		ifstream fin;
		fin.open(pach);
		if (!fin.is_open()) {
			cout << "err " << pach << endl;
			return false;
		}
		else
		{
			fin.read((char*)&size, sizeof(int));
			fin.read((char*)&pnt, sizeof(Point) * size);
			for (size_t i = 0; i < size; i++)
			{
				pnt = pnt2;
			}
			pnt2 = nullptr;
		}
		fin.close();
		return true;
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
		wrtPachF();
		return true;
	}
	bool wrtPachF() {
		ofstream fout;
		fout.open(pachF, ofstream::out);
		fout.close();
		fout.open(pachF, ofstream::app);
		if (!fout.is_open()) {
			cout << "err " << pachC << endl;
			return false;
		}
		else
		{
			fout.write((char*)&countF, sizeof(int));

		}
		fout.close();
		return true;
	}

public:
	ArrPoint(int i) : pnt{ new Point[i] }, size{ i } {
		count++;
		countF++;
		name();
		for (size_t i = 0; i < size; i++)
		{
			pnt[i].setXYZ(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
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
	ArrPoint():ArrPoint(5) {}

	ArrPoint(string pach) {
		count++;
		countF++;
		if (!rdPach1(pach))
		{
			cout << "constr " << endl;
		}
		pnt = new Point[size];
		if (!rdPach2(pach))
		{
			cout << "constr " << endl;
		}
		name();
		if (!wrtPach())
		{
			cout << "constr " << endl;
		}
		if (!wrtPachC())
		{
			cout << "constr " << endl;
		}
	}

	void copy(string pach) {
		if (!rdPach1(pach))
		{
			cout << "copy " << endl;
		}
		pnt = new Point[size];
		if (!rdPach2(pach))
		{
			cout << "copy " << endl;
		}
		if (!wrtPach())
		{
			cout << "copy " << endl;
		}
		if (!wrtPachC())
		{
			cout << "copy " << endl;
		}
	}

	void operator()(string pach) {
		copy(pach);
	}

	void print(ostream & ost) {
		for (size_t i = 0; i < size; i++)
		{
			pnt[i].print(ost);
		}
	}
	friend ostream& operator<< (ostream& ost, ArrPoint& ap) {
		ap.print(ost);
		return ost;
	}

	string getPach() {
		return pach;
	}
	~ArrPoint() {
		

	}
};

int ArrPoint::count = 0;
int ArrPoint::countF = 0;

int main() {
	srand(time(NULL));
	

	

}