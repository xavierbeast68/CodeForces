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
 * URL : 
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

v<int> ind;

void pathOfLIS(vector<int> nums) {
        int n = nums.size();
        
        vector<int> sub, subIndex; // Store index instead of value for tracing path purpose
        vector<int> trace(n, -1); // trace[i] point to the index of previous number in LIS
        
        for (int i = 0; i < n; ++i) {
            
            if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
                if (!sub.empty()) 
                    trace[i] = subIndex[sub.size() - 1];
                sub.push_back(nums[i]);
                
                
                subIndex.push_back(i);
            } else {
                int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                if (idx > 0)
                    trace[i] = subIndex[idx - 1];
                sub[idx] = nums[i];
                
                
                subIndex[idx] = i;
            }
        }
        
        
        // vector<int> path;
        int t = subIndex[subIndex.size() - 1];
        while (t != -1) {
            ind.push_back(t);
            // path.push_back(nums[t]);
            t = trace[t];
        }
        // reverse(path.begin(), path.end());
        // return path;
    }

// <-------------------------- Solve Function -------------------------->

/*
    *Thought Process*
    !---------------!
    
*/

void solve(){
    cin >> n;
    vec.resize(n); ind.resize(0);
    cin >> vec;
    
    reverse(all(vec)); // reverse the array
    
    pathOfLIS(vec);
    
    // cout << vec << endl;
    reverse(all(ind));
    // cout << ind << endl;
    
    // cout << ind << endl;
    v<int> newVec(0);
    
    fo(i, 0, n-1){
        if(binary_search(all(ind), i) == false){
            newVec.push_back(vec[i]);
        }
    }
    // cout << newVec << endl;
    reverse(all(newVec));
    
    int cnt = 0;
    int len = newVec.size();
    for(int i = 0; i < len-1; i++){
        if(newVec[i] < newVec[i+1]) cnt++;
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