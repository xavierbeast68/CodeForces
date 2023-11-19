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
 * URL : https://codeforces.com/contest/1899/problem/B
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

/*
    *Thought Process*
    !---------------!
    
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long

// Global variables
int n;
vector<int> arr;

// Functions

void solve(){
    cin >> n;
    arr.resize(n);
    for(auto &a : arr) cin >> a;
    
    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + arr[i-1];
    
    int ans = 0;
    for(int k = 1; k <= n/2; k++){

        int maxi = pref[k], mini = pref[k];
        
        if(n%k == 0){
            for(int j = 2*k; j <= n; j += k){
                int seg1 = pref[j] - pref[j-k];
                
                maxi = max(maxi, seg1);
                mini = min(mini, seg1);
            }

            ans = max(ans, maxi-mini);
        }
    }

    cout << ans << endl;
}

signed main(){
    
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int testcases = 1;
    cin >> testcases;
    while(testcases--){
        solve();
    }
    
    return 0;
}