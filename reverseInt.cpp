#include<iostream>
#include<cstring>
using namespace std;

int reverse(int x) {
	int max = 0x7FFFFFFF;
 	int min = 0x80000000;
        
 	long res = 0;
 	while(x){
		res = res * 10 + x % 10;
 		x = x / 10;
 		if(res < min || res > max){
		 	return 0;
		 }
  	}
  	return res;
}

bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int original = x;
        int res = 0;
        while(x != 0){
            res = res * 10 + x % 10;
            x = x / 10;
        }
       
        if(res == original){
            return true;
        }
        else{
            return false;
        }
    }
int main(){
	int n;
	while(cin >> n){
		cout << isPalindrome(n) <<endl;
	}
	return 0;
}