/**
 * @author xavierbeast68
 * Problem Name- Coprime ( Codeforces Round #824(div.4))
 * Problem Link- https://codeforces.com/contest/1742/problem/D
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*--Loop Macros--*/
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)
/*--Vector Macros--*/
#define pb push_back
#define ppb pop_back
/*--Print Macros--*/
#define print(x) (cout<<(x))
#define println(x) (cout<<(x)<<endl)

/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll max(ll a, ll b) {return a > b ? a : b;}
ll min(ll a, ll b) {return a < b ? a : b;}
ll countDigit(ll n) {return (floor(log10(n) + 1));}

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/

void solve()
{
	/*--Let's Code--*/
	int n; cin >> n;
	vector<int>a(n + 1);
	FOR(i, 1, n + 1)
	{
		cin >> a[i];
	}
	int max = -1;
	FOR(i, 1, n + 1)
	{
		FOR(j, i, n + 1)
		{
			int x = gcd(a[i], a[j]);
			if (x == 1)
			{
				if (max < (i + j))
				{
					max = i + j;
				}
			}
		}
	}
	println(max);
}

signed main()
{
	fastio;

	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
