struct XorBasis {
    long long b[61];// basis vectors for each bit
    int r;  // current size/rank of the basis
    int timer[61]; // timestamps for max_xor/min_xor queries

    XorBasis() {
        for (int i = 0; i <= 60; i++) b[i] = 0 , timer[i] = 0;
        r = 0;
    }

    // Add a number x to the basis
    // Optional 'time' parameter can be used for selective queries later
    void add(long long x , int time = 0) {
        for (int i = 60; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;
            if (!b[i]) {
                b[i] = x;
                timer[i] = time;
                r++;
                return;
            }
            // if (timer[i] < time) {
            //     swap(b[i], x);
            //     swap(timer[i], time);
            // }
            x ^= b[i];
        }
    }

    // Reduce the basis to upper-triangular form
    void reduceBasis() {
        for (int i = 60; i >= 0; i--) {
            if (!b[i]) continue;
            for (int j = i-1; j >= 0; j--) {
                if (b[j] && (b[i] & (1LL << j)))
                    b[i] ^= b[j];
            }
        }
    }

    // Check if x can be represented as XOR of some subset of basis elements
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

    // Compute the maximum XOR achievable by XORing any subset with x
    // Optional 'time' allows to consider only basis elements added after a certain time
    long long max_xor(long long x=0, int time=0) {
        for(int i = 60; i >= 0; i--) {
            if(timer[i] < time) continue;
            x = max(x, x ^ b[i]);
        }
        return x;
    }

    long long getMin() {
        for (int i = 0; i <= 60; i++)
            if (b[i]) return b[i];
        return 0;
    }

    // Compute the minimum XOR achievable by XORing any subset with x
    // Optional 'time' allows to consider only basis elements added after a certain time
    long long min_xor(long long x=0, int time=0) {
        for(int i = 60; i >= 0; i--) {
            if(timer[i] < time) continue;
            x = min(x, x ^ b[i]);
        }
        return x;
    }

    int size() {
        return r;
    }

    // How many distinct subset XORs
    long long countSubsets() {
        return 1LL << r;
    }

    // Return the k-th smallest subset XOR
    long long kth(long long k) { // 0-based
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

    // Count the number of distinct subset XORs that are less than x
    long long count_lt(long long x) {
        if(x == 0) return 0;
        long long ans = 0;
        long long cnt = 1LL << r;
        long long mask = 0;
        for(int i = 60; i >= 0; i--) {
            if(b[i]) {
                if((x >> i) & 1) {
                    ans += (cnt >> 1);
                    if(!(mask >> i & 1)) mask ^= b[i];
                } else {
                    if(mask >> i & 1) mask ^= b[i];
                }
                cnt >>= 1;
            } else {
                if(((x >> i) & 1) != ((mask >> i) & 1)) {
                    if((x >> i) & 1) return ans + cnt;
                    else return ans;
                }
            }
        }
        return ans;
    }

    // Return the basis as a vector
    vector<long long> buildList()  {
        vector<long long> res;
        for (int i = 0; i <= 60; ++i)
            if (b[i]) {
                res.push_back(b[i]);
            }
        return res;
    }

    // Get any subset XOR closest to a target
    long long getClosest(long long x)  {
        long long res = x;
        for (int i = 60; i >= 0; --i) {
            if (!b[i]) {
                continue;
            }
            if ((res ^ b[i]) < res){
                res ^= b[i];
            }
        }
        return res;
    }

    // Apply AND to all basis elements and rebuild the basis
    void AND(long long x) {
        r = 0;
        vector<long long> upd;
        for (int i = 60; i >= 0; i--) {
            b[i] &= x;
            if (b[i]) upd.push_back(b[i]);
            b[i] = 0;
            timer[i] = 0;
        }
        for (auto val : upd)
            add(val);
    }

    // Apply OR to all basis elements and rebuild the basis
    void OR(long long x) {
        r = 0;
        vector<long long> upd;
        for (int i = 60; i >= 0; i--) {
            b[i] |= x;
            if (b[i]) upd.push_back(b[i]);
            b[i] = 0;
            timer[i] = 0;
        }
        for (auto val : upd)
            add(val);
    }

    void merge(const XorBasis &other) {
        for (int i = 0; i <= 60; i++)
            if (other.b[i])
                add(other.b[i]);
    }
};
