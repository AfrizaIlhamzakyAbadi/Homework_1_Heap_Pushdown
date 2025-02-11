#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector <int> x)
{
	for (int i{ 0 }; i < x.size(); i++)
	{
		cout << x[i] << " ";
	}
	cout << '\n';
}
void pushDown(vector <int> &x, int size, int node)
{
	x.push_back(node);
	while (size >= 0 && x[size] > x[(size - 1) / 2])
	{
		int t = x[size];
		x[size] = x[(size - 1) / 2];
		x[(size - 1) / 2] = t;
		size = (size - 1) / 2;
	}
}
int main()
{
	vector <int> v{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27 };
	cout << "vector v :	";
	print(v);
	make_heap(v.begin(), v.end());
	cout << "heap v :	";
	print(v);
	cout << "node :	";
	int n{};
	cin >> n;
	pushDown(v, 14, n);
	cout << "after being pushed down\n" << "heap v :	";
	print(v);
	return 0;
}