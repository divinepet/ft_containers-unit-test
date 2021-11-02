#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> swap_test(std::map<T, V> mp) {
    std::vector<int> v;
    g_start1 = g_end1 = timer();
    for (int i = 0, j = 0; i < 250000; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    std::map<T, V> mp2;
    for (int i = 250000, j = 0; i < 350000; ++i, --j)
        mp.insert(std::make_pair(i, j));
    long *adr1 = reinterpret_cast<long *>(&mp);
    long *adr2 = reinterpret_cast<long *>(&mp2);
    mp.swap(mp2);
    if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
    	v.push_back(1);
    v.push_back(mp2.size());
    typename std::map<T, V>::iterator it = mp2.begin();
    for (; it != mp2.end(); ++it) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    std::swap(mp, mp2);
    typename std::map<T, V>::iterator it2 = mp2.begin();
    for (; it2 != mp2.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> swap_test(_map<T, V> mp) {
    std::vector<int> v;
    g_start2 = g_end2 = timer();
    for (int i = 0, j = 0; i < 250000; ++i, ++j)
        mp.insert(_make_pair(i, j));
    _map<T, V> mp2;
    for (int i = 250000, j = 0; i < 350000; ++i, --j)
        mp.insert(_make_pair(i, j));
    long *adr1 = reinterpret_cast<long *>(&mp);
    long *adr2 = reinterpret_cast<long *>(&mp2);
    mp.swap(mp2);
    if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
    	v.push_back(1);
    v.push_back(mp2.size());
    typename _map<T, V>::iterator it = mp2.begin();
    for (; it != mp2.end(); ++it) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    std::swap(mp, mp2);
    typename _map<T, V>::iterator it2 = mp2.begin();
    for (; it2 != mp2.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("swap()", swap_test, swap_test));
}