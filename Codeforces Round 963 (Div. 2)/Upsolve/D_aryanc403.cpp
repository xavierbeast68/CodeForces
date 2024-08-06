// https://codeforces.com/contest/1993/submission/274389157



/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
  https://codeforces.com/contest/4/submission/150120627
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC target ("sse,sse2,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define dbg(args...) 42;
    #define endl "\n"
#endif

// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second

using lli = long long int;
using mytype = long double;
using ii = pair<lli,lli>;
using vii = vector<ii>;
using vi = vector<lli>;

template <class T>
using ordered_set =  __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.

// namespace Re = std::ranges;
// namespace Ve = std::ranges::views;

const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
}

const lli INF = 0xFFFFFFFFFFFFFFFLL;
const lli SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// Ve::iota(1, 6) | Ve::transform([](int x) { return x * 2; }) | Ve::reverse | Ve::take(3)
lli T=1;
cin>>T;
while(T--)
{
    lli n,k;
    cin>>n>>k;
    vi a(n);
    for(auto &x:a)
        cin>>x;

    auto c=a;
    c.eb(-INF);
    c.eb(INF);
    sort(all(c));
    (c).erase(unique(all(c)),(c).end());

    const lli rem = ((n-1)%k)+1,reqGt=rem/2+1;
    dbg(rem,reqGt);

    vii dp(n,ii{-INF,0});
    auto chk=[&](const lli med)->bool{
        dp.clear();
        dp.resize(n,ii{-INF,0});
        for(lli j=0;j<n;j++){
            const lli cur = (a[j]>=med);
            const lli r=j/k,c=j%k;
            if(r)
                dp[j]=max(dp[j],dp[j-k]);
            if(c&&c<rem&&-dp[j-1].Y<rem)
                dp[j]=max(dp[j],ii{cur+dp[j-1].X,dp[j-1].Y-1});
            if(c==0)
                dp[j]=max(dp[j],ii{cur,-1});
        }
        dbg(med,dp);
        return dp[n-1].X>=reqGt;
    };

    lli l=0,r=sz(c);
    while(r-l>1){
        const lli m=(l+r)/2;
        if(chk(c[m]))
            l=m;
        else
            r=m;
    }
    cout<<c[l]<<endl;
}   aryanc403();
    return 0;
}
