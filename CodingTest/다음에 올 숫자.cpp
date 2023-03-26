#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) 
{
	int answer = 0;

	int first = common[0];
	int second = common[1];
	int third = common[2];

	// 등차수열
	if ((second - first) == (third - second))
	{
		int d = (second - first);
		answer = first + (common_len * d);
	}
	// 등비수열
	else 
	{
		int d = (second / first);
		answer = common[common_len - 1] * d;
	}

	return answer;
}

int main()
{
#define COMMON_LEN 3

	int datas[COMMON_LEN] = {2, 4, 8};
	int result = solution(datas, COMMON_LEN);

	return 0;
}