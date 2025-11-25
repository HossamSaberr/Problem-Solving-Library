int add(int x, int a) {
    return ((a % MOD) + (x % MOD)) % MOD;
}
int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
int sub(int a, int b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
int binpow(int x,int y,int m = MOD) {
    x %= m;
    int ans = 1;
    while (y > 0) {
        if (y & 1)ans = ((ans % m) * (x % m)) % m;
        x = ((x % m) * (x % m)) % m;
        y /= 2;
    }
    return ans;
}
int dive(int a, int b) {
    return mul(a, (binpow(b, MOD - 2)));
}
int inv_mod(int x) {
    return binpow(x, MOD - 2);
}
int gcd(int a , int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int fact[N];int inv[N];int invfact[N];
void pre() {
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = MOD - mul(inv[MOD % i], (MOD / i));
        invfact[i] = mul(inv[i], invfact[i - 1]);
    }
}
int nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return mul(fact[n], invfact[n - r]);
}
int nCr(int n, int r) {
    if (r > n || n < 0 || r < 0)return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
int nCr_OR(int n, int r) {
    if (r > n) { return 0; }
    if (r < 0) return 1;
    int res = 1;
    for (int i = 0; i < r; ++i) { res = (res * ((n - i) % MOD)) % MOD; }
    res = res * invfact[r] % MOD;
    return res;
}
int nPr_OR(int n, int r) {
    if (r > n) { return 0; }
    if (r < 0) return 1;
    int res = 1;
    for (int i = 0; i < r; ++i) { res = (res * ((n - i) % MOD)) % MOD; }
    return res;
}
 
int StarsandBars(int n , int r) {
    return nCr(n + r - 1 , r - 1);
}