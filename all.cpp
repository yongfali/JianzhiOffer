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
	TreeLinkNode *next;	//指向父节点的指针 
	TreeLinkNode(int x): val(x), left(NULL),right(NULL),next(NULL){} 
}; 

//字符串空格替换 
void replaceSpace(char* str,int length){
	if(str == NULL || length <= 0){
		return;
	}
	//统计字符串中空格数
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

// 从尾到头打印链表 
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

//重建二叉树
TreeNode* binaryTree(vector<int>a, int abegin, int aend, vector<int>b, int bbegin, int bend){
	if(aend >= abegin || bend >= bend){
		return NULL;
	}
	TreeNode* root = new TreeNode(a[abegin]);
	int i = 0;
	//在中序遍历中找到根节点 
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

// 用两个栈实现队列
static stack<int> stack1;
static stack<int> stack2;
//入栈 
void push(int node){
	stack1.push(node);
}
//出栈若stack2不为空先让所有数据出栈，否则stack1数据进入stack2中。 
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

// 旋转数组中的最小值
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

//矩形覆盖问题 也就是斐波拉切数列问题当前值等于前两项之和 
int rectCover(int number){
	
} 

// 二进制中1的个数
int countNumOf1(int num){
	int count = 0;
	while(num){
		count++;
		num = num & num-1;
	}
	return count;
} 

//数的整数次方
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

// 调整数组的顺序使得奇数位于偶数的前面并保证相对位置不变
vector<int> reverseArr(vector<int> arr){
	int len = arr.size();
	vector<int> res; 
	if(len == 0){
		return res;
	}
	//把奇数保存下来； 
	for(int i = 0; i < len; ++i){
		if(arr[i] & 1){
			res.push_back(arr[i]);
		}
	}
	//把偶数保存下来 
	for(int i = 0; i < len; ++i){
		if(arr[i] % 2 == 0){
			res.push_back(arr[i]);
		}
	}
	return res;
} 
 
 //链表中倒数第K个节点,定义两个指针，让第一个指针先走k-1步，然后两个指针一起走
 //直到第一个指针走到链表尾部，第二个指针所指的地方为第K个指针 
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
 
 //链表反转分别定义三个指针保存前一个和后一个节点的信息 
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
 
 //合并两个排序的链表,递归实现，每次只要选出一个就行进行大小的比较在两个链表头 
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
 
 //树的子结构判断
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
	 //两个根节点不一样则分别遍历树1的左右子树查找子结构 
	 if(!result){
 		result = DoseTree1HaveTree2(root1->left, root2); 
 	}
 	if(!result){
 		result = DoseTree1HaveTree2(root1->right, root2); 
 	}
 	return result;
 }
 
 //二叉树镜像，递归交换左右子树的节点就行
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
 
 //顺时针打印矩阵
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> res;
	if(matrix.empty()){
		return res;
	}
	 int rows = matrix.size();
	 int cols = matrix[0].size();
	 //定义四个角标变量，因为打印一共分为四步，分别为从左到右
	 //从上到下，从右到左，从下到上。
	 int left = 0;
	 int right = cols - 1;
	 int top = 0;
	 int bottom = rows - 1;
        while(left <= right && top <= bottom){
            //从左到右打印，这一步肯定有
            for(int i = left; i <=right; i++){
                res.push_back(matrix[top][i]);
            }
            //从上到下打印
            if(top < bottom){
                for(int j = top+1; j <= bottom; j++){
                    res.push_back(matrix[j][right]);
                }
            }
            //从右到左打印
            if(top < bottom && left < right){
                for(int k = right -1; k >= left; k--){
                    res.push_back(matrix[bottom][k]);
                }
            }
            //从下往上打印
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
 
 //栈的压入和弹出,即判断一个序列是否为出栈的顺序
 bool IsPopOrder(vector<int> pushS, vector<int> popS){
 	stack<int> temp;
 	int id = 0; //用于统计原序列是否已经全部入栈 
 	for(int i = 0; i < popS.size(); ++i){
	 	while(temp.empty() || temp.top() != popS[i]){
	 		temp.push(pushS[id++]);
	 		//当原序列全部入栈后还没有找到与当前值相等的则说明不是出栈顺序 
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

// 从上往下打印二叉树，同层从左到右
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

//判断一个数组是否为某一个二叉搜索树的后序遍历
//后序遍历根节点为最后一个，并且比根节点大的为左子树，反之为右子树
//递归直到左右都遍历完
bool ArrayIsHouXu(vector<int> arr){
	int len = arr.size();
	if(len <=0 ){
		return false;
	}
	int root = arr[len-1];//最后一个为树的根节点
	vector<int> leftNode;
	vector<int> rightNode;
	int i = 0;
	for(; i < len - 1; i++){
		if(arr[i] < root){
			leftNode.push_back(arr[i]);
		}
		break; //不再出现小的后说明左子节点全部遍历完 
	}
	int j = i;
	for(; j < len -1; ++j){
		if(arr[j] > root){
			rightNode.push_back(arr[j]);
		}
		return false; //当大的后面突然出现一个小的则不符合后序遍历 
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

// 查找二叉树中和为某一值的所有路径，可以递归每次查找的值为目标值减去当前的根节点值
// 这样就可以不用回溯了，相当于递归更新目标和，直到为0或树为空
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
	//左右子树不为空并且还没有达到目标值则调整目标值递归进行查找 
	FindAllPath(root->left, target - root->val);
	FindAllPath(root->right, target - root->val);
	if(!temp.empty()){
		temp.pop_back(); 
	} 
	return allSequence;
}

// 复杂链表的复制分三步进行，首先复制节点，然后调整random指针，最后按奇数偶数打印
//1：复制节点值
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
//2：完成Random节点链接
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
//3.拆分
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
 
//字符串的排列
void Permutation(string str, vector<string> & res, int begin){
	int len = str.size();
	if(begin == len){
		res.push_back(str);
		return;
	}
	          
	for(int i = begin; i < len; i++){
		//一样的两个数字不需要交换
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

//数组中出现次数超过一半的数字
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

//最小的K个数,通过维护一个K大顶堆即可 ,若果找K大则维护一个K小顶堆即可 
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
 
 //连续子数组的最大和
 int FindGreatestSumOfSubArray(vector<int> arr){
 	int len = arr.size();
	 if(len == 0){
 		return 0;
 	}
 	int maxSum = 0;
 	int currentSum = 0;
 	for(int i = 0; i < len; i++){
 		//当加上的值小于等于0时说明连续子和中断因为任何一个数加上一个非正数都会
		//使其值变小。 
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
 
 // 一个整数中1出现的次数
 int NumberOf1Count(int number){
 	int count = 0;
 	while(number){
	 	count++;
	 	number = number & (number - 1);
	 }
	 return count;
 }
 
 //把数组排成最小的数
 //对数据先排序若a+b < b+a则a在前，b在后，然后对排序后的数组进行拼接就行 
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
 
 //丑数
 int GetUglyNumber_Solution(int index) {
	 if(index <= 0){
	 	return 0;
	 }
	 int factors[] ={2,3,5};
	 int uglyNumbers[index];
	 uglyNumbers[0] = 1;
	 //记录使用的次数这样就不会出现重复的丑数
	 int num2 = 0, num3 = 0 , num5 = 0;
	 for(int i = 1; i < index; i++){
	 	uglyNumbers[i] = min(uglyNumbers[num2] * factors[0], min(uglyNumbers[num3] * factors[1], uglyNumbers[num5] * factors[2]));
	 	if(uglyNumbers[i] == uglyNumbers[num2]*factors[0])num2++;
	 	if(uglyNumbers[i] == uglyNumbers[num3]*factors[1])num3++;
	 	if(uglyNumbers[i] == uglyNumbers[num5]*factors[2])num5++;
	 }
 	return uglyNumbers[index-1];
 }
 
 //第一个只出现一次的字符
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
 
 //数组中的逆序对
 int reverseNum(vector<int> arr){
 	int len = arr.size();
 	if(len == 0 || len == 1){
	 	return 0;
	}
	 
} 

//两个链表的第一个公共节点
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

//数字在排序数组中出现的次数
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

//二叉树的深度
int TreeDepth(TreeNode* root){
	if(root == NULL)
		return 0;
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	return left > right ? left + 1 : right + 1;
	
}

//判断一棵树是否为平衡二叉树,采用后续遍历这样每一个节点只需要遍历一次就可以，
//自底向上判断是否符合平衡二叉树的条件 ,depth记录每个节点的深度便于判断 
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

//数组中只出现一次的两个数字
//若是只有一个则异或最后剩下的就是那个唯一一次的数字，因为任何相同的异或都为0 
void FindTwoAppearOnce(vector<int> arr){
	int len = arr.size();
	if(len < 2)
		return;
	int num1 = 0, num2 = 0;
	int result = arr[0]; //result的结果为两个出现一次数字的异或结果 
	for(int i = 1; i < len; ++i)
		result ^= arr[i];
	
	int indexOf1FirstAppear = (result ^ (result -1)) & result;//找到第一次出现1的位置然后根据此条件对数组进行划分
	
	for(int i = 0; i < len; ++i){
		if(arr[i] & (1 << indexOf1FirstAppear - 1))
			num1 ^= arr[i];
		else
			num2 ^= arr[i];
	}
	cout << num1 << " " << num2 << endl; 	
} 
 
//和为S的连续正数序列  
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

// 左旋转字符串,调用string的库函数substr()和erase()
string LeftRotateString(string str, int n){
	int len = str.length();
	if(n < 0 || len <= 0) return NULL;
	if(n == 0) return str;
	
	string temp = str.substr(0,n);
	str.erase(0,n);
	str += temp;
	return str;	 
}

//翻转单词顺序调用string的库函数reverse(const int &begin， const int &end)
string reverseStringOfWord(string str){
	int len = str.size();
	//cout << len << endl;
	if(len == 0) return NULL;
	reverse(str.begin(), str.end());//第一次翻转所有字符，然后再根据空格对单个单词进行翻转即可
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

//扑克牌顺子
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

//约瑟夫问题，即环形链表中每次剔除一个数据，最后剩下的是什么,n为长度，K为每次剔除的位置大小 
int LastRemind(int n, int k){
	if(n < 1 || k < 1) return -1;
	list<int> listArr;
	for(int i = 0; i < n; i++)
		listArr.push_back(i);
	auto item = listArr.begin();
	while(listArr.size() > 1){
		for(int i = 0; i < k - 1; i++){
			item++;
			if(item == listArr.end()) //当走到链表的尾部时让它重新指向头结点，这样就能形成环装。 
				item = listArr.begin();
		}
		item = listArr.erase(item++);
		if(item == listArr.end())
			item = listArr.begin();
	}
	return *item; 
}

//不用加减乘除求两个数之和
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


//把字符串转换为整数
long StringToInt(string str){
	int len = str.length();
	if(len == 0)
		return 0;
	int dig = true;
	int i = 0;
	long num = 0;
	while(str[i]== ' ')
		i++;
	
	//进行符号判断
	if(str[i]=='+')
		i++;
	if(str[i]=='-'){
		i++;
		dig =false;
	}
	while(str[i] != '\0'){
		//对字符进行是否为数字的判断
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

// 构建乘积数组,分别求两个对角阵的值然后相乘               
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

//正则表达式匹配
bool match(string str, string pattern){
	
}

//表示数值的字符串
bool IsNumber(string str){
	if(str == " ") return false;
	int len = str.length();
	int num = 0; //用来统计数字的数目
	int nume = 0; //用来统计E的数目
	int dot = 0; //Y用来统计小数点数目
	int i = 0; //表示字符串的位数
	if(str[i] == '+' || str[i] == '-') i++; //判断首字符是否是正负号
	if(str[i] == '\0') return false;
	while(i < len){
		if(isdigit(str[i])){
			num = 1; //只要表示有数字就行
			i++; 			
		}
		else if(str[i] == '.'){
			if(dot > 0 || nume > 0) return false; //当出现小数点时前面不能有小数点和e 
			dot++;
			i++;
		}
		else if(str[i] == 'e' || str[i] == 'E'){
			//cout << i <<endl;
			if(num == 0 || nume > 0) return false;
			nume++;
			i++;
			if(str[i] == '\0') return false;//说明E后面没有数字
			if(str[i] == '+' || str[i] == '-')i++;//E后面可以出现正负号 
			if(str[i] == '\0') return false;//说明E后面出现正负号但是没有数字 
		}
		else{
			return false;
		} 
	} 
	return true;
}

//字符流中第一个不重复的数字，定义一个map计数，第一次为1的弹出就行
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

//循环链表的入口,首先判断链表是否有环，采用快慢指针若相遇则有环
//然后统计环的大小，便可以采用寻找第K个节点的办法进行遍历 ，即先走K步跟找倒数第
//K个节点先走K-1步有点差别
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

//删除排序链表中重复的节点，让pre指向第一没有重复的节点则中间的节点就相当于在链表中删除了 
ListNode* DeleteDuplication(ListNode* pHead){
	// 链表有0个/1个节点，返回第一个节点
	if(pHead == NULL||pHead->next == NULL)
		return pHead;
	else
	{
		// 新建一个头节点，防止第一个结点被删除
		ListNode* newHead = new ListNode(-1);
		newHead->next = pHead;
		         
		// 建立索引指针
		ListNode* p = pHead;      // 当前节点
		ListNode* pre = newHead;  // 当前节点的前序节点
		ListNode* next = p->next;    // 当前节点的后序节点
	
		// 从头到尾遍历编标
		while(p != NULL && p->next != NULL)
		{
			if(p->val == next->val)//如果当前节点的值和下一个节点的值相等
			{
				// 循环查找，找到与当前节点不同的节点
				while(next != NULL && next->val == p->val)
				{
					ListNode* temp = next;
					next = next->next;	
					// 删除内存中的重复节点
					delete temp;
					temp = nullptr;
				}
				pre->next = next;
				p = next;
			}
			else//如果当前节点和下一个节点值不等，则向后移动一位
			{
				pre = p;
				p = p->next;
			}
			next = p->next; //这句两个条件内都有则提到外面公用。 
		}
	return newHead->next;//返回头结点的下一个节点
	}
}

//二叉树的下一个节点
/**
1：如果当前节点存在右子树，则找右子树的最左节点
2：如果没有右子树，当前节点的下一个节点分两种情况
2.1：当前节点是其父节点的左子树，则下一个节点为其父节点
2.1：当前节点是其父节点的右子树，则沿着父节点向上遍历直到找到一个父节点是其
	父节点的左子节点，那么该父节点的父节点就是要找的下一个节点，否则为空 
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

//对称二叉树判断
bool isSymmetrical(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;
	if(root1->val != root2->val) return false;
	return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
}
bool isSymmetrical(TreeNode* root){
	return isSymmetrical(root, root);
}

//分行从上到下打印二叉树
void printBinaryTree(TreeNode* root){
	if(root == NULL) return;
	queue<TreeNode*> que;
	que.push(root);
	int toBePrintNum = 1; //记录当前层没打印的节点数 
	int nextLevelNode = 0; // 记录下一层要打印的节点数 
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

// 按之字形打印二叉树，在上面代码加入一个层数统计就行，奇数层按从左到右进队列，偶数层按从右到左进队列就行
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

//二叉搜索树的第K个节点,其中序遍历是按照从小到大的顺序排的，若超时则添加一个计数器提前终止递归 
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

//两个有序数组中第K大的数字，即Top K问题 
/**

假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2个元素（即B[k/2-1]）进行比较，
有以下三种情况（为了简化这里先假设k 为偶数，所得到的结论对于k 是奇数也是成立的）：
A[k/2-1] == B[k/2-1]  则返回array1[k/2-1]或者array2[k/2-1]
A[k/2-1] > B[k/2-1] 则array2在[0,k/2-1]范围内的元素一定比array1、array2合并后第k个元素小，可以不用考虑array2在[0,k/2-1]范围内的元素
A[k/2-1] < B[k/2-1] 则array1在[0,k/2-1]范围内的元素一定比array1、array2合并后第k个元素小，可以不用考虑array1在[0,k/2-1]范围内的元素
因此算法可以写成一个递归的形式，递归结束的条件为：
1）array1[k/2-1] == array2[k/2-1] return array1[k/2-1]
2）array1或者array2为空时，return array1[k-1]或者array2[k-1]
3）k==1时，返回min(array1[0],array2[0])

**/
double FindKthNum(int a[],int len1, int b[], int len2, int k){
	//始终认为len1<len2
	if(len1 > len2) return FindKthNum(b, len2, a, len1, k); //始终保持短的数组在前 
	if(len1 == 0) return b[k-1];
	if(k == 1) return min(a[0], b[0]);
	
 	//将k分为两部分，分别在a和b数组上查找
	int k1 = min(k/2, len1);
	int k2 = k - k1;
	
	if(a[k1-1] < b[k2-1])
		return FindKthNum(a+k1, len1-k1, b, len2, k-k1); //数组指针加上一个偏移量表示指到对应下标位置 
		
	else if(a[k1-1] > b[k2-1])
		return FindKthNum(a, len1, b+k2,len2-k2, k-k2);  
	
	else
		return a[k1-1];	
}

//滑动窗口中的最大值,s使用双端队列存的数据的下表而不是数值，始终保持窗口的最大值在双端队列的头部 
vector<int> maxInWindowOfK(vector<int> arr, int k){
	int len = arr.size();
	vector<int> res;
	if(len == 0 || k <= 0) return res;
	if(k == 1) return arr;
	deque<int> deq;
	for(int i = 0; i < len; i++){
		//判断队列头部最大值是否要移除队列
		if(i >= k && deq.front() <= i - k) 
			deq.pop_front();
		//移除当前队列里小于当前值的数，因为进来一个大的后小的不可能不出现在窗口最大值中 
		while(!deq.empty() && arr[i] >= arr[deq.back()]) 
	 		deq.pop_back();
	 	deq.push_back(i);
	 	// 滑动窗口经过K个元素，获取当前的最大值，也就是队列的头元素
	 	if(i >= k - 1) 
			res.push_back(arr[deq.front()]);   	
	}
	return res;	
} 

//矩阵中的路径
static int row,col;
//判断该点是否已经走过 
bool Path(char* matrix, vector<int>right ,int i, int j, char* str){
	if(i<0||j<0||i>=row||j>=col)//越界
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
	vector<int> right(row*col,0); //初始化vector表示所有的格都没有走过 
	bool flag = false;
	for(int i = 0; i < rows; i++)
		for(int j = 0 ; j < cols; j++)
			flag = (flag || Path(matrix,right,i,j,str));
	
	return flag;
}

//机器人的运动范围
 
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
