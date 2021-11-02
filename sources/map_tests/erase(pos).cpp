#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> erase_test_2(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    typename std::map<T, V>::iterator it = mp.begin();
    v.push_back(it->first);
    mp.erase(it);
    v.push_back(mp.size());
    it = mp.begin();
    mp.erase(++it);
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    typename std::map<T, V>::iterator it4 = mp.begin();
    g_start1 = timer();
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4);
    g_end1 = timer();
    v.push_back(mp.size());
    std::map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(std::make_pair(i, j));
    typename std::map<T, V>::iterator ittest = mp2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    mp2.erase(ittest);
    for (int i = 0; i < 5; ++i) ittest++;
    mp2.erase(ittest);
    typename std::map<T, V>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> erase_test_2(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
        mp.insert(_make_pair(i, j));
    typename _map<T, V>::iterator it = mp.begin();
    v.push_back(it->first);
    mp.erase(it);
    v.push_back(mp.size());
    it = mp.begin();
    mp.erase(++it);
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    typename _map<T, V>::iterator it4 = mp.begin();
    g_start2 = timer();
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4);
    g_end2 = timer();
    v.push_back(mp.size());
    _map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(_make_pair(i, j));
    typename _map<T, V>::iterator ittest = mp2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    mp2.erase(ittest);
    for (int i = 0; i < 5; ++i) ittest++;
    mp2.erase(ittest);
    typename _map<T, V>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("erase(pos)", erase_test_2, erase_test_2));
}