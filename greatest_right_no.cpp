#include <iostream>
#include <stack>

using namespace std;

int  main(){
	stack <int> my_stack;
	int n;
	cin>>n;
	int A[n], B[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
		B[i] = -1;
		while(!my_stack.empty() && A[i] < A[my_stack.top()]){
			B[my_stack.top()] = i;
			my_stack.pop();
		}
		my_stack.push(i);
	}
	for(int i=0;i<n;i++){
		cout<<i<<" "<<A[i]<<" "<<B[i]<<endl;
	}
	return 0;
}