#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> copy_constructor_test(std::set<T> st) {
    std::vector<int> v;

    for (int i = 0; i < 30 * _ratio; ++i) {
        st.insert(i);
    }
    g_start1 = timer();
    std::set<int> st2(st.begin(), st.end());
    g_end1 = timer();
    std::set<int>::iterator it = st2.begin();
    for (int i = 0; i < 30 * _ratio; ++i, it++) {
        v.push_back(*it);
    }
    return v;
}

template <class T>
std::vector<int> copy_constructor_test(_set<T> st) {
    std::vector<int> v;

    for (int i = 0; i < 30 * _ratio; ++i)
        st.insert(i);
    g_start2 = timer();
    _set<int> st2(st.begin(), st.end());
    g_end2 = timer();
    _set<int>::iterator it = st2.begin();
    for (int i = 0; i < 30 * _ratio; ++i, it++) {
        v.push_back(*it);
    }
    return v;
}

int main() {
    exit(run_set_unit_test<int>("constructor", copy_constructor_test, copy_constructor_test));
}