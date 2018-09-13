#include <iostream>

using namespace std;

int main(){
	bool is_maj = false;
	int n;
	cin>>n;
	int a[n], maj_index=0, count=1;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[maj_index] == a[i])
			count++;
		else
			count--;
		if(count == 0){
			maj_index = i;
			count = 1;
		}
	}
	cout<<a[maj_index]<<endl;
	count = 0;
	for(int i=0;i<n;i++){
		if(a[i] == a[maj_index])
			count++;
		if(count == n/2 + 1){
			is_maj = true;
			break;
		}
	}
	cout<<is_maj<<endl;
	return 0;
}