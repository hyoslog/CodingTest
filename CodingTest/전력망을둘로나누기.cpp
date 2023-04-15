#include <string>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

void DFS(const vector<vector<int>>& graph, vector<bool>& outVisited, vector<int>& outConnected, const int num)
{
    if (outVisited[num] == true)
    {
        return;
    }

    outVisited[num] = true;
    outConnected.emplace_back(num);    

    for (int i = 0; i < graph[num].size(); ++i)
    {
        DFS(graph, outVisited, outConnected, graph[num][i]);
    }
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = -1;

    set<int> answerDatas;

    for (int cutIndex = 0; cutIndex < (n - 1); ++cutIndex)
    {
        vector<vector<int>> graph;
        graph.resize(n + 1);

        for (int wireIndex = 0; wireIndex < (n - 1); ++wireIndex)
        {
            int firstVertex = wires[wireIndex][0];
            int secondVertex = wires[wireIndex][1];

            // 연결 자르기
            if (cutIndex == wireIndex)
            {
                continue;
            }

            graph[firstVertex].emplace_back(secondVertex);
            graph[secondVertex].emplace_back(firstVertex);
        }

        // 연결된 송전탑 개수 구하기
        vector<bool> visited;
        visited.resize(n + 1, false);

        // 1부터 탐색 시작
        vector<int> connected;
        DFS(graph, visited, connected, 1);

        // 송전탑1: connected.size()
        // 송전탑2: (n - connected.size())
        int diff = abs(static_cast<int>(n - (2 * connected.size())));
        if (diff == 0)
        {
            answer = 0;
            break;
        }

        answerDatas.emplace(diff);
    }

    answer = *answerDatas.begin();
    return answer;
}

int main()
{
    vector<vector<int>> inputs = {{1, 2}, {2, 3}, {3, 4}};
    
    int result = solution(4, inputs);

    return 0;
}