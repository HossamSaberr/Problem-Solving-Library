 // LIS { 
    // **LIS**

    // O(N * N) Using Dp Itreative

    int lis(vector<int> const& a) {
        int n = a.size();
        vector<int> d(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i])
                    d[i] = max(d[i], d[j] + 1);
            }
        }

        int ans = d[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, d[i]);
        }
        return ans;
    }


    // How To Get That Seq O(N * N) Using Dp Itreative

    vector<int> lis(vector<int> const& a) {
        int n = a.size();
        vector<int> d(n, 1), p(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i] && d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }

        int ans = d[0], pos = 0;
        for (int i = 1; i < n; i++) {
            if (d[i] > ans) {
                ans = d[i];
                pos = i;
            }
        }

        vector<int> subseq;
        while (pos != -1) {
            subseq.push_back(a[pos]);
            pos = p[pos];
        }
        reverse(subseq.begin(), subseq.end());
        return subseq;
    }



    // O(N log N) Using Dp And BS

    int lis(vector<int> const& a) {
        int n = a.size();
        const int INF = 1e9;
        vector<int> d(n+1, INF);
        d[0] = -INF;

        for (int i = 0; i < n; i++) {
            int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[l-1] < a[i] && a[i] < d[l])
                d[l] = a[i];
        }

        int ans = 0;
        for (int l = 0; l <= n; l++) {
            if (d[l] < INF)
                ans = l;
        }
        return ans;
    }    
    
//}
