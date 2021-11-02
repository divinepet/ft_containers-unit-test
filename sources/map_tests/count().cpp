#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> count_test(std::map<T, V> mp) {
    std::vector<int> v;
    g_start1 = g_end1 = timer();
    v.push_back(mp.count(0));
    mp.insert(std::make_pair(0, 0));
    v.push_back(mp.count(0));
    return v;
}

template <class T, class V>
std::vector<int> count_test(_map<T, V> mp) {
    std::vector<int> v;
    g_start2 = g_end2 = timer();
    v.push_back(mp.count(0));
    mp.insert(_make_pair(0, 0));
    v.push_back(mp.count(0));
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("count()", count_test, count_test));
}