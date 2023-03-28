#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
	int answer = 1;

	const int maxValue = *(section.end() - 1);

	int next = section[0] + m - 1; // 다음은 몇 번까지 칠할 수 있는지

	for (int i = 1; i < section.size(); ++i)
	{
		if (next < section[i])
		{
			++answer;
			next = section[i] + m - 1;
		}

		if (next > maxValue)
		{
			break;
		}
	}

	return answer;
}

int main()
{
	vector<int> datas = { 2, 3, 6 };
	int result = solution(8, 4, datas);

	return 0;
}