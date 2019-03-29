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

//递归创建二叉树 
void create(TreeNode* root){
	char ch;
	cin >> ch;
	if(ch == '#'){
		root = NULL;
	}
	root = new TreeNode();
	root->val = ch;
	create(root->left);//递归建立左子树 
	create(root->right);//递归建立右子树 
}

//前序递归遍历
void preOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}
//中序遍历递归
void midOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	midOrder(root->left);
	cout << root->val << " ";
	midOrder(root->right);
}
//后续遍历递归实现
void lastOrder(TreeNode* root){
	if(root == NULL){
		return;
	}
	lastOrder(root->left);
	lastOrder(root->right);
	cout << root->val << " ";
}

//前序遍历非递归实现
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

//中序非递归遍历
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
