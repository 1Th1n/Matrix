//文件名:exp6-5.cpp
#include<iostream>
#include<algorithm>
#include<fstream>
#include <stdio.h>
#define N 4
#define M 10
using namespace std;
ifstream instream, instream2;
ofstream outstream;
int value(int a[], int i, int j)	//返回压缩存储a中A[i][j]之值
{
	if (i >= j)
		return a[(i * (i + 1)) / 2 + j];
	else
		return a[(j * (j + 1)) / 2 + i];
}
void madd(int a[], int b[], int c[][N])	//求压缩存储a和b的和
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			c[i][j] = value(a, i, j) + value(b, i, j);
}
void mult(int a[], int b[], int c[][N])	//求压缩存储a和b的乘积
{
	int i, j, k, s;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			s = 0;
			for (k = 0; k < N; k++)
				s = s + value(a, i, k) * value(b, k, j);
			c[i][j] = s;
		}
}
void disp1(int a[])	//输出压缩存储a
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			outstream << value(a, i, j);
		outstream << "\n";
	}
}
void disp2(int c[][N])	//输出对称矩阵c
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			outstream << c[i][j];
		outstream << "\n";
	}
}
void disp3(int a[])	//输出压缩存储a
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", value(a, i, j));
		printf("\n");
	}
}
void disp4(int c[][N])	//输出对称矩阵c
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", c[i][j]);
		printf("\n");
	}
}
int main()
{

	int j[M];
	int k[M];
	int c3[N][N], c4[N][N];
	for (int i = 0; i < 10; i++)
	{
		cin >> j[i];
	}

	for (int l = 0; l < 10; l++)
	{
		cin >> k[l];
	}
	madd(j, k, c3);
	mult(j, k, c4);
	printf("j矩阵:\n"); disp3(j);
	printf("k矩阵:\n"); disp3(k);
	printf("j+k:\n"); disp4(c3);
	printf("j×k:\n"); disp4(c4);


	int a[M] = { 0 };
	int b[M] = { 0 };
	int c1[N][N], c2[N][N];
	instream.open("exp6-5in1.txt");
	instream2.open("exp6-5in2.txt");
	outstream.open("exp6-5out.txt");
	for (int i = 0; i < 10; i++)instream >> a[i];
	for (int i = 0; i < 10; i++)instream2 >> b[i];
	madd(a, b, c1);
	mult(a, b, c2);
	outstream << "a矩阵:\n";
	disp1(a);
	outstream << "b矩阵:\n";
	disp1(b);
	outstream << "a+b:\n";
	disp2(c1);
	outstream << "a×b:\n";
	disp2(c2);
	instream.close();
	instream2.close();
	outstream.close();

	

	return 1;

	/*对称矩阵M的第i行和第j列的元素的数据存储在一维数组a中的位置k的计算公式:
		*1、当i大于或等于j时，k = (i * (i + 1)) / 2 + j(下三角)
		*2、当i小于j时，k = (j * (j + 1)) / 2 + i(上三角)*/
}
