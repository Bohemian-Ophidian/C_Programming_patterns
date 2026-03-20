#include <stdio.h>


int main(void)
{
	// ub with subscripting
	int arr[] = {11, 22, 33, 44, 55};
	for (int i = 0; i <= 5; i++) { // access of arr[5] is ub
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	// ub with pointer arithematic
	int *p_arr = arr;
	int len_arr = 5;
	while (p_arr++ && --len_arr); // p_arr increments even if len_arr is zero
	printf("%d %d\n", len_arr, *p_arr); // access of arr[5] is less clear
	
	p_arr = arr;
	len_arr = 5;
	// one fix can be
	while (--len_arr && p_arr++); // p_arr doesnt increment if len_arr is zero
	printf("%d %d\n", len_arr, *p_arr);

	return 0;
}