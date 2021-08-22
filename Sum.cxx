#include <bits/stdc++.h> 
using namespace std; 
/*mergsort or heap sort ---> O(nlogn)*/
void Merge(int arr[], int l, int m, int r){ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	i = 0;
	j = 0;
	k = l;  
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1){ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2){ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
void MergeSort(int arr[], int l, int r){ 
    if (l < r){ 
        int m = l+(r-l)/2; 
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
  
        Merge(arr, l, m, r); 
    } 
}
bool HAC(int A[], int arr_size, int sum){ 
    int l, r; 
    MergeSort(A, 0, arr_size - 1);
    l = 0; 
    r = arr_size - 1; 
    while (l < r) { 
        if (A[l] + A[r] == sum) 
            return 1; 
        else if (A[l] + A[r] < sum) 
            l++; 
        else
            r--; 
    } 
    return 0; 
} 
////////////////////////////////////
int main() 
{ 
    int Array[] = { 1, 4, 45, 6, 18, -8 }; 
    int n = 16; 
    int arr_size = sizeof(Array) / sizeof(Array[0]); 
    if (HAC(Array, arr_size, n)) 
        cout << "find number :)"; 
    else
        cout << "not find number :("; 
  
    return 0; 
} 
