#include "gtest1.h"
#include"..\lPolinom\lPolinom\Polinom.h"
#include"..\lPolinom\lPolinom\TList.h"

TEST(THeadList, can_create_list)
{
	ASSERT_NO_THROW(THeadList<int> list);
}

TEST(THeadList, can_InsFirst)
{
	THeadList<int> list;
	ASSERT_NO_THROW(list.InsFirst(3));
	ASSERT_NO_THROW(list.Reset());
	EXPECT_EQ(list.GetCurrEl(), 3);
}

TEST(TMonom, can_create_Monom)
{
	ASSERT_NO_THROW(TMonom mnom);
}

TEST(TMonom, can_insert_monom_with_positive_coeff)
{
	TMonom mnom;
	mnom.px = 0;
	mnom.py = 0;
	mnom.pz = 0;
	ASSERT_NO_THROW(mnom.coeff = 7);
}

TEST(TMonom, can_insert_monom_with_negative_coeff)
{
	TMonom mnom;
	mnom.px = 0;
	mnom.py = 0;
	mnom.pz = 0;
	ASSERT_NO_THROW(mnom.coeff = -7);
}

TEST(TMonom, can_insert_monom_with_positive_step)
{
	TMonom mnom;
	mnom.px = 1;
	mnom.py = 1;
	mnom.pz = 1;
	ASSERT_NO_THROW(mnom.coeff = 3);
}

TEST(TMonom, can_insert_monom_with_negative_step)
{
	TMonom mnom;
	mnom.px = -1;
	mnom.py = -1;
	mnom.pz = -1;
	ASSERT_NO_THROW(mnom.coeff = 5);
}

TEST(TMonom, can_compare_equal_monoms)
{
	TMonom mnom1, mnom2;
	mnom1.coeff = 2;
	mnom1.px = 7;
	mnom1.py = 7;
	mnom1.pz = 7;
	mnom2.coeff = 9;
	mnom2.px = 7;
	mnom2.py = 7;
	mnom2.pz = 7;
	EXPECT_EQ(mnom1 == mnom2, 1);
}

TEST(TMonom, can_compare_not_equal_monoms)
{
	TMonom mnom1, mnom2;
	mnom1.coeff = 3;
	mnom1.px = 7;
	mnom1.py = 7;
	mnom1.pz = 7;
	mnom2.coeff = 7;
	mnom2.px = 3;
	mnom2.py = 3;
	mnom2.pz = 3;
	EXPECT_EQ(mnom1 != mnom2, 1);
}

TEST(TMonom, can_compare_monoms)
{
	TMonom mnom1, mnom2;
	mnom1.coeff = 7;
	mnom1.px = 3;
	mnom1.py = 3;
	mnom1.pz = 3;
	mnom2.coeff = 3;
	mnom2.px = 1;
	mnom2.py = 1;
	mnom2.pz = 1;
	EXPECT_EQ(mnom1 < mnom2, 0);
	EXPECT_EQ(mnom1 > mnom2, 1);
}

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom poli);
}

TEST(TPolinom, can_create_polinom_with_arr)
{
	int arr[2][2];
	arr[0][0] = 7;
	arr[1][0] = 7;
	arr[0][1] = 7;
	arr[1][1] = 3;
	ASSERT_NO_THROW(TPolinom p(arr, 2));
}

TEST(TPolinom, can_copy_polynom)
{
	int arr[2][2];
	arr[0][0] = 3;
	arr[1][0] = 3;
	arr[0][1] = 3;
	arr[1][1] = 3;
	TPolinom p(arr, 2);
	ASSERT_NO_THROW(TPolinom p_copy(p));
}

TEST(TPolinom, can_add_monom)
{
	TPolinom poli;
	TMonom mnom;
	mnom.coeff = 3;
	mnom.px = 3;
	mnom.py = 3;
	mnom.pz = 3;
	ASSERT_NO_THROW(poli.AddMonom(mnom));
}

TEST(TPolinom, can_multi_poli_na_chislo)
{
	TPolinom poli;	
	ASSERT_NO_THROW(poli * 7);	
	ASSERT_NO_THROW(poli *= 7);
}

TEST(TPolinom, can_multi_poli_na_monom)
{
	TPolinom poli;
	TMonom mnom;
	mnom.coeff = 3;
	mnom.px = 3;
	mnom.py = 3;
	mnom.pz = 3;
	ASSERT_NO_THROW(poli * mnom);
	ASSERT_NO_THROW(poli *= mnom);
}

TEST(TPolinom, stop)
{
	system("pause");
}
