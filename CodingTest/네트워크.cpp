#include <string>
#include <vector>

using namespace std;

vector<bool> g_bVisited;
vector<vector<int>> g_Graph;

void DFS(const vector<vector<int>>& computers)
{

}

int solution(int n, vector<vector<int>> computers)
{
	g_bVisited.resize(n, false);
	g_Graph.resize(n);

	// 서로 연결되어있는 정보 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				continue;
			}

			if (computers[i][j] == 1)
			{
				g_Graph[i].emplace_back(j);
			}
		}
	}


	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
	}

	return answer;
}
int main()
{
    vector<vector<int>> inputs;
	inputs.push_back({ 1, 0, 1 });
	inputs.push_back({ 0, 1, 1 });
	inputs.push_back({ 1, 1, 1 });

	int result = solution(3, inputs);

    return 0;
}