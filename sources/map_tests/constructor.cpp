#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> copy_constructor_test(std::map<T, V> mp) {

    std::vector<int> v;

    for (int i = 0, j = 10; i < 300000; ++i, ++j) {
        mp.insert(std::make_pair(i, j));
    }
    g_start1 = timer();
    std::map<int, int> mp2(mp.begin(), mp.end());
    g_end1 = timer();
    std::map<int, int>::iterator it = mp2.begin();
    for (int i = 0; i < 300000; ++i, it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> copy_constructor_test(_map<T, V> mp) {

    std::vector<int> v;

    for (int i = 0, j = 10; i < 300000; ++i, ++j) {
        mp.insert(_make_pair(i, j));
    }
    g_start2 = timer();
    _map<int, int> mp2(mp.begin(), mp.end());
    g_end2 = timer();
    _map<int, int>::iterator it = mp2.begin();
    for (int i = 0; i < 300000; ++i, it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("constructor(InputIt)", copy_constructor_test, copy_constructor_test));
}