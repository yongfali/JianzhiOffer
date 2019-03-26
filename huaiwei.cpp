#include <stdio.h>
#include <tchar.h>
#include <iostream>
 
int state[6] = {1,2,3,4,5,6};//存放最终状态的数组
 
int stateL = 1;	
int stateR = 2;
int stateF = 3;
int stateB = 4;
int stateU = 5;
int stateD = 6;
 
using namespace std;
 
void ActionL(void)
{
	int temp1 = 0;
	int temp2 = 0;
 
	temp1 = stateL;
	temp2 = stateR;
 
	stateL = stateU;
	stateR = stateD;
 
	stateD = temp1;
	stateU = temp2;
 
	state[0] = stateL;
	state[1] = stateR;
	state[2] = stateF;
	state[3] = stateB;
	state[4] = stateU;
	state[5] = stateD;
}
 
void ActionR(void)
{
	int temp1 = 0;
	int temp2 = 0;
 
	temp1 = stateL;
	temp2 = stateR;
 
	stateL = stateD;
	stateR = stateU;
 
	stateD = temp2;
	stateU = temp1;
 
	state[0] = stateL;
	state[1] = stateR;
	state[2] = stateF;
	state[3] = stateB;
	state[4] = stateU;
	state[5] = stateD;
}
 
void ActionF(void)
{
	int temp1 = 0;
	int temp2 = 0;
 
	temp1 = stateF;
	temp2 = stateB;
 
	stateF = stateU;
	stateB = stateD;
 
	stateD = temp1;
	stateU = temp2;
 
	state[0] = stateL;
	state[1] = stateR;
	state[2] = stateF;
	state[3] = stateB;
	state[4] = stateU;
	state[5] = stateD;
}
 
void ActionB(void)
{
	int temp1 = 0;
	int temp2 = 0;
 
	temp1 = stateF;
	temp2 = stateB;
 
	stateF = stateD;
	stateB = stateU;
 
	stateD = temp2;
	stateU = temp1;
 
	state[0] = stateL;
	state[1] = stateR;
	state[2] = stateF;
	state[3] = stateB;
	state[4] = stateU;
	state[5] = stateD;
}
 
void ActionA(void)
{
	int temp1 = 0;
	int temp2 = 0;
 
	temp1 = stateF;
	temp2 = stateB;
 
	stateF = stateL;
	stateB = stateR;
 
	stateL = temp2;
	stateR = temp1;
 
	state[0] = stateL;
	state[1] = stateR;
	state[2] = stateF;
	state[3] = stateB;
	state[4] = stateU;
	state[5] = stateD;
}
 
void ActionC(void)
{
	int temp1 = 0;
	int temp2 = 0;
 
	temp1 = stateF;
	temp2 = stateB;
 
	stateF = stateR;
	stateB = stateL;
 
	stateL = temp1;
	stateR = temp2;
 
	state[0] = stateL;
	state[1] = stateR;
	state[2] = stateF;
	state[3] = stateB;
	state[4] = stateU;
	state[5] = stateD;
}

int main(int argc, char *argv[])
{
	char str[50];
	int numCount = 0;
	while(cin.getline(str,50)){
		for (int i = 0; i < 50; i++)
		{
			if (str[i] >0x40 && str[i]<0x53)
			{
				numCount++;
			}
	 
			else
			{
				break;
			}
		}
		for (int j = 0; j < numCount; j++)
		{
			switch (str[j])
			{
			case 'L':
				ActionL();
				break;
			case 'R':
				ActionR();
				break;
			case 'F':
				ActionF();
				break;
			case 'B':
				ActionB();
				break;
			case 'A':
				ActionA();
				break;
			case 'C':
				ActionC();
				break;
			default:
				break;
			}
		}
		cout << state[0] << state[1] << state[2] << state[3] << state[4] << state[5] << endl;
	}
    return 0;
}
