#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> insert_test(std::set<T> st) {
    std::vector<int> v;
    std::pair<std::set<int>::iterator , bool> pair = st.insert(7);
    std::set<int>::iterator it = st.begin();
    v.push_back(*it);

    v.push_back(*(pair.first));
    v.push_back(pair.second);
    st.insert(9);
    std::pair<std::set<int>::iterator , bool> pair2 = st.insert(9);
    std::set<int>::iterator it2 = pair.first;
    v.push_back(*it2);
    v.push_back(*(pair2.first));
    v.push_back(pair2.second);
    g_start1 = timer();
    for (int i = 0; i < 500000; ++i) {
        st.insert(i);
    }
    g_end1 = timer();
    typename std::set<T>::iterator it3 = st.begin();
    for (; it3 != st.end(); ++it3) {
        v.push_back(*it3);
    }
    v.push_back(st.size());
    return v;
}

template <class T>
std::vector<int> insert_test(_set<T> st) {
    std::vector<int> v;
    _pair<_set<int>::iterator , bool> pair = st.insert(7);
    _set<int>::iterator it = st.begin();
    v.push_back(*it);

    v.push_back(*(pair.first));
    v.push_back(pair.second);
    st.insert(9);
    _pair<_set<int>::iterator , bool> pair2 = st.insert(9);
    _set<int>::iterator it2 = pair.first;
    v.push_back(*it2);
    v.push_back(*(pair2.first));
    v.push_back(pair2.second);
    g_start2 = timer();
    for (int i = 0; i < 500000; ++i) {
        st.insert(i);
    }
    g_end2 = timer();
    typename _set<T>::iterator it3 = st.begin();
    for (; it3 != st.end(); ++it3) {
        v.push_back(*it3);
    }
    v.push_back(st.size());
    return v;
}

int main() {

    exit(run_set_unit_test<int>("insert(value)", insert_test, insert_test));
}