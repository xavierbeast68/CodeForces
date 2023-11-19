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
 * URL : https://codeforces.com/contest/1899/problem/E
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
    int minInd, mini = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        
        if(mini > arr[i]){
            minInd = i;
            mini = arr[i];
        }
    }
    
    // data after minInd is sorted or not??
    bool flag = true;
    for(int i = minInd; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            flag = false;
            break;
        }
    }
    if(!flag){
        cout << -1 << endl;
        return;
    }

    cout << minInd << endl;
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