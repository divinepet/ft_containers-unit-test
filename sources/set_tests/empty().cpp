#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> empty_test(std::set<T> st) {
    std::vector<int> v;
    g_start1 = timer();
    v.push_back(st.empty());
    st.insert(3);
    v.push_back(st.empty());
    g_end1 = timer();
    return v;
}

template <class T>
std::vector<int> empty_test(_set<T> st) {
    std::vector<int> v;
    g_start2 = timer();
    v.push_back(st.empty());
    st.insert(3);
    v.push_back(st.empty());
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_set_unit_test<int>("empty()", empty_test, empty_test));
}