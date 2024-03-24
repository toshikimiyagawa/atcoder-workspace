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
void solve(long long N, std::vector<std::string> S) {
    std::cout << std::fixed << std::setprecision(10);
    vector<pair<ll, ll>> p;
    pair<pair<ll, ll>, pair<ll, ll>> x;
    vector<pair<pair<ll, ll>, pair<ll, ll>>> c;
    vector<pair<pair<ll, ll>, pair<ll, ll>>> o;
    vvll F(N, vll(N, 0));
    rep(i, N) {
        rep(j, N) {
            if (S[i][j] == 'P') {
                p.pb({i, j});
            } else if (S[i][j] == '#') {
                F[i][j] = 1;
            }
        }
    }
    // rep(i,N){
    //     rep(j,N){
    //         cout<<F[i][j];
    //     }
    //     cout<<endl;

    // }
    c.pb({p[0], p[1]});
    o.pb({p[0], p[1]});
    ll ret = -1;
    rep(i, N) {
        vector<pair<pair<ll, ll>, pair<ll, ll>>> n;
        cout << i << endl;
        rep(j, c.size()) {
            vector<pair<ll, ll>> m = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            cout << c[j].first.first << " " << c[j].first.second << " ";
            cout << c[j].second.first << " " << c[j].second.second << endl;
            rep(k, 4) {
                pair<ll, ll> x = c[j].first;
                pair<ll, ll> y = c[j].second;
                ll x1 = x.first + m[k].first;
                ll x2 = x.second + m[k].second;
                ll y1 = y.first + m[k].first;
                ll y2 = y.second + m[k].second;
                if (x1 != -1 && x1 != N && x2 != -1 && x2 != N &&
                    F[x1][x2] == 0) {
                    x = {x1, x2};
                }
                if (y1 != -1 && y1 != N && y2 != -1 && y2 != N &&
                    F[y1][y2] == 0) {
                    y = {y1, y2};
                }
                if (x == y) {
                    cout << i + 1 << endl;
                    return;
                }
                bool t = true;
                rep(l, o.size()) {
                    if (o[l].first == x && o[l].second == y) {
                        t = false;
                    }
                }
                if (t) {
                    n.pb({x, y});
                    o.pb({x, y});
                }
            }
        }
        swap(c, n);
    }
    cout << -1 << endl;
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips:
// You use the default template now. You can remove this line by using your
// custom template)
int main() {
    long long N;
    cin >> N;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}
