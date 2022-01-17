#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> erase_test_1(std::map<T, V> mp) {
    std::vector<int> v;
    v.push_back(mp.erase(3));
    for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    typename std::map<T, V>::iterator it = mp.begin();
    v.push_back(it->first);
    v.push_back(mp.erase(-5));
    v.push_back(mp.size());
    v.push_back(mp.erase(0));
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    typename std::map<T, V>::iterator it4 = mp.begin();
    g_start1 = timer();
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4->first);
    g_end1 = timer();
    typename std::map<T, V>::iterator it2 = mp.end();
    it2--;
    v.push_back(mp.erase(30 * _ratio - 1));
    v.push_back(mp.size());
    std::map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(std::make_pair(i, j));
    mp2.erase(2);
    mp2.erase(7);
    typename std::map<T, V>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> erase_test_1(_map<T, V> mp) {
    std::vector<int> v;
    v.push_back(mp.erase(3));
    for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
    typename _map<T, V>::iterator it = mp.begin();
    v.push_back(it->first);
    v.push_back(mp.erase(-5));
    v.push_back(mp.size());
    v.push_back(mp.erase(0));
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    typename _map<T, V>::iterator it4 = mp.begin();
    g_start2 = timer();
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4->first);
    g_end2 = timer();
    typename _map<T, V>::iterator it2 = mp.end();
    it2--;
    v.push_back(mp.erase(30 * _ratio - 1));
    v.push_back(mp.size());
    _map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(_make_pair(i, j));
    mp2.erase(2);
    mp2.erase(7);
    typename _map<T, V>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("erase(key)", erase_test_1, erase_test_1));
}