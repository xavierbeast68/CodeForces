/**
 * @author xavierbeast68
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
	int n, q; cin >> n >> q;
	// vector<pair<int,int>> qx;
	int oddSum = 0, evenSum = 0;
	int oddN = 0, evenN = 0;
	FOR(i, 0, n)
	{
		int x; cin >> x;
		if (x % 2 == 0)
		{
			evenSum += x;
			evenN++;
		}
		else
		{
			oddSum += x;
			oddN++;
		}
	}
	FOR(i, 0, q)
	{
		int x, y; cin >> x >> y;
		// qx.push_back(make_pair(x,y));
		if (x == 0)
		{
			evenSum = evenSum + evenN * y;
		}
		else
		{
			oddSum = oddSum + oddN * y;
		}
		println(evenSum + oddSum);
	}
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
