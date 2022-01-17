#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> at_test(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 10; i < 70 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    g_start1 = timer();
    try {
        v.push_back(mp.at(40 * _ratio));
        v.push_back(mp.at(40 * _ratio + 1));
    } catch (std::exception &e) {
        v.push_back(1);
    }
    g_end1 = timer();
    return v;
}

template <class T, class V>
std::vector<int> at_test(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 10; i < 70 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
    g_start2 = timer();
    try {
        v.push_back(mp.at(40 * _ratio));
        v.push_back(mp.at(40 * _ratio + 1));
    } catch (std::exception &e) {
        v.push_back(1);
    }
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("at()", at_test, at_test));
}