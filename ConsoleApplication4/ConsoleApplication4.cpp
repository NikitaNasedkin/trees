#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;
void Show(vector<int> path)
{
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i] << ", ";
	}
	cout << endl;
}
void ShowLst(vector<vector<int>> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << i << ": ";
		for (int k = 0; k < list[i].size(); k++)
			cout << list[i][k] << ", ";
		cout << endl;
	}
	cout << endl;
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
	cout << endl;
}
vector<vector<bool>> Convert(vector<vector<int>> list)
{
	vector<vector<bool>> matrix = vector<vector<bool>>(list.size(), vector<bool>(list.size()));
	for (int i = 0; i < list.size(); i++)
	{
		for (int k = 0; k < list[i].size(); k++)
		{
			matrix[i][list[i][k]] = 1;
		}
	}
	return matrix;
}
void dfs(vector <vector<int>> list, vector <vector<bool>> visited, int v)
{
	vector<int> path;
	int count = 1;
	stack<int> plan;
	visited[v][v] = 1;
	path.push_back(v);
	for (int i = 0; i< list[v].size(); i++)
		plan.push(list[v][i]);
	while (!plan.empty())
	{
		if (visited[plan.top()][plan.top()] == 0)
		{
			visited[plan.top()][plan.top()] = 1;
			path.push_back(plan.top());
			count++;
			int current = plan.top();
			plan.pop();
			for (int i = 0; i < list[current].size(); i++)
				plan.push(list[current][i]);
		}
		else
			plan.pop();
	}
	cout << "DFS path: ";
	Show(path);
	cout <<"Count of peaks: "<< count << endl;
}
void bfs(vector <vector<int>> list, vector <vector<bool>> visited, int v)
{
	vector<int> path;
	int count = 1;
	queue<int> plan;
	visited[v][v] = 1;
	path.push_back(v);
	for (int i = 0; i < list[v].size(); i++)
		plan.push(list[v][i]);
	while (!plan.empty())
	{
		if (visited[plan.front()][plan.front()] == 0)
		{
			visited[plan.front()][plan.front()] = 1;
			path.push_back(plan.front());
			count++;
			int current = plan.front();
			plan.pop();
			for (int i = 0; i < list[current].size(); i++)
				plan.push(list[current][i]);
		}
		else
			plan.pop();
	}
	cout << "BFS path: ";
	Show(path);
	cout << "Count of peaks: " << count << endl;

}
int main()
{
	vector <vector<int>>lst = vector <vector<int>>(5);
	lst[0] = { 1,2,3,4 };
	lst[1] = { 0,2,4 };
	lst[2] = { 1 };
	lst[3] = { 0,4 };
	lst[4] = { 0,1,3 };
	/*ShowLst(lst);
	cout << endl;
	ShowMtrx(Convert(lst));*/
	dfs(lst, Convert(lst), 1);
	cout << endl;
	bfs(lst, Convert(lst), 3);
	return 0;
}

