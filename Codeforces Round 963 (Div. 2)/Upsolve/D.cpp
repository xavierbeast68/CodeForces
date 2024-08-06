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
 * URL : https://codeforces.com/contest/1993/problem/D
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
    
    Upsolve->
    
    aryanc403
    https://www.youtube.com/watch?v=TO8PszXGEz8&ab_channel=aryanc403
    Iterative implementation->
    https://codeforces.com/contest/1993/submission/274389157
*/
/*
recursive implementation->
https://codeforces.com/contest/1993/submission/274513622
*/

// <---------- Global Variables ---------->
int n, k, rem, reqGt; 
/* reqGt is required greater than, 
rem is final elements remaining after performing operations 
so that only <= k elements remains */
v<int> a;
pair<int,int> defaultVal;
string s;

// <---------- Helper Functions ---------->

vector<pair<int,int>> dp;
bool check(int med){
	dp.clear();
	defaultVal = make_pair(-INF, 0);
	dp.resize(n, defaultVal);
	
	function<pair<int,int>(int)> dfs = [&](int i)->pair<int,int>{
		
		if(i < 0) return defaultVal;
		
		int curr = (a[i] >= med);
		int r = i/k, c = i%k;
		
		if(dp[i] != defaultVal) return dp[i];
		
		
		// if row is not 0, we can check for element that was k elements before
		if(r != 0) dp[i] = max(dp[i], dfs(i-k));
		
		// if column is not zero, we can check previous element
		if(c && c < rem){
			pair<int,int> temp = dfs(i-1);
			
			if(temp.second < rem)
				dp[i] = max(dp[i], {curr+temp.first, temp.second+1});
		}
		
		// column = 0
		if(c == 0){
			dp[i] = max(dp[i], {curr, 1});
		}
		
		return dp[i];
	};
	
	dfs(n-1);
	
	return dp[n-1].first >= reqGt;
}

// <---------- Solve Function ---------->

void solve(){
    cin>>n>>k;
    a.resize(n);
    for(auto &x:a) cin>>x;
 
    auto c=a;
    c.push_back(-INF);
    c.push_back(INF);
    sort(all(c));
    (c).erase(unique(all(c)),(c).end());
 
 	// rem = ((n-1)%k)+1
    rem = (n%k?n%k:k), reqGt = rem/2+1;
    
    int l = 0, r = c.size();
    
    while(r - l > 1){
        int m=(l+r)/2;

        if(check(c[m]))
            l = m;
        else
            r = m;
    }
    
    cout << c[l] << endl;
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