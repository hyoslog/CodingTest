#include <string>
#include <vector>

using namespace std;

int solution(int M, int N)
{
	int answer = 0;

	int big = (M > N) ? M : N;
	int small = (M <= N) ? M : N;

	answer = (big - 1) * small + (small - 1);

	return answer;
}

int main()
{
	int result = solution(2, 5);

	return 0;
}