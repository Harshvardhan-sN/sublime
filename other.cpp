// #include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <climits>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fnf() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl "\n"
#define pb emplace_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll     // ll
#define nmap unordered_map
#define nset unordered_set
#define CC continue
#define all(a) a.begin(),a.end()
#define i_max INT_MAX
#define i_min INT_MIN
#define me(x) memset(x,1,sizeof(x))
#define sout cout << fixed << setprecision(6)
#define sz(x) ((int)(x).size())
#define PI 3.14159265358979323846
#define FOR(i,j,n) for(int i = j; i < n; i++)

const ll MOD = 1e9 + 7;

template<typename T1> void _printV(vector<T1> &v1) {
    for (auto &it : v1) {
        cout << it << " ";
    }   cout << nl;
}
template<typename T1, typename T2> void _printM(map<T1, T2> &m1) {
    for (auto &it : m1) {
        cout << it.ff << " " << it.ss << nl;
    }
}
template<typename T1, typename T2> void _printP(vector<pair<T1, T2>> &v1) {
    for (auto &it : v1) {
        cout << it.ff << " " << it.ss << nl;
    }
}
template<typename T1, typename T2> void read(vector<T1> &v1, T2 n) {
    for (T2 i = 0; i < n; i++) {
        T1 c;  cin >> c;
        v1.pb(c);
    }
}
void out(bool b1) {
    cout << (b1 ? "YES\n" : "NO\n");
}
void google(ll p) {
    cout << "Case #" << p << ": ";
}

ll bd(string n) {
    string num = n;
    ll dec_value = 0;
    ll base = 1;
    ll len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

ll power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}


bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.ff < p2.ff)     return true;
    return p1.ss > p2.ss;
}


int main() {
    fnf();
    long long tc = 1;

    int t;
    cin >> t;
    while (t--) {
        // int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
        ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;



    }


    return 0;
}