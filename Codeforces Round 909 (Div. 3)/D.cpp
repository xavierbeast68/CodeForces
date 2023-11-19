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
 * URL : https://codeforces.com/contest/1899/problem/D
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
    
    int one = 0, two = 0;
    map<int,int> mp;
    for(auto it : arr){
        mp[it]++;
        if(it == 1) one++;
        else if(it == 2) two++;
    }
    
    int ans = 0;
    for(auto it : mp){
        if(it.second > 1){
            ans += (it.second * (it.second-1) / 2);
        }
    }
    
    if(one>0 && two>0){
        ans += (one*two);
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