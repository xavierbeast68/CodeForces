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
 * URL : https://codeforces.com/contest/1845/problem/D
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


//*****************************************************TEMPLATE START*****************************************************************

#pragma GCC optimize("O3,Ofast,unroll-loops")

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio                                      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl                                        '\n'
#define cendl                                       cout << endl;
#define int                                         long long
using ll                                            = long long;
using ull                                           = unsigned long long;
using lld                                           = long double;
typedef pair<int, int>                              pi;
typedef pair<ll, ll>                                pll;
typedef vector<int>                                 vi;
typedef vector<ll>                                  vl;
typedef vector<pi>                                  vpi;
typedef vector<pll>                                 vpll;
typedef vector<vi>                                  vvi;
typedef vector<vl>                                  vvl;
typedef vector<vpi>                                 vvpi;
typedef vector<vpll>                                vvpll;
typedef vector<bool>                                vb;


constexpr ll MOD1                                   = 1e9 + 7; //1000000007
constexpr ll MOD2                                   = 1e9 + 9; //1000000009
constexpr ll MOD3                                   = 998244353;
constexpr lld EPS                                   = 1e-9;
constexpr lld PI                                    = 3.1415926535897932384626;
#define inf                                         INT_MAX
#define minf                                        INT_MIN

#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)

#define pb                                          push_back
#define ppb                                         pop_back
#define sz(x)                                       (int)(x).size()
#define all(x)                                      begin(x), end(x)
#define mp(x,y)                                     make_pair(x,y)
#define lb(arr, x)                                  lower_bound(arr.begin(), arr.end(), x) - arr.begin();
#define ub(arr, x)                                  upper_bound(arr.begin(), arr.end(), x) - arr.begin();
#define uniq(x)                                     (x).erase(unique(all(x)), (x).end())
#define getunique(v)                                {sort(all(v)); v.erase(unique(all(v)), v.end());} // for Vector v

/*------------------------------------------------------Read & Print Methods------------------------------------------------------*/

#define read(x)                                     cin >> x;    
#define readInt(x)                                  int x; cin >> x; // reads long long
#define readStr(x)                                  string x; cin >> x; // reads string(word)
#define readLine(x)                                 string x; getline(cin, x); // reads string(sentence)
#define print(x)                                    cout<<(x)<<" "
#define println(x)                                  cout<<(x)<<endl

// Vector Read & Print ->
// template <class T> vector<T> readvector(T n) { vector<T> arr(n); for (int i = 0; i < n; i++) {cin >> arr[i];} return arr;}   // vector<ll> arr = readvector(n);
// template <class T> void printvector(vector<T> arr) {for (int i = 0; i < (int)arr.size(); i++) {cout << arr[i] << " ";} cout << endl;}   // printvector(arr, n);

// Streams ->
template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a){in >> a.F >> a.S;return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a){os << a.F << " " << a.S;return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){for(int i = 0 ; i < sz(a) ; i++){if(i != 0){os << ' ';}os << a[i];}return os;}

//InputOutputError_From/To_File ->
void file_io()
{
// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


/*----------------------------------------------------------------PBDS----------------------------------------------------------------*/

// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;     // ordered_set <T> a; (work as ordered_set) // ordered_set <pair<T, T>> a; (ordered set of pairs (can also work as ordered_map))
// template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;      // multi_ordered_set <T> a; // multi_ordered_set <pair<T,T>> a;
// order_of_key(k): Returns the number of elements strictly smaller than k.
// find_by_order(k): Returns the address of the element at kth index in the set while using zero-based indexing, i.e the first element is at index zero.


/*--------------------------------------------------------------Debugger--------------------------------------------------------------*/
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

// void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
// void _print(auto t) {cerr << *t;} // for ordered_set

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
// template <class T> void _print(ordered_set<T> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]";}
// void _print(ordered_set v) {cerr << "[ "; for (int i=0 ; i<(int)v.size();i++) {_print(v.find_by_order(i)); cerr << " ";} cerr << "]";}

/*------------------------------------------------------Functions------------------------------------------------------*/

ll gcd(ll a, ll b)                                  {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                                  {return a / gcd(a, b) * b;}
ll ceil_div(ll a, ll b)                             {return a % b == 0 ? a / b : a / b + 1;}
ll countDigit(ll n)                                 {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b)                      {return log2(a) / log2(b);}
ll isPowerof2(ll x)                                 {return (x && !(x & (x - 1)));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a)                                 {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)
ll factorial(const int& p)                          {if (p <= 1) {return 1;} return p * factorial(p - 1);}
double nCr(ll n, ll r)                              {double sum = 1; for(int i = 1; i <= r; ++i){sum = sum * (n - r + i) / i;} return sum;}
ll binpow(ll a , ll b,ll mod)                       {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % mod, b / 2, mod);} else {return (a * binpow((a * a) % mod, b / 2, mod)) % mod;}}    // binary exponentiation
ll mod_inv(ll x, ll mod)                            {return binpow(x, mod-2, mod);}    

