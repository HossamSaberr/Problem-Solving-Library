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
    bool canMake(long long x , int time = 0) {
        for (int i = 60; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;
            if (!b[i] || timer[i] < time) return false;
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

    // Returns the minimum value obtainable from 'val' using basis elements 
    // from index 'limit_bit' down to 0.
    int get_min_lim(int val, int limit_bit) {
        for (int i = limit_bit; i >= 0; i--) {
            if (!basis[i]) continue;
            // Greedy minimization: if XORing makes it smaller, do it
            val = min(val, val ^ basis[i]);
        }
        return val;
    }

    // Query: Maximize XOR sum such that result <= K
    long long query_max_constrained(long long K) {
        long long ans = 0;

        for (int i = 60; i >= 0; i--) {
            // Optimization: if basis[i] is 0, we can't change bit i anyway
            if (!basis[i]) continue;

            long long option_keep = ans;
            long long option_change = ans ^ basis[i];

            // Look ahead: What is the BEST CASE (smallest value) for each path?
            // We pass i - 1 because we can only use lower bits to fix the number later
            long long min_keep = get_min_lim(option_keep, i - 1);
            long long min_change = get_min_lim(option_change, i - 1);

            bool can_keep = (min_keep <= K);
            bool can_change = (min_change <= K);

            if (can_keep && can_change) {
                // If both paths are valid (can stay under K), 
                // pick the one that gives the larger value NOW.
                ans = max(option_keep, option_change);
            } else if (can_change) {
                // If we MUST change to stay under K (or to fit valid path)
                ans = option_change;
            } else {
                // If we MUST keep (or neither is valid, which implies K < 0 impossible)
                ans = option_keep;
            }
        }
        
        return ans; 
    }

    // Get MAX value using lower bits
    int get_max_lim(int val, int limit_bit) {
        for (int i = limit_bit; i >= 0; i--) {
            if (!basis[i]) continue;
            // If XORing makes it BIGGER, do it
            val = max(val, val ^ basis[i]);
        }
        return val;
    }
    
    // Find Minimum XOR sum such that result >= K
    int query_min_constrained(int K) {
        int ans = 0;
    
        for (int i = 60; i >= 0; i--) {
            if (!basis[i]) continue;
    
            int ch1 = ans;              // Option 1: Don't use basis[i]
            int ch2 = ans ^ basis[i];   // Option 2: Use basis[i]
    
            // Look Ahead: meaningful check
            // Can ch1 eventually reach >= K? We check its MAX potential.
            int max_potential_1 = get_max_lim(ch1, i - 1);
            int max_potential_2 = get_max_lim(ch2, i - 1);
    
            bool can_1 = (max_potential_1 >= K);
            bool can_2 = (max_potential_2 >= K);
    
            if (can_1 && can_2) {
                // Both paths can satisfy the constraint >= K.
                // Since we want the OVERALL MINIMUM, we pick the smaller current value.
                ans = min(ch1, ch2);
            } else if (can_1) {
                // Only ch1 can eventually reach K
                ans = ch1;
            } else {
                // Only ch2 can eventually reach K (we know at least one must be true from initial check)
                ans = ch2;
            }
        }
        return ans;
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



