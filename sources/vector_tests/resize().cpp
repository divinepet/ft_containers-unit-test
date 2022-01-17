#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start1 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> resize_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start2 = timer();
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("resize()", resize_test, resize_test));
}