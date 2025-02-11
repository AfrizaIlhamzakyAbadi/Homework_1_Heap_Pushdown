#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
int l{};
void print(vector <int> x)
{
	for (int i{ 0 }; i < x.size(); i++)
	{
		cout << x[i] << " ";
	}
	cout << '\n';
}
void pushDown(vector <int>& x, int size, int node)
{
	x.push_back(node);
	while (size >= 0 && x[size] > x[(size - 1) / 2])
	{
		int t = x[size];
		x[size] = x[(size - 1) / 2];
		x[(size - 1) / 2] = t;
		l = size;
		size = (size - 1) / 2;
	}
	if (node <= x[(size - 1) / 2])
	{
		l = size;
	}
}
int PushDown(vector <int> x, int size, int node)
{
	x.push_back(node);
	while (size >= 0 && x[size] > x[(size - 1) / 2])
	{
		int t = x[size];
		x[size] = x[(size - 1) / 2];
		x[(size - 1) / 2] = t;
		size = (size - 1) / 2;
	}
	return x[l];
}
void push_down(vector <int>& x, int node)
{
	x.push_back(node);
	push_heap(x.begin(), x.end());
}
int Push_down(vector <int> x, int node)
{
	x.push_back(node);
	push_heap(x.begin(), x.end());
	return x[l];
}
int test(vector <int> x, int size, int node)
{

	vector <int> z = x;
	int t = PushDown(x, size, node);
	cout << "debug :	" << t << ", " << Push_down(z, node) << '\n';
	assert(t == Push_down(z, node));
	cout << "test succeeded.\n";
	return 0;
}
int main()
{
	vector <int> v{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27 };
	cout << "vector v :	";
	print(v);
	make_heap(v.begin(), v.end());
	cout << "heap v :	";
	print(v);
	srand(time(0));
	for (int i{ 0 }; i < 7; i++)
	{
		vector <int> a = v;
		vector <int> b = v;
		int c = rand() % 29;
		pushDown(a, 14, c);
		push_down(b, c);
		cout << "node :	" << c << '\n';
		cout << "by my function :	";
		print(a);
		cout << "by the test :		";
		print(b);
		test(v, 14, c);
		cout << '\n';
	}
	return 0;
}