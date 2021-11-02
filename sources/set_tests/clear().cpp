#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> clear_test(std::set<T> st) {
    std::vector<int> v;
    st.clear();
    for (int i = 0; i < 250000; ++i)
        st.insert(i);
    v.push_back(st.size());
    g_start1 = timer();
    st.clear();
    g_end1 = timer();
    v.push_back(st.size());
    typename std::set<T>::iterator it = st.begin();
    if (it == st.end())
        v.push_back(1);
    return v;
}

template <class T>
std::vector<int> clear_test(_set<T> st) {
    std::vector<int> v;
    st.clear();
    for (int i = 0; i < 250000; ++i)
        st.insert(i);
    v.push_back(st.size());
    g_start2 = timer();
    st.clear();
    g_end2 = timer();
    v.push_back(st.size());
    typename _set<T>::iterator it = st.begin();
    if (it == st.end())
        v.push_back(1);
    return v;
}

int main() {

    exit(run_set_unit_test<int>("clear()", clear_test, clear_test));
}