#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> end_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start1 = timer();
    v.push_back(*(vector.end() - 1));
    v.push_back(*(vector.end() - 2));
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> end_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start2 = timer();
    v.push_back(*(vector.end() - 1));
    v.push_back(*(vector.end() - 2));
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("end()", end_test, end_test));
}