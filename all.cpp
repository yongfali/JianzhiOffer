#include<iostream>
#include<vector>
#include<stack>
#include<string> 
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<list>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

struct RandomListNode{
	int val;
	RandomListNode *next, *random;
	RandomListNode(int x):val(x), next(NULL), random(NULL){}
};

struct TreeLinkNode{
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;	//ָ�򸸽ڵ��ָ�� 
	TreeLinkNode(int x): val(x), left(NULL),right(NULL),next(NULL){} 
}; 

//�ַ����ո��滻 
void replaceSpace(char* str,int length){
	if(str == NULL || length <= 0){
		return;
	}
	//ͳ���ַ����пո���
	int count = 0, i = 0, originalLength = 0;
	while(str[i++] != '\0'){
		originalLength++;
		if(str[i] == ' '){
			count++;
		}
	}
	int newLength = count*2 + originalLength; 
	if(newLength > length){
		return;
	}
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while(length >= 0 && indexOfNew > indexOfOriginal){
		if(str[indexOfOriginal] != ' '){
			str[indexOfNew--] = str[indexOfOriginal];
		}
		else{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		indexOfOriginal--;
	}     
}

// ��β��ͷ��ӡ���� 
vector<int> printLinkRevrve(ListNode* head){
	vector<int> result;
	if(head == NULL){
		return result;
	}
	stack<int> temp;
	ListNode* p = head;
	while(p != NULL){
		temp.push(p->val);
		p = p->next;
	}
	for(int i = 0; i < temp.size(); ++i){
		result.push_back(temp.top());
		temp.pop();
	}
	return result;
}

//�ؽ�������
TreeNode* binaryTree(vector<int>a, int abegin, int aend, vector<int>b, int bbegin, int bend){
	if(aend >= abegin || bend >= bend){
		return NULL;
	}
	TreeNode* root = new TreeNode(a[abegin]);
	int i = 0;
	//������������ҵ����ڵ� 
	for(int i = bbegin; i < bend; ++i){
		if(b[i] == a[abegin]){
			break;
		}
	}
	root->left = binaryTree(a, abegin+1, abegin+i-bbegin+1, b, bbegin, i);
	root->right = binaryTree(a, abegin+i-bbegin+1, aend, b, i+1, bend);
	return root;
}
 
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
	return binaryTree(pre,0,pre.size(),vin,0,vin.size());
}

// ������ջʵ�ֶ���
static stack<int> stack1;
static stack<int> stack2;
//��ջ 
void push(int node){
	stack1.push(node);
}
//��ջ��stack2��Ϊ�������������ݳ�ջ������stack1���ݽ���stack2�С� 
int pop(){
	if(stack2.empty()){
		while(!stack1.empty()){
			int temp = stack1.top();
			stack2.push(temp);
			stack1.pop();
		}
	}
	int result = stack2.top();
	stack2.pop();
	return result;
} 

// ��ת�����е���Сֵ
int reverseArrayMinNumber(vector<int> arr){
	int len = arr.size();
	if(len == 0){
		return 0;
	}
	int pos = 0;
	for(int i = 0; i < len - 1; ++i){
		if(arr[i] < arr[i+1]){
			continue;
		}
		else{
			pos = i;
			break;
		}
	}
	return arr[pos+1];
} 

//���θ������� Ҳ����쳲������������⵱ǰֵ����ǰ����֮�� 
int rectCover(int number){
	
} 

// ��������1�ĸ���
int countNumOf1(int num){
	int count = 0;
	while(num){
		count++;
		num = num & num-1;
	}
	return count;
} 

//���������η�
double Power(double num, int p){
	double result = 0.0;
	if(fabs(num) < 1e-6){
		return false;
	}
	if(p == 0){
		result = 1.0;
	}
	if(p == 1){
		result = num;
	}
	if(p == -1){
		result = 1.0 / num;
	}
	result = num;
	if(p > 1){
		for(int i = 1; i < p; i++){
			result *= num;
		}
	}
	else{
		p = 0 - p;
		for(int i = 1; i < p; i++){
			result *= num;
		}
		result = 1.0 / result;
	}
	return result;
}

