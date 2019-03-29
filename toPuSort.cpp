#include<iostream>
#include<algorithm>

using namespace std;

/**
�����������˼�룺
1��ÿ���ҵ����Ϊ0����û��ָ�����Ľڵ㣩�Ľڵ�
2�������ڶ�����ѡ��һ�������һ��ѡ��ڵ�ֵ��С�ģ����
3��ȥ���ýڵ������������
4���ظ�1��2��3���裬֪�����˿ռ�Ϊ0����������˿ռ��С��Ϊ0
���ʾ���ڻ�����˸�����ͼ�������˽ṹ�� 
**/

int main(){
	int a, b;
	int pointNum,edgeNum;
	cout << "�����붥������"<< " ";
	cin >> pointNum;
	cout << "�����������"<< " ";
	cin >> edgeNum;
	cout << "������ߣ�" << endl;
	int map[pointNum][pointNum]; //�����ڽӾ��� 
	for(int i = 0; i < pointNum; i++){
		for(int j = 0 ; j < pointNum; j++){
			map[i][j] = 0; //��ʼ���ڽӾ���0��ʾ�ڵ�֮��û����ͨ��1��ʾ��ͨ 
		}
	} 
	for(int i = 0; i < edgeNum; i++){
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	cout << "�ڽӾ���������ʾ:" << endl;
    for(int i = 0; i < pointNum; i++){
        for(int j = 0; j < pointNum; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    
    //����ÿ����������
	int temp;
	int deep[pointNum];
	for(int i = 0; i < pointNum; i++){
		temp = 0;
		for(int j = 0; j < pointNum; j++){
			if(map[j][i] == 1){ //i��jΪ1��ʾJ����ȼ�1 
				temp++;
			}
		}
		deep[i] = temp;
	}
	cout << "��ӡ��ÿ���ڵ����ȣ�"<<endl;
	for(int i = 0; i < pointNum; i++){
		cout << deep[i] << " ";
	}
	cout << endl;
 	cout << "��������:" << endl;
	int count = 0; //ͳ���Ѿ�������Ľڵ���
	while(true){
		for(int i = 0; i < pointNum; i++){
			if(deep[i] == 0){
				cout << i <<  " ";
				count++;
				deep[i] = -1; //-1��ʾ�Ƴ��ö���
				for(int j = 0; j < pointNum; j++){
					if(map[i][j] == 1){
						deep[j]--;//�������j�붥��i�бߣ���ɾ�������ߣ����Ҷ���j�����-1����ȼ�1�ͱ�ʾ�ñ߲������� 
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
 
