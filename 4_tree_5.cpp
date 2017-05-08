//求构成一个AVL二叉树后根节点的值
#include <iostream>  
#include <stdlib.h>  
using namespace std;  
typedef struct node *avltree;  
struct node{  
    int data;  
    avltree left;  
    avltree right;  
};  
int getHeight(avltree &root){  
    if(root)  
        return max(getHeight(root->left),getHeight(root->right))+1;  
    else  
        return 0;  
}  
avltree rotateLL(avltree &root){  
    avltree tree = root->left;  
    root->left = tree->right;  
    tree->right = root;  
    return tree;  
}  
avltree rotateRR(avltree &root){  
    avltree tree = root->right;  
    root->right = tree->left;  
    tree->left = root;  
    return tree;  
}  
avltree rotateLR(avltree &root){  
    root->left = rotateRR(root->left);  
    return rotateLL(root);  
}  
avltree rotateRL(avltree &root){  
    root->right = rotateLL(root->right);  
    return rotateRR(root);  
}  
avltree insert(avltree &root, int data){  
    if(root == NULL){  
        avltree tree = new node;  
        tree->data = data;  
        tree->left = NULL;  
        tree->right = NULL;  
        root = tree;  
        return root;  
    }  
    if(data < root->data){  
        root->left = insert(root->left, data);  
        if(getHeight(root->left) - getHeight(root->right) == 2){  
            if(data < root->left->data){  
                root = rotateLL(root);  
            }else{  
                root = rotateLR(root);  
            }  
        }  
    }else{  
        root->right = insert(root->right, data);  
        if(getHeight(root->left) - getHeight(root->right) == -2){  
            if(data > root->right->data){  
                root = rotateRR(root);  
            }else{  
                root = rotateRL(root);  
            }  
        }  
    }  
    return root;  
}  
void print(avltree root){  
    cout<<root->data<<' ';  
    if(root->left)  
        print(root->left);  
    if(root->right)  
        print(root->right);  
}  
int main(){  
    int N, data;  
    cin>>N;  
    avltree tree = NULL;  
    for(int i = 0; i < N; i++){  
        cin>>data;  
        insert(tree, data);  
    }  
    cout<<tree->data;  
    return 0;  
}  
