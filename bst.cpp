#include <iostream>
#include <cstddef>

using namespace std;

struct node{
	int value;
	node* right_child;
	node* left_child;
};

class bst{
	node* root;
	void delete_tree(node* root);
	void show(node* root);
	node* find(int item, node* root);
	node* insert(int item, node* root);
	node* delete_item(int item, node* root);
	node* min_value_node(node* root);
public:
	bst(){
		//cout<<"Here";
		root = NULL;
	}
	~bst(){
		delete_tree(root);
	}
	void find(int item){
		if(find(item, root) != NULL)
			cout<<"item found"<<endl;
		else
			cout<<"item not found"<<endl;
	}
	void insert(int item){
		root = insert(item, root);
	}
	void show(){
		show(root);
		cout<<endl;
	}
	void delete_item(int item){
		root = delete_item(item, root);
	}
	
};

node* bst::min_value_node(node* root){
	if(root->left_child == NULL)
		return root;
	return min_value_node(root->left_child);
}

void bst::delete_tree(node* root){
	if(root){
		delete_tree(root->left_child);
		delete_tree(root->right_child);
		delete root;
	}
}

void bst::show(node* root){
	if(root){
		show(root->left_child);
		cout<<root->value<<" ";
		show(root->right_child);
	}
}

node* bst::find(int item, node* root){
	if(root == NULL){
		return NULL;
	}
	else if(item == root->value){
		return root;
	}
	else if(item > root->value){
		return find(item, root->right_child);
	}
	else{ 
		return find(item, root->left_child);
	}
}

node* bst::insert(int item, node* root){
	if(root == NULL){
		node* new_node = new node();
		new_node->value = item;
		new_node->left_child = NULL;
		new_node->right_child = NULL;
		return new_node;
	}
	else if(root->value == item)
		cout<<"Item already exists"<<endl;
    else if(root->value > item)
	 	root->left_child = insert(item, root->left_child);
	else
	 	root->right_child = insert(item, root->right_child);
 	return root;
}

node* bst::delete_item(int item, node* root){
	if(root == NULL)
		cout<<"Item does not exist";
	else if(root->value > item)
		root->left_child = delete_item(item, root->left_child);
	else if(root->value < item)
		root->right_child = delete_item(item, root->right_child);
	else if(root->left_child == NULL){
		node* temp = root->right_child;
		delete root;
		return temp;
	}
	else if(root->right_child == NULL){
		node* temp = root->left_child;
		delete root;
		return temp;
	}
	else{
		root->value = min_value_node(root->right_child)->value;
		root->right_child = delete_item(root->value,root->right_child);
	}
	return root;
}

int main(){
	bst btree;
	btree.show();
	btree.insert(1);
	btree.insert(0);
	btree.insert(3);
	btree.insert(2);
	btree.insert(5);
	btree.insert(4);
	btree.insert(6);
	btree.show();
	btree.find(4);
	btree.delete_item(3);
	btree.delete_item(6);
	btree.show();
	return 0;
}