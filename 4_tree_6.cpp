//完全二叉搜索树的逐层遍历
#include <iostream>  
#include <stdlib.h>  
using namespace std;  
  
const int maxlen = 10001;  
int in_index = 0;  
int level[maxlen];  
  
int compare(const void *a, const void *b){  
    return  *(int*)a - *(int*)b;  
}  
  
void in_pass(int root, int N, int array[]){  
    if(root <= N){  
        in_pass(root*2, N, array);  
        level[root] = array[in_index++];  
        in_pass(root*2+1, N, array);  
    }  
}  
  
int main(){  
    int N;  
    cin>>N;  
    int in[maxlen];  
    for(int i = 0; i < N; i++){  
        cin>>in[i];  
    }  
    qsort(in, N, sizeof(int), compare);  
//  for(int i = 0; i < N; i++){  
//      cout<<in[i]<<' ';  
//  }  
//  cout<<endl;  
    in_pass(1, N, in);  
    cout<<level[1];  
    for(int i = 2; i <= N; i++){  
        cout<<' '<<level[i];  
    }  
    return 0;  
}  
