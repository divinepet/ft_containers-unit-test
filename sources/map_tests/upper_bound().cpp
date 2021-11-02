#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class V>
        std::vector<int> upper_bound_test(std::map<T, V> mp) {
    std::vector<int> v;
    std::map<int, int, std::greater<int> > mp2;
    mp.insert(std::make_pair(10, 10));
    mp2.insert(std::make_pair(10, 10));
    if (mp.upper_bound(11) == mp.end())
        v.push_back(1);
    if (mp2.upper_bound(1) == mp2.end())
        v.push_back(1);
    mp.insert(std::make_pair(20, 20));
    mp.insert(std::make_pair(30, 30));
    mp.insert(std::make_pair(40, 40));
    mp.insert(std::make_pair(50, 50));
    mp.insert(std::make_pair(60, 60));
    mp2.insert(std::make_pair(20, 20));
    mp2.insert(std::make_pair(30, 30));
    mp2.insert(std::make_pair(40, 40));
    mp2.insert(std::make_pair(50, 50));
    mp2.insert(std::make_pair(60, 60));
    std::map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.upper_bound(i);
        v.push_back(it->first);
    }
    for (int i = 11; i < 70; i += 10) {
        it = mp2.upper_bound(i);
        v.push_back(it->first);
    }
    std::map<int, int> mp3;
    for (int i = 0, j = 0; i < 500000; ++i, ++j) {
        mp3.insert(std::make_pair(i, j));
    }
    std::map<int, int> mp4;
    mp.insert(std::make_pair(-10, 10));
    mp.insert(std::make_pair(-20, 20));
    v.push_back((--mp.upper_bound(0))->first);
    g_start1 = timer();
    mp3.upper_bound(490000);
    g_end1 = timer();
    return v;
}

template <class T, class V>
        std::vector<int> upper_bound_test(_map<T, V> mp) {
    std::vector<int> v;
    _map<int, int, std::greater<int> > mp2;
    mp.insert(_make_pair(10, 10));
    mp2.insert(_make_pair(10, 10));
    if (mp.upper_bound(11) == mp.end())
        v.push_back(1);
    if (mp2.upper_bound(1) == mp2.end())
        v.push_back(1);
    mp.insert(_make_pair(20, 20));
    mp.insert(_make_pair(30, 30));
    mp.insert(_make_pair(40, 40));
    mp.insert(_make_pair(50, 50));
    mp.insert(_make_pair(60, 60));
    mp2.insert(_make_pair(20, 20));
    mp2.insert(_make_pair(30, 30));
    mp2.insert(_make_pair(40, 40));
    mp2.insert(_make_pair(50, 50));
    mp2.insert(_make_pair(60, 60));
    _map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.upper_bound(i);
        v.push_back(it->first);
    }
    for (int i = 11; i < 70; i += 10) {
        it = mp2.upper_bound(i);
        v.push_back(it->first);
    }
    _map<int, int> mp3;
    for (int i = 0, j = 0; i < 500000; ++i, ++j) {
        mp3.insert(_make_pair(i, j));
    }
    _map<int, int> mp4;
    mp.insert(_make_pair(-10, 10));
    mp.insert(_make_pair(-20, 20));
    v.push_back((--mp.upper_bound(0))->first);
    g_start2 = timer();
    mp3.upper_bound(490000);
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_map_unit_test<int, int>("upper_bound()", upper_bound_test, upper_bound_test));
}