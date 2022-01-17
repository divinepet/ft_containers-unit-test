#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> insert_test_2(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    std::map<int, int> mp2;
    g_start1 = timer();
    mp2.insert(mp.begin(), mp.end());
    g_end1 = timer();
    typename std::map<T, V>::iterator it2 = mp2.begin();
    for (; it2 != mp2.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> insert_test_2(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
    _map<int, int> mp2;
    g_start2 = timer();
    mp2.insert(mp.begin(), mp.end());
    g_end2 = timer();
    typename _map<T, V>::iterator it2 = mp2.begin();
    for (; it2 != mp2.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("insert(InputIt)", insert_test_2, insert_test_2));
}