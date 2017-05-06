#include <iostream>  
#include <stdlib.h>  
using namespace std;  
#define maxlen 1000  
typedef struct node{  
    int data[maxlen];  
    int capacity;  
    int top;  
}stack;  
int M,N,K;  
stack *create_stack(){  
    stack *ptr = (stack*)malloc(sizeof(struct node));  
    ptr->capacity = maxlen;  
    ptr->top = -1;  
    return ptr;  
}  
void push(stack *ptr, int num){  
    if(ptr->top == ptr->capacity -1){  
        cout<<"Full";  
        return;  
    }  
    ptr->top++;  
    ptr->data[ptr->top] = num;  
}  
int top(stack *ptr){  
    return ptr->data[ptr->top];  
}  
void pop(stack *ptr){  
    if(ptr->top == -1){  
        cout<<"Empty";  
        return;  
    }  
    ptr->top--;  
  
}  
int check_stack(int data[]){  
    int capacity = M+1;  
    stack *ptr = create_stack();  
    push(ptr,0);  
    int index = 0;  
    int num = 1;  
    while(index != N){  
        while(top(ptr)<data[index] && ptr->top+1 < capacity && index != N){  
            push(ptr,num++);  
        }  
        if(top(ptr) == data[index]){  
            pop(ptr);  
            index++;  
        }else  
            return false;  
    }  
    return true;  
}  
int main(){  
    cin>>M>>N>>K;  
    int dat[N];  
    int i;  
    for(;K!=0;--K){  
        for(i = 0; i < N; i++){  
            cin>>dat[i];  
        }  
        if(check_stack(dat)){  
            cout<<"YES"<<endl;  
        }else{  
            cout<<"NO"<<endl;  
        }  
    }  
    return 0;  
}  
