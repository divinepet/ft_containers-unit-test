#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> assign_test(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(40 * _ratio, 1);
    g_start1 = timer();
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    v.push_back(vector[4]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> assign_test(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(40 * _ratio, 1);
    g_start2 = timer();
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    v.push_back(vector[4]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    g_end2 = timer();
    return v;
}

int main() {

    exit(run_vector_unit_test<int>("assign()", assign_test, assign_test));
}
