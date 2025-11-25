struct XorBasis {
    long long b[61];
    int r;

    XorBasis() {
        for (int i = 0; i <= 60; i++) b[i] = 0;
        r = 0;
    }

    void add(long long x) {
        for (int i = 60; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;
            if (!b[i]) {
                b[i] = x;
                r++;
                return;
            }
            x ^= b[i];
        }
    }

    void reduceBasis() {
        for (int i = 60; i >= 0; i--) {
            if (!b[i]) continue;
            for (int j = i-1; j >= 0; j--) {
                if (b[j] && (b[i] & (1LL << j)))
                    b[i] ^= b[j];
            }
        }
    }

    bool canMake(long long x) {
        for (int i = 60; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;
            if (!b[i]) return false;
            x ^= b[i];
        }
        return true;
    }

    long long getMax() {
        long long ans = 0;
        for (int i = 60; i >= 0; i--)
            ans = max(ans, ans ^ b[i]);
        return ans;
    }

    long long getMin() {
        for (int i = 0; i <= 60; i++)
            if (b[i]) return b[i];
        return 0;
    }

    int size() {
        return r;
    }

    long long kth(long long k) {
        reduceBasis();
        long long v[61];
        int idx = 0;
        for (int i = 0; i <= 60; i++)
            if (b[i]) v[idx++] = b[i];

        long long ans = 0;
        for (int i = 0; i < idx; i++)
            if (k & (1LL << i))
                ans ^= v[i];
        return ans;
    }

    void merge(const XorBasis &other) {
        for (int i = 0; i <= 60; i++)
            if (other.b[i])
                add(other.b[i]);
    }
};