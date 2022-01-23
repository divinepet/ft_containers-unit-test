#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> assign_overload_test(std::set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 20 * _ratio; ++i)
        st.insert(i);
    std::set<T> st2;
    for (int i = 20 * _ratio; i < 40 * _ratio; ++i)
        st2.insert(i);
    g_start1 = timer();
    st2 = st;
    g_end1 = timer();
    typename std::set<T>::iterator it = st2.begin();
    for (; it != st2.end(); it++)
        v.push_back(*it);
    v.push_back(st2.size());
    return v;
}

template <class T>
std::vector<int> assign_overload_test(_set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 20 * _ratio; ++i)
        st.insert(i);
    _set<T> st2;
    for (int i = 20 * _ratio; i < 40 * _ratio; ++i)
        st2.insert(i);
    g_start2 = timer();
    st2 = st;
    g_end2 = timer();
    typename _set<T>::iterator it = st2.begin();
    for (; it != st2.end(); it++)
        v.push_back(*it);
    v.push_back(st2.size());
    return v;
}

int main() {

    exit(run_set_unit_test<int>("assign overload", assign_overload_test, assign_overload_test));
}
