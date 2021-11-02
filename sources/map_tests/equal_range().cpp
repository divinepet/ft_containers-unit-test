#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int> equal_range_test(std::map<T, V> mp) {
    std::vector<int> v;
    mp.insert(std::make_pair(10, 10));
    mp.insert(std::make_pair(20, 20));
    mp.insert(std::make_pair(30, 30));
    mp.insert(std::make_pair(40, 40));
    mp.insert(std::make_pair(50, 50));
    mp.insert(std::make_pair(60, 60));
    g_start1 = timer();
    const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair = mp.equal_range(10);
    const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair2 = mp.equal_range(11);
    const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair3 = mp.equal_range(1);
    g_end1 = timer();
    v.push_back(pair.first->first);
    v.push_back(pair.first->second);
    v.push_back(pair.second->first);
    v.push_back(pair.second->second);
    v.push_back(pair2.first->first);
    v.push_back(pair2.first->second);
    v.push_back(pair2.second->first);
    v.push_back(pair2.second->second);
    v.push_back(pair3.first->first);
    v.push_back(pair3.first->second);
    v.push_back(pair3.second->first);
    v.push_back(pair3.second->second);
    return v;
}

template <class T, class V>
std::vector<int> equal_range_test(_map<T, V> mp) {
    std::vector<int> v;
    mp.insert(_make_pair(10, 10));
    mp.insert(_make_pair(20, 20));
    mp.insert(_make_pair(30, 30));
    mp.insert(_make_pair(40, 40));
    mp.insert(_make_pair(50, 50));
    mp.insert(_make_pair(60, 60));
    g_start2 = timer();
    const _pair<_map<int, int>::const_iterator , _map<int, int>::const_iterator>& pair = mp.equal_range(10);
    const _pair<_map<int, int>::const_iterator , _map<int, int>::const_iterator>& pair2 = mp.equal_range(11);
    const _pair<_map<int, int>::const_iterator , _map<int, int>::const_iterator>& pair3 = mp.equal_range(1);
    g_end2 = timer();
    v.push_back(pair.first->first);
    v.push_back(pair.first->second);
    v.push_back(pair.second->first);
    v.push_back(pair.second->second);
    v.push_back(pair2.first->first);
    v.push_back(pair2.first->second);
    v.push_back(pair2.second->first);
    v.push_back(pair2.second->second);
    v.push_back(pair3.first->first);
    v.push_back(pair3.first->second);
    v.push_back(pair3.second->first);
    v.push_back(pair3.second->second);
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("equal_range()", equal_range_test, equal_range_test));
}