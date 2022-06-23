#include<stdio.h>
#define Max 100


void big_add(int *temp, int *sum);
void big_mul(int,int*);
void big_mul_sum(int, int*);
void big_printf(int*);
void main(){
	int sum[Max] {0};
	for (int i = 1; i <= 100000; i++)
	{
		big_mul_sum(i,sum);
	}
	//big_mul(10000, sum);
	/*int test1[Max] {1, 0, 0, 1};
	int test2[Max] {911, 0, 0, 9};
	big_add(test1, test2);*/
	big_printf(sum);

	getchar();

}

void big_mul_sum(int i, int *sum){
	int temp[Max] {0};
	big_mul(i, temp);
	big_add(temp, sum);
}

void big_add(int *temp, int *sum){
	int carry = 0;
	for (int i = 0; i < Max; i++)
	{
		sum[i] += temp[i] + carry;
		carry = sum[i] / 10;
		sum[i] %= 10;
	}

}

void big_mul(int i,int *sum){
	int temp[Max] {0};
	//reverse
	int index{ 0 };
	for (index = 0; i != 0; index++)
	{
		temp[index] = i % 10;
		i = i / 10;
	}
	
	for (int tt = 0; tt < index+1; tt++)
	{
		for (int kk = 0; kk + tt < Max; kk++)
		{
			sum[tt + kk] += temp[tt] * temp[kk];
		}
	}
	int carry = 0;
	for (int tt = 0; tt < Max; tt++)
	{
		sum[tt] += carry;
		carry = sum[tt] / 10;
		sum[tt] = sum[tt] % 10;
	}
	
}

void big_printf(int* aa){
	bool print_flag = false;
	for (int i = Max-1; i >= 0; i--)
	{
		if (aa[i] != 0 || print_flag){
			printf("%d", aa[i]);
			print_flag = true;
		}
	}
}