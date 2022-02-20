#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start1 = timer();
    vector.insert(vector.end() - 50, 4200 * _ratio , 2);
    g_end1 = timer();
    v.push_back(vector[2121]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_2(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start2 = timer();
    vector.insert(vector.end() - 50, 4200 * _ratio , 2);
    g_end2 = timer();
    v.push_back(vector[2121]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("insert(fill)", insert_test_2, insert_test_2));
}