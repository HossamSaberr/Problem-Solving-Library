namespace {
    // fast a*b mod m
    int mod_mul(int a, int b, int m) {
        return (int)((unsigned __int128)a * b % m);
    }
    // fast a^e mod m
    int mod_pow(int a, int e, int m) {
        int r = 1;
        while (e) {
            if (e & 1) r = mod_mul(r, a, m);
            a = mod_mul(a, a, m);
            e >>= 1;
        }
        return r;
    }
    // Miller–Rabin deterministic for 64‑bit
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int p : {2,3,5,7,11,13,17,19,23,29,31,37})
            if (n % p == 0) return n == p;
        int d = n - 1, s = 0;
        while (!(d & 1)) { d >>= 1; ++s; }
        for (int a : {2,325,9375,28178,450775,9780504,1795265022}) {
            if (a % n == 0) continue;
            int x = mod_pow(a, d, n);
            if (x == 1 || x == n-1) continue;
            bool comp = true;
            for (int r = 1; r < s; ++r) {
                x = mod_mul(x, x, n);
                if (x == n-1) { comp = false; break; }
            }
            if (comp) return false;
        }
        return true;
    }
    // Pollard’s Rho
    mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int pollard(int n) {
        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;
        int c = uniform_int_distribution<int>(1, n-1)(rng);
        int x = uniform_int_distribution<int>(0, n-1)(rng), y = x, d = 1;
        auto f = [&](int v){ return (mod_mul(v, v, n) + c) % n; };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y), n);
        }
        return (d == n ? pollard(n) : d);
    }
    void factorRec(int n, map<int,int>& M) {
        if (n == 1) return;
        if (isPrime(n)) {
            M[n]++;
        } else {
            int d = pollard(n);
            factorRec(d, M);
            factorRec(n/d, M);
        }
    }
}

vector<int> generatePermutationForOrder(int k) {
    if (k == 1) {
        // identity on one card
        return {0};
    }
    // factor k
    map<int,int> fac;
    factorRec(k, fac);

    const int NMAX = 100000;
    vector<int> cycles;
    int total = 0;
    // for each prime^exp, make one cycle of length p^exp
    for (auto &pr : fac) {
        int p = pr.first;
        int e = pr.second;
        int pe = 1;
        for (int i = 0; i < e; i++) {
            if (pe > NMAX / p) return {};
            pe *= p;
        }
        cycles.push_back(pe);
        total += pe;
        if (total > NMAX) return {};
    }

    int n = (int)total;
    vector<int> perm(n, -1);
    int cur = 0;
    for (int L : cycles) {
        int len = (int)L;
        // build a single cycle of length len on positions [cur..cur+len-1]
        for (int i = 0; i < len-1; i++) {
            perm[cur + i] = cur + i + 1;
        }
        perm[cur + len - 1] = cur;
        cur += len;
    }
    return perm;
}