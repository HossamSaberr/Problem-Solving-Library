#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename key>
using ordered_set = tree<key, null_type,less/*can do greater and less_equal*/<key>,rb_tree_tag,tree_order_statistics_node_update>; /* set.order_of_key(x) => give you number of elemenst smallest than x in the set && *set.find_by_order(x) give you the elemnt in the xth index in the set both on log(N)*/

struct orderedSet {
    ordered_set<int> se;

    void insert(int val) { se.insert(val); }

    bool exist(int val) {
        if (se.upper_bound(val) == se.end()) { return false; }
        return (*se.upper_bound(val)) == val;
    }

    void erase(int val) {
        auto it = se.find(val);
        if (it != se.end()) { se.erase(it); }
    }

    void erase_one(int val) {
        auto it = se.lower_bound(val);
        if (it != se.end() && *it == val) { se.erase(it); }
    }

    int index(int val) {
        if (!exist(val)) { return -1; }
        return se.order_of_key(val);
    }

    int lower_bound(int val) { return *se.upper_bound(val); }

    int upper_bound(int val) { return *se.lower_bound(val); }

    int operator[](int idx) { return *se.find_by_order(idx); }

    int size() { return se.size(); }

    void clear() { se.clear(); }

    int order_of_key(int x) { return se.order_of_key(x); }
};