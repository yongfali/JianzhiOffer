#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
	map<int, int> maps;
	int len = numbers.size();
	vector<int> indexs;
	if (len < 2) {
		return indexs;
	}
	for (int i = 0; i < len; i++) {
		maps[numbers[i]] = i;
	}
	for (int j = 0; j < len; j++) {
		int temp = target - numbers[j];
		if (maps.find(temp) != maps.end() && j != maps[temp]) {
			indexs.push_back(j + 1);
			indexs.push_back(maps[temp] + 1);
			break;
		}
	}
	return indexs;
}
int main() {
	int m, n;
	cin >> m >> n;
	vector<int> arr;
	vector<int> result;
	int temp;
	for (int i = 0; i < m; ++i) {
		cin >> temp;
		arr.push_back(temp);
	}
	result = twoSum(arr, n);
	cout << result.size()<<endl;
	vector<int>::iterator it = result.begin();
	while (it != result.end()) {
		cout << *it << " ";
		it++;
	}
	return 0;
}
