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

//ð������ 
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

//ѡ������
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

//��������
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

//���� 
void quickSort(int a[], int low, int high){
	if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];	/*���ȵ�һ������Ƶ��߶�*/    
    }
    a[first] = key;/*�����¼��λ*/
    quickSort(a, low, first-1);
    quickSort(a, first+1, high);
} 

//������
/**
�㷨˼��(�Դ󶥶�Ϊ����ʵ�ʴ洢������һά����)��
1.������Ϊn�Ĵ������������ж����򻯹����һ���󶥶�
 
2.�����ڵ���β�ڵ㽻���������ʱ��β�ڵ�
 
3.��ʣ���n -1���ڵ����½��ж�����
 
4.�ظ�����2������3ֱ�������һ����������
**/
void headAdjust(int arr[], int start, int end){
	int parentNode = start;
	int childNode = parentNode * 2 + 1;
	while(childNode <= end){
		//�ж������ӽڵ��С 
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
	//��Ϊֻ�У�n/2-1)֮ǰ�Ľڵ�ſ�ʼ���ӽڵ㡣
	//���ڴ󶥶�a[i]>=a[2*i+1] &&  a[i]>=a[2*i+2], i(0,n/2-1)
	for(int i = len/2 - 1; i >=0; --i){
		headAdjust(arr,i,len-1);
	}
	for(int i = len -1; i > 0; --i){
		swap(arr[0], arr[i]);
		headAdjust(arr,0,i-1);
	} 
}
//�鲢����
//merge��Ҫ�Ƕ���������������кϲ� 
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

	//����ð������
 	//maoPaoSort(arr); 
 	
 	//ʹ��ѡ������
	//selectSort(arr); 
	//ѡ������ 
	//Print(arr,len); 
	//�������� 
	//insertSort(arr);
	//quickSort(arrs,0,len-1);
	//for(int i = 0; i < len; ++i){
	//	cout << arrs[i] << endl;
	//}
	//������
 	//headSort(arrs,len);
	//�鲢����
	mergeSort(arrs,0,len-1); 
 	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}
	return 0;
}
