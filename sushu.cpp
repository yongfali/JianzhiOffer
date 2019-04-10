#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//求两个区间内的所有素数，主要该数不能被2 ~ 根号m 之间的每一个整数去除就可以了
bool isSuShu(int number){
	for(int i = 2; i <= (int)sqrt(number); i++){
		if(number % 2 == 0)
			return false;
	}
	return true;
}

vector<int> suShu(int start, int end){
	vector<int> res;
	for(int i = start; i <= end; i++){
		if(isSuShu(i))
			res.push_back(i);
	}
	return res;
}
int main(){
	int n,m;
	while(cin >> n >> m){
		if(n > m)
			swap(n,m);
		vector<int> result = suShu(n,m);
		auto it = result.begin();
		while(it != result.end()){
			cout << *it << " ";
			it++;
		}
	}
	return 0;
}
