#include<iostream>
#include<stdio.h>
#include<map>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s) {
        int head = 0, tail = 0;
        int maxLength = 0;
        for(; tail < s.length(); tail++){
            for(int i = head; i < tail; i++){
                if(s[i] == s[tail]){
                    maxLength = max(maxLength, tail - head);
                    head = i + 1;
                    break;
                }
            }
        }
        return max(maxLength, tail - head);
}
int main() {
	string test;
	while(cin >> test){
		cout << lengthOfLongestSubstring(test) <<endl;
	}
	
	return 0;
}