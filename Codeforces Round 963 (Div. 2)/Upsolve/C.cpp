/*
    ▄  ██       ▄   ▄█ ▄███▄   █▄▄▄▄ ███   ▄███▄   ██      ▄▄▄▄▄      ▄▄▄▄▀ 
▀▄   █ █ █       █  ██ █▀   ▀  █  ▄▀ █  █  █▀   ▀  █ █    █     ▀▄ ▀▀▀ █    
  █ ▀  █▄▄█ █     █ ██ ██▄▄    █▀▀▌  █ ▀ ▄ ██▄▄    █▄▄█ ▄  ▀▀▀▀▄       █    
 ▄ █   █  █  █    █ ▐█ █▄   ▄▀ █  █  █  ▄▀ █▄   ▄▀ █  █  ▀▄▄▄▄▀       █     
█   ▀▄    █   █  █   ▐ ▀███▀     █   ███   ▀███▀      █              ▀      
 ▀       █     █▐               ▀                    █                      
        ▀      ▐                                    ▀                       
*/
/**
 * xavierbeast68
 * URL : https://codeforces.com/contest/1993/problem/C
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


#include<bits/stdc++.h>
using namespace std;

#define JULI ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define repl(it, var) for(auto &it : var)
#define all(x) begin(x), end(x)
const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int INF = 1000000000000000005;
template<class T> using v = vector<T>;
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){int sz = a.size();for(int i = 0 ; i < sz; ++i){os << a[i] << " \n"[i==sz-1];}return os;}

// ------------------------------------------------------------------------------------------------------------------------------------------------------

/*
    *Thought Process*
    !---------------!
    
    UpSolve->
    https://www.youtube.com/watch?v=TO8PszXGEz8&ab_channel=aryanc403
*/

// <---------- Global Variables ---------->
int n, k;
v<int> a;
string s;

// <---------- Helper Functions ---------->

// <---------- Solve Function ---------->

void solve(){
    cin >> n >> k;
    a.resize(n);
    for(auto &e : a) cin >> e;
    
    sort(all(a));
	int M = 2 * k;
	int mx = a.back();
	
	for(auto &x : a){
		int d = (mx - x) / M;
		x = x + d * M; // changing x to a number nearer to mx
		// at time x, lights are on, and at time (x+d*M) also lights are on
	}
	
	sort(all(a));
	map<int,int> mp; // stores the ranges in which lights are on
	// take upto 2 or 3 intervals
	for(auto &e : a){
		mp[e]++;		// lights on-> [e to e+k-1]
		mp[e+k]--;		// lights off-> [e+k to e+2k-1]
		mp[e+2*k]++;	// lights on-> [e+2k to e+3k-1]
		mp[e+3*k]--;	// lights off-> [e+3k to e+4k-1]
		mp[e+4*k]++;	// lights on-> [e+4k to e+5k-1]
		mp[e+5*k]--;	// lights off-> [e+5k to e+6k-1]
	}
	
	int on = 0, ans = -1;
	for(auto it : mp){
		on += it.second;
		
		// all lights on
		if(on == n){
			ans = it.first; // time at which all lights are on
			break;
		}
	}
	
	cout << ans << endl;
}

// <-------------------------- Main -------------------------->

signed main(){
    
    JULI; // FAST_IO
    
    int testcases = 1;
    cin >> testcases;
    while(testcases--){
        solve();
    }
    
    return 0;
}