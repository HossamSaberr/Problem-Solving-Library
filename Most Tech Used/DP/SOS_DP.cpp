const int MLOG = 20 , MAXN = 1 << MLOG;      
int sosdp[MAXN] , freq[MAXN];            

void forward1() { // sum over subsets -> dp[mask] = sum_{s ⊆ mask} original[s]
    for (int bit = 0; bit < MLOG; ++bit) {
        for (int mask = 0; mask < MAXN; ++mask) {
            if (mask & (1 << bit)) {
                sosdp[mask] += sosdp[mask ^ (1 << bit)];
            }
        }
    }
}

void backward1() { // inverse of forward1
    for (int bit = 0; bit < MLOG; ++bit) {
        for (int mask = MAXN - 1; mask >= 0; --mask) {
            if (mask & (1 << bit)) {
                sosdp[mask] -= sosdp[mask ^ (1 << bit)];
            }
        }
    }
}

void forward2() { // sum over supersets -> dp[mask] = sum_{s ⊇ mask} original[s]
    for (int bit = 0; bit < MLOG; ++bit) {
        for (int mask = MAXN - 1; mask >= 0; --mask) {
            if (mask & (1 << bit)) {
                sosdp[mask ^ (1 << bit)] += sosdp[mask];
            }
        }
    }
}

void backward2() { // inverse of forward2
    for (int bit = 0; bit < MLOG; ++bit) {
        for (int mask = 0; mask < MAXN; ++mask) {
            if (mask & (1 << bit)) {
                sosdp[mask ^ (1 << bit)] -= sosdp[mask];
            }
        }
    }
}