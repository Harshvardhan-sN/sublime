#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fnf() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl "\n"
#define pb push_back
#define ff first
#define ss second
#define bits __builtin_popcountll
#define nmap unordered_map
#define nset unordered_set
#define br break
#define all(a) a.begin(),a.end()
#define i_max INT_MAX
#define i_min INT_MIN
#define me(x) memset(x,-1,sizeof(x))
#define sout cout << fixed << setprecision(6)
#define sz(x) ((int)(x).size())
#define PI 3.14159265358979323846
#define FOR(i,j,n) for(int i = j; i < n; i++)

const ull N = 1e9;
const int MOD = 1e7 + 1;
const ull mod = 1e9 + 7;

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
void google(ll p) {
	cout << "Case #" << p << ": ";
}

int number_digit(int n) {
	return floor(log10(n) + 1);
}

void out(bool b1) {
	cout << (b1 ? "YES\n" : "NO\n");
}

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
	return p1.ff < p2.ff;
}


int main() {
	fnf();

	int t;
	cin >> t;
	while (t--) {
		// ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
		int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;



	}

	return 0;

}