#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    int t; cin >> t;
    while (t--)
    {
        ll a, b, c, t1, t2;
        cin >> a >> b >> c;
        t1 = a - 1;
        t2 = (c > b ? (c - b) : (b - c)) + (c - 1);
        cout << (t1 == t2 ? "3" : (t1 < t2 ? "1" : "2")) << endl;
    }
}