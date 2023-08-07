// // // @Author : LKE
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define अंतः_अस्ति_प्रारंभः() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl "\n"
#define pb push_back
#define ff first
#define ss second
#define mkp make_pair
#define pi pair<int, int>
#define set_bits __builtin_popcountll     // ll
#define nmap unordered_map
#define nset unordered_set
#define CC continue
#define all(a) a.begin(),a.end()
#define i_max INT_MAX
#define i_min INT_MIN
#define me(x, y) memset(x, y, sizeof(x))
#define sout cout << fixed << setprecision(10)
#define sz(x) ((int)(x).size())
#define PI 3.14159265358979323846
#define FOR(i,j,n) for(int i = j; i < n; i++)


template<typename T1> void _printV(vector<T1> &v1) {for (auto &it : v1) {cout << it << " ";}   cout << nl;}
template<typename T1, typename T2> void _printM(map<T1, T2> &m1) {for (auto &it : m1) {cout << it.ff << " " << it.ss << nl;}}
template<typename T1, typename T2> void _printP(vector<pair<T1, T2>> &v1) {for (auto &it : v1) {cout << it.ff << " " << it.ss << nl;}}
template<typename T1, typename T2> void read(vector<T1> &v1, T2 n) {for (T2 i = 0; i < n; i++) {T1 c;  cin >> c; v1.pb(c);}}
template<typename T1> void print(T1 a) {cout << a << nl;}
void out(bool b1) {cout << (b1 ? "Yes\n" : "No\n");}
void google(int p) {cout << "Case #" << p << ": ";}
long long power(long long x, long long y) {long long temp; if (y == 0) {return 1;} temp = power(x, y / 2); if (y % 2 == 0) {return temp * temp;} else {if (y > 0) {return x * temp * temp;} else {return (temp * temp) / x;}}}
bool isPrime(ll n) {if (n <= 1) {return 1;} for (int i = 2; i * i <= n; i++) {if (n % i == 0) {return 0;}} return 1;}
int findMaxXOR(int a) { int max_xor = pow(2, floor(log2(a) + 1)) - 1; return max_xor;}
template<typename T1, typename T2> void swapNum(T1 &a, T2 & b) {a ^= b; b ^= a; a ^= b;}
string dis = "ULDR";
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isValidDirection(int X, int Y, int n, int m) {return (X >= 0 && Y >= 0 && X < n && Y < m);}
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    अंतः_अस्ति_प्रारंभः()
    int test_case = 1;
    cin >> test_case;
    while (test_case--) {
        ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;       
 
    }
    return 0;
}

