struct query {
    int l, r, idx;
    bool operator<(query &other) {
        if (l / SQ != other.l / SQ)
            return l / SQ < other.l / SQ;
        return (l / SQ & 1 ? r < other.r : r > other.r);
    }
};

int frq[N];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<query> qry(q);
    for (int i = 0; i < q; ++i) {
        int u , v;
        cin >> u >> v;
        u--;v--;
        qry[i].idx = i;
        qry[i].l = u;
        qry[i].r = v;
    }

    sort(all(qry));
    int cnt = 0;

    auto add = [&](int idx) {
        int value = a[idx];
        if (value > n)
            return;
        cnt -= frq[value] == value;
        frq[value]++;
        cnt += frq[value] == value;
    };

    auto del = [&](int idx) {
        int value = a[idx];
        if (value > n)
            return;
        cnt -= frq[value] == value;
        frq[value]--;
        cnt += frq[value] == value;
    };

    auto query = [&]() {
        return cnt;
    };

    int l = 0, r = -1;
    vector<int> ans(q);
    for (auto &[lq, rq, idx]: qry) {
        while (l > lq)
            add(--l);
        while (r < rq)
            add(++r);
        while (l < lq)
            del(l++);
        while (r > rq)
            del(r--);
        ans[idx] = query();
    }

    for(auto x : ans)
        cout << x << endl;
}