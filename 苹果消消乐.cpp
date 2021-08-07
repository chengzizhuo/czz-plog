/*
������������
   ��100��ƻ�����㽶�ų�һ��ֱ�ߣ�������N���㽶��
   �����ʹ������M��ħ�����߽��㽶���ƻ����
   ����������ƻ����������Ϊ�㱾��ƻ�������ֵĵ÷֣�
   ����ƻ�����㽶�����У������ܻ�õ����÷֡������Ǹ�ö���⣩
��������ʽ��
   ��һ����һ������T(1 <= T <= 10)������������ݵ�������
   ÿ���������ݵ�һ����2������N��M(0 <= N, M <= 100)��
   �ڶ��а���N������a1, a2, ... aN(1 <= a1 < a2 < ... < aN<= 100)����ʾ��a1, a2, ... aN��λ���ϰڷŵ����㽶��
�������ʽ��
   ����ÿ�����ݣ����ͨ��ʹ��ħ�����ߺ����ܻ�õ����÷֡�
���������롿
   3
   5 1
   34 77 82 83 84
   5 2
   10 30 55 56 90
   5 10
   10 30 55 56 90
�����������
   76
   59
   100 
*/
#include<iostream>
using namespace std;

int main()
{
	int n, M, N;
	cin >> n;
	for (int i = 1; i < n+1; i++)
	{
		cin >> N >> M;
		if (M >= N)
		{
			cout << 100<<endl;
			continue;
		}
			
		int* position = new int[N]();//�㽶λ�� 
		int* distance = new int[N + 1]();//�㽶��� 
		int score = 0, w = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> position[j];
		}
		for (int j = 0; j < N +1 ; j++)
		{
			if (j == 0) distance[j] = position[j];//0����һ���㽶 
			else if (j == N) distance[j] = 100 - position[j-1];//���һ���㽶��100 
			else distance[j] = position[j] - position[j-1];//���㽶�� 
		}
		for (int j = 0; j < N - M + 1; j++)//�ӵڼ����㽶ʩħ�� 
		{
			score = 0;
			for (int k = 0; k < M + 1; k++)//ʩ����ħ�� 
			{
				score += distance[j + k];//���� 
			}
			if (score > w) w = score;
		}
		cout << w-1 << endl;
		delete[] position; position = 0;
		delete[] distance; distance = 0;
	}
	return 0;
}


