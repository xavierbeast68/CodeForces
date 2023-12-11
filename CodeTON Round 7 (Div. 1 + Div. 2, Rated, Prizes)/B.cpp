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
 * URL : https://codeforces.com/contest/1896/problem/B
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
#define all(x) (begin(x), end(x))
const int mod = 1e9+7;
const int INF = 1000000000000000005;
#define v(x) vector<x>

// <---------- Global Variables ---------->
int n;
string s;
// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

void solve(){
    cin >> n;
    cin >> s;
    
    int firstB = (s[n-1]=='B'?n-1:-1);
    int ans = 0;
    
    int i = n-1;
    while(i >= 0 && s[i] != 'B'){
        i--;
        if(s[i] == 'B'){
            firstB = i;
        }
    }
        
    for(; i >= 0; --i){
        if(s[i] == 'A'){
            ans += (firstB-i);
            firstB = i;
        }
    }
    
    cout << ans << endl;
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