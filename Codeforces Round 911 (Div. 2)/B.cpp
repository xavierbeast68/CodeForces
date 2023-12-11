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
 * URL : https://codeforces.com/contest/1900/problem/B
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
#define v(x) vector<x>
const int mod = 1e9+7;
const int INF = 1000000000000000005;

// <---------- Global Variables ---------->

// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

void solve(){
    int a, b, c; cin >> a >> b >> c;
    
    vector<int> ans(4, 0);
    
    fo(i, 1, 3){
        // ansA
        if(i == 1){
            if(b == 0 && c == 0){
                if(a != 0) ans[i] = 1;
                else continue;
            }
            int aa = a + min(b, c);
            int diff = abs(b-c);
            if(diff%2 == 0 && diff/2 <= aa) ans[i] = 1;
        }
        else if(i == 2){
            if(a == 0 && c == 0){
                if(b != 0) ans[i] = 1;
                else continue;
            }
            int bb = b + min(a, c);
            int diff = abs(a-c);
            if(diff%2 == 0 && diff/2 <= bb) ans[i] = 1;
        }
        else{
            if(a == 0 && b == 0){
                if(c != 0) ans[i] = 1;
                else continue;
            }
            int cc = c + min(a, b);
            int diff = abs(a-b);
            if(diff%2 == 0 && diff/2 <= cc) ans[i] = 1;
        }
    }
    
    cout << ans[1] << " " << ans[2] << " " << ans[3] << endl;
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