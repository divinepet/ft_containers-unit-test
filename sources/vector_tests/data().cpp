#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> data_test(std::vector<T> vector) {
    std::vector<int> v;
    std::ostringstream oss;
    g_start1 = timer();
    oss << &*(vector.data());
    g_end1 = timer();
    string str = oss.str();
    if (!oss.str().rfind("0x", 0))
        v.push_back(1);
    return v;
}

template <typename T>
std::vector<int> data_test(_vector<T> vector) {
    std::vector<int> v;
    std::ostringstream oss;
    g_start2 = timer();
    oss << &*(vector.data());
    g_end2 = timer();
    string str = oss.str();
    if (!oss.str().rfind("0x", 0))
        v.push_back(1);
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("data()", data_test, data_test));
}