#include <iostream>
#include <string>
#include <climits>
using namespace std;
int main() {
    // TASK 1
    // int a = 17, b = 5;
    // cout << "Values – 17 and 5" << endl;
    // cout << "Sum: " << a+b << endl;
    // cout << "Diff: " << a-b << endl;
    // cout << "Product: " << a*b << endl;
    // cout << "Exact div: " << a/b << endl;
    // cout << "Remainder: " << a%b << endl;

    // TASK 2
    // double d1 = 7.0, d2 = 2.0;
    // cout << "Delenie double: " << d1/d2 << endl;
    // cout << "Delenie int: " << 7/2 << endl;
    // if (d1/d2 > 7/2) {
    //     cout << "Delenie double > Delenie int";
    // } else if (d1/d2 < 7/2) {
    //     cout << "Delenie double < Delenie int";
    // } else {
    //     cout << "Delenie double == Delenie int";
    // }

    // TASK 3
    // int x = 10;
    // cout << "0. x=" << x << endl;
    // x += 5;
    // cout << "1. x+=5. x=" << x << endl;
    // x -= 3;
    // cout << "2. x-=3. x=" << x << endl;
    // x *= 2;
    // cout << "3. x*=2. x=" << x << endl;
    // x /= 4;
    // cout << "4. x/=4. x=" << x << endl;
    // x %= 3;
    // cout << "5. x%=3. x=" << x << endl;

    // TASK 4
    // int a=5, b=5;
    // int c = ++a; // сначала увеличивает а, потом возвращает новое значение
    // int d = b++; // сначала возвращает b, потом увеличивает его
    // cout << "Before:\na=5, b=5" << endl;
    // cout << "After:\na=" << a << ", b=" << b << ", c=" << c << ", d=" << d;
    
    // TASK 5
    // for (int n = 10; n>0; n--) {
    //     cout << n << endl;
    // }

    // TASK 6
    // int a=8, b=12, c=20;
    // cout << "a=8, b=12, c=20" << endl;
    // cout << "a<b - " << (a<b) << endl;
    // cout << "a==c - " << (a==c) << endl;
    // cout << "b*2>=c - " << (b*2>=c) << endl;
    // cout << "(c-a)!=b - " << (c-a!=b) << endl;
    // cout << "(a+b)<=c - " << (a+b<=c) << endl;

    // TASK 7
    // int a=5, b=10, c=15;
    // cout << "a=5, b=10, c=15" << endl;
    // cout << "(a<b)&&(b<c) - " << ((a<b)&&(b<c)) << endl;
    // cout << "(a>b)||(b<c) - " << ((a>b)||(b<c)) << endl;
    // cout << "!((a+b)==c) - " << (!((a+b)==c)) << endl;
    // cout << "(a==5)&&(b!=10)||(c==15) - " << ((a==5)&&(b!=10)||(c==15)) << endl;
    
    // TASK 8
    // int a, b;
    // cout << "Enter two integer a and b: ";
    // cin >> a;
    // cin >> b;
    // (a>=b) ? (cout << "Max = " << a) : (cout << "Max = " << b);
    
    // TASK 9
    // int age = 20;
    // string status;
    // if (age >= 18) {
    //     status = "Adult";
    // } else {
    //     status = "Minor";
    // }
    // cout << "Age = " << age << " - " << status;

    // TASK 10
    // int a, b, c;
    // c = (a=5, b=7, a+b);
    // cout << "a=" << a << " b=" << b << " c=" << c;

    // TASK 11
    // cout << "Size of char = " << sizeof(char) << endl;
    // cout << "Size of char16_t = " << sizeof(char16_t) << endl;
    // cout << "Size of char32_t = " << sizeof(char32_t) << endl;
    // cout << "Size of wchar_t = " << sizeof(wchar_t) << endl;
    // cout << "Size of signed char = " << sizeof(signed char) << endl;
    // cout << "Size of signed short int = " << sizeof(signed short int) << endl;
    // cout << "Size of signed int = " << sizeof(signed int) << endl;
    // cout << "Size of signed long int = " << sizeof(signed long int) << endl;
    // cout << "Size of signed long long int = " << sizeof(signed long long int) << endl;
    // cout << "Size of unsigned char = " << sizeof(unsigned char) << endl;
    // cout << "Size of unsigned short int = " << sizeof(unsigned short int) << endl;
    // cout << "Size of unsigned int = " << sizeof(unsigned int) << endl;
    // cout << "Size of unsigned long int = " << sizeof(unsigned long int) << endl;
    // cout << "Size of unsigned long long int = " << sizeof(unsigned long long int) << endl;
    // cout << "Size of float = " << sizeof(float) << endl;
    // cout << "Size of double = " << sizeof(double) << endl;
    // cout << "Size of long double = " << sizeof(long double) << endl;

    // TASK 12
    // int a = -744, b = 67;
    // double d = 0.279;
    // char c = 'k';
    // bool t = true;
    // cout << "Size of int a: " << sizeof(a) << endl;
    // cout << "Size of int b: " << sizeof(b) << endl;
    // cout << "Size of char c: " << sizeof(c) << endl;
    // cout << "Size of double d: " << sizeof(d) << endl;
    // cout << "Size of bool t: " << sizeof(t) << endl;
    // cout << "Size of (a+b): " << sizeof(a+b) << endl;

    // TASK 13
    // double pi = 3.14159;
    // int pi_int = (int)pi;
    // int pi_int2 = int(pi);
    // cout << "pi_int = (int)pi: " << pi_int << endl;
    // cout << "pi_int2 = int(pi): " << pi_int2 << endl;

    // TASK 14
    // float f = 9.99;
    // int f_int = int(f);
    // char f_ch = f_int;
    // cout << "float f = " << f << endl;
    // cout << "int f = " << f_int << endl;
    // cout << "char f = " << f_ch << endl;

    // TASK 15
    // int var = 42;
    // cout << "var: " << var << endl;
    // cout << "&var: " << &var << endl;

    // TASK 16
    // int x=5, y=10, z=0;
    // z = (x+=3)*(y-=2)+(++x)-(y--);
    // cout << "x = 5, y = 10, z = (x+=3)*(y-=2)+(++x)-(y--)\nz = " << z;

    // TASK 17
    // int a=2, b=3, c=4;
    // int res = a + b * c - a / b % c;
    // int res1 = (a + (b * c)) - (a / (b % c));
    // cout << "result = a + b * c - a / b % c = " << res << endl;
    // cout << "result = (a + (b * c)) - (a / (b % c)) = " << res1; 

    // TASK 18
    // signed char a = CHAR_MAX;
    // short b = SHRT_MAX;
    // int c = INT_MAX;
    // long d = LONG_MAX;
    // long long e = LLONG_MAX;
    // unsigned char a1 = UCHAR_MAX;
    // unsigned short b1 = USHRT_MAX;
    // unsigned int c1 = UINT_MAX;
    // unsigned long d1 = ULONG_MAX;
    // unsigned long long e1 = ULLONG_MAX;
    // cout << "Max of signed char = " << a << endl;
    // cout << "Max of short = " << b << endl;
    // cout << "Max of int = " << c << endl;
    // cout << "Max of long = " << d << endl;
    // cout << "Max of long long = " << e << endl;
    // cout << "Max of unsigned char = " << a1 << endl;
    // cout << "Max of unsigned short = " << b1 << endl;
    // cout << "Max of unsigned int = " << c1 << endl;
    // cout << "Max of unsigned long = " << d1 << endl;
    // cout << "Max of unsigned long long = " << e1 << endl;

    // TASK 19
    // float a = 1.0/3.0;
    // double b = 1.0/3.0;
    // long double c = 1.0/3.0;
    // cout << "float 1.0/3.0 = " << fixed << cout.precision(15) << a << endl;
    // cout << "double 1.0/3.0 = " << fixed << cout.precision(15) << b << endl;
    // cout << "long double 1.0/3.0 = " << fixed << cout.precision(15) << c << endl;

    // TASK 20
    // char ch = 'A';
    // char16_t u16 = u'B';
    // char32_t u32 = U'C';
    // wchar_t w = L'D';
    // bool flag = true;
    // cout << "char: " << ch << ", int(char): " << int(ch) << endl;
    // cout << "char16_t: " << u16 << ", int(char16_t): " << int(u16) << endl;
    // cout << "char32_t: " << u32 << ", int(char32_t): " << int(u32) << endl;
    // cout << "wchar_t: " << w << ", int(wchar_t): " << int(w) << endl;
    // cout << "bool: " << boolalpha << flag << ", int(bool): " << int(flag) << endl;

    // TASK 21
    // int i;
    // float f;
    // char c;
    // cout << "Enter the integer i: ";
    // cin >> i;
    // cout << "Enter the float f: ";
    // cin >> f;
    // cout << "Enter the char c: ";
    // cin >> c;
    // int a = int(f);
    // int b = c;
    // cout << "float f >>> int a: " << f << " >>> " << a << endl;
    // cout << "char c >>> int b: " << c << " >>> " << b << endl;
    // cout << "i + a = " << i+a << endl;
    // cout << "i - b = " << i-b << endl;
    // if (i>a) {
    //     cout << "i > a" << endl;
    // } else if (i<a) {
    //     cout << "i < a" << endl;
    // } else {
    //     cout << "i = a" << endl;
    // }
    // cout << "(i>10) && (b<100) - " << boolalpha << ((i>10)&&(b<100)) << endl;
    // cout << "Size of int i = " << sizeof(i) << endl;
    // cout << "Size of float f = " << sizeof(f) << endl;
    // cout << "Size of char c = " << sizeof(c) << endl;
    
    return 0; 
}