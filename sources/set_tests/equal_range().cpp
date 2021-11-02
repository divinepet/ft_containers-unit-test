#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> equal_range_test(std::set<T> st) {
    std::vector<int> v;
    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(40);
    st.insert(50);
    st.insert(60);
    g_start1 = timer();
    const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& pair = st.equal_range(10);
    const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& pair2 = st.equal_range(11);
    const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& pair3 = st.equal_range(1);
    g_end1 = timer();
    v.push_back(*(pair.first));
    v.push_back(*(pair.second));
    v.push_back(*(pair2.first));
    v.push_back(*(pair2.second));
    v.push_back(*(pair3.first));
    v.push_back(*(pair3.second));
    return v;
}

template <class T>
std::vector<int> equal_range_test(_set<T> st) {
    std::vector<int> v;
    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(40);
    st.insert(50);
    st.insert(60);
    g_start2 = timer();
    const _pair<_set<int>::const_iterator , _set<int>::const_iterator>& pair = st.equal_range(10);
    const _pair<_set<int>::const_iterator , _set<int>::const_iterator>& pair2 = st.equal_range(11);
    const _pair<_set<int>::const_iterator , _set<int>::const_iterator>& pair3 = st.equal_range(1);
    g_end2 = timer();
    v.push_back(*(pair.first));
    v.push_back(*(pair.second));
    v.push_back(*(pair2.first));
    v.push_back(*(pair2.second));
    v.push_back(*(pair3.first));
    v.push_back(*(pair3.second));
    return v;
}

int main() {

    exit(run_set_unit_test<int>("equal_range()", equal_range_test, equal_range_test));
}