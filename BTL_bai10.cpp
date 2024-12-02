#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Lớp SoLon
class SoLon {
private:
    vector<int> digits;  // Sử dụng vector để lưu trữ các chữ số

public:
    // Hàm khởi tạo số lớn từ chuỗi
    SoLon(string s) {
        for (char c : s) {
            if (isdigit(c)) {
                digits.push_back(c - '0');  // Chuyển ký tự thành chữ số
            }
        }
    }

    // In số lớn ra màn hình
    void print() const {
        for (int digit : digits) {
            cout << digit;
        }
        cout << endl;
    }

    // Nhân một số lớn với một số nguyên
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
        reverse(result.begin(), result.end());  // Đảo ngược kết quả
        SoLon resultSoLon("");
        resultSoLon.digits = result;
        return resultSoLon;
    }

    // Nhân hai số lớn
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

       // Tạo SoLon từ vector kết quả
        int startIndex = 0;
        while (startIndex < tempResult.size() && tempResult[startIndex] == 0) {
            ++startIndex;
        }

        for (int i = startIndex; i < tempResult.size(); ++i) {
            result.digits.push_back(tempResult[i]);
        }

        return result;
    }

    // Cộng hai số lớn
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
        reverse(result.begin(), result.end());  // Đảo ngược kết quả
        SoLon sumResult("");
        sumResult.digits = result;
        return sumResult;
    }

    // Trừ hai số lớn
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

        // Loại bỏ các số 0 thừa ở đầu
        int startIndex = result.size() - 1;
        while (startIndex > 0 && result[startIndex] == 0) {
            --startIndex;
        }

        result.resize(startIndex + 1);
        reverse(result.begin(), result.end());  // Đảo ngược kết quả
        SoLon diffResult("");
        diffResult.digits = result;
        return diffResult;
    }
};

// Tính số Fibonacci thứ n
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

// Tính giai thừa của số n
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

    // Tính số Fibonacci thứ n
    cout << "So Fibonacci thu " << n << " la: ";
    fibonacci(n).print();

    // Tính giai thừa của n
    cout << "Giai thua cua " << n << " la: ";
    factorial(n).print();

    return 0;
}

