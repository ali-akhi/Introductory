#include <iostream>
#include <climits>
using namespace std;
/*function for find minimum and maximum*/
void findMin_Max_D_C(int arr[], int low, int high, int& min, int& max){
    if (low == high){
        if (max < arr[low])
            max = arr[low];

        if (min > arr[high])
            min = arr[high];

        return;
    }
    if (high - low == 1){
        if (arr[low] < arr[high]){
            if (min > arr[low])
                min = arr[low];

            if (max < arr[high])
                max = arr[high];
        }
        else{
            if (min > arr[high])
                min = arr[high];

            if (max < arr[low])
                max = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    findMin_Max_D_C(arr, low, mid, min, max);
    findMin_Max_D_C(arr, mid + 1, high, min, max);
}
int main(){
    int arr[100], n;
    cout<<"Enter size of your array: ";
    cin>>n;
    for(int i=0; i<n; i++){
		cout<<"a=["<<i<<"] :";
		cin>>arr[i];
	}
    int max = INT_MIN, min = INT_MAX;

    findMin_Max_D_C(arr, 0, n - 1, min, max);
	cout<<endl;
    cout << "=>min element in this array is " << min << '\n';
    cout << "=>max element in this array is " << max;
    return 0;
}
