#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

class Quick
{
public:
	void Sort(char *a, int length)
	{
		//�ڿ�ʼ�ݹ�����ǰ����ȴ���һ�����飬��ֹ��������з֣������Ͳ����׳���O(N^2)�������
		SortCore(a, 0, length - 1);
	}

	//�����Ż��������鱻�ָ��С��ĳ����ֵ��ʱ�򣬸��ò�������
	void SortCore(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{
			int j = Partition(a, left, right);
			SortCore(a, left, j - 1);
			SortCore(a, j + 1, right);
		}
	}

	//�����Ż���ѡȡ����Ԫ�����ҳ��ⲿ��Ԫ�ص���λ��������׼
	//�����Ż�����һ�������У�������ѡ������ֵͬ����Ԫ����Ϊ��׼�����Ըĳ������з֣����ǱȻ�׼ֵС��Ԫ�ط�����ߣ����׼ֵ��ȵ�Ԫ�ط����м䣬�Ȼ�׼ֵ���Ԫ�ط����ұߣ����ڰ��������ظ�Ԫ�ص����飬���Խ�ʱ�临�Ӷ���NlgN����N	
	int Partition(char *a, int left, int right)
	{
		//�ָ��׼��ȡ����Ԫ��������׼
		char standard = a[left];

		int i = left + 1;
		int j = right;
		while (i < j)
		{
			//ע��a[i] <= standard��standard <= a[j]�ĵ��ں�
			//ע��i��j�ı߽���߶��ˣ�����������
			while (a[i] <= standard && i <= right){ ++i; }
			while (standard <= a[j] && j >= left + 1){ --j; }

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		a[left] = a[j];
		a[j] = standard;

		return j;
	}
};

#endif