ll _mod(ll x, ll mod)                               {return (((x) % mod + mod) % mod);}
ll mod_add(ll a, ll b, ll mod)                      {a = a % mod; b = b % mod; return (_mod(a+b, mod));}
ll mod_mul(ll a, ll b, ll mod)                      {a = a % mod; b = b % mod; return (_mod(a*b, mod));}
ll mod_sub(ll a, ll b, ll mod)                      {a = a % mod; b = b % mod; return (_mod(a-b, mod));}
ll mod_div(ll a, ll b, ll mod)                      {return _mod(_mod(a, mod) * _mod(mod_inv(b, mod), mod), mod);}

vector<string> split(string s, char delimeter)      {vector <string> tokens; stringstream check1(s); string intermediate; while (getline(check1, intermediate, delimeter)) { tokens.push_back(intermediate); } return tokens;}
ll stringToNo(string s)                             {stringstream din(s); ll x; din >> x; return x;}
void toLower(string& s)                             {transform(s.begin(), s.end(), s.begin(), ::tolower);}
void toUpper(string& s)                             {transform(s.begin(), s.end(), s.begin(), ::toupper);}


// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r)                      {return uniform_int_distribution<ll>(l, r)(rng); }

// Prime utility
bool isPrime(ll n)                                  {if (n == 2 || n == 3) {return true;} if (n <= 1 || n % 2 == 0 || n % 3 == 0) {return false;} for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) {return false;}} return true;}

int sz = 1e6 + 5;
bool PrimeSieve[1000005]; // 1e6+5
void buildSieve(){
    for (int i = 2; i <= sz; i++)
        PrimeSieve[i] = 1;
    PrimeSieve[0] = 0; //
    PrimeSieve[1] = 0; // 1 is neither prime nor composite
    for (int i = 2; i < sz; i++){
        if (PrimeSieve[i] == 0)
            continue; // the current number itself is composite
        for (int j = 2; j * i < sz; j++){
            PrimeSieve[i * j] = 0;
        }
    }
}

/*
//--- Custom Hash(for random hashing)---
// https://codeforces.com/blog/entry/62393
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T> // Key should be integer type
using safe_set = unordered_set<T, custom_hash>;
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;
*/

//--for grid operations--
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

// #pragma warning restore format

//*********************************************************TEMPLATE ENDS***************************************************************

/*-------------------------------------------------------||||||||||-----------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
                                        |H| |e| |r| |e|   |w| |e|   |g| |o| |!| |!| |!|
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------||||||||||------------------------------------------------------------------------*/


/*
! THINGS TO KEEP IN MIND BEFORE SUBMITTTING
* Always Check Which MOD it is Asking For
* Unique function return iterator Then We can resize the container
* Look for Possible Edge Cases
* int overflows, array bounds, etc.
* https://oeis.org/ Sequence Related Problem
* DO NOT GET STUCK ON ONE APPROACH
*/

/*
    *Thought Process*
    !---------------!

    https://www.youtube.com/watch?v=TrR6KEd0XMU
    https://codeforces.com/blog/entry/117791
*/

void solve(){
    //--Let's Code--

    readInt(n);
    vi arr(n);
    cin >> arr;

    int i = 0, maxi = 0, curr = 0, max_diff = 0, ans = 0;

    while(i < n){

        curr += arr[i];
        maxi = max(maxi, curr);

        if(max_diff < maxi - curr){
            max_diff = maxi - curr;
            ans = maxi;
        }
        i++;
    }

    println(ans);
}


//---------------------------------------- DON'T TOUCH IT ----------------------------------------


// signed main(signed argc, char const *argv[])
signed main(){
    fastio;

    cout << fixed << setprecision(10);
    // file_io();
    auto start = high_resolution_clock::now();

    //testcases=1: default value for single test case
    int testcases = 1;
    cin >> testcases;
    while (testcases--){
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    #ifdef XAVIERBEAST
        cerr << endl << "Time: " << (float)duration.count()/1000000 << " s" << endl;
    #endif

    return 0;
}