#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> count_test(std::set<T> st) {
    std::vector<int> v;
    g_start1 = g_end1 = timer();
    v.push_back(st.count(0));
    st.insert(0);
    v.push_back(st.count(0));
    return v;
}

template <class T>
std::vector<int> count_test(_set<T> st) {
    std::vector<int> v;
    g_start2 = g_end2 = timer();
    v.push_back(st.count(0));
    st.insert(0);
    v.push_back(st.count(0));
    return v;
}

int main() {

    exit(run_set_unit_test<int>("count()", count_test, count_test));
}