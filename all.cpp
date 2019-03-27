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
