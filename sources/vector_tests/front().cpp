#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> front_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(44444, 1);
    g_start1 = timer();
    v.push_back(vector.front());
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> front_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(44444, 1);
    g_start2 = timer();
    v.push_back(vector.front());
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("front()", front_test, front_test));
}