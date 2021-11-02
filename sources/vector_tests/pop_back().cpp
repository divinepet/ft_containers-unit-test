#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> pop_back_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(99000000, 1);
    g_start1 = timer();
    vector.pop_back();
    g_end1 = timer();
    v.push_back(vector[vector.size() - 1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> pop_back_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(99000000, 1);
    g_start2 = timer();
    vector.pop_back();
    g_end2 = timer();
    v.push_back(vector[vector.size() - 1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("pop_back()", pop_back_test, pop_back_test));
}