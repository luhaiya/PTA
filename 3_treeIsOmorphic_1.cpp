#include <iostream>  
using namespace std;  
#define maxTree 10  
#define null -1  
struct node{  
    char tag;  
    int left;  
    int right;  
}T1[maxTree],T2[maxTree];  
int N, isRoot[maxTree];  
int create_tree(struct node T[], int treeLen){  
    int root = null, i;  
    char cl, cr;  
    if(treeLen){  
        for(i = 0; i < treeLen; i++)  
            isRoot[i] = 0;  
        for(i = 0; i < treeLen; i++){  
            cin>>T[i].tag>>cl>>cr;  
            if(cl != '-'){  
                T[i].left = cl - '0';  
                isRoot[T[i].left] = 1;  
            }else{  
                T[i].left = null;  
            }  
            if(cr != '-'){  
                T[i].right = cr - '0';  
                isRoot[T[i].right] = 1;  
            }else{  
                T[i].right = null;  
            }  
        }  
        for(i = 0; i < N; i++){  
            if(!isRoot[i]) break;  
        }  
        root = i;  
    }  
    return root;  
}  
int isOmorphic(int t1, int t2){  
    if(t1 == null && t2 == null){  
        return true;  
    }  
    if(t1 != null && t2 == null){  
        return false;  
    }  
    if(t1 == null && t2 != null){  
        return false;  
    }  
    if(T1[t1].tag != T2[t2].tag){  
        return false;  
    }  
    if(T1[t1].left == null && T2[t2].left == null){  
        return isOmorphic(T1[t1].right, T2[t2].right);  
    }  
    if(T1[t1].left != null && T2[t2].left != null && T1[T1[t1].left].tag == T2[T2[t2].left].tag){  
        return isOmorphic(T1[t1].left, T2[t2].left) && isOmorphic(T1[t1].right, T2[t2].right);  
    }else{  
        return isOmorphic(T1[t1].left, T2[t2].right) && isOmorphic(T1[t1].right, T2[t2].left);  
    }  
}  
int main(){  
    cin>>N;  
    int t1, t2;  
    t1 = create_tree(T1, N);  
    cin>>N;  
    t2 = create_tree(T2, N);  
    if(isOmorphic(t1,t2)){  
        cout<<"Yes"<<endl;  
    }else{  
        cout<<"No"<<endl;  
    }  
    return 0;  
}  
