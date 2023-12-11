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
 * URL : https://codeforces.com/contest/1904/problem/B
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
v(int) vec;

// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

void solve(){
    cin >> n;
    vec.resize(n);
    for(auto &i : vec) cin >> i;
    
    v(int) arr(vec);
    sort(arr.begin(), arr.end());
    
    v(int) pref(n);
    pref[0] = arr[0];
    fo(i, 1, n-1) pref[i] = pref[i-1] + arr[i];
    
    v(int) ans(n, 0);
    fo(i, 0, n-1){
        int ind1 = upper_bound(arr.begin(), arr.end(), vec[i]) - arr.begin();
        ind1 -= 1;
        
        int cnt = ind1;
        int sum = pref[ind1];
        
        while(true){
            
            int ind2 = upper_bound(arr.begin(), arr.end(), sum) - arr.begin();
            ind2 -= 1;
            if(ind1 == ind2){
                break;
            }
            sum = pref[ind2];
            cnt += (ind2-ind1);
            ind1 = ind2;
        }

        ans[i] = cnt;
    }
    
    
    fo(i, 0, n-1) cout << ans[i] << " \n"[i==n-1];
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