#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> find_test(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = -750000, j = 0; i < 750000; ++i, ++j) {
        mp.insert(std::make_pair(i, j));
    }
    g_start1 = timer();
    typename std::map<T, V>::iterator it = mp.find(345678);
    g_end1 = timer();
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-345678);
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-987654321);
    if (it == mp.end())
        v.push_back(1);
    return v;
}

template <class T, class V>
std::vector<int> find_test(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = -750000, j = 0; i < 750000; ++i, ++j) {
        mp.insert(_make_pair(i, j));
    }
    g_start2 = timer();
    typename _map<T, V>::iterator it = mp.find(345678);
    g_end2 = timer();
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-345678);
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-987654321);
    if (it == mp.end())
        v.push_back(1);
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("find()", find_test, find_test));
}