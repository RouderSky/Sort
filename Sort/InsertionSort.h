#ifndef __INSERTIONSOER_H__
#define __INSERTIONSOER_H__

//��������(ð������)
class Insertion
{
public:
	//ð����ʽ
	void Sort1_0(char *a, int length)
	{
		for (int index = 1; index < length; ++index)	//ÿһ����Ҫ��ʼ�³���Ԫ��
		{
			for (int i = index; i > 0; --i)				//�³��Ĺ���
			{
				if (a[i] < a[i - 1])
				{
					char temp = a[i];
					a[i] = a[i - 1];
					a[i - 1] = temp;
				}
			}
		}
	}

	//������ʽ
	//ð�ݵ��Ż��汾
	void Sort2_0(char *a, int length)
	{
		for (int index = 1; index < length; ++index)				//ÿһ����Ҫ��ʼ�³���Ԫ��
		{
			char needToInsert = a[index];

			int i;
			for (i = index - 1; i >= 0 && needToInsert < a[i]; --i)		//Ѱ��λ�õĹ���
				a[i + 1] = a[i];	//����

			a[i + 1] = needToInsert;
		}
	}

};



#endif