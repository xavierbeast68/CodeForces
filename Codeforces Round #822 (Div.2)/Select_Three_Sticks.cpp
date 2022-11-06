/**
 * @author xavierbeast68
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define print(x) (cout<<(x)<<endl)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	vector <int> a(n);
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int moves = 100000000000;
	FOR(i, 0, n - 2)
	{
		int mind1 = abs(a[i] - a[i + 1]);
		int mind2 = abs(a[i + 1] - a[i + 2]);
		if ((mind1 + mind2) < moves)
		{
			moves = mind1 + mind2;
		}
	}
	print(moves);

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
