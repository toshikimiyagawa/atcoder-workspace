#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using namespace atcoder;

// clang-format off
/* accelration */
// 高速バイナリ生成
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
struct Fast {
    Fast() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
    }
} fast;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i, n) for(ll i=n-1;i>=0;i--)
#define rrepd(i, n) for(ll i=n;i>=1;i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

// search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template<typename T>
inline bool vector_finder(std::vector<T> vec, T element, unsigned int search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance(vec.begin(), itr);
    if (index == vec.size() || index >= search_length) { return false; } else { return true; }
}

template<typename T>
inline void print(const vector<T> &v, string s = " ") {
    rep(i, v.size()) cout << v[i] << (i != (ll) v.size() - 1 ? s : "\n");
}

template<typename T, typename S>
inline void print(const pair<T, S> &p) { cout << p.first << " " << p.second << endl; }

template<typename T>
inline void print(const T &x) { cout << x << "\n"; }

template<typename T, typename S>
inline void print(const vector<pair<T, S>> &v) { for (auto &&p: v) print(p); }

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template<typename T>
inline bool chmin(T &a, const T &b) {
    bool compare = a > b;
    if (a > b) a = b;
    return compare;
}

template<typename T>
inline bool chmax(T &a, const T &b) {
    bool compare = a < b;
    if (a < b) a = b;
    return compare;
}

const ll INF = 1e18;
// clang-format on

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips:
// You use the default template now. You can remove this line by using your
// custom template)
int main() {
    map<ll, vll> x;
    ll N;
    cin >> N;
    ll bb = 0, b = 0, t = 0;
    rep(i, N) {
        bb = b;
        b = t;
        cin >> t;
        x[b].pb(bb);
        x[b].pb(t);
    }
    x[t].pb(b);
    x[t].pb(-1);
    x[-1].pb(t);
    x[-1].pb(-1);
    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll xx, xxx, xxxx;
        cin >> xx >> xxx;
        ll bbb, aaa;
        bbb = x[xxx][0];
        aaa = x[xxx][1];
        if (xx == 1) {
            cin >> xxxx;
            x[xxx][1] = xxxx;
            x[xxxx].pb(xxx);
            x[xxxx].pb(aaa);
            x[aaa][0] = xxxx;
        } else {
            x.erase(xxx);
            x[bbb][1] = aaa;
            x[aaa][0] = bbb;
        }
        // ll nxt = x[0][1];
        // bool sep = false;
        // while (nxt != -1) {
        //     if (sep) {
        //         cout << " ";
        //     } else {
        //         sep = true;
        //     }
        //     cout << nxt;
        //     nxt = x[nxt][1];
        // }
        // cout << endl;
    }
    ll nxt = x[0][1];
    bool sep = false;
    while (nxt != -1) {
        if (sep) {
            cout << " ";
        } else {
            sep = true;
        }
        cout << nxt;
        nxt = x[nxt][1];
    }
    cout << endl;
    // Failed to predict input format
    return 0;
}
