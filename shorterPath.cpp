#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
string matchStr(string str1, string str2)
{
	string flag = "true";
	int len1 = str1.size();
	int num = 0;
	vector<int> pos;
	for (int i = 0; i < len1 - 1; ++i)
	{
		if (str1[i + 1] == str1[i])
			pos.push_back(i + 1);
	}
	for (int i = 0; i < pos.size(); i++)
	{
		int tmp = pos[i] - i;
		str1.erase(str1.begin() + tmp);
	}
	for (int i = 0; i < str2.size(); i++)
	{
		num = str1.find(str2[i]);
		if (num < 0)
		{
			flag = "false";
			break;
		}
		else
			continue;
	}
	return flag;
}
int main()
{
	string Str1, Str2;
	cin >> Str1;
	cin >> Str2;
	string Res = matchStr(Str1, Str2);
	cout << Res << endl;
	return 0;
}
