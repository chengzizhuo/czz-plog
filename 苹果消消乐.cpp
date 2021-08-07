/*
【问题描述】
   有100个苹果和香蕉排成一条直线，其中有N个香蕉，
   你可以使用至多M次魔法道具将香蕉变成苹果，
   最后“最长的连续苹果数量”即为你本次苹果消消乐的得分，
   给定苹果和香蕉的排列，求你能获得的最大得分。（这是个枚举题）
【输入形式】
   第一行是一个整数T(1 <= T <= 10)，代表测试数据的组数。
   每个测试数据第一行是2个整数N和M(0 <= N, M <= 100)。
   第二行包含N个整数a1, a2, ... aN(1 <= a1 < a2 < ... < aN<= 100)，表示第a1, a2, ... aN个位置上摆放的是香蕉。
【输出形式】
   对于每组数据，输出通过使用魔法道具后你能获得的最大得分。
【样例输入】
   3
   5 1
   34 77 82 83 84
   5 2
   10 30 55 56 90
   5 10
   10 30 55 56 90
【样例输出】
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
			
		int* position = new int[N]();//香蕉位置 
		int* distance = new int[N + 1]();//香蕉间距 
		int score = 0, w = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> position[j];
		}
		for (int j = 0; j < N +1 ; j++)
		{
			if (j == 0) distance[j] = position[j];//0到第一个香蕉 
			else if (j == N) distance[j] = 100 - position[j-1];//最后一个香蕉到100 
			else distance[j] = position[j] - position[j-1];//两香蕉间 
		}
		for (int j = 0; j < N - M + 1; j++)//从第几个香蕉施魔法 
		{
			score = 0;
			for (int k = 0; k < M + 1; k++)//施几次魔法 
			{
				score += distance[j + k];//叠加 
			}
			if (score > w) w = score;
		}
		cout << w-1 << endl;
		delete[] position; position = 0;
		delete[] distance; distance = 0;
	}
	return 0;
}


