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
 * URL : https://codeforces.com/contest/1996/problem/E
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
string s;

// <---------- Helper Functions ---------->

// <---------- Solve Function ---------->

void solve(){
    cin >> s;
    
    int n = s.length();
    v<int> pref(n+1, 0); // stores count of 0
    
    for(int i = 1; i <= n; ++i){
    	pref[i] = pref[i-1];
    	
    	if(s[i-1] == '0') pref[i]++;
    }
    
    int ans = 0;
    
    for(int i = 1; i <= n-1; ++i){
    	for(int j = i+1; j <= n; ++j){
    		int cnt0 = pref[j] - pref[i-1];
    		int cnt1 = (j-i+1) - cnt0;
    		
    		if(cnt0 == cnt1) ans++;
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