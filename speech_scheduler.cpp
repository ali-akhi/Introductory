 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string.h>
using namespace std;

void merge(int a[], int Findex, int m, int Lindex);
 //merge sort algorithm
void mergeSort(int a[], int Findex, int Lindex) { 
    if (Findex < Lindex) { 
        int m = Findex + (Lindex - Findex)/2; 
        mergeSort(a, Findex, m); 
        mergeSort(a, m+1, Lindex); 
        merge(a, Findex, m, Lindex); 
    } 
}   
void merge(int a[], int Findex, int m, int Lindex) { 
    int x, y, z;
    int sub1 = m - Findex + 1; 
    int sub2 =  Lindex - m; 
    int First[sub1], Second[sub2];  
    
    for (x = 0; x < sub1; x++) 
        First[x] = a[Findex + x]; 
    for (y = 0; y < sub2; y++) 
        Second[y] = a[m + 1+ y]; 
    x = 0; y = 0;z = Findex; 
    while (x < sub1 && y < sub2) { 
        if (First[x] <= Second[y]) { 
            a[z] = First[x]; 
            x++; 
        } 
        else{ 
            a[z] = Second[y]; 
            y++; 
        } 
        z++; 
    } 
    while (x < sub1){ 
        a[z] = First[x]; 
        x++; 
        z++; 
    } 
    while (y < sub2){ 
        a[z] = Second[y]; 
        y++; 
        z++; 
    } 
} 
//map elements
void printMapping(int A[], int B[], int start[], int C[], int M){
	int temp;
	for(int i=0; i<M; i++){
		temp= A[i];
		for(int j=0; j<M; j++){
			if(temp == B[j]){
				C[j]=start[i];
			}
		}
	}
}
//read arrat
void readArray(int A[], int M){
	for(int i=0; i<M; i++){
		cout<< "speech"<<i<<" :";
		cin>> A[i];
	}
}
///////////////////////
int main(){
	int n;int Var=0;
	cout<< "enter Number of speech: ";
	cin>>n;
	int start[100];int end[100];int order[100]; int not_merg[100];
	cout<< "ENTER START TIME: "<<endl;
	readArray(start, n);
	cout<<endl;
	cout<< "ENTER END TIME: "<<endl;
	readArray(end, n);
	for(int i=0; i<n; i++)
		not_merg[i]= end[i];
		
	mergeSort(end, 0, n- 1);
	
		printMapping(not_merg, end, start, order, n);
		int k=0;
	for(int i=1; i<n; i++){
		if(order[i+1] >= end[k]){
			Var++;
			k=i;
		}
		//end[i-1]= end[i+1];
	}
	cout<< Var;
	return 0;
}

