#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> insert_test_2(std::set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 50 * _ratio; ++i)
        st.insert(i);
    std::set<int> st2;
    g_start1 = timer();
    st2.insert(st.begin(), st.end());
    g_end1 = timer();
    typename std::set<T>::iterator it2 = st2.begin();
    for (; it2 != st2.end(); ++it2) {
        v.push_back(*it2);
    }
    return v;
}

template <class T>
std::vector<int> insert_test_2(_set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 50 * _ratio; ++i)
        st.insert(i);
    _set<int> st2;
    g_start2 = timer();
    st2.insert(st.begin(), st.end());
    g_end2 = timer();
    typename _set<T>::iterator it2 = st2.begin();
    for (; it2 != st2.end(); ++it2) {
        v.push_back(*it2);
    }
    return v;
}

int main() {

    exit(run_set_unit_test<int>("insert(InputIt)", insert_test_2, insert_test_2));
}