#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>		/* NULL */
#include <algorithm>	/* min */

using namespace std;

class Merge
{
private:
	//����һ��a����ĸ���,�����ռ䣻��ʵ���Բ��õģ���ʱ�������ռ�
	char *aux;
public:
	Merge(){ aux = NULL; }

	//���ι鲢����a��������������źõ�������ϲ�����
	//mid�����������������һ��Ԫ���±�
	void merge(char *a, int left, int mid, int right)
	{
		for (int i = left; i <= right; ++i)
			aux[i] = a[i];

		int idxOfLeft = left;
		int idxOfRight = mid + 1;
		//��ʼ�鲢
		for (int i = left; i <= right; ++i)
		{
			if (idxOfLeft > mid&&idxOfRight <= right)
				a[i] = aux[idxOfRight++];
			else if (idxOfLeft <= mid&&idxOfRight > right)
				a[i] = aux[idxOfLeft++];
			else if (aux[idxOfLeft] < aux[idxOfRight])
				a[i] = aux[idxOfLeft++];
			else
				a[i] = aux[idxOfRight++];
		}
	}

	//�Զ����µĵݹ�鲢����
	//��������������Ż������left��right֮��Ĳ�ֵС��һ���ĳ̶ȣ��Ͳ����ٵݹ��ˣ�ֱ���ò�������ϣ���������ѡ�������ٶȿ������������в��������������10%~15%
	void SortCore(char *a, int left, int right)
	{
		if (left >= right)
			return;
		else
		{
			int mid = (left + right) / 2;
			SortCore(a, left, mid);
			SortCore(a, mid + 1, right);
			merge(a, left, mid, right);		//���������ִ��ǰ��������һ���жϣ����a[mid]<=a[mid+1]�����������Բ�ִ�У�
		}
	}

	//��������
	void Sort(char *a, int length)
	{
		//����
		if (aux != NULL)
		{
			delete[] aux;
			aux = NULL;
		}

		aux = new char[length];
		SortCore(a, 0, length - 1);
	}

};

class MergeBu
{
private:
	//����һ��a����ĸ���,�����ռ䣻��ʵ���Բ��õģ���ʱ�������ռ�
	char *aux;

public:
	MergeBu(){ aux = NULL; }

	//���ι鲢����a��������������źõ�������ϲ�����
	//mid�����������������һ��Ԫ���±�
	void merge(char *a, int left, int mid, int right)
	{
		for (int i = left; i <= right; ++i)
			aux[i] = a[i];

		int idxOfLeft = left;
		int idxOfRight = mid + 1;
		//��ʼ�鲢
		for (int i = left; i <= right; ++i)
		{
			if (idxOfLeft > mid&&idxOfRight <= right)
				a[i] = aux[idxOfRight++];
			else if (idxOfLeft <= mid&&idxOfRight > right)
				a[i] = aux[idxOfLeft++];
			else if (aux[idxOfLeft] < aux[idxOfRight])
				a[i] = aux[idxOfLeft++];
			else
				a[i] = aux[idxOfRight++];
		}
	}

	//�Ե����ϵĹ鲢����
	//���Ը�����������򣬶����ø�������
	void Sort(char *a, int length)
	{
		//����
		if (aux)
		{
			delete[] aux;
			aux = NULL;
		}

		aux = new char[length];

		for (int subArraySize = 1; subArraySize < length; subArraySize <<= 1)
		{
			for (int left = 0; left < length - subArraySize; left += (subArraySize << 1))		//ע���������ֹ����
				merge(a, left, left + subArraySize - 1, min(left + (subArraySize << 1) - 1, length - 1));
		}
	}
};

#endif