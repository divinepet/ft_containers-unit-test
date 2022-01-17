#include "../system/system_methods.ipp"
#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> clear_test(std::map<T, V> mp) {
    std::vector<int> v;
    mp.clear();
    for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    v.push_back(mp.size());
    g_start1 = timer();
    mp.clear();
    g_end1 = timer();
    v.push_back(mp.size());
    typename std::map<T, V>::iterator it = mp.begin();
    if (it == mp.end())
        v.push_back(1);
    return v;
}

template <class T, class V>
std::vector<int> clear_test(_map<T, V> mp) {
    std::vector<int> v;
    mp.clear();
    for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
    v.push_back(mp.size());
    g_start2 = timer();
    mp.clear();
    g_end2 = timer();
    v.push_back(mp.size());
    typename _map<T, V>::iterator it = mp.begin();
    if (it == mp.end())
        v.push_back(1);
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("clear()", clear_test, clear_test));
}