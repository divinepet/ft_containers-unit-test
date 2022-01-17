#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> erase_test_2(std::set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 30 * _ratio; ++i)
        st.insert(i);
    typename std::set<T>::iterator it = st.begin();
    v.push_back(*it);
    st.erase(it);
    v.push_back(st.size());
    it = st.begin();
    st.erase(++it);
    v.push_back(st.size());
    it = st.begin();
    v.push_back(*it);
    typename std::set<T>::iterator it4 = st.begin();
    g_start1 = timer();
    for (; it4 != st.end(); it4 = st.begin())
        st.erase(it4);
    g_end1 = timer();
    v.push_back(st.size());
    std::set<int> st2;
    for (int i = 0; i < 10 ; ++i)
        st2.insert(i);
    typename std::set<T>::iterator ittest = st2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    st2.erase(ittest);
    ittest = st2.begin();
    for (int i = 0; i < 5; ++i) ittest++;
    st2.erase(ittest);
    typename std::set<T>::iterator it3 = st2.begin();
    for (; it3 != st2.end(); ++it3) {
        v.push_back(*it3);
    }
    return v;
}

template <class T>
std::vector<int> erase_test_2(_set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 30 * _ratio; ++i)
        st.insert(i);
    typename _set<T>::iterator it = st.begin();
    v.push_back(*it);
    st.erase(it);
    v.push_back(st.size());
    it = st.begin();
    st.erase(++it);
    v.push_back(st.size());
    it = st.begin();
    v.push_back(*it);
    typename _set<T>::iterator it4 = st.begin();
    g_start2 = timer();
    for (; it4 != st.end(); it4 = st.begin())
        st.erase(it4);
    g_end2 = timer();
    v.push_back(st.size());
    _set<int> st2;
    for (int i = 0; i < 10 ; ++i)
        st2.insert(i);
    typename _set<T>::iterator ittest = st2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    st2.erase(ittest);
    ittest = st2.begin();
    for (int i = 0; i < 5; ++i) ittest++;
    st2.erase(ittest);
    typename _set<T>::iterator it3 = st2.begin();
    for (; it3 != st2.end(); ++it3) {
        v.push_back(*it3);
    }
    return v;
}

int main() {

    exit(run_set_unit_test<int>("erase(pos)", erase_test_2, erase_test_2));
}
