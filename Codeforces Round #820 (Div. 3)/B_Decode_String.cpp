#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    int t1; cin >> t1;
    while (t1--)
    {
        int n; cin >> n;
        string t; cin >> t;
        string s = "";
        for (int i = 0; i < n;)
        {
            if (t[i + 2] != '0')
            {
                string s1 = t.substr(i, 1);
                stringstream strToint(s1);
                int x = 0;
                strToint >> x; x = x + 96;
                char ch = char(x);
                s = s + ch;
                i += 1;
            }
            else
            {
                if (t[i + 3] == '0')
                {
                    string s1 = t.substr(i, 1);
                    stringstream strToint(s1);
                    int x = 0;
                    strToint >> x; x = x + 96;
                    char ch = char(x);
                    s = s + ch;
                    i += 1;
                    continue;
                }
                string s1 = t.substr(i, 2);
                stringstream strToint(s1);
                int x = 0;
                strToint >> x; x = x + 96;
                char ch = char(x);
                s = s + ch;
                i += 3;
            }
        }
        cout << s << endl;
    }
}