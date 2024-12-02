#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// L?p SoLon (S? L?n)
class SoLon {
private:
    vector<int> digits;  // S? d?ng vector ð? lýu tr? các ch? s?

public:
    // Hàm kh?i t?o s? l?n t? chu?i
    SoLon(string s) {
        for (char c : s) {
            if (isdigit(c)) {
                digits.push_back(c - '0');  // Chuy?n k? t? thành ch? s?
            }
        }
    }

    // In s? l?n ra màn h?nh
    void print() const {
        for (int digit : digits) {
            cout << digit;
        }
        cout << endl;
    }

    // Nhân m?t s? l?n v?i m?t s? nguyên
    SoLon operator*(int n) const {
        vector<int> result;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int product = digits[i] * n + carry;
            result.push_back(product % 10);
            carry = product / 10;
        }
        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
        reverse(result.begin(), result.end());  // Ð?o ngý?c k?t qu?
        SoLon resultSoLon("");
        resultSoLon.digits = result;
        return resultSoLon;
    }

    // Nhân hai s? l?n
    SoLon operator*(const SoLon& other) const {
        SoLon result("0");
        vector<int> tempResult(digits.size() + other.digits.size(), 0);

        for (int i = digits.size() - 1; i >= 0; --i) {
            for (int j = other.digits.size() - 1; j >= 0; --j) {
                int product = digits[i] * other.digits[j];
                int sum = product + tempResult[i + j + 1];
                tempResult[i + j + 1] = sum % 10;
                tempResult[i + j] += sum / 10;
            }
        }

        // T?o SoLon t? vector k?t qu?
        int startIndex = 0;
        while (startIndex < tempResult.size() && tempResult[startIndex] == 0) {
            ++startIndex;
        }

        for (int i = startIndex; i < tempResult.size(); ++i) {
            result.digits.push_back(tempResult[i]);
        }

        return result;
    }

    // C?ng hai s? l?n
    SoLon operator+(const SoLon& other) const {
        vector<int> result;
        int carry = 0;
        int i = digits.size() - 1, j = other.digits.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += digits[i--];
            }
            if (j >= 0) {
                sum += other.digits[j--];
            }
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());  // Ð?o ngý?c k?t qu?
        SoLon sumResult("");
        sumResult.digits = result;
        return sumResult;
    }

    // Tr? hai s? l?n
    SoLon operator-(const SoLon& other) const {
        vector<int> result;
        int borrow = 0;
        int i = digits.size() - 1, j = other.digits.size() - 1;

        while (i >= 0 || j >= 0) {
            int diff = borrow;
            if (i >= 0) {
                diff += digits[i--];
            }
            if (j >= 0) {
                diff -= other.digits[j--];
            }

            if (diff < 0) {
                diff += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }

            result.push_back(diff);
        }

        // Lo?i b? các s? 0 th?a ? ð?u
        int startIndex = result.size() - 1;
        while (startIndex > 0 && result[startIndex] == 0) {
            --startIndex;
        }

        result.resize(startIndex + 1);
        reverse(result.begin(), result.end());  // Ð?o ngý?c k?t qu?
        SoLon diffResult("");
        diffResult.digits = result;
        return diffResult;
    }
};

// Tính s? Fibonacci th? n
SoLon fibonacci(int n) {
    SoLon a("0");
    SoLon b("1");

    for (int i = 2; i <= n; ++i) {
        SoLon c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Tính giai th?a c?a s? n
SoLon factorial(int n) {
    SoLon result("1");
    for (int i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result;
}

int main() {
    int n;
    cout << "Nhap n (1 <= n <= 1000): ";
    cin >> n;

    // Tính s? Fibonacci th? n
    cout << "So Fibonacci thu " << n << " la: ";
    fibonacci(n).print();

    // Tính giai th?a c?a n
    cout << "Giai thua cua " << n << " la: ";
    factorial(n).print();

    return 0;
}

