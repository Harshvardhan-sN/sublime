// #include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
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
#define pb push_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll     // ll
#define nmap unordered_map
#define nset unordered_set
#define CC continue
#define all(a) a.begin(),a.end()
#define i_max INT_MAX
#define i_min INT_MIN
#define me(x) memset(x,-1,sizeof(x))
#define sout cout << fixed << setprecision(6)
#define sz(x) ((int)(x).size())
#define PI 3.14159265358979323846
#define FOR(i,n) for(int i = 0; i < n; i++)

const ull N = 1e9;
const int MOD = 1e5 + 7;
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
template<typename T1> void read(vector<T1> &v1, long n) {
	for (int i = 0; i < n; i++) {
		T1 c;  cin >> c;
		v1.pb(c);
	}
}

class BigInt {
	string digits;
public:

	//Constructors:
	BigInt(unsigned long long n = 0);
	BigInt(string &);
	BigInt(const char *);
	BigInt(BigInt &);

	//Helper Functions:
	friend void divide_by_2(BigInt &a);
	friend bool Null(const BigInt &);
	friend int Length(const BigInt &);
	int operator[](const int)const;

	/* * * * Operator Overloading * * * */

	//Direct assignment
	BigInt &operator=(const BigInt &);

	//Post/Pre - Incrementation
	BigInt &operator++();
	BigInt operator++(int temp);
	BigInt &operator--();
	BigInt operator--(int temp);

	//Addition and Subtraction
	friend BigInt &operator+=(BigInt &, const BigInt &);
	friend BigInt operator+(const BigInt &, const BigInt &);
	friend BigInt operator-(const BigInt &, const BigInt &);
	friend BigInt &operator-=(BigInt &, const BigInt &);

	//Comparison operators
	friend bool operator==(const BigInt &, const BigInt &);
	friend bool operator!=(const BigInt &, const BigInt &);

	friend bool operator>(const BigInt &, const BigInt &);
	friend bool operator>=(const BigInt &, const BigInt &);
	friend bool operator<(const BigInt &, const BigInt &);
	friend bool operator<=(const BigInt &, const BigInt &);

	//Multiplication and Division
	friend BigInt &operator*=(BigInt &, const BigInt &);
	friend BigInt operator*(const BigInt &, const BigInt &);
	friend BigInt &operator/=(BigInt &, const BigInt &);
	friend BigInt operator/(const BigInt &, const BigInt &);

	//Modulo
	friend BigInt operator%(const BigInt &, const BigInt &);
	friend BigInt &operator%=(BigInt &, const BigInt &);

	//Power Function
	friend BigInt &operator^=(BigInt &, const BigInt &);
	friend BigInt operator^(BigInt &, const BigInt &);

	//Square Root Function
	friend BigInt sqrt(BigInt &a);

	//Read and Write
	friend ostream &operator<<(ostream &, const BigInt &);
	friend istream &operator>>(istream &, BigInt &);

	//Others
	friend BigInt NthCatalan(int n);
	friend BigInt NthFibonacci(int n);
	friend BigInt Factorial(int n);
};

