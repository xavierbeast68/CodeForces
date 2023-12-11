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

//*--------------------------------------------------------------Debugger Starts--------------------------------------------------------------
//            [di:b^b-ing]
// -Being the detective in a crime
//  where you are also the murderer.

#define test(i)                                     cerr << "(#" << i << ")" << endl

// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
#define dbg(x)                                      cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

// #pragma warning disable format

void _print(int t) {cerr << t;}
// void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";}
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) { _print(v.top()); v.pop(); cerr << " "; } cerr << "]";}

//*--------------------------------------------------------------Debugger Ends--------------------------------------------------------------



// <---------- Global Variables ---------->

// <-------------------------- Helper Functions -------------------------->

// <-------------------------- Solve Function -------------------------->

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int len = s.length();
    
    vector<vector<int>> tree(n+1, vector<int>(2, 0));
    vector<int> par(n+1, 0);
    par[1]=1;
    fo(i, 1, n){
        cin >> tree[i][0] >> tree[i][1];
        if(tree[i][0] != 0){
            par[tree[i][0]] = i;
        }
        if(tree[i][1] != 0){
            par[tree[i][1]] = i;
        }
    }
    
    // dbg(tree);
    
    function<int(int, int)> dfs = [&](int node, int ind)->int{
        if(tree[node][0] == 0 && tree[node][1] == 0){
            return 0;
        }
        if(ind >= len){
            return INF;
        }
        
        int ans = INF;
        
        
        // if(s[ind] == 'L'){
        //     // i can flip it to right and go to right
        //     if(tree[node][1] != 0){
        //         ans = min(ans, 1 + dfs(tree[node][1], ind+1));
        //     }
            
        //     // i can flip it to up and go to parent if it is not 1
        //     if(par[node] != 1){
        //         ans = min(ans, 1 + dfs(par[node], ind+1));
        //     }
            
        //     // if left exist and i go to it
        //     if(tree[node][0] != 0){
        //         ans = min(ans, 0 + dfs(tree[node][0], ind+1));
        //     }
        //     else{
        //         // skip
        //         ans = min(ans, dfs(node, ind+1));
        //     }
        // }
        
        // if(s[ind] == 'R'){
        //     // i can flip it to left and go to left
        //     if(tree[node][0] != 0){
        //         ans = min(ans, 1 + dfs(tree[node][0], ind+1));
        //     }
            
        //     // i can flip it to up and go to parent if it is not 1
        //     if(par[node] != 1){
        //         ans = min(ans, 1 + dfs(par[node], ind+1));
        //     }
            
        //     // if right exist and i go to it
        //     if(tree[node][1] != 0){
        //         ans = min(ans, 0 + dfs(tree[node][1], ind+1));
        //     }
        //     else{
        //         // skip
        //         ans = min(ans, dfs(node, ind+1));
        //     }
        // }
        
        
        // if(s[ind] == 'U'){
        //     // i can flip it to left and go to left
        //     if(tree[node][0] != 0){
        //         ans = min(ans, 1 + dfs(tree[node][0], ind+1));
        //     }
            
        //     // i can flip it to right and go to right
        //     if(tree[node][1] != 0){
        //         ans = min(ans, 1 + dfs(tree[node][1], ind+1));
        //     }
            
        //     // if par exist and i go to par
        //     if(par[node] != 1){
        //         ans = min(ans, 0 + dfs(par[node], ind+1));
        //     }
        //     else{
        //         // skip
        //         ans = min(ans, dfs(node, ind+1));
        //     }
        // }
        
        
        // skip
        if((s[ind]=='U' && par[node]==1) || (s[ind]=='L' && tree[node][0]==0) || (s[ind]=='R' && tree[node][1]==0)){
            ans = min(ans, dfs(node, ind+1));
        }
        
        // left exists
        if(tree[node][0] != 0){
            int cost = (s[ind] != 'L');
            
            ans = min(ans, cost + dfs(tree[node][0], ind+1));
        }
        
        // right exists
        if(tree[node][1] != 0){
            int cost = (s[ind] != 'R');
            
            ans = min(ans, cost + dfs(tree[node][1], ind+1));
        }
        
        // if up
        if(node != 1){
            int cost = (s[ind] != 'U');
            
            ans = min(ans, cost + dfs(par[node], ind+1));
        }
        
        
        return ans;
    };
    
    cout << dfs(1, 0) << endl;
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