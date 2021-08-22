 
#include <bits/stdc++.h> 
using namespace std; 
  
int findLocalMaxima(int n, int arr[]) 
{ 
    vector<int> mx, mn; 
    if (arr[0] > arr[1]) 
        mx.push_back(0); 
    for(int i = 1; i < n - 1; i++) 
    { 
    if ((arr[i - 1] < arr[i]) and 
                (arr[i] > arr[i + 1])) 
        mx.push_back(i); 
    } 
    if (arr[n - 1] > arr[n - 2]) 
        mx.push_back(n - 1); 
  
    else if (arr[n - 1] < arr[n - 2]) 
        mn.push_back(n - 1); 
    if (mx.size() > 0) 
    { 
        cout << "Points of Local maxima are : "; 
        for(int a : mx) 
        return a;
    } 
 }
 
 inline int get(int x){
	 cout<<  "?"<< x<< '\n';
	 cout.flush();
	 int a;
	 cin>>a;
	 return a;
 }
 
 inline void submit(int i){
	 cout<< "1" << i<< '\n';
	 cout.flush();
	 
 }
 
  #define MAX_NAME_LEN 3
  

int main() 
{ 
    int N = 5; 
    // Given array arr[] 
    int arr[] = { 1, 2, 3,  4, 5}; 
	char inputUser[100] = {0};
    int  value;
    // Function call 
    int MaxLog;
    MaxLog= findLocalMaxima(N, arr); 
    cout<< "judge  >>  "<< N<<endl;
	for(int i=0; i<N; i++){
		cout <<"solver  >>  ";
		cin.getline(inputUser,100);
		if((inputUser[0] == '?' || inputUser[0] == '!') && inputUser[1] == ' ' ){
			if(inputUser[0] == '?'){
				value=(int) inputUser[2] - 48;
				if(value < N){
					cout <<  "judge  >>  "<< arr[value]<<endl;
				}else{
					cout<< "is too large !"<< endl;
					return 0;
				}
			}else if(inputUser[0] == '!'){
				if(inputUser[2] -48 == MaxLog){
					cout<< "accepted !"<<endl; 
					return 0;
				}
			}
		}else{
			cout<< "You are wrong to ask a question";
			return 0;
		}		
	}
	cout<< "too many question !"<< endl;
} 
