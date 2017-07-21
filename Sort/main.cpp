#include <iostream>		/* cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

//�Ժ���pf��������ɳ���Ϊn��char���飬����t�β���
double TimeRandomInput(void(*pf)(char*, int),int n,int t)
{
	clock_t start = clock();

	char *a = new char[n];
	for (; t >= 0; --t)
	{
		for (int i=0;i<n;++i)
			a[i] = 'A' + rand() % 26;

		pf(a, n);
	}

	clock_t finish = clock();
	double totalTime = (double)(finish - start) / CLOCKS_PER_SEC;

	return totalTime;
}

int main()
{
#if 1
	srand(time(NULL));
	char a[10];

	for (int i = 0; i < 10; ++i)
		a[i] = 'A' + rand() % 26;

	//SelectionSort(a, 10);
	//InsertionSort2_0(a, 10);
	//ShellSort2_0(a, 10);
	Quick test;
	test.Sort(a, 10);

	for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;
#endif

#if 0
	//ʱ�����
	double time1 = TimeRandomInput(SelectionSort, 1000, 1000);
	double time2 = TimeRandomInput(SelectionSort, 1000, 1000);
	cout << time1 << endl;
	cout << time2 << endl;
#endif

	system("pause");
	return 0;
}