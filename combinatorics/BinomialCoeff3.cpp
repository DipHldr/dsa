#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;        
const int MOD = 1e9 + 7; 

long long fact[MAXN];
long long inv_fact[MAXN];

// Modular exponentiation: computes (base^exp) % mod
long long mod_pow(long long base, long long exp, int mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Precompute factorials and inverse factorials modulo MOD
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAXN - 1] = mod_pow(fact[MAXN - 1], MOD - 2, MOD); // Fermat's Little Theorem
    for (int i = MAXN - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

// function for Computing C(n, k) % MOD
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    precompute();

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int n, k;
        cout << "Enter n and k: ";
        cin >> n >> k;
        cout << "C(" << n << ", " << k << ") % " << MOD << " = " << C(n, k) << '\n';
    }

    return 0;
}
