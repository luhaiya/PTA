#include <iostream>  
#include <queue>  
using namespace std;  
#define maxTree 10  
#define null -1  
struct node{  
    int data;  
    int left;  
    int right;  
}tree[maxTree];  
int N, isRoot[maxTree];  
queue<int> Q;  
int create_tree(struct node T[]){  
    int root = null, i;  
    char cl, cr;  
    cin>>N;  
    if(N){  
        for(i = 0; i < N; i++)  
            isRoot[i] = 1;  
        for(i = 0; i < N; i++){  
            T[i].data = i;  
            cin>>cl>>cr;  
            if(cl != '-'){  
                T[i].left = cl - '0';  
                isRoot[T[i].left] = 0;  
            }else{  
                T[i].left = null;  
            }  
            if(cr != '-'){  
                T[i].right = cr - '0';  
                isRoot[T[i].right] = 0;  
            }else{  
                T[i].right = null;  
            }  
        }  
        for(i = 0; i < N; i++){  
            if(isRoot[i]) break;  
        }  
        root = i;  
    }  
    return root;  
}  
void bfs_find_leaves(int root){  
    Q.push(root);  
    int flag = 0;  
    while(!Q.empty()){  
        root = Q.front();  
        Q.pop();  
        if(tree[root].left == null && tree[root].right == null){  
            if(flag == 0){  
                cout<<tree[root].data;  
                flag = 1;  
            }else{  
                cout<<' '<<tree[root].data;  
            }  
        }  
        if(tree[root].left != null){  
            Q.push(tree[root].left);  
        }  
        if(tree[root].right != null){  
            Q.push(tree[root].right);  
        }  
    }  
}  
int main(){  
    int root;  
    root = create_tree(tree);  
    bfs_find_leaves(root);  
    return 0;  
}  
