#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> size_test(std::set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 100000; ++i)
        st.insert(i);
    g_start1 = timer();
    v.push_back(st.size());
    g_end1 = timer();
    for (int i = 0; i < 43; ++i)
        st.erase(i);
    v.push_back(st.size());
    return v;
}

template <class T>
std::vector<int> size_test(_set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 100000; ++i)
        st.insert(i);
    g_start2 = timer();
    v.push_back(st.size());
    g_end2 = timer();
    for (int i = 0; i < 43; ++i)
        st.erase(i);
    v.push_back(st.size());
    return v;
}

int main() {

    exit(run_set_unit_test<int>("size()", size_test, size_test));
}