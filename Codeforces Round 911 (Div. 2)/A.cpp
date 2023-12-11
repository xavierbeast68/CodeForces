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
 * URL : https://codeforces.com/contest/1900/problem/0
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
    int n; cin >> n;
    n += 2;
    string s; cin >> s;
    
    s = '#' + s + '#';
    
    size_t i, j = s.find('#', 0);
    int ans = 0;
    while(j != string::npos){
        i = s.find('.', j+1);
        if(i != string::npos){
            j = s.find('#', i+1);
            
            if(j != string::npos){
                if(j-i > 2){
                    cout << 2 << endl;
                    return;
                }
                
                ans += (j-i);
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    
    cout << ans << endl;
}

// #...#..#.#

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