// https://www.acmicpc.net/problem/12100

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> board)
{
	vector<vector<int>> returned = board;
	
	int col_size = board.size();
	int	row_size = board[0].size();

	for (int i = 0; i < col_size; i++)
		for (int j = 0; j < row_size; j++)
		{
			returned[j][row_size - i - 1] = board[i][j];
		}
	return (returned);
}

vector<vector<int>> doBoard(vector<vector<int>> board, int dir)
{
	vector<vector<int>> ans_board = board;
	vector<vector<int>> is_merged;

	int n = board.size();

	is_merged.resize(n, vector<int>(n, false));

	for (int i = 0; i < dir; i++)
		ans_board = rotate(ans_board);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
				continue;
			for (int k = j; k > 0; k--)
			{
				if (ans_board[i][k-1] == 0)
				{
					ans_board[i][k-1] = ans_board[i][k];
					ans_board[i][k] = 0;
				}
				else if (ans_board[i][k-1] == ans_board[i][k])
				{
					if (!is_merged[i][k-1])
					{
						ans_board[i][k-1] *= 2;
						ans_board[i][k] = 0;
						is_merged[i][k-1] = true;
					}
					break;
				}
				else
					break;
			}
		}

	for (int i = 0; i < 4 - dir; i++)
		ans_board = rotate(ans_board);
	
	return ans_board;
}

int	find_max(vector<vector<int>> board)
{
	int max = 0;
	for (vector<int> row : board)
		for (int num : row)
		{
			if (num > max)
				max = num;
		}
	
	return max;
}

int	dfs(vector<vector<int>> board, int cnt)
{
	static int	max;
	vector<vector<int>> tmp;

	if (cnt == 5)
		return max;

	for (int i = 0; i < 4; i++)
	{
		tmp = doBoard(board, i);
		if (max < find_max(tmp))
			max = find_max(tmp);
		dfs(tmp, cnt + 1);
	}
	
	return max;
}

int main()
{
	int		n;
	int		max;
	vector<vector<int>> board;

	cin >> n;
	board.resize(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	max = dfs(board, 0);
	cout << max << "\n";

	return 0;
}