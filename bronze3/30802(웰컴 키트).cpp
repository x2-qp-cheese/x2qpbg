#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int sz[6];
	int t, p;

	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> sz[i];
	cin >> t >> p;

	int orderT = 0;
	for (int i = 0; i < 6; i++)
	{
		if (sz[i] % t == 0)
			orderT += sz[i] / t;
		else
			orderT += sz[i] / t + 1;
	}
	cout << orderT << endl;

	cout << n / p << " " << n % p;
}