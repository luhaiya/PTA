#include <iostream>  
#include <vector>  
#include <stack>  
#include <string>  
using namespace std;  
#define maxLen 30  
vector<int> pre, in;  
int post[maxLen];  
int N;  
int find_index(vector<int> v, int data){  
    for(unsigned int i = 0; i < v.size(); i++){  
        if(v[i] == data){  
            return i;  
        }  
    }  
    return -1;  
}  
void tree_traversals_again(int prehead, int inhead, int posthead, int len){  
    if(len == 0)  
        return;  
    if(len == 1){  
        post[posthead] = pre[prehead];  
        return;  
    }  
    int root = pre[prehead];  
    post[posthead + len - 1] = root;  
    int index = find_index(in, root);  
    int L = index - inhead;  
    int R = len - L - 1;  
    tree_traversals_again(prehead + 1, inhead, posthead, L);  
    tree_traversals_again(prehead + L + 1, inhead + L + 1, posthead + L, R);  
}  
int main(){  
    cin>>N;  
    string str;  
    int data;  
    stack<int> sta;  
    for(int i = 0; i < 2*N; i++){  
        cin>>str;  
        if(str == "Push"){  
            cin>>data;  
            pre.push_back(data);  
            sta.push(data);  
        }else{  
            in.push_back(sta.top());  
            sta.pop();  
        }  
    }  
    tree_traversals_again(0,0,0,N);  
    if(N){  
        cout<<post[0];  
        for(int i = 1; i < N; i++)  
            cout<<' '<<post[i];  
    }  
    return 0;  
} 