BigInt::BigInt(string & s) {
	digits = "";
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(unsigned long long nr) {
	do {
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
}
BigInt::BigInt(const char *s) {
	digits = "";
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		if (!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(BigInt & a) {
	digits = a.digits;
}

bool Null(const BigInt& a) {
	if (a.digits.size() == 1 && a.digits[0] == 0)
		return true;
	return false;
}
int Length(const BigInt & a) {
	return a.digits.size();
}
int BigInt::operator[](const int index)const {
	if (digits.size() <= index || index < 0)
		throw("ERROR");
	return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b) {
	return a.digits == b.digits;
}
bool operator!=(const BigInt & a, const BigInt &b) {
	return !(a == b);
}
bool operator<(const BigInt&a, const BigInt&b) {
	int n = Length(a), m = Length(b);
	if (n != m)
		return n < m;
	while (n--)
		if (a.digits[n] != b.digits[n])
			return a.digits[n] < b.digits[n];
	return false;
}
bool operator>(const BigInt&a, const BigInt&b) {
	return b < a;
}
bool operator>=(const BigInt&a, const BigInt&b) {
	return !(a < b);
}
bool operator<=(const BigInt&a, const BigInt&b) {
	return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a) {
	digits = a.digits;
	return *this;
}

BigInt &BigInt::operator++() {
	int i, n = digits.size();
	for (i = 0; i < n && digits[i] == 9; i++)
		digits[i] = 0;
	if (i == n)
		digits.push_back(1);
	else
		digits[i]++;
	return *this;
}
BigInt BigInt::operator++(int temp) {
	BigInt aux;
	aux = *this;
	++(*this);
	return aux;
}

BigInt &BigInt::operator--() {
	if (digits[0] == 0 && digits.size() == 1)
		throw("UNDERFLOW");
	int i, n = digits.size();
	for (i = 0; digits[i] == 0 && i < n; i++)
		digits[i] = 9;
	digits[i]--;
	if (n > 1 && digits[n - 1] == 0)
		digits.pop_back();
	return *this;
}
BigInt BigInt::operator--(int temp) {
	BigInt aux;
	aux = *this;
	--(*this);
	return aux;
}

BigInt &operator+=(BigInt &a, const BigInt& b) {
	int t = 0, s, i;
	int n = Length(a), m = Length(b);
	if (m > n)
		a.digits.append(m - n, 0);
	n = Length(a);
	for (i = 0; i < n; i++) {
		if (i < m)
			s = (a.digits[i] + b.digits[i]) + t;
		else
			s = a.digits[i] + t;
		t = s / 10;
		a.digits[i] = (s % 10);
	}
	if (t)
		a.digits.push_back(t);
	return a;
}
BigInt operator+(const BigInt &a, const BigInt &b) {
	BigInt temp;
	temp = a;
	temp += b;
	return temp;
}

BigInt &operator-=(BigInt&a, const BigInt &b) {
	if (a < b)
		throw("UNDERFLOW");
	int n = Length(a), m = Length(b);
	int i, t = 0, s;
	for (i = 0; i < n; i++) {
		if (i < m)
			s = a.digits[i] - b.digits[i] + t;
		else
			s = a.digits[i] + t;
		if (s < 0)
			s += 10,
			     t = -1;
		else
			t = 0;
		a.digits[i] = s;
	}
	while (n > 1 && a.digits[n - 1] == 0)
		a.digits.pop_back(),
		                  n--;
	return a;
}
BigInt operator-(const BigInt& a, const BigInt&b) {
	BigInt temp;
	temp = a;
	temp -= b;
	return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b)
{
	if (Null(a) || Null(b)) {
		a = BigInt();
		return a;
	}
	int n = a.digits.size(), m = b.digits.size();
	vector<int> v(n + m, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			v[i + j] += (a.digits[i] ) * (b.digits[j]);
		}
	n += m;
	a.digits.resize(v.size());
	for (int s, i = 0, t = 0; i < n; i++)
	{
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		a.digits[i] = v[i] ;
	}
	for (int i = n - 1; i >= 1 && !v[i]; i--)
		a.digits.pop_back();
	return a;
}
BigInt operator*(const BigInt&a, const BigInt&b) {
	BigInt temp;
	temp = a;
	temp *= b;
	return temp;
}

BigInt &operator/=(BigInt& a, const BigInt &b) {
	if (Null(b))
		throw("Arithmetic Error: Division By 0");
	if (a < b) {
		a = BigInt();
		return a;
	}
	if (a == b) {
		a = BigInt(1);
		return a;
	}
	int i, lgcat = 0, cc;
	int n = Length(a), m = Length(b);
	vector<int> cat(n, 0);
	BigInt t;
	for (i = n - 1; t * 10 + a.digits[i]  < b; i--) {
		t *= 10;
		t += a.digits[i] ;
	}
	for (; i >= 0; i--) {
		t = t * 10 + a.digits[i];
		for (cc = 9; cc * b > t; cc--);
		t -= cc * b;
		cat[lgcat++] = cc;
	}
	a.digits.resize(cat.size());
	for (i = 0; i < lgcat; i++)
		a.digits[i] = cat[lgcat - i - 1];
	a.digits.resize(lgcat);
	return a;
}
BigInt operator/(const BigInt &a, const BigInt &b) {
	BigInt temp;
	temp = a;
	temp /= b;
	return temp;
}

BigInt &operator%=(BigInt& a, const BigInt &b) {
	if (Null(b))
		throw("Arithmetic Error: Division By 0");
	if (a < b) {
		a = BigInt();
		return a;
	}
	if (a == b) {
		a = BigInt(1);
		return a;
	}
	int i, lgcat = 0, cc;
	int n = Length(a), m = Length(b);
	vector<int> cat(n, 0);
	BigInt t;
	for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
		t *= 10;
		t += a.digits[i];
	}
	for (; i >= 0; i--) {
		t = t * 10 + a.digits[i];
		for (cc = 9; cc * b > t; cc--);
		t -= cc * b;
		cat[lgcat++] = cc;
	}
	a = t;
	return a;
}
BigInt operator%(const BigInt &a, BigInt &b) {
	BigInt temp;
	temp = a;
	temp %= b;
	return temp;
}

BigInt &operator^=(BigInt & a, const BigInt & b) {
	BigInt Exponent, Base(a);
	Exponent = b;
	a = 1;
	while (!Null(Exponent)) {
		if (Exponent[0] & 1)
			a *= Base;
		Base *= Base;
		divide_by_2(Exponent);
	}
	return a;
}
BigInt operator^(BigInt & a, BigInt & b) {
	BigInt temp(a);
	temp ^= b;
	return temp;
}

void divide_by_2(BigInt & a) {
	int add = 0;
	for (int i = a.digits.size() - 1; i >= 0; i--) {
		int digit = (a.digits[i] >> 1) + add;
		add = ((a.digits[i] & 1) * 5);
		a.digits[i] = digit;
	}
	while (a.digits.size() > 1 && !a.digits.back())
		a.digits.pop_back();
}

BigInt sqrt(BigInt & a) {
	BigInt left(1), right(a), v(1), mid, prod;
	divide_by_2(right);
	while (left <= right) {
		mid += left;
		mid += right;
		divide_by_2(mid);
		prod = (mid * mid);
		if (prod <= a) {
			v = mid;
			++mid;
			left = mid;
		}
		else {
			--mid;
			right = mid;
		}
		mid = BigInt();
	}
	return v;
}

BigInt NthCatalan(int n) {
	BigInt a(1), b;
	for (int i = 2; i <= n; i++)
		a *= i;
	b = a;
	for (int i = n + 1; i <= 2 * n; i++)
		b *= i;
	a *= a;
	a *= (n + 1);
	b /= a;
	return b;
}

BigInt NthFibonacci(int n) {
	BigInt a(1), b(1), c;
	if (!n)
		return c;
	n--;
	while (n--) {
		c = a + b;
		b = a;
		a = c;
	}
	return b;
}

BigInt Factorial(int n) {
	BigInt f(1);
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

istream &operator>>(istream &in, BigInt&a) {
	string s;
	in >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (!isdigit(s[i]))
			throw("INVALID NUMBER");
		a.digits[n - i - 1] = s[i];
	}
	return in;
}

ostream &operator<<(ostream &out, const BigInt &a) {
	for (int i = a.digits.size() - 1; i >= 0; i--)
		cout << (short)a.digits[i];
	return cout;
}


ull pow_x_mod(ll a, ll b, ll m) {
	ll res = 1;
	a %= m;
	while (b) {
		if (b & 1)     res = ((res % m) * (a % m)) % m;
		a = ((a % m) * (a % m)) % m;
		b >>= 1;
	}
	return res;
}

ull MOD_X(ull a, ull n, ull m) {
	ull x = 0, y = a % m;
	while (n) {
		if (n & 1)      x = (x + y) % m;
		y = (y << 1) % m;
		n >>= 1;
	}
	return x % m;
}


ull power(ull a, ull n, ull m) {
	if (n == 0) return 1;
	if (n == 1) return a % m;
	ull c = power(a, n / 2, m);
	ull p = MOD_X(c % m, c % m, m);
	if (n % 2 == 0) return p;
	return (MOD_X(p, a, m));
}


void prime_factor(ll n) {
	ull ans1 = 0;
	for (ull i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ull c = 0;
			while (n % i == 0) {
				c++;
				n /= i;
			}
			while (c--) {
				cout << i << " ";
			}
		}
	}
	if (n > 1)      cout << n;
	// return ans1;
}
vector<ll> p1;
void is_prime(ull n) {
	if (n == 1) {
		p1.pb(1);
		return;
	}

	for (ull i = 2; i * i <= n; i++) {
		if (n % i == 0)     p1.pb(i);
	}
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}


ll msb(ll n) {
	if (n == 0)    return n;
	ll x = 1;
	while (n >> x)     n++;
	return x;
}

ull highestPowerof2(ull x) {

	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;

	return x ^ (x >> 1);
}

vector<int> lele;
char prime[MOD];
void sieve() {
	prime[0] = prime[1] = 1;

	for (ll i = 2; i * i <= MOD; i++) {
		if (!prime[i]) {
			for (ll j = i * i; j <= MOD; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (int i = 0; i <= MOD; i++) {
		if (!prime[i])   lele.pb(i);
	}
}


int main() {
	fnf();


	return 0;

}
