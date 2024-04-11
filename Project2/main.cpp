//�ļ���:exp6-5.cpp
#include<iostream>
#include<algorithm>
#include<fstream>
#include <stdio.h>
#define N 4
#define M 10
using namespace std;
ifstream instream, instream2;
ofstream outstream;
int value(int a[], int i, int j)	//����ѹ���洢a��A[i][j]ֵ֮
{
	if (i >= j)
		return a[(i * (i + 1)) / 2 + j];
	else
		return a[(j * (j + 1)) / 2 + i];
}
void madd(int a[], int b[], int c[][N])	//��ѹ���洢a��b�ĺ�
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			c[i][j] = value(a, i, j) + value(b, i, j);
}
void mult(int a[], int b[], int c[][N])	//��ѹ���洢a��b�ĳ˻�
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
void disp1(int a[])	//���ѹ���洢a
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			outstream << value(a, i, j);
		outstream << "\n";
	}
}
void disp2(int c[][N])	//����Գƾ���c
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			outstream << c[i][j];
		outstream << "\n";
	}
}
void disp3(int a[])	//���ѹ���洢a
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", value(a, i, j));
		printf("\n");
	}
}
void disp4(int c[][N])	//����Գƾ���c
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
	printf("j����:\n"); disp3(j);
	printf("k����:\n"); disp3(k);
	printf("j+k:\n"); disp4(c3);
	printf("j��k:\n"); disp4(c4);


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
	outstream << "a����:\n";
	disp1(a);
	outstream << "b����:\n";
	disp1(b);
	outstream << "a+b:\n";
	disp2(c1);
	outstream << "a��b:\n";
	disp2(c2);
	instream.close();
	instream2.close();
	outstream.close();

	

	return 1;

	/*�Գƾ���M�ĵ�i�к͵�j�е�Ԫ�ص����ݴ洢��һά����a�е�λ��k�ļ��㹫ʽ:
		*1����i���ڻ����jʱ��k = (i * (i + 1)) / 2 + j(������)
		*2����iС��jʱ��k = (j * (j + 1)) / 2 + i(������)*/
}
