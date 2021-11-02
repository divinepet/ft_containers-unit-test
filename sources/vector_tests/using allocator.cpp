#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class A>
void allocator_test(_vector<T, A> vector) {

    for (int i = 0; i < 10; ++i) {
        vector.push_back(i);
    }
}

int main() {

    exit(run_vector_allocator_unit_test<int, Alloc<int> >("using allocator", allocator_test));
}