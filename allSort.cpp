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

    //int mid = (end + start)/2;
    int mid = start + (end - start) / 2; //�η�ֹ�±���� 
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);

    merge(a, start, mid, end);
}

//ϣ������Ҳ��һ�ֲ������� NlogN��,ÿ�θ���gap���з��飬Ȼ��Է�����в�������
//ֱ��gap=1ʱ������� Ϊ���ȶ�������Ϊ������ȵ��п��ܸ��ֿ��ˡ� 
void ShellSort(vector<int> arr){
	int len = arr.size();
	int gap = len / 2; //gap��ʾ��Ϊ�����ˣ�Ҳ����˵������֮��ļ�� 
	for(; gap > 0; gap /= 2){ //�ֶ��ٴν��в������� 
		for(int i = gap; i < len; i++){ //��ÿ��������в������� 
			int j = i;
			while(j - gap >=0 && arr[j] < arr[j - gap]){
				swap(arr[j], arr[j-gap]);
				j -= gap;
			}
		}
	}
	Print(arr, len);	
}

//Ͱ����N������һ�� ����N+1��Ͱ�У�Ͱ���մ�С�����˳�����У���Ȼ�����Ͱ
//���Ƿ�������һ�δ�����ɣ�ʱ�临�Ӷ�ΪO(n),��ҪO(n)�Ŀռ临�Ӷȡ�

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
	int temp[max - min +1] = {0};//�������������ֵ����Сֵֻ�����Ͱ�ĸ�������ֹ��0 ���1�� 
	
	for(int i = 0; i < n; i++) //���������Ͱ�У����ÿһ�����ֳ��ֵĴ��� 
		temp[arr[i]]++;
		
	for(int i = 0; i < max - min + 1; i++){
		for(int j = 0; j < temp[i]; j++){
			cout << i << endl;
		}
	} 	 
}

// �������򣬷���ʮ��Ͱ����Ϊ������0-9����Ȼ�����θ���ÿ������λ����Ӧλ��С�ŵ�
//��Ӧ��Ͱ���LSD���������λ�������� MSD �������λ��ʼ�������� 

void jiShuSort(int arr[], int n){
	int temp[10][n];//����ʮ��Ͱ��0~9��
	int num[10] = {0}; //��¼ÿ��Ͱ�б����Ԫ�صĸ��� 
	int max = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	
	int weishu = (int)log10(max*1.0) + 1; //��¼������ݵ�λ�����������ж���Ҫ�ȽϵĴ���
	
	//cout << weishu <<endl;
	//�����λ��ʼ�����ΰ��չؼ��ֽ��з���
	for(int i = 0; i < weishu; i++){
		//ɨ����������Ԫ�أ���Ԫ�ط��䵽��Ӧ��Ͱ��
		for(int j = 0; j < n; j++){
  			//ȡ����Ԫ�ض�Ӧ��i+1λ�ϵ����֣�����341������Ҫȡ��ʮλ�ϵ����֣�341%100=41,41/10=4
			int pos = (arr[j] % (int) pow(10, i + 1)) / (int) pow(10,i); 
			temp[pos][num[pos]] = arr[j];
			num[pos]++;
		}
		
  		//������֮�󣬽�Ͱ�е�Ԫ�����θ��ƻ�����
		int count = 0; //Ԫ�ؼ����� ������ÿ��Ͱ�е�Ԫ���������Ͱ�ڵ����ݼ�Ϊ�������� 
		for(int i = 0; i < 10; i++){
			if(num[i] !=0){
				for(int j = 0; j < num[i]; j++)
					arr[count++] = temp[i][j];
			}
			num[i] = 0; //��һ��Ͱ�ڵ�Ԫ��ȫ��������Ͱ�ڵļ������� 
		}
	} 	 
} 


//�������򣬺�Ͱ����һ������ͳ��ÿ��Ԫ�س��ֵĴ�����Ȼ����ݴ���������� 
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
	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}
 	headSort(arrs,len);
	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}
 	cout << endl;
	//�鲢����
	/**mergeSort(arrs,0,len-1); 
 	for(int i = 0; i < len; ++i){
		cout << arrs[i] << endl;
	}*/
	
	//ϣ������
	//ShellSort(arr); 
	
	//Ͱ����
	
	//cout << "Ͱ����" << endl; 
 	//TongSort(arrs, len);
 	
 	//��������
 	//int arr1[] = {15,25,104,78,34,21,341,41,2};
	//int len1 = sizeof(arr1) / sizeof(arr1[0]);
	//jiShuSort(arr1,len1);
	//for(int i = 0; i < len1; ++i){
	//	cout << arr1[i] << endl;
	//}
	 
	
	return 0;
}

