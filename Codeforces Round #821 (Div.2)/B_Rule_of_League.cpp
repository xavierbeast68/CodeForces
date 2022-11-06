/**
 * @author xavierbeast68
 * ? Problem From : Codeforces Round #821 (Div.2)
 * @name : Rule of League
 * @date : 19-09-2022
 * @link : https://codeforces.com/contest/1733/problem/B
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;


/*--Loop Macros--*/
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORL(i,a,b) for(int i = a; i <= b; ++i)
#define FORR(i,a,b) for(int i = a; i >= b; --i)
/*--Minimum-Maximum Macros--*/
#define Min2(a,b) (a<b?a:b)
#define Max2(a,b) (a>b?a:b)
/*--Vector Macros--*/
#define pb push_back
#define ppb pop_back
/*--other macros--*/
#define sz(x) ((int)(x).size())
#define all(x) ((x).begin(), (x).end())


/*--Print Functions--*/
//std outputs
#define print(x) (cout<<(x)<<endl)
//std errors
void _print(ll t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}

/*--Debug--*/
//#define debugO(i) (cout<<"<==Testing(#"<<i<<")==>"<<endl)
#ifndef ONLINE_JUDGE
#define debug(x) cerr <<"<==Testing(#"; _print(x); cerr <<")==>"<< endl;
#else
#define debug(x)
#endif
/*--Debug File(Debug stderr statements to a file)--*/
void debugf()
{
#ifndef ONLINE_JUDGE
	freopen("debug.txt", "w", stderr);
#endif
}


/*--InputOutputError_From/To_File*/
void IOE()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("error.txt", "w", stderr);
#endif
}


/*--Execution Time--*/
void execTime() {cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;}


/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/


void solve()
{
	/*--Let's Code--*/
	int n, x, y; cin >> n >> x >> y;
	if ((x == 0 && y == 0) || (x != 0 && y != 0))
	{
		print(-1);
	}
	else
	{
		int max = Max2(x, y);
		if ((n - 1) % max == 0)
		{
			int j = 2;
			int i = 1;
			while ((i < n) && (j <= n))
			{
				cout << j << " ";
				if (i % max == 0)
				{
					j = j + max;
				}
				i++;
			}
			cout << endl;
		}
		else
		{
			print(-1);
		}
	}

}

signed main()
{
	fastio;
	//IOE();
	//debugf();

	/*t=1: default value for single test case*/
	int t = 1;
	cin >> t;
	while (t--)
	{
		//debug(t);
		solve();
	}

	//execTime();
	return 0;
}

/**
 * check t: comment cin>>t; for single test case
 * if using CPH Judge or CppFastOlympicsCoding: no need to use IOE;
 */