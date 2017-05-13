#include <iostream>  
#include <algorithm>  
using namespace std;  
const int maxlen = 1005;  
int H[maxlen];  
void insert(int data, int index){  
    H[index] = data;  
    for(int j = index; j > 0; j /= 2){  
        if(H[j/2] > H[j]){  
            swap(H[j/2], H[j]);  
        }  
    }  
}  
void print_path(int index){  
    cout<<H[index];  
    for(int j = index/2; j > 0; j /= 2){  
        cout<<' '<<H[j];  
    }  
}  
int main(){  
    int N, M;  
    cin>>N>>M;  
    int data;  
    H[0] = -10001;  
    for(int i = 1; i <= N; i++){  
        cin>>data;  
        insert(data, i);  
    }  
    for(int i = 1; i <= M; i++){  
        cin>>data;  
        print_path(data);  
        cout<<endl;  
    }  
    return 0;  
}  
