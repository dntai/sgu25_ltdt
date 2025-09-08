Các hàm trong STL Algorithm:

// Sắp xếp, sort(a.begin(),a.end(),MyComp());
sort(first, last, objCompareClass);

// Tìm kiếm, tìm cận dưới, cận trên
binary_search(first, last, objCompareClass);
lower_bound(first, last, objCompareClass);
upper_bound(first, last, objCompareClass);

// Sinh hoán vị
next_permutation(first, last, objCompareClass);
prev_permutation(first, last, objCompareClass);

// Tạo heap
make_heap(v.begin(), v.end(), MyCompare);

// Kiểm tra có phải là heap
is_heap(v.begin(), v.end(), MyCompare);

// Đưa phần tử đỉnh heap về cuối và xoá khỏi heap
pop_heap(v.begin(), v.end(), MyCompare); → v.pop_back()

// Đưa 1 phần tử vào cuối heap và cân bằng heap
v.push_back(x); push_heap(v.begin(), v.end(), MyCompare);
→ v.front() x/lý phần tử đỉnh heap

// Một số hàm khác
adjacent_find / binary_search / copy / copy_backward / count / count_if / equal /
equal_range / fill / fill_n / find / find_end / find_first_of / find_if / for_each
/ generate / generate_n / includes / inplace_merge / iter_swap /
lexicographical_compare / lower_bound / make_heap / max / max_element / merge /
min / min_element / mismatch / next_permutation / nth_element / partial_sort /
partial_sort_copy / partition / pop_heap / prev_permutation / push_heap /
random_shuffle / remove / remove_copy / remove_copy_if / remove_if / replace /
replace_copy / replace_copy_if / replace_if / reverse / reverse_copy / rotate /
rotate_copy / search / search_n / set_difference / set_intersection /
set_symmetric_difference / set_union / sort / sort_heap / stable_partition /
stable_sort / swap / swap_ranges / transform / unique / unique_copy / upper_bound