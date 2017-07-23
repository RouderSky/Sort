#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

//���ȶ��е�һ��ʵ�ַ�ʽ�������
//����ѣ���������ݽṹ�Ϳ��Ժ����׽���������ˣ�����ֱ����������ݾ͹�������Ч�ʲ����ߣ���Ϊ����ֻ�ú�Сһ���ִ���͹���
class MaxPQ
{
private:
	char *pq;		//�ڵ�Ϊk�����ڵ�Ϊ(k-1)/2������Ϊ2*k+1���Һ���Ϊ2*k+2
	int N;			//��¼����Ԫ�صĸ���
public:
	MaxPQ(int maxN)
	{
		pq = new char[maxN];
		N = 0;
	}
	~MaxPQ()
	{
		delete[] pq;
	}
	bool isEmpty()
	{
		return N == 0;
	}
	int size()
	{
		return N;
	}
	void insert(char v)
	{
		pq[N] = v;
		swim(N);

		++N;
	}
	char delMax()
	{
		char max = pq[0];

		char temp = pq[0];
		pq[0] = pq[N - 1];
		pq[N - 1] = temp;

		--N;

		sink(0);

		return max;
	}
	//����
	void swim(int k)
	{
		while (k > 0 && pq[k] > pq[(k - 1) / 2])
		{
			char temp = pq[k];
			pq[k] = pq[(k - 1) / 2];
			pq[(k - 1) / 2] = temp;

			k = (k - 1) / 2;
		}
	}
	//����
	void sink(int k)
	{
		//���д��һ���Ǿ����˵����Ż���ô����
		while (2 * k + 1 < N)
		{
			int maxChild = 2 * k + 1;
			if (maxChild + 1 < N && pq[maxChild + 1] > pq[maxChild])
				++maxChild;

			if (pq[k] >= pq[maxChild])
				break;
			else
			{
				char temp = pq[k];
				pq[k] = pq[maxChild];
				pq[maxChild] = temp;

				k = maxChild;
			}

		}
	}
};


class Heap
{
public:
	//ע�⣺N�Ǵ���������ĳ���
	void sink(char *a, int k, int N)
	{
		while (2 * k + 1 < N)
		{
			int maxChild = 2 * k + 1;
			if (maxChild + 1 < N && a[maxChild + 1] > a[maxChild])
				++maxChild;

			if (a[k] >= a[maxChild])
				break;
			else
			{
				char temp = a[k];
				a[k] = a[maxChild];
				a[maxChild] = temp;

				k = maxChild;
			}
		}
	}
	//�����Ż������³����ϸ����ɽ��Ƚϴ�������һ�룻���������Ҫ����Ŀռ���������ֻ�е��Ƚ���Ҫ�ܸߵĴ���ʱ�Ų���
	void sort(char *a,int N)
	{
		for (int i = (N - 1) / 2; i >= 0; --i)
			sink(a, i, N);

		for (int i = N - 1; i > 0; --i)
		{
			char temp = a[i];
			a[i] = a[0];
			a[0] = temp;

			sink(a, 0, i);
		}
	}
};

#endif