struct Matrix {
    int n;
    int *a;

    // construct n×n zero‑matrix
    Matrix(int _n): n(_n) {
        a = new int[n * n];
        memset(a, 0, sizeof(int) * n * n);
    }

    // initializer-list constructor
    Matrix(initializer_list<initializer_list<int>> init) : Matrix((int)init.size()) {
        int i = 0;
        for (auto &row : init) {
            int j = 0;
            for (auto v : row) {
                a[i * n + j++] = (v % MOD + MOD) % MOD;
            }
            ++i;
        }
    }

    // copy constructor
    Matrix(const Matrix &o): n(o.n) {
        a = new int[n * n];
        memcpy(a, o.a, sizeof(int) * n * n);
    }

    // assignment
    Matrix& operator=(const Matrix &o) {
        if (this != &o) {
            delete[] a;
            n = o.n;
            a = new int[n * n];
            memcpy(a, o.a, sizeof(int) * n * n);
        }
        return *this;
    }

    ~Matrix() { delete[] a; }

    // element access
    int& operator()(int i, int j) { return a[i * n + j]; }
    const int& operator()(int i, int j) const { return a[i * n + j]; }

    // identity matrix
    static Matrix identity(int n) {
        Matrix I(n);
        for (int i = 0; i < n; i++) I(i, i) = 1;
        return I;
    }

    // addition
    Matrix operator+(const Matrix &o) const {
        Matrix res(n);
        for (int i = 0; i < n * n; i++) {
            res.a[i] = a[i] + o.a[i];
            if (res.a[i] >= MOD) res.a[i] -= MOD;
        }
        return res;
    }

    // multiplication
    Matrix operator*(const Matrix &o) const {
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                long long v = (*this)(i, k);
                if (v == 0) continue;
                for (int j = 0; j < n; j++) {
                    res(i, j) = (res(i, j) + v * o(k, j)) % MOD;
                }
            }
        }
        return res;
    }

    // fast exponentiation
    Matrix pow(long long e) const {
        Matrix base = *this;
        Matrix result = identity(n);
        while (e > 0) {
            if (e & 1) result = result * base;
            base = base * base;
            e >>= 1;
        }
        return result;
    }

    // geometric series sum: I + A + A^2 + ... + A^e
    Matrix power_sum(long long e) const {
        if (e == 0) return identity(n);
        if (e & 1) {
            return power_sum(e-1) + pow(e);
        } else {
            long long k = e / 2;
            Matrix half = power_sum(k - 1);
            Matrix Ak = pow(k);
            return half + Ak + (Ak * half);
        }
    }
};