#include "../system/system_methods.ipp"
#include "__service.ipp"

bool operator_less_equal_test() {
    std::vector<int> result, result_2;
    std::vector<int> v_int1, v_int2, v_int3;
    std::vector<string> v_str1, v_str2;
    _vector<int> V_int1, V_int2, V_int3;
    _vector<string> V_str1, V_str2;
    v_int1.push_back(1);
    v_int3.push_back(1);
    v_str1.push_back("aa");
    v_str2.push_back("ab");
    result.push_back(v_int1 <= v_int2);
    v_int2.push_back(2);
    result.push_back(v_int1 <= v_int2);
    result.push_back(v_int1 <= v_int3);
    result.push_back(v_str1 <= v_str2);
    V_int1.push_back(1);
    V_int3.push_back(1);
    V_str1.push_back("aa");
    V_str2.push_back("ab");
    result_2.push_back(V_int1 <= V_int2);
    V_int2.push_back(2);
    result_2.push_back(V_int1 <= V_int2);
    result_2.push_back(V_int1 <= V_int3);
    result_2.push_back(V_str1 <= V_str2);
    return result == result_2;
}

int main() {

	exit(run_bool_unit_test("operator <=", operator_less_equal_test));
}