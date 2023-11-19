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
 * URL : https://codeforces.com/contest/1899/problem/C
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
    
    int maxSum = INT_MIN;
    int currSum = 0;
    int maxElement = INT_MIN; // in case all elements are -ve, we must choose least -ve.

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        
        if(currSum < 0){
            currSum = 0;
        }
        
        maxSum = max(maxSum, currSum);
        maxElement = max(maxElement, arr[i]);
        
        if(i < n-1 && abs(arr[i]%2) == abs(arr[i+1]%2)){
            currSum = 0;
        }
    }
    
    cout << (maxSum == 0 ? maxElement : maxSum) << endl;
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