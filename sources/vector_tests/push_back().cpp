#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> push_back_test(std::vector<T> vector) {
    std::vector<int> v;
    g_start1 = timer();
    for (int i = 0; i < 55000000; ++i)
        vector.push_back(i);
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> push_back_test(_vector<T> vector) {
    std::vector<int> v;
    g_start2 = timer();
    for (int i = 0; i < 55000000; ++i) {
        vector.push_back(i);
    }
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("push_back()", push_back_test, push_back_test));
}