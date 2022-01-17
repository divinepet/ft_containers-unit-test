#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> erase_test_3(std::set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 50 * _ratio; ++i)
        st.insert(i);
    g_start1 = timer();
    st.erase(st.begin(), --st.end());
    g_end1 = timer();
    v.push_back(*(st.begin()));
    return v;
}

template <class T>
std::vector<int> erase_test_3(_set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 50 * _ratio; ++i)
        st.insert(i);
    g_start2 = timer();
    st.erase(st.begin(), --st.end());
    g_end2 = timer();
    v.push_back(*(st.begin()));
    return v;
}

int main() {

    exit(run_set_unit_test<int>("erase(InputIt)", erase_test_3, erase_test_3));
}