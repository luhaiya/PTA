#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node btree;
struct node{
	int data;
	int flag;
	btree *left;
	btree *right;
};
btree* create_node(int data){
	btree *p = (btree*)malloc(sizeof(struct node));
	p->data = data;
	p->flag = 0;
	p->left = NULL;
	p->right = NULL;
	return p;
}
btree* add_node(btree *root, int data){
	if(root){
		if(data > root->data)
			root->right = add_node(root->right, data);
		else
			root->left = add_node(root->left, data);
	}else{
		root = create_node(data);
	}
	return root;
}
btree* create_tree(int len){
	btree *tree = NULL;
	int data;
	for(int i = 0; i < len; i++){
		cin>>data;
		if(tree){
			add_node(tree, data);
		}else{
			tree = create_node(data);
		}
	}
	return tree;
}
void print(btree *root){

	cout<<root->data<<' '<<root->flag;
	if(root->left)
		print(root->left);
	if(root->right)
		print(root->right);

}
int check_tree(btree *root, int data){
	int flag = 0;
	while(root->flag){
		if(root->data > data)
			root = root->left;
		else if(root->data < data)
			root = root->right;
	}
	if(root->data != data)
		flag = 1;
	else
		root->flag = 1;
	return flag;
}
void compare_tree(btree *root, int len){
	int flag = 0;
	int data;
	for(int i = 0; i < len; i++){
		cin>>data;
		if(check_tree(root, data))
			flag = 1;
	}
	if(flag)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}
void reset_flag(btree *root){
	if(root->left)
		reset_flag(root->left);
	if(root->right)
		reset_flag(root->right);
	root->flag = 0;
}
void free_tree(btree *root){
	if(root->left)
		free_tree(root->left);
	if(root->right)
		free_tree(root->right);
	free(root);
}

int main(){
	int N, L;
	cin>>N;
	btree *tree = NULL;
	while(N){
		cin>>L;
		tree = create_tree(N);
		for(int i = 0; i < L; i++){
			compare_tree(tree, N);
			reset_flag(tree);
		}
		free_tree(tree);
		cin>>N;
	}
}
