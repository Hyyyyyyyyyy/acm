int hui[210][210];
void huihuan(int N)
{
	int n = N;
	int sq = (int)sqrt((double)N);
	for (int i = sq; i >= 2; i -= 2)
	{
		int up = (sq - i) / 2 + i;
		int down = (sq - i) / 2 + 1;
		for (int y = down; y <= up; y++)
		{
			hui[down][y] = n--;
		}
		for (int x = down + 1; x <= up; x++)
		{
			hui[x][up] = n--;
		}
		for (int y = up - 1; y >= down; y--)
		{
			hui[up][y] = n--;
		}
		for (int x = up - 1; x > down; x--)
		{
			hui[x][down] = n--;
		}
	}
}
//N是一个平方数 且是整个宫格中最大数
//最大数为左上角
//这是逆时针转，副对角线左上方向为平方数，顺时针改为右下角是最大数，副对角线右下方向为平方数