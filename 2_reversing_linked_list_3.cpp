#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <stdio.h>  
using namespace std;  
#define maxlen 100001  
  
struct node{  
    int add;  
    int data;  
    int next;  
};  
typedef struct node Node;  
Node nodes[maxlen];  
vector<Node> nodeList;  
int main(){  
    int firstAdd, N, K;  
    cin>>firstAdd>>N>>K;  
    while(N--){  
        Node n;  
        cin>>n.add>>n.data>>n.next;  
        nodes[n.add] = n;  
    }  
    int address = firstAdd;  
    while(address != -1){  
        nodeList.push_back(nodes[address]);  
        address = nodes[address].next;  
    }  
    //到此nodeList存储的就是顺序的列表  
    int len = nodeList.size();  
    int period = len/K;  
    for(int i = 1; i <= period; i++){  
        int head = (i-1)*K;  
        int end = i*K;  
        reverse(nodeList.begin()+head, nodeList.begin()+end);  
    }  
    //reverse complete  
    //print nodeList  
    for(int i = 0; i < len-1; i++){  
        //cout<<nodeList[i].add<<" "<<nodeList[i].data<<" "<<nodeList[i+1].add<<endl;  
        printf("%05d %d %05d\n", nodeList[i].add, nodeList[i].data, nodeList[i+1].add);  
    }  
    //cout<<nodeList[len-1].add<<" "<<nodeList[len-1].data<<" "<<-1;  
    printf("%05d %d %d\n",nodeList[len-1].add, nodeList[len-1].data, -1);  
    return 0;  
}  
