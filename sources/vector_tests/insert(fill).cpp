#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(26000000, 1);
    vector.assign(22000000, 1);
    g_start1 = timer();
    vector.insert(vector.end() - 14000000, tmp.begin(), tmp.end());
    g_end1 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_2(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp;
    tmp.assign(26000000, 1);
    vector.assign(22000000, 1);
    g_start2 = timer();
    vector.insert(vector.end() - 14000000, tmp.begin(), tmp.end());
    g_end2 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("insert(fill)", insert_test_2, insert_test_2));
}