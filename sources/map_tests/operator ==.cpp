#include "../system/system_methods.ipp"
#include "__service.ipp"

bool map_equal_test() {
	std::vector<int> result, result2;
	g_start2 = g_end2 = g_start1 = g_end1 = 0;
	MapBoolTest mt;

	result.push_back(mt.m1 == mt.m1); result.push_back(mt.m3 == mt.m3); result.push_back(mt.m5 == mt.m9);
	result.push_back(mt.m1 == mt.m2); result.push_back(mt.m3 == mt.m4); result.push_back(mt.m6 == mt.m6);
	result.push_back(mt.m1 == mt.m3); result.push_back(mt.m4 == mt.m4); result.push_back(mt.m6 == mt.m7);
	result.push_back(mt.m1 == mt.m4); result.push_back(mt.m5 == mt.m5); result.push_back(mt.m6 == mt.m8);
	result.push_back(mt.m2 == mt.m2); result.push_back(mt.m5 == mt.m6); result.push_back(mt.m6 == mt.m9);
	result.push_back(mt.m2 == mt.m3); result.push_back(mt.m5 == mt.m7); result.push_back(mt.m7 == mt.m7);
	result.push_back(mt.m2 == mt.m4); result.push_back(mt.m5 == mt.m8); result.push_back(mt.m7 == mt.m8);
	result.push_back(mt.m7 == mt.m9); result.push_back(mt.m8 == mt.m8); result.push_back(mt.m8 == mt.m9);
	result.push_back(mt.m9 == mt.m9);

	result2.push_back(mt.mp1 == mt.mp1); result2.push_back(mt.mp3 == mt.mp3); result2.push_back(mt.mp5 == mt.mp9);
	result2.push_back(mt.mp1 == mt.mp2); result2.push_back(mt.mp3 == mt.mp4); result2.push_back(mt.mp6 == mt.mp6);
	result2.push_back(mt.mp1 == mt.mp3); result2.push_back(mt.mp4 == mt.mp4); result2.push_back(mt.mp6 == mt.mp7);
	result2.push_back(mt.mp1 == mt.mp4); result2.push_back(mt.mp5 == mt.mp5); result2.push_back(mt.mp6 == mt.mp8);
	result2.push_back(mt.mp2 == mt.mp2); result2.push_back(mt.mp5 == mt.mp6); result2.push_back(mt.mp6 == mt.mp9);
	result2.push_back(mt.mp2 == mt.mp3); result2.push_back(mt.mp5 == mt.mp7); result2.push_back(mt.mp7 == mt.mp7);
	result2.push_back(mt.mp2 == mt.mp4); result2.push_back(mt.mp5 == mt.mp8); result2.push_back(mt.mp7 == mt.mp8);
	result2.push_back(mt.mp7 == mt.mp9); result2.push_back(mt.mp8 == mt.mp8); result2.push_back(mt.mp8 == mt.mp9);
	result2.push_back(mt.mp9 == mt.mp9);

	return result == result2;
}

int main() {

	exit(run_bool_unit_test("operator ==", map_equal_test));
}