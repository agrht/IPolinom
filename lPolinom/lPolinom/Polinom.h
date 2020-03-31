#pragma once
#include "TList.h"

struct TMonom
{
	double coeff;
	int px, py, pz;
public:
	bool operator <(const TMonom &mnom)
	{
		int mon1, mon2;
		mon1 = px * 100 + py * 10 + pz;
		mon2 = mnom.px * 100 + mnom.py * 10 + mnom.pz;
		if (mon1 < mon2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator >(const TMonom &mnom)
	{
		int mon1, mon2;
		mon1 = px * 100 + py * 10 + pz;
		mon2 = mnom.px * 100 + mnom.py * 10 + mnom.pz;
		if (mon1 > mon2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator >=(const TMonom &mnom)
	{
		int mon1, mon2;
		mon1 = px * 100 + py * 10 + pz;
		mon2 = mnom.px * 100 + mnom.py * 10 + mnom.pz;
		if (mon1 >= mon2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator ==(const TMonom &mnom)
	{
		if (px == mnom.px && py == mnom.py&& pz == mnom.pz)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator <=(const TMonom &mnom)
	{
		int mon1, mon2;
		mon1 = px * 100 + py * 10 + pz;
		mon2 = mnom.px * 100 + mnom.py * 10 + mnom.pz;
		if (mon1 <= mon2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator !=(const TMonom &mnom)
	{
		if (*this == mnom)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	friend ostream& operator<<(ostream& os, const TMonom &mnom)
	{
		os << mnom.coeff << "(x^" << mnom.px << ")" << "(y^" << mnom.py << ")" << "(z^" << mnom.pz << ")";
		return os;
	}

	friend istream& operator>>(istream& is, TMonom &mnom)
	{
		int mon;
		cout << "Vvedite_coefff";
		is >> mnom.coeff;
		cout << "Vvedite_stepeni";
		is >> mon;
		cout << endl;
		mnom.px = mon / 100;
		mnom.py = mon / 10 % 10;
		mnom.pz = mon % 10;
		return is;
	}
};


TMonom operator+ (const TMonom &mnom1, const TMonom &mnom2)
{
	if ((mnom1.px != mnom2.px) || (mnom1.py != mnom2.py) || (mnom1.pz != mnom2.pz))
	{
		throw 777;
	}
	TMonom rez;
	rez.px = mnom1.px;
	rez.py = mnom2.py;
	rez.pz = mnom2.pz;
	rez.coeff = mnom1.coeff + mnom2.coeff;
	return rez;
}

TMonom operator- (const TMonom & mnom1, const TMonom & mnom2)
{
	if ((mnom1.px != mnom2.px) || (mnom1.py != mnom2.py) || (mnom1.pz != mnom2.pz))
	{
		throw 7;
	}
	TMonom rez;
	rez.px = mnom1.px;
	rez.py = mnom2.py;
	rez.pz = mnom2.pz;
	rez.coeff = mnom1.coeff - mnom2.coeff;
	return rez;
}

TMonom operator*(const TMonom & mnom1, const TMonom & mnom2)
{
	TMonom rez;
	rez.px = mnom1.px + mnom2.px;
	rez.py = mnom1.py + mnom2.py;
	rez.pz = mnom1.pz + mnom2.pz;
	rez.coeff = mnom1.coeff * mnom2.coeff;
	return rez;
}

TMonom operator/(const TMonom & mnom1, const TMonom & mnom2)
{
	TMonom rez;
	rez.px = mnom1.px - mnom2.px;
	rez.py = mnom1.py - mnom2.py;
	rez.pz = mnom1.pz - mnom2.pz;
	rez.coeff = mnom1.coeff / mnom2.coeff;
	return rez;
}

TMonom operator*(const TMonom & mnom1, const double a)
{
	TMonom rez;
	rez.coeff = mnom1.coeff * a;
	return rez;
}

class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom() :THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
	}

	TPolinom(int arr[][2], int n) :THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
		TMonom Mnom;
		for (int i = 0; i < n; i++)
		{
			Mnom.coeff = arr[i][0];
			Mnom.px = arr[i][1] / 100;
			Mnom.py = arr[i][1] / 10 % 10;
			Mnom.pz = arr[i][1] % 10;
			AddMonom(Mnom);
		}
	}

	TPolinom(TPolinom & Poli) : THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
		TMonom Mnom;
		for (Poli.Reset(); !Poli.IsEnd(); Poli.GoNext())
		{
			Mnom = Poli.pCurr->val;
			InsLast(Mnom);
		}
	}

	void AddMonom(const TMonom &M)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			if (pCurr->val == M)
			{
				pCurr->val.coeff += M.coeff;
				if (pCurr->val.coeff == 0)
				{
					DelCurr();
					break;
				}
			}
			else if (pCurr->val < M)
			{
				InsCurr(M);
				break;
			}
		}
		if (IsEnd()) InsLast(M);
	}

	TPolinom operator* (double a)
	{
		TPolinom rez(*this);
		for (rez.Reset(); !rez.IsEnd(); rez.GoNext())
		{
			rez.pCurr->val.coeff *= a;
			if (rez.pCurr->val.coeff == 0)
			{
				rez.DelCurr(); break;
			}
		}
		return rez;
	}

	void operator*=(double a)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.coeff *= a;
			if (pCurr->val.coeff == 0)
			{
				DelCurr(); break;
			}
		}
	}

	void operator*=(TMonom M)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.coeff *= M.coeff;
			pCurr->val.px += M.px;
			pCurr->val.py += M.py;
			pCurr->val.pz += M.pz;
		}
	}

	TPolinom operator *(TMonom M)
	{
		TPolinom res(*this);
		for (res.Reset(); !res.IsEnd(); res.GoNext())
		{
			res.pCurr->val.px += M.px;
			res.pCurr->val.py += M.py;
			res.pCurr->val.pz += M.pz;
			res.pCurr->val.coeff *= M.coeff;
		}
		return res;
	}

	void operator +=(TPolinom& Q)
	{
		TMonom pm, qm, rm;
		Reset();
		Q.Reset();
		while (!Q.IsEnd())
		{
			pm = pCurr->val;
			qm = Q.pCurr->val;
			if (pm > qm)
			{
				GoNext();
			}
			else
			{
				if (pm < qm)
				{
					InsCurr(qm);
					Q.GoNext();
				}
				else
				{
					rm = pm;
					rm.coeff += qm.coeff;
					if (rm.coeff == 0)
					{
						DelCurr();
						Q.GoNext();
					}
					else
					{
						pCurr->val = rm;
						if (&Q == this)
						{
							GoNext();
						}
						else
						{
							GoNext();
							Q.GoNext();
						}
					}
				}
			}
		}
	}

	friend istream& operator>>(istream &is, TPolinom &poli)
	{
		TMonom mnom;
		is >> mnom;
		while (mnom.coeff != 0)
		{
			poli.AddMonom(mnom);
			is >> mnom;
		}
		return is;
	}

	friend ostream& operator<< (ostream &os, TPolinom &poli)
	{
		for (poli.Reset(); !poli.IsEnd(); poli.GoNext())
		{
			if (poli.pCurr->val.coeff < 0 || poli.pCurr == poli.pFirst)
				os << poli.pCurr->val;
			else
				os << " + " << poli.pCurr->val;
		}
		if (poli.pFirst == poli.pStop)
		{
			os << "0";
		}
		return os;
	}
};