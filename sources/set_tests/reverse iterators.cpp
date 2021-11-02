#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> reverse_iterators_test(std::set<T> st) {
    std::vector<int> v;

    g_start1 = g_end1 = timer();
    st.insert(5);
    st.insert(3);
    st.insert(7);
    typename std::set<T>::reverse_iterator rit = st.rbegin();
    typename std::set<T>::reverse_iterator rit2 = st.rend();
    v.push_back(*rit);
    rit++;
    rit2--;
    v.push_back(*rit);
    v.push_back(*rit2);
    rit++;
    v.push_back(*rit == *rit2);
    v.push_back(rit == rit2);
    rit2--;
    v.push_back(*rit);
    v.push_back(*rit2);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back(*(--rit));
    v.push_back(*(++rit2));
    v.push_back(*(rit--));
    v.push_back(*(rit2++));
    return v;
}

template <class T>
std::vector<int> reverse_iterators_test(_set<T> st) {

    std::vector<int> v;

    g_start2 = g_end2 = timer();
    st.insert(5);
    st.insert(3);
    st.insert(7);
    typename _set<T>::reverse_iterator rit = st.rbegin();
    typename _set<T>::reverse_iterator rit2 = st.rend();
    v.push_back(*rit);
    rit++;
    rit2--;
    v.push_back(*rit);
    v.push_back(*rit2);
    rit++;
    v.push_back(*rit == *rit2);
    v.push_back(rit == rit2);
    rit2--;
    v.push_back(*rit);
    v.push_back(*rit2);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back(*(--rit));
    v.push_back(*(++rit2));
    v.push_back(*(rit--));
    v.push_back(*(rit2++));
    return v;
}

int main() {
    exit(run_set_unit_test<int>("reverse iterators", reverse_iterators_test, reverse_iterators_test));
}