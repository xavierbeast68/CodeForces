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
 * URL : https://codeforces.com/contest/1996/problem/F
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
    
*/

// <---------- Global Variables ---------->
int n, k;
v<int> a, b;

// <---------- Helper Functions ---------->

// <---------- Solve Function ---------->


// Time limit exceeded
void solve(){
    cin >> n >> k;
    
    a.resize(n), b.resize(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    
    priority_queue<pair<int,int>> pq;
	for(int i = 0; i < n; ++i) pq.push(make_pair(a[i], i));
	
	int ans = 0;
	while(!pq.empty() && k--){
		int num = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		ans += num;
		num -= b[pos];
		if(num > 0) pq.push(make_pair(num, pos));
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