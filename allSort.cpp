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
/**
算法思想(以大顶堆为例，实际存储还是以一维数组)：
1.将长度为n的待排序的数组进行堆有序化构造成一个大顶堆
 
2.将根节点与尾节点交换并输出此时的尾节点
 
3.将剩余的n -1个节点重新进行堆有序化
 
4.重复步骤2，步骤3直至构造成一个有序序列
**/
void headAdjust(int arr[], int start, int end){
	int parentNode = start;
	int childNode = parentNode * 2 + 1;
	while(childNode <= end){
		//判断左右子节点大小 
		if(childNode + 1 <= end && arr[childNode] < arr[childNode + 1]){
			childNode++;
		}
		if(arr[parentNode] > arr[childNode]){
			return;
		}
		else{
			swap(arr[parentNode], arr[childNode]);
			parentNode = childNode;
			childNode = parentNode * 2 + 1;
		}
	}
}
 
void headSort(int arr[], int len){
	//因为只有（n/2-1)之前的节点才开始有子节点。
	//对于大顶堆a[i]>=a[2*i+1] &&  a[i]>=a[2*i+2], i(0,n/2-1)
	for(int i = len/2 - 1; i >=0; --i){
		headAdjust(arr,i,len-1);
	}
	for(int i = len -1; i > 0; --i){
		swap(arr[0], arr[i]);
		headAdjust(arr,0,i-1);
	} 
}
//归并排序
//merge主要是对两个有序数组进行合并 
void merge(int a[], int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));
    int i = start;            
    int j = mid + 1;        
    int k = 0;                

    while(i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];

    while(j <= end)
        tmp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    free(tmp);
}

void mergeSort(int a[], int start, int end)
{
    if(a==NULL || start >= end)
        return ;

    int mid = (end + start)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);

    merge(a, start, mid, end);
}
int main(){
	vector<int> arr;
	int arrs[] = {7,3,8,9,4,2,6};
	int len = sizeof(arrs) / sizeof(arrs[0]);
	//cout << len <<endl;
	//int temp[len];
	for(int i = 0; i < len; ++i){
		arr.push_back(arrs[i]);
	}

	//调用冒泡排序
 	//maoPaoSort(arr); 
 	
 	//使用选择排序
	//selectSort(arr); 
	//选择排序 
	//Print(arr,len); 
	//插入排序 
	//insertSort(arr);
	//quickSort(arrs,0,len-1);
	//for(int i = 0; i < len; ++i){
	//	cout << arrs[i] << endl;
	//}
	//堆排序
 	//headSort(arrs,len);
	//归并排序
	mergeSort(arrs,0,len-1); 
 	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}
	return 0;
}
