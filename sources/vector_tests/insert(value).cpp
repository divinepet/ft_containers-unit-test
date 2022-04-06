#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> insert_test_1(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(2600 * _ratio, 1);
    g_start1 = timer();
    v.push_back(*(vector.insert(vector.end() - 800 * _ratio, 44)));
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    return v;
}

template <typename T>
std::vector<int> insert_test_1(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(2600 * _ratio, 1);
    g_start2 = timer();
    v.push_back(*(vector.insert(vector.end() - 800 * _ratio, 44)));
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    return v;
}

int main() {

    exit(run_vector_unit_test<int>("insert(value)", insert_test_1, insert_test_1));
}