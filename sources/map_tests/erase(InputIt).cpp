#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> erase_test_3(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));

    g_start1 = timer();
    mp.erase(mp.begin(), --mp.end());
    g_end1 = timer();
    v.push_back(mp.begin()->first);
    return v;
}

template <class T, class V>
std::vector<int> erase_test_3(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));

    g_start2 = timer();
    mp.erase(mp.begin(), --mp.end());
    g_end2 = timer();
    v.push_back(mp.begin()->first);
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("erase(InputIt)", erase_test_3, erase_test_3));
}