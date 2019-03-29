#include<iostream>
#include<algorithm>

using namespace std;

/**
拓扑排序基本思想：
1：每次找到入度为0（即没有指向他的节点）的节点
2：若存在多个随机选择一个输出（一般选择节点值较小的）输出
3：去掉该节点出发的连接线
4：重复1，2，3步骤，知道拓扑空间为0，若最后拓扑空间大小不为0
则表示存在环，因此该有向图不是拓扑结构。 
**/

int main(){
	int a, b;
	int pointNum,edgeNum;
	cout << "请输入顶点数："<< " ";
	cin >> pointNum;
	cout << "请输入边数："<< " ";
	cin >> edgeNum;
	cout << "请输入边：" << endl;
	int map[pointNum][pointNum]; //定义邻接矩阵 
	for(int i = 0; i < pointNum; i++){
		for(int j = 0 ; j < pointNum; j++){
			map[i][j] = 0; //初始化邻接矩阵，0表示节点之间没有联通，1表示联通 
		}
	} 
	for(int i = 0; i < edgeNum; i++){
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	cout << "邻接矩阵如下所示:" << endl;
    for(int i = 0; i < pointNum; i++){
        for(int j = 0; j < pointNum; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    
    //计算每个顶点的入度
	int temp;
	int deep[pointNum];
	for(int i = 0; i < pointNum; i++){
		temp = 0;
		for(int j = 0; j < pointNum; j++){
			if(map[j][i] == 1){ //i到j为1表示J的入度加1 
				temp++;
			}
		}
		deep[i] = temp;
	}
	cout << "打印出每个节点的入度："<<endl;
	for(int i = 0; i < pointNum; i++){
		cout << deep[i] << " ";
	}
	cout << endl;
 	cout << "拓扑序列:" << endl;
	int count = 0; //统计已经排序完的节点数
	while(true){
		for(int i = 0; i < pointNum; i++){
			if(deep[i] == 0){
				cout << i <<  " ";
				count++;
				deep[i] = -1; //-1表示移除该顶点
				for(int j = 0; j < pointNum; j++){
					if(map[i][j] == 1){
						deep[j]--;//如果顶点j与顶点i有边，则删除这条边，并且顶点j的入度-1，入度减1就表示该边不存在了 
					}
				} 
			}
		}
		
		if(count == pointNum){
			break;
		}
	} 
	
	return 0;	 
} 
 
