#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) 
{
	vector<int> answer;

	// 3, 12 => 3, 4 ,5
	// x + 0
	// x + 1
	// x + 2

	//(num * x) + ((num - 1) * num) / 2 = total; => x ±¸ÇÏ±â
	int x = ((total - (((num - 1) * num) / 2)) / num);

	for (int i = 0; i < num; ++i)
	{
		answer.emplace_back(x + i);
	}

	return answer;
}

int main()
{
	vector<int> result = solution(3, 0);

	return 0;
}