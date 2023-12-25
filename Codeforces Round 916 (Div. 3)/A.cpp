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
 * URL : https://codeforces.com/contest/1914/problem/0
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

// <---------- Global Variables ---------->
int n;
v<int> vec;
string s;

// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

/*
    *Thought Process*
    !---------------!
    
*/

void solve(){
    cin >> n;
    cin >> s;
    
    int cnt = 0;
    vector<int> vis(26, 0);

    fo(i, 0, n-1){
        int check = s[i]-'A';
        check += 1;
        if((vis[s[i]-'A'] == 0) && (check <= (n-i))){
            cnt++;
            vis[s[i]-'A'] = 1;
            // cout << s[i] << endl;
        }
    }
    
    cout << cnt << endl;
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