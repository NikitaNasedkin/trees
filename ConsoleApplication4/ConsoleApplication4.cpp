#include <iostream>
#include <vector>
#include <string>
using namespace std;
void ShowLst(vector<vector<int>> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << i << ": ";
		for(int k = 0; k < list[i].size(); k++)
		cout << list[i][k] << ", ";
		cout << endl;
	}
}
void ShowMtrx(vector<vector<bool>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int k = 0; k < matrix.size(); k++)
		{
			cout << matrix[i][k] << " ";
		}
		cout << endl;
	}
}
vector<vector<bool>> Convert(vector<vector<int>> list)
{
	vector<vector<bool>> matrix = vector<vector<bool>>(list.size(), vector<bool>(list.size()));
	for(int i = 0; i < list.size(); i++)
	{
		for (int k = 0; k < list[i].size(); k++)
		{
			matrix[i][list[i][k]] = 1;
		}
	}
	return matrix;
}
void dfs()
{

}
int main()
{
	vector <vector<int>>lst = vector <vector<int>>(5);
	lst[0] = { 1,2,3,4 };
	lst[1] = { 0,2,4 };
	lst[2] = { 1 };
	lst[3] = { 0,4 };
	lst[4] = { 0,1,3 };
	ShowLst(lst);
	cout << endl;
	ShowMtrx(Convert(lst));
}

