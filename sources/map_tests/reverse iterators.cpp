#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
std::vector<int>    reverse_iterators_test_std(std::map<T, V> mp) {
    std::vector<int> v;

    g_start1 = g_end1 = timer();
    mp.insert(std::make_pair(5, 5));
    mp.insert(std::make_pair(3, 3));
    mp.insert(std::make_pair(7, 7));
    typename std::map<T, V>::reverse_iterator rit = mp.rbegin();
    typename std::map<T, V>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
    return v;
}

template <class T, class V>
std::vector<int> reverse_iterators_test_ft(_map<T, V> mp) {

    std::vector<int> v;

    g_start2 = g_end2 = timer();
    mp.insert(_make_pair(5, 5));
    mp.insert(_make_pair(3, 3));
    mp.insert(_make_pair(7, 7));
    typename _map<T, V>::reverse_iterator rit = mp.rbegin();
    typename _map<T, V>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("reverse iterators", reverse_iterators_test_std, reverse_iterators_test_ft));
}