/**
 * @author xavierbeast68
 * Problem Name- Stripes ( Codeforces Round #824(div.4))
 * Problem Link- https://codeforces.com/contest/1742/problem/C
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
	vector<vector<char>> ch(8);
	FOR(i, 0, 8)
	{
		ch[i] = vector<char>(8);
		FOR(j, 0, 8)
		{
			char x; cin >> x;
			ch[i][j] = x;
		}
	}
	char last;
	FOR(i, 0, 8)
	{
		int cntR = 0, cntB = 0;
		cntR = count(ch[i].begin(), ch[i].end(), 'R');
		FOR(j, 0, 8)
		{
			if (ch[j][i] == 'B')
			{
				cntB++;
			}
		}
		if (cntR == 8)
		{
			last = 'R';
		}
		if (cntB == 8)
		{
			last = 'B';
		}
	}
	println(last);
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
