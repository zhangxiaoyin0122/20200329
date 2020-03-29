#include <stdio.h>
#include <stdlib.h>
//向右旋转一次
void Func1(int arr[],int size) {
	int tmp = arr[size - 1];
	while (size - 1 >= 0) {
		arr[size - 1] = arr[size - 2];
		size--;
	}
	arr[0] = tmp;
}
//向右旋转k次
void Funck(int arr[], int size, int k) {
	while (k > 0) {
		Func1(arr,size);
		k--;
	}
}
int main() {
	int arr[] = { 1,2,3,4,5,6,7 };
	Funck(arr, sizeof(arr) / sizeof(arr[0]),2);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int* Anum = (int*) malloc(sizeof(int)*(m + n));
	int idx = 0;
	int n1 = 0;
	int n2 = 0;
	while (n1 < m && n2 < n) {
		if (nums1[n1] < nums2[n2]) {
			Anum[idx++] = nums1[n1++];
		}
		else {
			Anum[idx++] = nums2[n2++];
		}
	}
	if (n1 < m) {
		memcpy(Anum +idx, nums1 + n1, sizeof(int)*(m - n1));
	}
	if (n2 < n) {
		memcpy(Anum + idx, nums2 + n2, sizeof(int)*(n - n2));
	}
	memcpy(nums1, Anum, sizeof(int)*(m + n));
	free(Anum);
}


int main() {
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int	nums2[] = { 2, 5, 6 }; 
	merge(nums1, 6, 3, nums2, 3, 3);
	for (int i = 0; i < 6; i++) {
		printf("%d", nums1[i]);
	}
	system("pause");
	return 0;
}