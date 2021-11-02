#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int>    iterators_test(std::map<T, V> mp) {
    std::vector<int> v;
    std::map<T, V> mpp;
    fillMap(mpp);
    for (typename std::map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
    std::map<int, int> mp0;
    std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
    ii++;
    v.push_back((--ii)->first);
    for (int i = 0, j = 10; i < 5; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    typename std::map<T, V>::iterator it = mp.begin();
    typename std::map<T, V>::iterator it2 = mp.end();
    g_start1 = timer();
    v.push_back(it->first);
    it++;
    it++;
    it++;
    it++;
    v.push_back(it->first);
    it++;
    it--;
    v.push_back(it->first);
    it2--;
    v.push_back(it2->first);
    v.push_back(it2 == it);
    v.push_back((--it2)->first);
    v.push_back((it2--)->first);
    v.push_back((it2++)->first);
    v.push_back((++it2)->first);
    g_end1 = timer();
    return v;
}

template <class T, class V>
std::vector<int> iterators_test(_map<T, V> mp) {
    std::vector<int> v;
    _map<T, V> mpp;
    fillMap(mpp);
    for (typename _map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
    for (typename _map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
    _map<int, int> mp0;
    _map<int, int>::iterator ii = mp0.insert(_make_pair(3, 3)).first;
    ii++;
    v.push_back((--ii)->first);
    for (int i = 0, j = 10; i < 5; ++i, ++j)
        mp.insert(_make_pair(i, j));
    typename _map<T, V>::iterator it = mp.begin();
    typename _map<T, V>::iterator it2 = mp.end();
    g_start2 = timer();
    v.push_back(it->first);
    it++;
    it++;
    it++;
    it++;
    v.push_back(it->first);
    it++;
    it--;
    v.push_back(it->first);
    it2--;
    v.push_back(it2->first);
    v.push_back(it2 == it);
    v.push_back((--it2)->first);
    v.push_back((it2--)->first);
    v.push_back((it2++)->first);
    v.push_back((++it2)->first);
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("iterators", iterators_test, iterators_test));
}