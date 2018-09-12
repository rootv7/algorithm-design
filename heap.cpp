#include<iostream>

using namespace std;

class heap{
	int btree[1000];
	int index;
public:
	heap(int root){
		btree[0] = root;
		index = 1;
	}
	int findmin(){
		return btree[0];
	}
	void insert(int element);
	void delmin();
	void show(){
		for(int i = 0; i < index; i++)
			cout<<btree[i]<<endl;
	}
};

void heap::insert(int element){
	btree[index] = element;
	int pos = index, parent_pos;
	while(1){
		int parent_pos = (pos - 1)/2;
		if(pos == 0 || btree[parent_pos] <= btree[pos])
			break;
		btree[pos] = btree[parent_pos];
		btree[parent_pos] = element;
		pos = parent_pos;
	}
	index++;
}

void heap::delmin(){
	btree[0] = btree[index - 1];
	index--;
	int pos = 0;
	while(1){
		int right_pos = pos*2 + 2;
		int left_pos = pos*2 + 1;
		int swap_index;
		if(left_pos >= index){
			break;
		}else if(right_pos == index){
			swap_index = left_pos;
		}else{
			if(btree[right_pos] > btree[left_pos])
				swap_index = left_pos;
			else
				swap_index = right_pos;
		}
		if(btree[swap_index] >= btree[pos])
			break;
		int temp = btree[swap_index];
		btree[swap_index] = btree[pos];
		btree[pos] = temp;
		pos = swap_index;
	}
}

int main(){
	heap H(23);
	H.insert(5);
	H.insert(19);
	H.insert(2);
	H.insert(21);
	H.insert(32);
	H.show();
	cout<<H.findmin()<<endl;
	H.delmin();
	H.show();
}