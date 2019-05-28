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

    //int mid = (end + start)/2;
    int mid = start + (end - start) / 2; //课防止下表溢出 
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);

    merge(a, start, mid, end);
}

//希尔排序（也是一种插入排序 NlogN）,每次根据gap进行分组，然后对分组进行插入排序
//直到gap=1时排序完成 为不稳定排序，因为遇到相等的有可能给分开了。 
void ShellSort(vector<int> arr){
	int len = arr.size();
	int gap = len / 2; //gap表示分为几组了，也可以说是数据之间的间隔 
	for(; gap > 0; gap /= 2){ //分多少次进行插入排序 
		for(int i = gap; i < len; i++){ //对每个分组进行插入排序 
			int j = i;
			while(j - gap >=0 && arr[j] < arr[j - gap]){
				swap(arr[j], arr[j-gap]);
				j -= gap;
			}
		}
	}
	Print(arr, len);	
}

//桶排序，N个数据一次 放入N+1个桶中（桶按照从小到大的顺序排列），然后遍历桶
//中是否有数，一次打出即可，时间复杂度为O(n),需要O(n)的空间复杂度。

void TongSort(int arr[], int n){
	if(n <= 0) return;
	int max = arr[0];
	int min = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	} 
	cout << max << " " << min << endl;
	int temp[max - min +1] = {0};//根据数组中最大值和最小值只差决定桶的个数，防止有0 则加1； 
	
	for(int i = 0; i < n; i++) //把数组放入桶中，标记每一个数字出现的次数 
		temp[arr[i]]++;
		
	for(int i = 0; i < max - min + 1; i++){
		for(int j = 0; j < temp[i]; j++){
			cout << i << endl;
		}
	} 	 
}

// 基数排序，分配十个桶（因为数字是0-9），然后依次根据每个数的位数对应位大小排到
//对应的桶里。（LSD，即从最低位依次排序， MSD 即从最高位开始依次排序） 

void jiShuSort(int arr[], int n){
	int temp[10][n];//定义十个桶（0~9）
	int num[10] = {0}; //记录每个桶中保存的元素的个数 
	int max = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	
	int weishu = (int)log10(max*1.0) + 1; //记录最大数据的位数，即可以判断需要比较的次数
	
	//cout << weishu <<endl;
	//由最低位开始，依次按照关键字进行分配
	for(int i = 0; i < weishu; i++){
		//扫描所有数组元素，将元素分配到对应的桶中
		for(int j = 0; j < n; j++){
  			//取出该元素对应第i+1位上的数字，比如341，现在要取出十位上的数字，341%100=41,41/10=4
			int pos = (arr[j] % (int) pow(10, i + 1)) / (int) pow(10,i); 
			temp[pos][num[pos]] = arr[j];
			num[pos]++;
		}
		
  		//分配完之后，将桶中的元素依次复制回数组
		int count = 0; //元素计数器 ，根据每个桶中的元素依次输出桶内的数据即为排序数据 
		for(int i = 0; i < 10; i++){
			if(num[i] !=0){
				for(int j = 0; j < num[i]; j++)
					arr[count++] = temp[i][j];
			}
			num[i] = 0; //当一个桶内的元素全部输出后该桶内的计数清零 
		}
	} 	 
} 


//计数排序，和桶排序一样，是统计每个元素出现的次数，然后根据次数进行输出 
void tongJiSort(){
	
} 

int main(){
	vector<int> arr;
	int arrs[] = {7,3,8,9,4,2,6,1,0};
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
	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}
 	headSort(arrs,len);
	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}
 	cout << endl;
	//归并排序
	/**mergeSort(arrs,0,len-1); 
 	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}*/
	
	//希尔排序
	//ShellSort(arr); 
	
	//桶排序
	
	//cout << "桶排序：" << endl; 
 	//TongSort(arrs, len);
 	
 	//基数排序
 	//int arr1[] = {15,25,104,78,34,21,341,41,2};
	//int len1 = sizeof(arr1) / sizeof(arr1[0]);
	//jiShuSort(arr1,len1);
	//for(int i = 0; i < len1; ++i){
	//	cout << arr1[i] << endl;
	//}
	 
	
	return 0;
}

