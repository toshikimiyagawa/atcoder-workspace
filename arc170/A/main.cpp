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

// clang-format on
void solve(long long N, std::string S, std::string T) {
    std::cout << std::fixed << std::setprecision(10);
    vll X(N, 0);
    ll x = 0;
    ll y = 0;
    ll amin = N + 1, aamax = N + 1, bmax = -1, bbmin = -1;
    rep(i, N) {
        if (amin == N + 1 && T[i] == 'A') {
            amin = i;
        }
        if (T[i] == 'B') {
            bmax = i;
        }
        if (S[i] == 'A' && T[i] == 'B') {
            y--;
            // cout << y << endl;
            if (bbmin == -1) {
                bbmin = i;
            }
            if (y < 0) {
                x++;
                y = 0;
            }
        }
        if (S[i] == 'B' && T[i] == 'A') {
            y++;
            x++;
            // cout << y << endl;
            aamax = i;
        }
    }
    // cout << x << " " << amin << " " << bmax << " " << bbmin << " " << aamax
    //      << endl;
    if ((bbmin != -1 && amin > bbmin) || (aamax != N + 1 && bmax < aamax)) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips:
// You use the default template now. You can remove this line by using your
// custom template)
int main() {
    long long N;
    cin >> N;
    std::string S;
    cin >> S;
    std::string T;
    cin >> T;
    solve(N, S, T);
    return 0;
}
