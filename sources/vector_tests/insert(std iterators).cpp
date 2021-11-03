#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> insert_std_test(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(26000000, 1);
	vector.assign(42000000, 7);
	g_start1 = timer();
	vector.insert(vector.begin(), tmp.begin(), tmp.end());
	g_end1 = timer();
	for (size_t i = 0; i < tmp.size(); ++i) {
		v.push_back(vector[i]);
	}
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> insert_std_test(_vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(26000000, 1);
	vector.assign(42000000, 7);
	g_start2 = timer();
	vector.insert(vector.begin(), tmp.begin(), tmp.end());
	g_end2 = timer();
	for (size_t i = 0; i < tmp.size(); ++i) {
		v.push_back(vector[i]);
	}
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

int main() {

	exit(run_vector_unit_test<int>("insert(std iterators)", insert_std_test, insert_std_test));
}