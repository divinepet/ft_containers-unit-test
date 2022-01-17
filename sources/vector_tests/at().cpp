#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> at_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start1 = timer();
    v.push_back(vector.at(354 * _ratio));
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> at_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start2 = timer();
    v.push_back(vector.at(354 * _ratio));
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("at()", at_test, at_test));
}