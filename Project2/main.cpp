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

	cout << "/*-----------------------------------------------------------------------------------*/";
	cout << endl;
	cout << "这是一个当你输入两个一维数组时，可以转化为两个对称矩阵并输出两对称矩阵之和与之积的程序";
	cout << endl;
	cout << "------------------------------------------------------------------------------------*/"<< endl<<endl;
start:	cout << "===============================请选择输入方式=========================================" << endl;
	cout << "=================================1.文件输入===========================================" << endl;
	cout << "=================================2.手动输入===========================================" << endl;
	cout << "======================================================================================" << endl<<endl;

	int select = 2;
	int select1 = 2;
	int select2 = 2;
	cin >> select;
	switch (select)
	{
	  case 1:
		  cout << endl;
		  cout << "1.我还未在文件中输入数组" << endl;
		  cout << "2.我已在文件中输入数组" << endl<<endl;
		  scanf_s("%d", &select1);
		  switch (select1)
		  {
		  case 2:
			  cout << endl << "请前往解决方案管理器打开项目文件夹查看，程序的运行结果已在exp6-5out.txt文件中生成......" << endl;
			  break;
		  case 1:
			  cout << endl << "请输入‘0’退出当前窗口后在解决方案管理器打开项目文件夹，修改exp6-5in1.txt与exp6-5in2.txt文件，并再次运行" << endl;
			  cout << endl;
			  cout << "输入范例:1 2 3 4 5 6 7 8 9 10";
			  break;
		  }
		  cout << endl << endl; printf("输入‘0’退出，输入‘1’重新选择案例:");
		 
		  scanf_s("%d", &select2);
		  switch (select2)
		  {
		  case 1:
			  goto start;
			  break;
		  case 0:
			  cout << endl;
			  cout << "感谢你的使用:)";
			  cout << endl;
			  cout << "@author 陈政元";
			  cout << endl;
			  break;
		  }
		  break;


	  case 2:
		  cout << endl;
		  cout << "输入范例:1 2 3 4 5 6 7 8 9 10";
		  cout << endl;
		  cout << endl;
		  cout << "接下来请输入你的第一个一维数组吧！";
		  cout << endl;
		  cout << endl;
		  cout << "第一个一维数组:";
		  for (int i = 0; i < 10; i++)
		  {
			  cin >> j[i];
		  }
		  cout << endl;
		  cout << "第二个一维数组:";

		  for (int l = 0; l < 10; l++)
		  {
			  cin >> k[l];
		  }
		  madd(j, k, c3);
		  mult(j, k, c4);
		  cout << endl;
		  printf("你输入的第一个矩阵:\n"); disp3(j);
		  cout << endl;
		  printf("你输入的第二个矩阵:\n"); disp3(k);
		  cout << endl;
		  printf("两个矩阵之和:\n"); disp4(c3);
		  cout << endl;
		  printf("两个矩阵乘积:\n"); disp4(c4);
		  cout << endl;


		  cout << endl << endl; printf("输入‘0’退出，输入‘1’重新选择案例:");

		  scanf_s("%d", &select2);
		  switch (select2)
		  {
		  case 1:
			  goto start;
			  break;
		  case 0:
			  cout << endl;
			  cout << "感谢你的使用:)";
			  cout << endl;
			  cout << "@author 陈政元";
			  cout << endl;
			  break;
		  }
		  break;
	}
	


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
