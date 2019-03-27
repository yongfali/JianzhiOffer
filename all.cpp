#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
#include<queue>
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
		return;
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
	nodeClone(pHead);
	connectRandom(pHead);
	return reconnect(pHead);
 }
 

int main(){
	//cout << Power(0,1) << " " << Power(2.0,3) << " " << Power(2.0,-3) << endl;
	//int n;
	//vector<int> vec;
	//while(cin >> n){
	//	int temp;
	//	for(int i = 0; i< n; i++){
	//		cin >> temp;
	//		vec.push_back(temp);
	//	}
	//	vector<int> result = reverseArr(vec);
	//	vector<int>::iterator it = result.begin();
	//	for(; it != result.end(); it++){
	//		cout << *it <<endl;
	//	}
//	}
	vector<int> vec1 = {1,2,3,4,5};
	vector<int> vec2 = {4,5,3,2,1};
	cout << IsPopOrder(vec1, vec2) << endl;
	return 0;
}
