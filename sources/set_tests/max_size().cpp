#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> max_size_test(std::set<T> st) {
    std::vector<int> v;
    g_start1 = timer();
    v.push_back((st.size() * 0) + 1);
    g_end1 = timer();
    return v;
}

template <class T>
std::vector<int> max_size_test(_set<T> st) {
    std::vector<int> v;
    std::set<int> std_st;
    g_start2 = timer();
    if ((std_st.max_size() / 2) < st.max_size())
        v.push_back(1);
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_set_unit_test<int>("max_size()", max_size_test, max_size_test));
}