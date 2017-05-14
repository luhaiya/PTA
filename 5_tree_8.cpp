/*
 *并查集问题
 */
#include <iostream>
#include <vector>
using namespace std;
const int maxlen = 10001;
int find_set(vector<int> &set, int data){
	while(set[data] > 0){
		data = set[data];
	}
	return data;
}
void union_set(vector<int> &set, int data1, int data2){
	int index1 = find_set(set, data1);
	int index2 = find_set(set, data2);
	if(set[index1] < set[index2]){
		set[index2] = index1;
		set[index1]--;
	}else{
		set[index1] = index2;
		set[index2]--;
	}
}
bool check_set(vector<int> &set, int data1, int data2){
	int index1 = find_set(set, data1);
	int index2 = find_set(set, data2);
	if(index1 == index2){
		return true;
	}else{
		return false;
	}
}
int count_set(vector<int> &set){
	int num = 0;
	for(unsigned int i = 1; i < set.size(); i++){
		if(set[i] < 0){
			num++;
		}
	}
	return num;
}
int main(){
	int N;
	cin>>N;
	vector<int> set(N + 1);
	for(int i = 1; i <= N; i++){
		set[i] = -1;
	}
	char str;
	int data1 = 0, data2 = 0;
	while(1){
		cin>>str;
		if(str == 'S'){
			break;
		}else if(str == 'I'){
			cin>>data1>>data2;
			union_set(set, data1, data2);
		}else{
			cin>>data1>>data2;
			if(check_set(set, data1, data2)){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}
	}
	int num = count_set(set);
	if(num > 1){
		cout<<"There are "<<num<<" components."<<endl;
	}else{
		cout<<"The network is connected.";
	}
}
