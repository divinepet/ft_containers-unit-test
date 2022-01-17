#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> erase_test_1(std::set<T> st) {
    std::vector<int> v;
    v.push_back(st.erase(3));
    for (int i = 0; i < 30 * _ratio; ++i)
        st.insert(i);
    typename std::set<T>::iterator it = st.begin();
    v.push_back(*it);
    v.push_back(st.erase(-5));
    v.push_back(st.size());
    v.push_back(st.erase(0));
    v.push_back(st.size());
    typename std::set<T>::iterator it4 = st.begin();
    g_start1 = timer();
    for (; it4 != st.end(); it4 = st.begin())
        st.erase(*it4);
    g_end1 = timer();
    typename std::set<T>::iterator it2 = st.end();
    it2--;
    v.push_back(st.erase(30 * _ratio - 1));
    v.push_back(st.size());
    std::set<int> st2;
    for (int i = 0; i < 10 ; ++i)
        st2.insert(i);
    st2.erase(2);
    st2.erase(7);
    typename std::set<T>::iterator it3 = st2.begin();
    for (; it3 != st2.end(); ++it3) {
        v.push_back(*it3);
    }
    return v;
}

template <class T>
std::vector<int> erase_test_1(_set<T> st) {
    std::vector<int> v;
    v.push_back(st.erase(3));
    for (int i = 0; i < 30 * _ratio; ++i)
        st.insert(i);
    typename _set<T>::iterator it = st.begin();
    v.push_back(*it);
    v.push_back(st.erase(-5));
    v.push_back(st.size());
    v.push_back(st.erase(0));
    v.push_back(st.size());
    typename _set<T>::iterator it4 = st.begin();
    g_start2 = timer();
    for (; it4 != st.end(); it4 = st.begin())
        st.erase(*it4);
    g_end2 = timer();
    typename _set<T>::iterator it2 = st.end();
    it2--;
    v.push_back(st.erase(30 * _ratio - 1));
    v.push_back(st.size());
    _set<int> st2;
    for (int i = 0; i < 10 ; ++i)
        st2.insert(i);
    st2.erase(2);
    st2.erase(7);
    typename _set<T>::iterator it3 = st2.begin();
    for (; it3 != st2.end(); ++it3) {
        v.push_back(*it3);
    }
    return v;
}

int main() {

    exit(run_set_unit_test<int>("erase(value)", erase_test_1, erase_test_1));
}