#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	int answer = 0;

	vector<vector<int>> dp;

	const size_t height = triangle.size();
	dp.resize(height);

	for (size_t i = 0; i < height; ++i)
	{
		dp[i].resize(triangle[i].size(), -1);
	}

	dp[0][0] = triangle[0][0];

	for (int i = 1; i < height; ++i)
	{
		for (int j = 0; j < (i + 1); ++j)
		{
			//int& ret = dp[i][j];

			int left = (j - 1);
			if (left >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][left] + triangle[i][j]);
			}

			int right = j;
			if (right < i)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][right] + triangle[i][j]);
			}
		}
	}

	answer = dp[height - 1][0];
	for (int i = 0; i < height; ++i)
	{
		if (answer < dp[height - 1][i])
		{
			answer = dp[height - 1][i];
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };
	int result = solution(triangle);

	return 0;
}