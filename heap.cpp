#include<iostream>

using namespace std;

struct node{
	int element;
	node* parent;
	node* leftchild;
	node* rightchild;
};

class heap{
	node* root;
	node* position;
public:
	heap(node* root){
		this.root = root;
	}
	void insert(int element);
	void bubble_up(node* position);
	void update_position();
	node* leftmostchild(node* root){
		if(root->leftchild){
			leftmostchild(root->leftchild)
		}
		else{
			return root;
		}
	}
	/*void delmin() {
		delmin(this.root);
	}
	int findmin();
	void delmin(node* root);
	~heap(){
		if(root->rightchild)
	}*/
};
void heap::insert(int element){
	position->element = element;
	bubble_up(position);
}
void heap::bubble_up(node* position){
	if(position->parent){
		if(position->parent->element > position->element){
			int element = position->element;
			position->element = position->parent->element
			position->parent->element = element;
			insert(position->parent)
		}
	}
}
void heap::update_position(){
	if(position->parent){
		if(position->parent->leftchild == position){
			position = parent->rightchild->leftmostchild();
			node* new_position = new node*;
			position->leftchild = new_position;
			new_position->parent = position;
			position = new_position;
		}
		else{
			postion = parent->position
		}
	}
}

int main(){

}