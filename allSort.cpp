#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

void Print(vector<int> arr, int len){
	for(int i = 0; i < len; i++){
		cout << arr[i] << endl;
	}
}

//冒泡排序 
void maoPaoSort(vector<int> arr){
	int len = arr.size();
	if(len == 0){
		return;
	}
	for(int i = 0; i < len - 1; ++i){
		for(int j = 0; j < len - i - 1; j++){
			if(arr[j] >= arr[j+1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	Print(arr, len);
}

//选择排序
void selectSort(vector<int> arr){
	int len = arr.size();
	if(len == 0){
		return;
	}
	for(int i = 0; i < len-1; ++i){
		for(int j = i+1; j < len; j++){
			if(arr[i] >= arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	Print(arr, len);
}

//插入排序
void insertSort(vector<int> arr){
	int len = arr.size();
	if(len == 0){
		return;
	}
	for(int i = 1; i < len; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] < arr[j]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	Print(arr, len);
} 

//快排 
void quickSort(int a[], int low, int high){
	if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];/*将比第一个小的移到低端*/
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];	/*将比第一个大的移到高端*/    
    }
    a[first] = key;/*枢轴记录到位*/
    quickSort(a, low, first-1);
    quickSort(a, first+1, high);
} 

//堆排序
void headSort(int[] arr){
	
}
//归并排序
 
int main(){
	vector<int> arr;
	int arrs[] = {7,3,8,9,4,2,6};
	for(int i = 0; i < 7; ++i){
		arr.push_back(arrs[i]);
	}

	//调用冒泡排序
 	//maoPaoSort(arr); 
 	
 	//使用选择排序
	//selectSort(arr); 
	//选择排序 
	//Print(arr,7); 
	//插入排序 
	//insertSort(arr);
	quickSort(arrs,0,6);
	for(int i = 0; i < sizeof(arrs) / sizeof(arrs[0]); ++i){
		cout << arrs[i] << endl;
	}
	
	return 0;
}
