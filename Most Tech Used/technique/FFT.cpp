struct FFT {
    // Bit-reversal permutation
    static void bitReverse(vector<complex<double>> &a) {
        int n = a.size(), logn = 0;
        while ((1 << logn) < n) logn++;
        vector<int> rev(n);
        for (int i = 0; i < n; i++) {
            int x = i, y = 0;
            for (int b = 0; b < logn; b++) {
                y = (y << 1) | (x & 1);
                x >>= 1;
            }
            rev[i] = y;
        }
        for (int i = 0; i < n; i++) {
            if (i < rev[i]) swap(a[i], a[rev[i]]);
        }
    }
 
    // FFT or inverse FFT
    static void transform(vector<complex<double>> &a, bool invert) {
        int n = a.size();
        bitReverse(a);
        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 *  acos(-1) / len * (invert ? -1 : 1);
            complex<double>  wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                complex<double> w(1);
                for (int j = 0; j < len/2; j++) {
                    complex<double> u = a[i+j];
                    complex<double> v = a[i+j+len/2] * w;
                    a[i+j] = u + v;
                    a[i+j+len/2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert) {
            for (auto &x : a)
                x /= n;
        }
    }
 
    // Multiply two integer-coefficient polys (result is exact convolution)
    static vector<long long> multiply(const vector<long long> &A,
                                      const vector<long long> &B) {
        int need = A.size() + B.size() - 1;
        int n = 1;
        while (n < need) n <<= 1;
        vector<complex<double>> fa(n), fb(n);
        for (int i = 0; i < (int)A.size(); i++)
            fa[i] = complex<double>(A[i], 0);
        for (int i = 0; i < (int)B.size(); i++)
            fb[i] = complex<double>(B[i], 0);
        transform(fa, false);
        transform(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];
        transform(fa, true);
 
        vector<long long> R(need);
        for (int i = 0; i < need; i++)
            R[i] = llround(fa[i].real());
        return R;
    }
};
 
// Raise the “boolean” polynomial base(x) to the k-th power.
// After each convolution we clamp coefficients to 0/1.
vector<long long> bin_pow(vector<long long> base, int exp) {
    vector<long long> result = {1};
    // cap on maximum degree we care about:
    const int MAXSUM = 1000 * 1000 + 5;
 
    while (exp > 0) {
        if (exp & 1) {
            result = FFT::multiply(result, base);
            if ((int)result.size() > MAXSUM)
                result.resize(MAXSUM);
            for (auto &v : result)
                if (v > 0) v = 1;
        }
        exp >>= 1;
        if (exp) {
            base = FFT::multiply(base, base);
            if ((int)base.size() > MAXSUM)
                base.resize(MAXSUM);
            for (auto &v : base)
                if (v > 0) v = 1;
        }
    }
    return result;
}