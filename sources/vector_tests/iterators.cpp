#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> iterator_test(std::vector<T> vector) {
    typename std::vector<T>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    g_start1 = timer();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> iterator_test(_vector<T> vector) {
    typename _vector<T>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    g_start2 = timer();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("iterators", iterator_test, iterator_test));
}