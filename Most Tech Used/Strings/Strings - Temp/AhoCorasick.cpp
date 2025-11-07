struct Aho {
    static const int ALPH = 26; // alphabet size (a–z)
    vector<array<int, ALPH>> nxt; // trie transitions
    vector<int> link , out_link;             // suffix links
    vector<vector<int>> out;      // pattern ids ending at this node
    int nodes;

    Aho() {
        nodes = 1; // root = node 0
        nxt.push_back({});
        for (int i = 0; i < ALPH; i++) nxt[0][i] = -1;
        link.push_back(-1);
        out_link.push_back(0);
        out.push_back({});
    }

    // Insert pattern into trie
    int add(const string &s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nxt[v][c] == -1) {
                nxt[v][c] = nodes++;
                nxt.push_back({});
                for (int i = 0; i < ALPH; i++) nxt.back()[i] = -1;
                link.push_back(-1);
                out_link.push_back(0);
                out.push_back({});
            }
            v = nxt[v][c];
        }
        out[v].push_back(id); // mark this node as ending for pattern id
        return v;
    }

    // Build suffix links
    void build() {
        queue<int> q;
        for (int c = 0; c < ALPH; c++) {
            int v = nxt[0][c];
            if (v != -1) {
                link[v] = 0;
                q.push(v);
            } else {
                nxt[0][c] = 0; // root fallback
            }
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int c = 0; c < ALPH; c++) {
                int u = nxt[v][c];
                if (u != -1) {
                    link[u] = nxt[link[v]][c];
                    // if (!out[link[u]].empty()) out_link[u] = link[u];
                    // else out_link[u] = out_link[link[u]];
                    // merge outputs: patterns ending at suffix link also end here
                    for (int pid : out[link[u]]) out[u].push_back(pid);
                    q.push(u);
                } else {
                    nxt[v][c] = nxt[link[v]][c];
                }
            }
        }
    }
};struct Aho {
    static const int ALPH = 26; // alphabet size (a–z)
    vector<array<int, ALPH>> nxt; // trie transitions
    vector<int> link , out_link;             // suffix links
    vector<vector<int>> out;      // pattern ids ending at this node
    int nodes;

    Aho() {
        nodes = 1; // root = node 0
        nxt.push_back({});
        for (int i = 0; i < ALPH; i++) nxt[0][i] = -1;
        link.push_back(-1);
        out_link.push_back(0);
        out.push_back({});
    }

    // Insert pattern into trie
    int add(const string &s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nxt[v][c] == -1) {
                nxt[v][c] = nodes++;
                nxt.push_back({});
                for (int i = 0; i < ALPH; i++) nxt.back()[i] = -1;
                link.push_back(-1);
                out_link.push_back(0);
                out.push_back({});
            }
            v = nxt[v][c];
        }
        out[v].push_back(id); // mark this node as ending for pattern id
        return v;
    }

    // Build suffix links
    void build() {
        queue<int> q;
        for (int c = 0; c < ALPH; c++) {
            int v = nxt[0][c];
            if (v != -1) {
                link[v] = 0;
                q.push(v);
            } else {
                nxt[0][c] = 0; // root fallback
            }
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int c = 0; c < ALPH; c++) {
                int u = nxt[v][c];
                if (u != -1) {
                    link[u] = nxt[link[v]][c];
                    // if (!out[link[u]].empty()) out_link[u] = link[u];
                    // else out_link[u] = out_link[link[u]];
                    // merge outputs: patterns ending at suffix link also end here
                    for (int pid : out[link[u]]) out[u].push_back(pid);
                    q.push(u);
                } else {
                    nxt[v][c] = nxt[link[v]][c];
                }
            }
        }
    }
};