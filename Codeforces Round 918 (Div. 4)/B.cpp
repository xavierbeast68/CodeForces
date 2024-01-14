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
 * URL : https://codeforces.com/contest/1915/problem/B
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
v<string> vec;
string s;

// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

/*
    *Thought Process*
    !---------------!
    
*/

void solve(){
    n = 3;
    set<char> abc{'A', 'B', 'C'};
    
    int done = 0;
    
    fo(i, 0, 2){
        cin >> s;

        if(done == 1) continue;
        
        if(s[0] == '?'){
            abc.erase(s[1]);
            abc.erase(s[2]);
            
            cout << *(abc.begin()) << endl;
            
            done = 1;
        }
        if(s[1] == '?'){
            abc.erase(s[0]);
            abc.erase(s[2]);
            
            cout << *(abc.begin()) << endl;
            
            done = 1;
        }
        if(s[2] == '?'){
            abc.erase(s[0]);
            abc.erase(s[1]);
            
            cout << *(abc.begin()) << endl;
            
            done = 1;
        }
    }
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