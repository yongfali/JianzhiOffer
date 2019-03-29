#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

struct TreeNode{
	char val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(char x):val(x), left(NULL), right(NULL){}
};

//�ݹ鴴�������� 
void create(TreeNode* root){
	char ch;
	cin >> ch;
	if(ch == '#'){
		root = NULL;
	}
	root = new TreeNode();
	root->val = ch;
	create(root->left);//�ݹ齨�������� 
	create(root->right);//�ݹ齨�������� 
}

//ǰ��ݹ����
void preOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}
//��������ݹ�
void midOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	midOrder(root->left);
	cout << root->val << " ";
	midOrder(root->right);
}
//���������ݹ�ʵ��
void lastOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	lastOrder(root->left);
	lastOrder(root->right);
	cout << root->val << " ";
}

//ǰ������ǵݹ�ʵ��
 void preOrder2(TreeNode* root){
	if(root == NULL){
		return;
	}
	TreeNode *pNode = root;
	stack<TreeNode*> temp;
	temp.push(pNode); 
	while(!temp.empty()){
		TreeNode *tempNode = temp.top();
		temp.pop();
		cout << tempNode->val << " ";
		if(tempNode->right)
			temp.push(tempNode->right);
		
		pNode = tempNode->left;
	}	
}

//����ǵݹ����
void midOrder2(TreeNode* root){
	if(root == NULL){
		return;
	}
} 
int main(){
	TreeNode root;
	create(&root);
	//preOrder2(&root);
	
	return 0;
}
