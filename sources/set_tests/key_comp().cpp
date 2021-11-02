#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> key_comp_test(std::set<T> st) {

    std::vector<int> v;
    g_start1 = g_end1 = timer();
    std::set<int, std::greater<int> > st2;
    std::set<int, std::equal_to<int> > st3;
    v.push_back(st.key_comp()(1, 2));
    v.push_back(st2.key_comp()(1, 2));
    v.push_back(st3.key_comp()(1, 2));
    return v;
}

template <class T>
std::vector<int> key_comp_test(_set<T> st) {

    std::vector<int> v;
    g_start2 = g_end2 = timer();
    _set<int, std::greater<int> > st2;
    _set<int, std::equal_to<int> > st3;
    v.push_back(st.key_comp()(1, 2));
    v.push_back(st2.key_comp()(1, 2));
    v.push_back(st3.key_comp()(1, 2));
    return v;
}

int main() {

    exit(run_set_unit_test<int>("key_comp()", key_comp_test, key_comp_test));
}