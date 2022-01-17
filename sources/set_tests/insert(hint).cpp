#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> insert_test_3(std::set<T> st) {
    std::vector<int> v;
    typename std::set<T>::iterator it = st.end();
    g_start1 = timer();
    for (int i = 0; i < 50 * _ratio; ++i) {
        st.insert(it, i);
    }
    g_end1 = timer();
    typename std::set<T>::iterator it2 = st.begin();
    for (; it2 != st.end(); ++it2) {
        v.push_back(*it2);
    }
    return v;
}

template <class T>
std::vector<int> insert_test_3(_set<T> st) {
    std::vector<int> v;
    typename _set<T>::iterator it = st.end();
    g_start2 = timer();
    for (int i = 0; i < 50 * _ratio; ++i) {
        st.insert(it, i);
    }
    g_end2 = timer();
    typename _set<T>::iterator it2 = st.begin();
    for (; it2 != st.end(); ++it2) {
        v.push_back(*it2);
    }
    return v;
}

int main() {

    exit(run_set_unit_test<int>("insert(hint)", insert_test_3, insert_test_3));
}