#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> find_test(std::set<T> st) {
    std::vector<int> v;
    for (int i = -75 * _ratio; i < 75 * _ratio; ++i) {
        st.insert(i);
    }
    g_start1 = timer();
    typename std::set<T>::iterator it = st.find(34 * _ratio);
    g_end1 = timer();
    v.push_back(*it);

    it = st.find(-34 * _ratio);
    v.push_back(*it);

    it = st.find(-987654321);
    if (it == st.end())
        v.push_back(1);
    return v;
}

template <class T>
std::vector<int> find_test(_set<T> st) {
    std::vector<int> v;
    for (int i = -75 * _ratio; i < 75 * _ratio; ++i) {
        st.insert(i);
    }
    g_start2 = timer();
    typename _set<T>::iterator it = st.find(34 * _ratio);
    g_end2 = timer();
    v.push_back(*it);

    it = st.find(-34 * _ratio);
    v.push_back(*it);

    it = st.find(-987654321);
    if (it == st.end())
        v.push_back(1);
    return v;
}

int main() {

    exit(run_set_unit_test<int>("find()", find_test, find_test));
}