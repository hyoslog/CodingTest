#include <string>
#include <vector>

using namespace std;

void DFS(const int n, const vector<vector<int>>& computers, vector<bool>& outVisited, vector<int>& outConnected, const int vertex)
{
	outVisited[vertex] = true;
	outConnected.emplace_back(vertex);

	for (int connectedVertex = 0; connectedVertex < n; ++connectedVertex)
	{
		if ((outVisited[connectedVertex] == false) && (computers[vertex][connectedVertex] == 1))
		{
			DFS(n, computers, outVisited, outConnected, connectedVertex);
		}		
	}
}

int solution(int n, vector<vector<int>> computers)
{
	vector<bool> visited;
	visited.resize(n, false);

	int answer = 0;

	for (int vertex = 0; vertex < n; ++vertex)
	{
		if (visited[vertex] == false)
		{
			vector<int> connected;
			DFS(n, computers, visited, connected, vertex);

			if (connected.empty() == false)
			{
				++answer;
			}
		}
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