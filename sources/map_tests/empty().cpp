#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> empty_test(std::map<T, V> mp) {
    std::vector<int> v;
    g_start1 = timer();
    v.push_back(mp.empty());
    mp.insert(std::make_pair(3, 3));
    v.push_back(mp.empty());
    g_end1 = timer();
    return v;
}

template <class T, class V>
std::vector<int> empty_test(_map<T, V> mp) {
    std::vector<int> v;
    g_start2 = timer();
    v.push_back(mp.empty());
    mp.insert(_make_pair(3, 3));
    v.push_back(mp.empty());
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("empty()", empty_test, empty_test));
}