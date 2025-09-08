Các thao tác trên vector:
vector<int> s; vector<int> s(n);

// int a[]={1,2,3,4,5}; vector<int> s(a, a+5);
vector<int> s(first, last);

// Lấy phần tử đầu / cuối, thêm / xoá phần tử cuối
s.front(), s.back(), s.push_back(), s.pop_back()

// Lấy giá trị ở vị trí i
s[i], *(s.begin()+i), s.at(i)

// Kiểm tra rỗng, lấy số lượng phần tử
s.empty(), s.size()

// Lấy bộ duyệt đầu và cuối → phần tử cuối *(s.end()-1)
s.begin(), s.end()

// Chèn phần tử x vào vị trí x, chèn n phần tử x vào vị trí x
s.insert(it, x), s.insert(it, n, x)

// int a[]={1,2,3,4,5}; s.insert(s.begin()+1,a+2,a+4);
s.insert(it, first, last)

// s.erase(s.begin()+2), s.erase(s.end()-3, s.end()-1)
s.erase(it), s.erase(first, last)

// xoá nội dung/hoán đổi 2 vector
s.clear(), s.swap(v)

// thay đổi kích thước và điền giá trị vào phần trống
s.resize(n), s.resize(n,val)

// int a[]={1,2,3,4,5}; s.assign(a+2,a+4);
s.assign(first, last)

// s.assign(5,10); → vector{10,10,10,10,10}
s.assign(n, val)

// Hỗ trợ các toán tử
//gán (=) , so sánh (>,<,>=,<=,==,!=)
