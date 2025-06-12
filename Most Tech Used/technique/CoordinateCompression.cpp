struct CoordinateCompression {
    vector<int> compress;
    CoordinateCompression(vector<int> &a) {
        compress.push_back(-1e18);
        for (int i = 0; i < a.size(); ++i) {
            compress.push_back(a[i]);
        }
        sort(all(compress));
        compress.erase(unique(all(compress)), compress.end());
        compress.push_back(1e18);
    }
    int idx(int val) {
        return lower_bound(all(compress), val) - compress.begin();
    }
    int size() {
        return compress.size();
    }
};