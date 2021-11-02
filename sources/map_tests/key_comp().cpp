#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> key_comp_test(std::map<T, V> mp) {

    std::vector<int> v;
    g_start1 = g_end1 = timer();
    std::map<int, int, std::greater<int> > mp2;
    std::map<int, int, std::equal_to<int> > mp3;
    v.push_back(mp.key_comp()(1, 2));
    v.push_back(mp2.key_comp()(1, 2));
    v.push_back(mp3.key_comp()(1, 2));
    return v;
}

template <class T, class V>
std::vector<int> key_comp_test(_map<T, V> mp) {

    std::vector<int> v;
    g_start2 = g_end2 = timer();
    _map<int, int, std::greater<int> > mp2;
    _map<int, int, std::equal_to<int> > mp3;
    v.push_back(mp.key_comp()(1, 2));
    v.push_back(mp2.key_comp()(1, 2));
    v.push_back(mp3.key_comp()(1, 2));
    return v;
}

int main() {

    run_map_unit_test<int, int>("key_comp()", key_comp_test, key_comp_test);

    return (0);
}