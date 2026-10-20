#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    //TASK 1.1
    // cout << "Nums 1-100 (while):" << endl;
    // int i = 1;
    // while (i<=100) {
    //     cout << i << endl;
    //     i++;
    // }
    // cout << "Nums 1-100 (for):" << endl;
    // for (i=1; i<=100; i++) {
    //     cout << i << endl;
    // }
    // cout << "Nums 11-33 (while):" << endl;
    // i = 11;
    // while (i<=33) {
    //     cout << i << endl;
    //     i++;
    // }
    // cout << "Nums 11-33 (for):" << endl;
    // for (i=11; i<=33; i++) {
    //     cout << i << endl;
    // }
    // cout << "Even nums 0-100 (while):" << endl;
    // i = 0;
    // while (i<=100) {
    //     cout << i << endl;
    //     i += 2;
    // }
    // cout << "Even nums 0-100 (for):" << endl;
    // for (i=0; i<=100; i+=2) {
    //     cout << i << endl;
    // }
    // int sum = 0;
    // i = 1;
    // while (i<=100) {
    //     sum += i;
    //     i++;
    // }
    // cout << "Sum of the nums 1-100 (while): " << sum << endl;
    // sum = 0; 
    // for (i=1; i<=100; i++) {
    //     sum += i;
    // }
    // cout << "Sum of the nums 1-100 (for): " << sum << endl;

    //TASK 1.2
    // cout << "dm  --> sm" << endl;
    // for (int i=1; i<=20; i++) {
    //     cout << left << setw(3) << i << " --> " << i*2.5 << endl;
    // }
    // float eur;
    // cout << "Enter euro exchange rate (XX.XX): ";
    // cin >> eur;
    // cout << "Euro --> Rouble" << endl;
    // for (int i=5; i<=25; i++) {
    //     cout << left << setw(4) << i << " --> " << i*eur << endl;
    // }

    //TASK 1.3
    // int sum = 0;
    // for (int i = 10; i<=99; i++) { sum += i; }
    // cout << "Sum of the nums 10-99: " << sum << endl;
    // int i = 1;
    // sum = 0;
    // while (i<=200) {
    //     sum += i;
    //     i += 2;
    // }
    // cout << "Sum of the odd nums 1-200: " << sum << endl;
    // sum = 0;
    // for (i=1;i<=50;i++) {
    //     if (i%5==0 || i%7==0) { sum += i; }
    // }
    // cout << "Sum of the nums 1-50 divisible by 5 or 7: " << sum << endl;
    // cout << "Nums 20-50 divisible by 3 and not divisible 7: "<< endl;
    // i = 20;
    // while (i<=50) {
    //     if (i%3==0 && i%5!=0) { cout << i << endl; }
    //     i++;
    // }

    //TASK 1.4
    // int n;
    // cout << "Enter the count of nums: ";
    // cin >> n;
    // cout << "Enter integer nums: ";
    // int pos = 0, neg = 0, zeros = 0;
    // for (int i=0;i<n;i++) {
    //     int k;
    //     cin >> k;
    //     if (k==0) { zeros++; }
    //     else if (k>0) { pos++; }
    //     else { neg++; }
    // }
    // cout << "Positive nums - " << pos << ", negative nums - " << neg << ", zeros - " << zeros << endl;
    // cout << "\nEnter 10 integer nums:" << endl;
    // int nums[10];
    // for (int i=0;i<10;i++) {
    //     int k;
    //     cin >> k;
    //     if (k>=15) { nums[i]=15; }
    //     else { nums[i]=k; }
    // }
    // cout << "Nums after transformation:" << endl;
    // for (int i=0;i<10;i++) { cout << nums[i] << endl; }

    //TASK 1.5
    // int nums[] = {1,2,3,4,5};
    // cout << "1):";
    // for (int i=0; i<5; i++) { cout << " " << nums[i]; }
    // int numbers[] = {1, 2, 3, 4, 5};
    // cout << endl << "2):";
    // for (int num : numbers) { cout << " " << num; }

    //TASK 2.1
    // int N;
    // cout << "Enter the size of massive (1-1000): ";
    // cin >> N;
    // int mas[1000];
    // cout << "Enter " << N << " int nums: " << endl;
    // for (int i=0;i<N;i++) { cin >> mas[i]; }
    // cout << "\nReceived massive:";
    // for (int n=0; n<N; n++) { cout << " " << mas[n]; }
    // float sum = 0;
    // for (int n=0; n<N; n++) { sum += mas[n]; }
    // cout << "\nSum of the nums: " << sum << endl;
    // cout << "Arithmetic mean of the nums: " << sum/N << endl; 
    // int max = mas[0], min = mas[0];
    // for (int n=1; n<N; n++) {
    //     if (max<mas[n]) { max = mas[n]; }
    //     if (min>mas[n]) { min = mas[n]; }
    // }
    // cout << "Max: " << max << "   Min: " << min << endl;
    // int c5[5];
    // cout << "Enter 5 int nums:" << endl;
    // for (int i=0; i<5; i++) { cin >> c5[i]; }
    // int sum2 = 0;
    // for (int i=0; i<5; i++) { sum2+=c5[i]*c5[i]; }
    // cout << "Sum of squares of nums: " << sum2 << endl;
    // int c7[7];
    // cout << "Enter 7 int nums:" << endl;
    // for (int i=0; i<7; i++) { cin >> c7[i]; }
    // cout << "Enter float A: ";
    // float A;
    // cin >> A;
    // cout << "Enter float B>A: ";
    // float B;
    // cin >> B;
    // int c = 0;
    // for (int i=0; i<7; i++) {
    //     if (c7[i]>=A && c7[i]<=B) { c++; }
    // } 
    // cout << "Amount nums in [A;B]: " << c;

    //TASK 2.2
    // int r,c;
    // cout << "Enter r: "; cin >> r;
    // cout << "Enter c: "; cin >> c;
    // vector<vector<int>> m(r, vector<int>(c));
    // cout << "Enter " << r*c << " numbers: " << endl;
    // for (int i=0;i<r;i++) {
    //     for (int j=0;j<c;j++) { cin >> m[i][j]; }
    // }
    // cout << "Amount 2D-massive:" << endl;
    // for (const auto& row: m) {
    //     for (int val: row) { cout << left << setw(9) << val << " "; }
    //     cout << endl;
    // }
    // cout << "Enter r: "; cin >> r;
    // cout << "Enter c: "; cin >> c;
    // vector<vector<int>> m1(r, vector<int>(c));
    // vector<vector<int>> m2(r, vector<int>(c));
    // vector<vector<int>> Sum(r, vector<int>(c));
    // cout << "Enter " << r*c << " numbers for the first matrix: " << endl;
    // for (int i=0;i<r;i++) {
    //     for (int j=0;j<c;j++) { cin >> m1[i][j]; }
    // }
    // cout << "Enter " << r*c << " numbers for the second matrix: " << endl;
    // for (int i=0;i<r;i++) {
    //     for (int j=0;j<c;j++) { cin >> m2[i][j]; }
    // }
    // for (int i=0;i<r;i++) {
    //     for (int j=0;j<c;j++) { Sum[i][j] = m1[i][j]+m2[i][j]; }
    // }
    // cout << "Matrix Sum:" << endl;
    // for (const auto& row: Sum) {
    //     for (int val: row) { cout << left << setw(9) << val << " "; }
    //     cout << endl;
    // }

    //TASK 2.3
    // int test[2][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // for (int i=0; i<2; i++) {
    //     for (int j=0; j<3; j++) {
    //         for (int k=0; k<2; k++) {
    //             cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << endl;
    //         }
    //     }
    // }

    //TASK 3.1
    // int var1=3, var2=24, var3=17;
    // cout << "Address var1: " << &var1 << endl;
    // cout << "Address var2: " << &var2 << endl;
    // cout << "Address var3: " << &var3 << endl << endl;
    // int var = 10;
    // int* point_var = &var;
    // cout << "var = " << var << endl;
    // cout << "Address var: " << &var << endl;
    // cout << "point_var = " << point_var << endl;
    // cout << "*point_var = " << *point_var << endl;
    // *point_var = 16;
    // cout << "new *point_var = " << *point_var << endl;

    //TASK 3.2
    // int arr[5];
    // int *ptr = arr;
    // cout << "First method:" << endl;
    // for (int i=0; i<5; i++) {
    //     cout << "Element " << i+1 << ": " << &arr[i] << endl;
    // }
    // cout << "Second method:" << endl;
    // for (int i=0; i<5; i++) {
    //     cout << "Element " << i+1 << ": " << ptr+i << endl;
    // }
    // cout << "Enter 5 nums:\n";
    // for (int i=0; i<5; i++) {
    //     cin >> *(arr+i);
    // }
    // cout << "arr elements:\n";
    // for (int i=0; i<5; i++) {
    //     cout << "Element " << i+1 << ": " << *(arr+i) << endl;
    // }

    //TASK 4.1
    // vector<int> num;
    // for (int i=1; i<=5; i++) num.push_back(i);
    // vector<int> v1 = {1,2,3,4,5};
    // vector<int> v2 {6,7,8,9,10};
    // vector<int> v3(5,12);
    // cout << "Vector v1: ";
    // for (int i=0; i<5; i++) cout << v1.at(i) << " ";
    // cout << "\nVector v2: ";
    // for (int i=0; i<5; i++) cout << v2.at(i) << " ";
    // cout << "\nVector v3: ";
    // for (int i=0; i<5; i++) cout << v3.at(i) << " ";

    //TASK 4.2
    // vector<int> num;
    // for (int i=1; i<=7; i++) num.push_back(i);
    // cout << "num[0] = " << num.at(0) << endl; 
    // cout << "num[2] = " << num.at(2) << endl; 
    // cout << "num[4] = " << num.at(4) << endl; 
    // num.at(1) = 8;
    // num.at(4) = 9;
    // num.pop_back();
    // vector<int> v = {2, 3, 5, 7};
    // cout << "Size v = " << v.size() << endl;
    // cout << "First element = " << v.front() << endl;
    // cout << "Last element = " << v.back() << endl;
    // cout << "Empty v = " << v.empty() << endl;
    // cout << "Capacity v = " << v.capacity();

    //TASK 4.3
    vector<int> nums {9,11,13,15,17};
    cout << "vector nums: ";
    for (int i=0; i<nums.capacity(); i++) cout << nums.at(i) << " ";
    int sum = 0;
    for (int i=0; i<nums.capacity(); i++) sum += nums.at(i);
    cout << "\nSum of the elements = " << sum << endl;
    cout << "Arithmetic mean of the elements = " << double(sum)/nums.capacity() << endl;
    int max=nums.at(0), min=nums.at(0);
    for (int i=1; i<nums.capacity(); i++) {
        if (nums.at(i)>max) max=nums.at(i);
        if (nums.at(i)<min) min=nums.at(i);
    }
    cout << "Max element = " << max << endl;
    cout << "Min element = " << min << endl;
    for (int i=0; i<nums.capacity(); i++) {
        if (nums.at(i)%2==0) {
            nums.erase(nums.cbegin()+i);
            i--;
        }
    }
    cout << "nums without even elements: ";
    for (int i=0; i<nums.capacity(); i++) cout << nums.at(i) << " ";

    return 0;
}