#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
void combine(int*** result, int* size, int* nums, int n, int target, int** column, int* before, int bef, int sum, int start, int time) {
	if (sum == target && bef == time) {
		(*size)++;
		result[0] = (int**)realloc(result[0], *size * sizeof(int*));
		result[0][*size - 1] = (int*)malloc(bef * sizeof(int));
		column[0] = (int*)realloc(column[0], *size * sizeof(int));
		column[0][*size - 1] = bef;
		memcpy(result[0][*size - 1], before, sizeof(int)* bef);
		return;
	}
	if (bef == time) return;
	int i = 0;
	for (i = start; i < n; i++) {
		if (sum + nums[i] > target)
			continue;
		before[bef] = nums[i];
		combine(result, size, nums, n, target, column, before, bef + 1, sum + nums[i], i, time);
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int time) {
	int** result = NULL;
	int* before = (int*)malloc(100 * sizeof(int));
	combine(&result, returnSize, candidates, candidatesSize, target, columnSizes, before, 0, 0, 0, time);
	free(before);
	return result;
}
int main(){
	/*int candidates[6] {1, 2, 3, 4, 5, 6};
	int candidatesSize = 6;
	int target = 15;
	int time = 5;*/

	int candidates[20] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int candidatesSize = 20;
	int target = 72;
	int time = 6;

	int** columnSizes = (int**)malloc(sizeof(int));
	*columnSizes = (int*)malloc(sizeof(int));
	columnSizes[0][0] = 0;
	int* returnSize = (int*)malloc(sizeof(int));
	*returnSize = 0;

	int** result = combinationSum(candidates, candidatesSize, target, columnSizes, returnSize, time);

	/*std::vector<std::vector<int>> a;
	int vector_size = 0;
	for (int i = 0; i < *returnSize; i++)
	{
		if (columnSizes[0][i] == time)
		{
			std::vector<int> temp;
			for (int kk = 0; kk < time; kk++)
			{
				temp.push_back(result[i][kk]);
			}
			a.push_back(temp);
			vector_size++;
		}
	}*/

	return 0;
}