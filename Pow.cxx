#include<iostream> 
using namespace std;  
	int Pow(int x, unsigned int y) { 
		int temp; 
		if( y == 0) 
			return 1; 
		temp = Pow(x, y/2); 
		if (y%2 == 0) 
			return temp*temp; 
		else
			return x*temp*temp; 
	}  
int main(){ 
    int p; 
    unsigned int s; 
    cout<<"enter p: ";
    cin>>p;
    cout<<"enter s: ";
    cin>>s;
    cout<<endl;
    cout <<"p^s = "<< Pow(p, s); 
    return 0; 
} 
