#include<iostream>
#include"Polinom.h"
#include<math.h>

using namespace std;
//¬водите степени монома без пробелов (3 числа подр€д)
int main()
{
	try 
	{
		TPolinom poli1, poli2;
		TMonom mnom1,mnom2,rez;
		mnom1.coeff = 3;
		mnom1.px = 3;
		mnom1.py = 2;
		mnom1.pz = 1;
		mnom2.coeff = 2;
		mnom2.px = 3;
		mnom2.py = 2;
		mnom2.pz = 1;
		cout << "POLINOM" << endl;
		cout << "Vvedi_pervui_polinom" << endl;
		cin >> poli1;
		cout << poli1 << endl;
		cout << "Vvedi_vtoroi_polinom" << endl;
		cin >> poli2;
		cout << poli2 << endl;
		cout << "Add_poli" << endl;
		poli1 += poli2;
		cout << poli1 << endl;
		cout << "Sub_poli" << endl;
		poli2 *= -1;
		poli1 += poli2;
		cout << poli1 << endl;
		cout << endl;
		cout << "MONOM" << endl;
		cout << "Mon1" << endl;
		cout << mnom1 << endl;
		cout << "Mon2" << endl;
		cout << mnom2 << endl;
		cout << "Multi_mon" << endl;
		rez = mnom1 * mnom2;
		cout << rez << endl;
		cout << "Add_mon" << endl;
		rez = mnom1 + mnom2;
		cout << rez<<endl;
		cout << "Div_mon" << endl;
		rez = mnom1 / mnom2;
		cout << rez << endl;
	}
	catch (char *r) 
	{
		cout << r;
	}
	system("pause");
}