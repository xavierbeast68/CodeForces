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
 * URL : https://codeforces.com/contest/1903/problem/B
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

/*
    *Thought Process*
    !---------------!
    
*/


#include<bits/stdc++.h>
using namespace std;

#define JULI_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define repl(it, var) for(auto &it : var)
#define all(x) begin(x), end(x)
#define v(x) vector<x>
const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int INF = 1000000000000000005;

// <---------- Global Variables ---------->
int n;
string s;
v(v(int)) vec;

// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

void solve(){
    cin >> n;
    vec.resize(n+1, vector<int>(n+1, 0));
    fo(i, 1, n) fo(j, 1, n) cin >> vec[i][j];
}

// <-------------------------- Main -------------------------->
signed main(){
    
    JULI_OP; // FAST_IO
    
    int testcases = 1;
    cin >> testcases;
    while(testcases--){
        solve();
    }
    
    return 0;
}