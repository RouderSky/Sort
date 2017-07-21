#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__

//ϣ������
class Shell
{
public:
	//�Լ�ʵ��
	void Sort1_0(char *a, int length)
	{
		//ȷ��h�����ֵ
		int h = 1;
		while (h < length / 3)
			h = 3 * h + 1;		//1,4,13,40,121,364,1093��...

		while (h >= 1)	//�������
		{
			for (int i = 0; i < h; ++i)	//ÿ���������ͷ
			{
				//��ÿ����������в�������
				for (int j = i + h; j < length; j += h)
				{
					char needToInsert = a[j];
					int k;
					for (k = j - h; j >= i&&needToInsert < a[k]; k -= h)
						a[k + h] = a[k];

					a[k + h] = needToInsert;
				}
			}

			h /= 3;
		}
	}

	//�鱾ʵ��
	void Sort2_0(char *a, int length)
	{
		//ȷ��h�����ֵ
		int h = 1;
		while (h < length / 3)
			h = 3 * h + 1;		//1,4,13,40,121,364,1093��...

		while (h >= 1)
		{
			for (int i = h; i < length; ++i)		//������������ĵڶ�Ԫ�ؿ�ʼ������Ԫ�أ���
			{
				//��iԪ���������������ڶ�iԪ�ؽ��в�������
				char needToInsert = a[i];
				int j;
				for (j = i - h; j >= 0 && needToInsert < a[j]; j -= h)
					a[j + h] = a[j];

				a[j + h] = needToInsert;
			}

			h /= 3;
		}

	}
};

#endif