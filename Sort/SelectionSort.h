#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

class Selection
{
public:
	//ѡ������
	void Sort(char *a, int length)
	{
		for (int index = 0; index < length - 1; ++index)
		{
			//�ҳ��ӵ�ǰλ��index��ʼ����������Ԫ������СԪ�ص��±�
			int indexOfCurMin = index;
			for (int i = index + 1; i < length; ++i)
			{
				if (a[i] < a[indexOfCurMin])
					indexOfCurMin = i;
			}

			//���ҵ�����СԪ�غ�indexλ���ϵ�Ԫ�ؽ��н���
			int temp = a[index];
			a[index] = a[indexOfCurMin];
			a[indexOfCurMin] = temp;
		}
	}
};

#endif