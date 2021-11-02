#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int>    iterators_test(std::set<T> st) {
    std::vector<int> v;
    std::set<T> stt;
    fillSet(stt);
    for (typename std::set<T>::iterator it = stt.begin(); it != stt.end(); it++) { v.push_back(*it); }
    for (typename std::set<T>::iterator it = --stt.end(); it != stt.begin(); it--) { v.push_back(*it); }
    std::set<int> mp0;
    std::set<int>::iterator ii = mp0.insert(3).first;
    ii++;
    v.push_back(*(--ii));
    for (int i = 0; i < 5; ++i)
        st.insert(i);
    typename std::set<T>::iterator it = st.begin();
    typename std::set<T>::iterator it2 = st.end();
    g_start1 = timer();
    v.push_back(*it);
    it++;
    it++;
    it++;
    it++;
    v.push_back(*it);
    it++;
    it--;
    v.push_back(*it);
    it2--;
    v.push_back(*it2);
    v.push_back(it2 == it);
    v.push_back(*(--it2));
    v.push_back(*(it2--));
    v.push_back(*(it2++));
    v.push_back(*(++it2));
    g_end1 = timer();
    return v;
}

template <class T>
std::vector<int> iterators_test(_set<T> st) {
    std::vector<int> v;
    _set<T> stt;
    fillSet(stt);
    for (typename _set<T>::iterator it = stt.begin(); it != stt.end(); it++) { v.push_back(*it); }
    for (typename _set<T>::iterator it = --stt.end(); it != stt.begin(); it--) { v.push_back(*it); }
    _set<int> mp0;
    _set<int>::iterator ii = mp0.insert(3).first;
    ii++;
    v.push_back(*(--ii));
    for (int i = 0; i < 5; ++i)
        st.insert(i);
    typename _set<T>::iterator it = st.begin();
    typename _set<T>::iterator it2 = st.end();
    g_start2 = timer();
    v.push_back(*it);
    it++;
    it++;
    it++;
    it++;
    v.push_back(*it);
    it++;
    it--;
    v.push_back(*it);
    it2--;
    v.push_back(*it2);
    v.push_back(it2 == it);
    v.push_back(*(--it2));
    v.push_back(*(it2--));
    v.push_back(*(it2++));
    v.push_back(*(++it2));
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_set_unit_test<int>("iterators", iterators_test, iterators_test));
}