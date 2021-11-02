#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T, class C, class A>
void allocator_test(_set<T, C, A> st) {
    for (int i = 0; i < 10; ++i) {
        st.insert(i);
    }
}

int main() {
    exit(run_set_allocator_unit_test<int, std::less<int>, Alloc<int> >("using allocator", allocator_test));
}