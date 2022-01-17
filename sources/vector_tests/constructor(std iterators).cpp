#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> constructor_std_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(3, 3);
	std::vector<int> tmp(1000 * _ratio, 4);
	g_start1 = timer();
	std::vector<int> tmp2(tmp.begin(), tmp.end());
	g_end1 = timer();
	v.push_back(tmp2.size());
	v.push_back(tmp2.capacity());
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(tmp2[i]);
	return v;
}

template <typename T>
std::vector<int> constructor_std_test(_vector<T> vecto) {
	(void)vecto;
	std::vector<int> v;
	_vector<T> vector(3, 3);
	std::vector<int> tmp(1000 * _ratio, 4);
	g_start2 = timer();
	_vector<int> tmp2(tmp.begin(), tmp.end());
	g_end2 = timer();
	v.push_back(tmp2.size());
	v.push_back(tmp2.capacity());
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(tmp2[i]);
	return v;
}

int main() {

	exit(run_vector_unit_test<int>("constructor(std iterators)", constructor_std_test, constructor_std_test));
}