// ���������˳��ʹ������λ��ż����ǰ�沢��֤���λ�ò���
vector<int> reverseArr(vector<int> arr){
	int len = arr.size();
	vector<int> res; 
	if(len == 0){
		return res;
	}
	//���������������� 
	for(int i = 0; i < len; ++i){
		if(arr[i] & 1){
			res.push_back(arr[i]);
		}
	}
	//��ż���������� 
	for(int i = 0; i < len; ++i){
		if(arr[i] % 2 == 0){
			res.push_back(arr[i]);
		}
	}
	return res;
} 
 
 //�����е�����K���ڵ�,��������ָ�룬�õ�һ��ָ������k-1����Ȼ������ָ��һ����
 //ֱ����һ��ָ���ߵ�����β�����ڶ���ָ����ָ�ĵط�Ϊ��K��ָ�� 
 ListNode* FindLastKNode(ListNode* head, int k){
 	if(head == NULL){
	 	return NULL;
	 }
	 ListNode *p1, *p2;
	 p1 = p2 = head;
	 for(int i = 0; i < k -1; k++){
 		if(p1 -> next == NULL){
		 	return NULL;
		 }
		 else{
 			p1 = p1 -> next;
 		}
 	}
	while(p1->next != NULL){
		p2 = p2->next;
		p1 = p1->next;
	}
	return p2;  
 }
 
 //����ת�ֱ�������ָ�뱣��ǰһ���ͺ�һ���ڵ����Ϣ 
 ListNode* reverseList(ListNode* head){
 	ListNode *reverseHead = NULL;
	ListNode *pNode = head;
	ListNode *Prev = NULL;
	while(pNode != NULL){
		ListNode *pNext = pNode->next;
		if(pNode == NULL){
			reverseHead = pNode;
		}
		pNode ->next = Prev;
		Prev = pNode; 
		pNode = pNext;
	}
	return reverseHead; 
 } 
 
 //�ϲ��������������,�ݹ�ʵ�֣�ÿ��ֻҪѡ��һ�����н��д�С�ıȽ�����������ͷ 
 ListNode* MergeList(ListNode* list1, ListNode* list2){
 	ListNode *newHead = NULL;
 	if(list1 == NULL && list2 == NULL){
	 	return NULL;
	 }
	 if(list1 == NULL){
	 	return list2;
	 }
	 if(list2 == NULL){
	 	return list1;
	 }
	 if(list1->val > list2->val){
	 	newHead = list2;
	 	MergeList(list1, list2->next);
	 }
	 if(list1->val <= list2->val){
	 	newHead = list1;
	 	MergeList(list1->next, list2);
	 }  
 	return newHead;
 } 
 
 //�����ӽṹ�ж�
  bool DoseTree1HaveTree2(TreeNode* root1, TreeNode* root2) {
 	if(root1 == NULL){
	 	return false;
	 }
	 if(root2 == NULL){
 		return true;
 	}
 	if(root1->val != root2->val){
	 	return false;
 	}
 	return DoseTree1HaveTree2(root1->left, root2->left) && DoseTree1HaveTree2(root1->right, root2->right);
 }
 
 bool IsSubTree(TreeNode* root1, TreeNode* root2){
 	bool result = false;
 	if(root1 == NULL || root2 == NULL){
	 	return result;
	 }
 	if(root1->val == root2->val){
	 	result = DoseTree1HaveTree2(root1, root2);
	 }
	 //�������ڵ㲻һ����ֱ������1���������������ӽṹ 
	 if(!result){
 		result = DoseTree1HaveTree2(root1->left, root2); 
 	}
 	if(!result){
 		result = DoseTree1HaveTree2(root1->right, root2); 
 	}
 	return result;
 }
 
 //���������񣬵ݹ齻�����������Ľڵ����
 void Mirro(TreeNode* pNode){
 	if(pNode == NULL){
	 	return;
	 }
	 if(pNode->left == NULL && pNode->right == NULL){
 		return;
 	}
 	TreeNode *temp = pNode->left;
 	pNode->left = pNode->right;
 	pNode->right= temp;
 	if(pNode->left != NULL){
	 	Mirro(pNode->left);
	 }
	 if(pNode->right != NULL){
	 	Mirro(pNode->right);
	 }
 } 
 
 //˳ʱ���ӡ����
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> res;
	if(matrix.empty()){
		return res;
	}
	 int rows = matrix.size();
	 int cols = matrix[0].size();
	 //�����ĸ��Ǳ��������Ϊ��ӡһ����Ϊ�Ĳ����ֱ�Ϊ������
	 //���ϵ��£����ҵ��󣬴��µ��ϡ�
	 int left = 0;
	 int right = cols - 1;
	 int top = 0;
	 int bottom = rows - 1;
        while(left <= right && top <= bottom){
            //�����Ҵ�ӡ����һ���϶���
            for(int i = left; i <=right; i++){
                res.push_back(matrix[top][i]);
            }
            //���ϵ��´�ӡ
            if(top < bottom){
                for(int j = top+1; j <= bottom; j++){
                    res.push_back(matrix[j][right]);
                }
            }
            //���ҵ����ӡ
            if(top < bottom && left < right){
                for(int k = right -1; k >= left; k--){
                    res.push_back(matrix[bottom][k]);
                }
            }
            //�������ϴ�ӡ
            if(top+1 < bottom && left < right){
                for(int h = bottom - 1; h >= top+1; h--){
                    res.push_back(matrix[h][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
 } 
 
 //ջ��ѹ��͵���,���ж�һ�������Ƿ�Ϊ��ջ��˳��
 bool IsPopOrder(vector<int> pushS, vector<int> popS){
 	stack<int> temp;
 	int id = 0; //����ͳ��ԭ�����Ƿ��Ѿ�ȫ����ջ 
 	for(int i = 0; i < popS.size(); ++i){
	 	while(temp.empty() || temp.top() != popS[i]){
	 		temp.push(pushS[id++]);
	 		//��ԭ����ȫ����ջ��û���ҵ��뵱ǰֵ��ȵ���˵�����ǳ�ջ˳�� 
	 		if(id > pushS.size()){
		 		return false;
		 	}
	 	}
	 	temp.pop();
	 }
	 if(temp.empty()){
 		return true;
 	}
 	else{
	 	return false;
	 }
 } 

// �������´�ӡ��������ͬ�������
vector<int> PrintBST(TreeNode* root){
	vector<int> res;
	if(root == NULL){
		return res;
	}
	queue<TreeNode*> temp;
	temp.push(root);
	while(!temp.empty()){
		TreeNode *tempNode = temp.front();
		res.push_back(tempNode->val);
		if(tempNode->left != NULL){
			temp.push(tempNode->left);
		}
		if(tempNode->right != NULL){
			temp.push(tempNode->right);
		}
		temp.pop();  
	}
	return res;
} 

//�ж�һ�������Ƿ�Ϊĳһ�������������ĺ������
//����������ڵ�Ϊ���һ�������ұȸ��ڵ���Ϊ����������֮Ϊ������
//�ݹ�ֱ�����Ҷ�������
bool ArrayIsHouXu(vector<int> arr){
	int len = arr.size();
	if(len <=0 ){
		return false;
	}
	int root = arr[len-1];//���һ��Ϊ���ĸ��ڵ�
	vector<int> leftNode;
	vector<int> rightNode;
	int i = 0;
	for(; i < len - 1; i++){
		if(arr[i] < root){
			leftNode.push_back(arr[i]);
		}
		break; //���ٳ���С�ĺ�˵�����ӽڵ�ȫ�������� 
	}
	int j = i;
	for(; j < len -1; ++j){
		if(arr[j] > root){
			rightNode.push_back(arr[j]);
		}
		return false; //����ĺ���ͻȻ����һ��С���򲻷��Ϻ������ 
	}
	bool left = false;
	if(i > 0){
		left = ArrayIsHouXu(leftNode);
	}
	bool right = false;
	if(i < len - 1){
		right = ArrayIsHouXu(rightNode);
	} 
	return left && right;
	 
}

// ���Ҷ������к�Ϊĳһֵ������·�������Եݹ�ÿ�β��ҵ�ֵΪĿ��ֵ��ȥ��ǰ�ĸ��ڵ�ֵ
// �����Ϳ��Բ��û����ˣ��൱�ڵݹ����Ŀ��ͣ�ֱ��Ϊ0����Ϊ��
vector<vector<int> > allSequence;
vector<int> temp;
vector<vector<int> > FindAllPath(TreeNode* root, int target){
	if(root == NULL){
		return allSequence;
	}
	temp.push_back(root->val);
	if(target - root->val == 0 && root->left == NULL && root->right == NULL){
		allSequence.push_back(temp);
	}
	//����������Ϊ�ղ��һ�û�дﵽĿ��ֵ�����Ŀ��ֵ�ݹ���в��� 
	FindAllPath(root->left, target - root->val);
	FindAllPath(root->right, target - root->val);
	if(!temp.empty()){
		temp.pop_back(); 
	} 
	return allSequence;
}

// ��������ĸ��Ʒ��������У����ȸ��ƽڵ㣬Ȼ�����randomָ�룬�������ż����ӡ
//1�����ƽڵ�ֵ
void copyListNode(RandomListNode* head){
	if(head == NULL){
		return;
	}
	RandomListNode *pNode = head;
	while(pNode != NULL){
		RandomListNode *tempNode = new RandomListNode(pNode->val);
		tempNode->next = pNode->next;
		pNode->next= tempNode;
		pNode = tempNode->next;
	}
}
//2�����Random�ڵ�����
void linkRandomList(RandomListNode* head){
	if(head == NULL){
		return;
	}
	RandomListNode *pNode = head;
	while(pNode != NULL){
		if(pNode->random){
			pNode->next->random = pNode->random->next;
		}
		pNode = pNode->next->next;
	} 
}
//3.���
RandomListNode *ChaiFen(RandomListNode* head){
	if(head == NULL){
		return NULL;
	}
	RandomListNode *pNode = head;
	RandomListNode *result = head->next;
	while (pNode != NULL){
		RandomListNode *pClone = pNode->next;
	 	pNode->next = pClone->next;
	 	pNode = pNode->next;
	 	if (pNode != NULL)
	 		pClone->next = pNode->next;
	}
 	return result;
}

RandomListNode* Clone(RandomListNode* pHead){
	if (!pHead) return NULL;
	copyListNode(pHead);
	linkRandomList(pHead);
	return ChaiFen(pHead);
 }
 
//�ַ���������
void Permutation(string str, vector<string> & res, int begin){
	int len = str.size();
	if(begin == len){
		res.push_back(str);
		return;
	}
	          
	for(int i = begin; i < len; i++){
		//һ�����������ֲ���Ҫ����
		if( i!=begin && str[i] == str[begin])
			continue;
		swap(str[i], str[begin]);
		Permutation(str, res, begin+1);
	}
}
vector<string> Permutation(string str) {
	vector<string> res;
	if(str.size()==0)
		return res;
	Permutation(str, res, 0);
	return res;
}

//�����г��ִ�������һ�������
int MoreThanHalfNum(vector<int> arr){
	map<int,int> numCount;
	int len = arr.size();
	if(len == 0){
		return 0;
	}
	if(len == 1){
		return arr[0];
	}
	for(int i = 0; i < len; ++i){
		if(numCount.count(arr[i])){
			numCount[arr[i]]++;
		}
		else{
			numCount[arr[i]] = 1;
		}
	}
	auto item = numCount.begin();
	int tempMax = 0;
	int num = 0;
	while(item != numCount.end()){
		if((item->second) > tempMax){
			num = item->first;
			tempMax = item->second;
		}
		item++;
	}
	if(tempMax * 2 > len){
		//cout << tempMax << endl;
		return num;
	}
	else{
		return 0;
	}
} 

//��С��K����,ͨ��ά��һ��K�󶥶Ѽ��� ,������K����ά��һ��KС���Ѽ��� 
 vector<int> Get_K_MinNum(vector<int> arr, int k){
 	priority_queue<int> maxHeap;
 	vector<int> res;
	int len = arr.size();
	if(len == 0 || k <=0){
		return res;
	}
	if(k >= len){
		return arr;
	}
	for(int i = 0; i < len; ++i){
		if(maxHeap.size() < k){
			maxHeap.push(arr[i]);
		}
		else{
			if(arr[i] < maxHeap.top()){
				maxHeap.pop();
				maxHeap.push(arr[i]);
			}
		}
	}
	for(int i = 0; i < k; i++){
		res.push_back(maxHeap.top());
		maxHeap.pop();
	}
	
	return res;
	  
 }
 
 //���������������
 int FindGreatestSumOfSubArray(vector<int> arr){
 	int len = arr.size();
	 if(len == 0){
 		return 0;
 	}
 	int maxSum = 0;
 	int currentSum = 0;
 	for(int i = 0; i < len; i++){
 		//�����ϵ�ֵС�ڵ���0ʱ˵�������Ӻ��ж���Ϊ�κ�һ��������һ������������
		//ʹ��ֵ��С�� 
	 	if(currentSum <=0 ){
	 		currentSum = arr[i];
	 	}
	 	else{
	 		currentSum += arr[i];
	 	}
	 	if(currentSum > maxSum){
	 		maxSum = currentSum;
	 	}
	 }
	 return maxSum;
 } 
 
 // һ��������1���ֵĴ���
 int NumberOf1Count(int number){
 	int count = 0;
 	while(number){
	 	count++;
	 	number = number & (number - 1);
	 }
	 return count;
 }
 
 //�������ų���С����
 //��������������a+b < b+a��a��ǰ��b�ں�Ȼ����������������ƴ�Ӿ��� 
 bool compare(int a, int b){
 	string first = to_string(a) + to_string(b);
 	string second = to_string(b) + to_string(a);
 	return first < second;
 }
 string PrintMinNumber(vector<int> arr){
 	int len = arr.size();
 	string result;
 	if(len == 0){
	 	return NULL;
	 }
	 sort(arr.begin(), arr.end(), compare);
	 for(int i = 0; i < len; i++){
 		result += to_string(arr[i]);
 	}
 	return result;
 }
 
 //����
 int GetUglyNumber_Solution(int index) {
	 if(index <= 0){
	 	return 0;
	 }
	 int factors[] ={2,3,5};
	 int uglyNumbers[index];
	 uglyNumbers[0] = 1;
	 //��¼ʹ�õĴ��������Ͳ�������ظ��ĳ���
	 int num2 = 0, num3 = 0 , num5 = 0;
	 for(int i = 1; i < index; i++){
	 	uglyNumbers[i] = min(uglyNumbers[num2] * factors[0], min(uglyNumbers[num3] * factors[1], uglyNumbers[num5] * factors[2]));
	 	if(uglyNumbers[i] == uglyNumbers[num2]*factors[0])num2++;
	 	if(uglyNumbers[i] == uglyNumbers[num3]*factors[1])num3++;
	 	if(uglyNumbers[i] == uglyNumbers[num5]*factors[2])num5++;
	 }
 	return uglyNumbers[index-1];
 }
 
 //��һ��ֻ����һ�ε��ַ�
 char firstAppearCharOnLyOnce(string s){
 	int len = s.length();
 	if(s == " " || len == 0){
	 	return ' ';
 	}
	int result[256] = {0};
 	for(int i = 0; i < len; i++){
 		result[s[i]]++;
 	}
 	for(int j = 0; j < len; j++){
 		//cout << result[s[j]] << endl;
	 	if(result[s[j]] == 1){
	 		return s[j];
	 	}
 	}
 	return ' ';
}
 
 //�����е������
 int reverseNum(vector<int> arr){
 	int len = arr.size();
 	if(len == 0 || len == 1){
	 	return 0;
	}
	 
} 

//��������ĵ�һ�������ڵ�
int listLength(ListNode * head){
	if(head == NULL)
		return 0;
	ListNode *pNode = head; 
	int count = 0;
	while(pNode != NULL){
		count++;
		pNode = pNode->next;
	}
	return count;
}
    
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
	int len1 = listLength(pHead1);
	int len2 = listLength(pHead2);
	ListNode *longList, *shortList;
	int lengthDiff = 0;
	if(len1 > len2){
		longList = pHead1;
		shortList = pHead2;
		lengthDiff = len1 - len2;
	}
	else{
		longList = pHead2;
		shortList = pHead1;
		lengthDiff = len2 - len1;
	}
	for(int i = 0; i < lengthDiff; i++)
		longList = longList->next;
	while(shortList != NULL && longList != NULL && shortList->val != longList->val){
		shortList = shortList->next;
		longList = longList->next;
	}
	return shortList;
}

//���������������г��ֵĴ���
int countNum(vector<int> arr, int num){
	int len = arr.size();
	if(len == 0)
		return 0;
	int count = 0;
	for(int i = 0; i < len; i++){
		if(arr[i] == num)
			count++;
	}
	return count;
}

//�����������
int TreeDepth(TreeNode* root){
	if(root == NULL)
		return 0;
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	return left > right ? left + 1 : right + 1;
	
}

//�ж�һ�����Ƿ�Ϊƽ�������,���ú�����������ÿһ���ڵ�ֻ��Ҫ����һ�ξͿ��ԣ�
//�Ե������ж��Ƿ����ƽ������������� ,depth��¼ÿ���ڵ����ȱ����ж� 
bool IsBalance(TreeNode* root, int* depth){
	if(root == NULL){
		*depth = 0;
		return true;
	}
	int left, right;
	if(IsBalance(root->left, &left) && IsBalance(root->right, &right)){
		int temp = left - right;
		if(temp >= -1 && temp <= 1){
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false; 
} 
bool IsBalanceBinaryTree(TreeNode* root){
	int depth = 0;
	return IsBalance(root, &depth);
}

//������ֻ����һ�ε���������
//����ֻ��һ����������ʣ�µľ����Ǹ�Ψһһ�ε����֣���Ϊ�κ���ͬ�����Ϊ0 
void FindTwoAppearOnce(vector<int> arr){
	int len = arr.size();
	if(len < 2)
		return;
	int num1 = 0, num2 = 0;
	int result = arr[0]; //result�Ľ��Ϊ��������һ�����ֵ������ 
	for(int i = 1; i < len; ++i)
		result ^= arr[i];
	
	int indexOf1FirstAppear = (result ^ (result -1)) & result;//�ҵ���һ�γ���1��λ��Ȼ����ݴ�������������л���
	
	for(int i = 0; i < len; ++i){
		if(arr[i] & (1 << indexOf1FirstAppear - 1))
			num1 ^= arr[i];
		else
			num2 ^= arr[i];
	}
	cout << num1 << " " << num2 << endl; 	
} 
 
//��ΪS��������������  
vector<vector<int> > FindContinuousSequence(int sum) {
	int small =1, big = 2;
	int middle = (sum + 1) / 2;
	int currentSum = small + big;
	vector<vector<int>> allSequence;
	if(sum < 3)
		return allSequence;

	vector<int> temp;
	while(small < middle){
		temp.push_back(small);
		temp.push_back(big);
		if(currentSum == sum){
			allSequence.push_back(temp);
		}
		else if(currentSum < sum){
			big++;
			currentSum += big;
			temp.push_back(big);
		}
		else{
			currentSum -= small;
			small++;
			temp.erase(temp.begin());
		}
	}
	temp.clear();
	return allSequence;
}

// ����ת�ַ���,����string�Ŀ⺯��substr()��erase()
string LeftRotateString(string str, int n){
	int len = str.length();
	if(n < 0 || len <= 0) return NULL;
	if(n == 0) return str;
	
	string temp = str.substr(0,n);
	str.erase(0,n);
	str += temp;
	return str;	 
}

//��ת����˳�����string�Ŀ⺯��reverse(const int &begin�� const int &end)
string reverseStringOfWord(string str){
	int len = str.size();
	//cout << len << endl;
	if(len == 0) return NULL;
	reverse(str.begin(), str.end());//��һ�η�ת�����ַ���Ȼ���ٸ��ݿո�Ե������ʽ��з�ת����
	int start = 0;
	for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			reverse(str.begin() + start, str.begin() + i);
			start = i + 1;			
		}
		if(i == len - 1)
			reverse(str.begin(), str.end());			
	}
	return str; 
} 

//�˿���˳��
bool IsConnection(vector<int> arr){
	int len = arr.size();
	if(len == 0 || len < 5)
		return false;
	sort(arr.begin(), arr.end());
	int NumberOfZero = 0;
	for(int i = 0; i < len; ++i){
		if(arr[i] == 0)
			NumberOfZero++;
	}
	int Gaps = 0;
	for(int i = NumberOfZero; i < len - 1; ++i){
		if(arr[i] == arr[i+1])
			return false;
		Gaps += arr[i+1] - arr[i] - 1;
	}
	
	return NumberOfZero < Gaps ? false : true;
}

//Լɪ�����⣬������������ÿ���޳�һ�����ݣ����ʣ�µ���ʲô,nΪ���ȣ�KΪÿ���޳���λ�ô�С 
int LastRemind(int n, int k){
	if(n < 1 || k < 1) return -1;
	list<int> listArr;
	for(int i = 0; i < n; i++)
		listArr.push_back(i);
	auto item = listArr.begin();
	while(listArr.size() > 1){
		for(int i = 0; i < k - 1; i++){
			item++;
			if(item == listArr.end()) //���ߵ������β��ʱ��������ָ��ͷ��㣬���������γɻ�װ�� 
				item = listArr.begin();
		}
		item = listArr.erase(item++);
		if(item == listArr.end())
			item = listArr.begin();
	}
	return *item; 
}

//���üӼ��˳���������֮��
int Add(int num1, int num2){
	int sum, operate;
	while(operate != 0){
		sum = num1 ^ num2;
		operate = (num1 & num2) << 1;
		num1 = sum;
		num2 = operate;
	}
	return num1;
} 


//���ַ���ת��Ϊ����
long StringToInt(string str){
	int len = str.length();
	if(len == 0)
		return 0;
	int dig = true;
	int i = 0;
	long num = 0;
	while(str[i]== ' ')
		i++;
	
	//���з����ж�
	if(str[i]=='+')
		i++;
	if(str[i]=='-'){
		i++;
		dig =false;
	}
	while(str[i] != '\0'){
		//���ַ������Ƿ�Ϊ���ֵ��ж�
		if(str[i] >= '0' && str[i] <= '9'){
			int flag = dig ? 1 : -1;
			num = num * 10 + flag * (str[i] - '0');
			i++;
		}
		else
			return 0;            
	}
	return num;
}

// �����˻�����,�ֱ��������Խ����ֵȻ�����               
vector<int> multiply(vector<int> arr){
	vector<int> arr1;
	int len = arr.size();
	if(len == 0) return arr1;
	arr1[0] = 1;
	for(int i = 1; i < len; i++)
		arr1[i] = arr1[i-1] * arr[i-1]; 
	int temp = 1;
	for(int i = len - 2; i >= 0; i--){
		temp *= arr[i+1];
		arr1[i] *= temp;
	}
	return arr1;	
}

//������ʽƥ��
bool match(string str, string pattern){
	
}

//��ʾ��ֵ���ַ���
bool IsNumber(string str){
	if(str == " ") return false;
	int len = str.length();
	int num = 0; //����ͳ�����ֵ���Ŀ
	int nume = 0; //����ͳ��E����Ŀ
	int dot = 0; //Y����ͳ��С������Ŀ
	int i = 0; //��ʾ�ַ�����λ��
	if(str[i] == '+' || str[i] == '-') i++; //�ж����ַ��Ƿ���������
	if(str[i] == '\0') return false;
	while(i < len){
		if(isdigit(str[i])){
			num = 1; //ֻҪ��ʾ�����־���
			i++; 			
		}
		else if(str[i] == '.'){
			if(dot > 0 || nume > 0) return false; //������С����ʱǰ�治����С�����e 
			dot++;
			i++;
		}
		else if(str[i] == 'e' || str[i] == 'E'){
			//cout << i <<endl;
			if(num == 0 || nume > 0) return false;
			nume++;
			i++;
			if(str[i] == '\0') return false;//˵��E����û������
			if(str[i] == '+' || str[i] == '-')i++;//E������Գ��������� 
			if(str[i] == '\0') return false;//˵��E������������ŵ���û������ 
		}
		else{
			return false;
		} 
	} 
	return true;
}

//�ַ����е�һ�����ظ������֣�����һ��map��������һ��Ϊ1�ĵ�������
char FirstAppearOnce(string str){
	int len = str.length();
	if(len == 0 || str == " ") return '#';
	map<char, int> temp ;
	for(int i = 0; i < len; i++){
		if(temp.count(str[i]))
			temp[str[i]]++;
		else
			temp[str[i]] = 1;				
	}
	auto item = temp.begin();
	while(item != temp.end()){
		if(item->second == 1)
			return item->first;
		else
			item++;
	}
	return '#';
} 

//ѭ����������,�����ж������Ƿ��л������ÿ���ָ�����������л�
//Ȼ��ͳ�ƻ��Ĵ�С������Բ���Ѱ�ҵ�K���ڵ�İ취���б��� ��������K�����ҵ�����
//K���ڵ�����K-1���е���
ListNode* MettingNode(ListNode* root){
	ListNode *pNode = root;
	ListNode *firstNode, *secondNode;
	firstNode = secondNode = pNode;
	while(firstNode->next != NULL && secondNode->next->next != NULL){
		if(firstNode->val == secondNode->next->next->val)return firstNode;
		firstNode = firstNode -> next;
		secondNode = secondNode -> next -> next;
	}
	return NULL;
} 

ListNode* EnterNodeOfLoop(ListNode* root){
	if(root == NULL) return NULL;
	ListNode *meetingNode = MettingNode(root);
	if(meetingNode == NULL) return NULL;
	int loopNum = 1;
	ListNode *pNode = meetingNode;
	while(pNode->next != meetingNode){
		pNode = pNode->next;
		loopNum++;
	}
	ListNode *firstNode, *secondNode;
	firstNode = secondNode = root;
	for(int i = 0; i < loopNum; ++i)
		secondNode = secondNode -> next;
	while(firstNode != secondNode){
		firstNode = firstNode -> next;
		secondNode = secondNode -> next;
	}
	return firstNode; 
}

//ɾ�������������ظ��Ľڵ㣬��preָ���һû���ظ��Ľڵ����м�Ľڵ���൱����������ɾ���� 
ListNode* DeleteDuplication(ListNode* pHead){
	// ������0��/1���ڵ㣬���ص�һ���ڵ�
	if(pHead == NULL||pHead->next == NULL)
		return pHead;
	else
	{
		// �½�һ��ͷ�ڵ㣬��ֹ��һ����㱻ɾ��
		ListNode* newHead = new ListNode(-1);
		newHead->next = pHead;
		         
		// ��������ָ��
		ListNode* p = pHead;      // ��ǰ�ڵ�
		ListNode* pre = newHead;  // ��ǰ�ڵ��ǰ��ڵ�
		ListNode* next = p->next;    // ��ǰ�ڵ�ĺ���ڵ�
	
		// ��ͷ��β�������
		while(p != NULL && p->next != NULL)
		{
			if(p->val == next->val)//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ���
			{
				// ѭ�����ң��ҵ��뵱ǰ�ڵ㲻ͬ�Ľڵ�
				while(next != NULL && next->val == p->val)
				{
					ListNode* temp = next;
					next = next->next;	
					// ɾ���ڴ��е��ظ��ڵ�
					delete temp;
					temp = nullptr;
				}
				pre->next = next;
				p = next;
			}
			else//�����ǰ�ڵ����һ���ڵ�ֵ���ȣ�������ƶ�һλ
			{
				pre = p;
				p = p->next;
			}
			next = p->next; //������������ڶ������ᵽ���湫�á� 
		}
	return newHead->next;//����ͷ������һ���ڵ�
	}
}

//����������һ���ڵ�
/**
1�������ǰ�ڵ����������������������������ڵ�
2�����û������������ǰ�ڵ����һ���ڵ���������
2.1����ǰ�ڵ����丸�ڵ��������������һ���ڵ�Ϊ�丸�ڵ�
2.1����ǰ�ڵ����丸�ڵ���������������Ÿ��ڵ����ϱ���ֱ���ҵ�һ�����ڵ�����
	���ڵ�����ӽڵ㣬��ô�ø��ڵ�ĸ��ڵ����Ҫ�ҵ���һ���ڵ㣬����Ϊ�� 
**/ 
TreeLinkNode* NextTreeNode(TreeLinkNode* pNode){
	if(pNode == NULL) return NULL;
	TreeLinkNode *pNext;
	if(pNode->right != NULL){
		TreeLinkNode *temp = pNode->right;
		while(pNode->left)
			temp = temp->left;
		pNext = temp;
	}
	else if(pNode->next != NULL){
		TreeLinkNode *pCurrent = pNode;
		TreeLinkNode *pParent = pNode->next;
		while(pParent !=NULL && pCurrent == pParent -> right){
			pCurrent = pParent;
			pParent = pParent->next;
		}
		pNext = pParent;
	} 
	return pNext;
}

//�Գƶ������ж�
bool isSymmetrical(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;
	if(root1->val != root2->val) return false;
	return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
}
bool isSymmetrical(TreeNode* root){
	return isSymmetrical(root, root);
}

//���д��ϵ��´�ӡ������
void printBinaryTree(TreeNode* root){
	if(root == NULL) return;
	queue<TreeNode*> que;
	que.push(root);
	int toBePrintNum = 1; //��¼��ǰ��û��ӡ�Ľڵ��� 
	int nextLevelNode = 0; // ��¼��һ��Ҫ��ӡ�Ľڵ��� 
	while(!que.empty()){
		TreeNode *temp = que.front();
		cout << temp->val << " ";
		
		if(temp->left){
			que.push(temp->left);
			nextLevelNode++;
		}
		if(temp->right){
			que.push(temp->right);
			nextLevelNode++;
		}
		que.pop();
		if(toBePrintNum == 0){
			cout << endl;
			toBePrintNum = nextLevelNode;
			nextLevelNode = 0;
		}
	}
}

// ��֮���δ�ӡ��������������������һ������ͳ�ƾ��У������㰴�����ҽ����У�ż���㰴���ҵ�������о���
vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int>> res;
	if(pRoot == NULL)
		return res;
	queue<TreeNode*> que;
	que.push(pRoot);
	bool even = false;
	while(!que.empty()){
		vector<int> vec;
		const int size = que.size();
		for(int i=0; i<size; ++i){
			TreeNode* tmp = que.front();
			que.pop();
			vec.push_back(tmp->val);
			if(tmp->left != NULL)
				que.push(tmp->left);
			if(tmp->right != NULL)
				que.push(tmp->right);
		}
		if(even)
			std::reverse(vec.begin(), vec.end());
		res.push_back(vec);
		even = !even;
	}
	return res;
}

//�����������ĵ�K���ڵ�,����������ǰ��մ�С�����˳���ŵģ�����ʱ�����һ����������ǰ��ֹ�ݹ� 
vector<int> MiddleSearch(TreeNode* root){
	vector<int> result;
	if(root == NULL) return result;
	MiddleSearch(root->left);
	result.push_back(root->val);
	MiddleSearch(root->right);
	return result;
} 
int kthNode(TreeNode* root, int k){
	vector<int> result;
	result = MiddleSearch(root);
	return result[k-1];	 	
} 

//�������������е�K������֣���Top K���� 
/**

����A ��B ��Ԫ�ظ���������k/2�����ǽ�A �ĵ�k/2 ��Ԫ�أ���A[k/2-1]����B �ĵ�k/2��Ԫ�أ���B[k/2-1]�����бȽϣ�
���������������Ϊ�˼������ȼ���k Ϊż�������õ��Ľ��۶���k ������Ҳ�ǳ����ģ���
A[k/2-1] == B[k/2-1]  �򷵻�array1[k/2-1]����array2[k/2-1]
A[k/2-1] > B[k/2-1] ��array2��[0,k/2-1]��Χ�ڵ�Ԫ��һ����array1��array2�ϲ����k��Ԫ��С�����Բ��ÿ���array2��[0,k/2-1]��Χ�ڵ�Ԫ��
A[k/2-1] < B[k/2-1] ��array1��[0,k/2-1]��Χ�ڵ�Ԫ��һ����array1��array2�ϲ����k��Ԫ��С�����Բ��ÿ���array1��[0,k/2-1]��Χ�ڵ�Ԫ��
����㷨����д��һ���ݹ����ʽ���ݹ����������Ϊ��
1��array1[k/2-1] == array2[k/2-1] return array1[k/2-1]
2��array1����array2Ϊ��ʱ��return array1[k-1]����array2[k-1]
3��k==1ʱ������min(array1[0],array2[0])

**/
double FindKthNum(int a[],int len1, int b[], int len2, int k){
	//ʼ����Ϊlen1<len2
	if(len1 > len2) return FindKthNum(b, len2, a, len1, k); //ʼ�ձ��̵ֶ�������ǰ 
	if(len1 == 0) return b[k-1];
	if(k == 1) return min(a[0], b[0]);
	
 	//��k��Ϊ�����֣��ֱ���a��b�����ϲ���
	int k1 = min(k/2, len1);
	int k2 = k - k1;
	
	if(a[k1-1] < b[k2-1])
		return FindKthNum(a+k1, len1-k1, b, len2, k-k1); //����ָ�����һ��ƫ������ʾָ����Ӧ�±�λ�� 
		
	else if(a[k1-1] > b[k2-1])
		return FindKthNum(a, len1, b+k2,len2-k2, k-k2);  
	
	else
		return a[k1-1];	
}

//���������е����ֵ,sʹ��˫�˶��д�����ݵ��±��������ֵ��ʼ�ձ��ִ��ڵ����ֵ��˫�˶��е�ͷ�� 
vector<int> maxInWindowOfK(vector<int> arr, int k){
	int len = arr.size();
	vector<int> res;
	if(len == 0 || k <= 0) return res;
	if(k == 1) return arr;
	deque<int> deq;
	for(int i = 0; i < len; i++){
		//�ж϶���ͷ�����ֵ�Ƿ�Ҫ�Ƴ�����
		if(i >= k && deq.front() <= i - k) 
			deq.pop_front();
		//�Ƴ���ǰ������С�ڵ�ǰֵ��������Ϊ����һ����ĺ�С�Ĳ����ܲ������ڴ������ֵ�� 
		while(!deq.empty() && arr[i] >= arr[deq.back()]) 
	 		deq.pop_back();
	 	deq.push_back(i);
	 	// �������ھ���K��Ԫ�أ���ȡ��ǰ�����ֵ��Ҳ���Ƕ��е�ͷԪ��
	 	if(i >= k - 1) 
			res.push_back(arr[deq.front()]);   	
	}
	return res;	
} 

//�����е�·��
static int row,col;
//�жϸõ��Ƿ��Ѿ��߹� 
bool Path(char* matrix, vector<int>right ,int i, int j, char* str){
	if(i<0||j<0||i>=row||j>=col)//Խ��
		return false;
	if(matrix[i*col+j] == *str && right[i*col+j] == 0){
		right[i*col+j] = 1;
		if(*(str+1) == 0)
			return true;
		bool flag = Path(matrix,right,i,j+1,str+1)||
					Path(matrix,right,i+1,j,str+1)||
					Path(matrix,right,i-1,j,str+1)||
					Path(matrix,right,i,j-1,str+1);
		if(!flag)
			right[i*col+j] = 0;
		return flag;
	}
	else
		return false;
}
 
bool hasPath(char* matrix, int rows, int cols, char* str){
	row = rows;
	col = cols;
	vector<int> right(row*col,0); //��ʼ��vector��ʾ���еĸ�û���߹� 
	bool flag = false;
	for(int i = 0; i < rows; i++)
		for(int j = 0 ; j < cols; j++)
			flag = (flag || Path(matrix,right,i,j,str));
	
	return flag;
}

//�����˵��˶���Χ
 
int main(){
	int arr1[4] = {1,2,3,4};
	int arr2[4] = {5,6,7,8};
	cout << FindKthNum(arr1,4,arr2,4,6) << endl;
	
	//cout << Power(0,1) << " " << Power(2.0,3) << " " << Power(2.0,-3) << endl;
	int n,k;
	vector<int> vec;
	while(cin >> n >> k){
		int temp;
		for(int i = 0; i< n; i++){
			cin >> temp;
			vec.push_back(temp);
		}
		//vector<int> result = reverseArr(vec);
		vector<int> result = maxInWindowOfK(vec,k);
		auto it = result.begin();
		for(; it != result.end(); it++){
			cout << *it <<endl;
		}
	}
	//vector<int> vec1 = {1,2,3,0,5};
	//cout << IsConnection(vec1) << endl;
	//cout << LastRemind(5,3) << endl;
	//cout << Add(5,17) << endl;
	//string str = "gomognlele";
	//cout << FirstAppearOnce(str) << endl;
	//cout << StringToInt(str) << endl;
	//cout << IsNumber(str) << endl;
	//vector<int> vec2 = {4,5,3,2,1};
	//cout << IsPopOrder(vec1, vec2) << endl;
	
	//string str = "abc";
	//vector<string> result = Permutation(str);
	//auto item = result.begin();
	//cout << result.size() <<endl;
	//while(item != result.end()){
	//	cout << *item << endl;
	//	item++;
	//}
	/**vector<int> arr;
	int n;
	int temp;
	int k;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> temp;
			arr.push_back(temp);
		}
		FindTwoAppearOnce(arr);
		//cout << MoreThanHalfNum(arr) <<endl;
	//	auto item = Get_K_MinNum(arr,k).begin();
		//while(item != Get_K_MinNum(arr,k).end()){
		//	cout << *item << " ";
		//	item++;
		//} 
		//cout << Get_K_MinNum(arr,k) <<endl;
		//arr.clear();
	}**/
	//string s;
	//while(cin >> s){
		/**for(int i = 0; i < n; i++){
			cin >> temp;
			arr.push_back(temp);
		}
		cout << FindGreatestSumOfSubArray(arr) << endl;**/
		//cout << NumberOf1Count(n) << endl;
		//cout <<GetUglyNumber_Solution(n) << endl;
		//cout << firstAppearCharOnLyOnce(s) << endl;
	//}
	
	/**string str;
	int n;
	while(cin >> str){
		//cout << LeftRotateString(str, n) << endl;
		reverseStringOfWord(str);
		//cout << reverseStringOfWord(str)<< " "; 
	}**/
	
	return 0;
}
