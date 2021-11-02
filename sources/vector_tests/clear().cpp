#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> clear_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(50000000, 1);
    g_start1 = timer();
    vector.clear();
    g_end1 = timer();
    v.push_back(vector.capacity());
    v.push_back(vector.size());
    return v;
}

template <typename T>
std::vector<int> clear_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(50000000, 1);
    g_start2 = timer();
    vector.clear();
    g_end2 = timer();
    v.push_back(vector.capacity());
    v.push_back(vector.size());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("clear()", clear_test, clear_test));
}