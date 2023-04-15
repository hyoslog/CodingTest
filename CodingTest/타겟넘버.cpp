#include <string>
#include <vector>

using namespace std;

int op[2] = { -1, 1 };

void DFS(int& outAnswer, const vector<int>& numbers, const int target, const int index, const int sum)
{
    if (numbers.size() == index)
    {
        if (sum == target)
        {
            ++outAnswer;
        }
        return;
    }

    const int caseA = numbers[index] * op[0];
    DFS(outAnswer, numbers, target, index + 1, sum + caseA);

    const int caseB = numbers[index] * op[1];
    DFS(outAnswer, numbers, target, index + 1, sum + caseB);
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;

    DFS(answer, numbers, target, 0, 0);

    return answer;
}

int main()
{
    vector<int> inputs = {1, 1, 1, 1, 1};
    int result = solution(inputs, 3);

    return 0;
}