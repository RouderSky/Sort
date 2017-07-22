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
	//�����Ż������뿴quick3way������һ�������У�������ѡ������ֵͬ����Ԫ����Ϊ��׼�����Ըĳ������з֣����ǱȻ�׼ֵС��Ԫ�ط�����ߣ����׼ֵ��ȵ�Ԫ�ط����м䣬�Ȼ�׼ֵ���Ԫ�ط����ұߣ����ڰ��������ظ�Ԫ�ص����飬���Խ�ʱ�临�Ӷ���NlgN����N	
	int Partition(char *a, int left, int right)
	{
		//�ָ��׼��ȡ����Ԫ��������׼
		char standard = a[left];
#if 0
		//�Լ�д�ĵ�һ���汾
		int i = left;
		int j = right+1;
		while (i < j)
		{
			while (a[++i] <= standard && i <= right){  }			//i <= right���Ըĳ�i < right
			while (standard <= a[--j] && j >= left+1){  }			//j >= left+1�����Ը���j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
#endif
#if 0
		/*��δ���ǳ����������еĴ���С�ںŶ�Ҫ�ǳ�׼ȷ����дʧ�ܣ����Ե���ģ�������*/
		//�Լ�д�ĵڶ����汾
		int i = left + 1;
		int j = right;
		while (true)
		{
			while (a[i] <= standard && i <= right) { ++i; }			//i <= right���Ըĳ�i < right
			while (standard <= a[j] && j >= left+1) { --j; }		//j >= left+1�����Ը���j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				break;
		}
#endif
#if 1
		//�鱾�İ汾
		int i = left;
		int j = right + 1;
		while (true)
		{
			//�ر�ע�� ++i �� --j ��λ��
			//ע��a[i] <= standard��standard <= a[j]�ĵ��ں�
			while (a[++i] <= standard && i <= right){}				//i <= right���Ըĳ�i < right
			while (standard <= a[--j] && j >= left + 1){}			//j >= left+1�����Ը���j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				break;
		}
#endif
		a[left] = a[j];
		a[j] = standard;

		return j;
	}
};

//�����зֵĿ�������
class Quick3way
{
public:
	void Sort1_0(char *a, int length)
	{
		//�ڿ�ʼ�ݹ�����ǰ����ȴ���һ�����飬��ֹ��������з֣������Ͳ����׳���O(N^2)�������
		SortCore1_0(a, 0, length - 1);
	}

	void SortCore1_0(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{
			char standard = a[left];

			//��һ���з�
			int i = left;
			int j = right+1;
			while (i < j)
			{
				while (a[++i] < standard && i <= right){ }
				while (standard <= a[--j] && j >= left+1){ }

				if (i < j)
				{
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			a[left] = a[j];
			a[j] = standard;

			int lessRight = j - 1;

			//�ڶ����з�
			j = right;
			while (i < j)
			{
				while (a[i] == standard && i <= right){ ++i; }
				while (standard < a[j] && j >= lessRight + 2){ --j; }

				if (i < j)
				{
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}

			int equelRight = j;

			SortCore1_0(a, left, lessRight);
			SortCore1_0(a, equelRight + 1, right);
		}
	}

	//����޷������δ��룬��ʹ��������6��2��3��7��6��6��9��1����ģ��һ��
	void Sort2_0(char *a, int length)
	{
		//�ڿ�ʼ�ݹ�����ǰ����ȴ���һ�����飬��ֹ��������з֣������Ͳ����׳���O(N^2)�������
		SortCore2_0(a, 0, length - 1);
	}

	void SortCore2_0(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{
			//�����з�
			char standard = a[left];
			int lt = left;				//lt��ʵ��Զ��ָ������˵Ļ�׼ֵ
			int i = left + 1;
			int gt = right;
			while (i <= gt)
			{
				if (a[i] < standard)
				{
					char temp = a[i];
					a[i] = a[lt];
					a[lt] = temp;

					++i;
					++lt;
				}
				else if (a[i] == standard)
				{
					++i;
				}
				else if (a[i] > standard)
				{
					char temp = a[i];
					a[i] = a[gt];
					a[gt] = temp;

					--gt;
				}
			}

			SortCore2_0(a, left, lt - 1);
			SortCore2_0(a, gt + 1, right);
		}
	}
};

#endif