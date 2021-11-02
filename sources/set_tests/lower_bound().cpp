#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> lower_bound_test(std::set<T> st) {
    std::vector<int> v;
    std::set<int, std::greater<int> > st2;
    st.insert(10);
    st2.insert(10);
    if (st.lower_bound(11) == st.end())
        v.push_back(1);
    if (st2.lower_bound(1) == st2.end())
        v.push_back(1);
    st.insert(20);
    st.insert(30);
    st.insert(40);
    st.insert(50);
    st.insert(60);
    st2.insert(20);
    st2.insert(30);
    st2.insert(40);
    st2.insert(50);
    st2.insert(60);
    std::set<int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = st.lower_bound(i);
        v.push_back(*it);
    }
    for (int i = 11; i < 70; i += 10) {
        it = st2.lower_bound(i);
        v.push_back(*it);
    }
    std::set<int> st3;
    for (int i = 0; i < 500000; ++i) {
        st3.insert(i);
    }
    g_start1 = timer();
    st3.lower_bound(490000);
    g_end1 = timer();
    return v;
}

template <class T>
std::vector<int> lower_bound_test(_set<T> st) {
    std::vector<int> v;
    _set<int, std::greater<int> > st2;
    st.insert(10);
    st2.insert(10);
    if (st.lower_bound(11) == st.end())
        v.push_back(1);
    if (st2.lower_bound(1) == st2.end())
        v.push_back(1);
    st.insert(20);
    st.insert(30);
    st.insert(40);
    st.insert(50);
    st.insert(60);
    st2.insert(20);
    st2.insert(30);
    st2.insert(40);
    st2.insert(50);
    st2.insert(60);
    _set<int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = st.lower_bound(i);
        v.push_back(*it);
    }
    for (int i = 11; i < 70; i += 10) {
        it = st2.lower_bound(i);
        v.push_back(*it);
    }
    _set<int> st3;
    for (int i = 0; i < 500000; ++i) {
        st3.insert(i);
    }
    g_start2 = timer();
    st3.lower_bound(490000);
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_set_unit_test<int>("lower_bound()", lower_bound_test, lower_bound_test));
}