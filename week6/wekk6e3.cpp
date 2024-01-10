#include <iostream>
#include <cstring>
using namespace std;

class String {
  private:
    unsigned buflen;
    char *buffer;

  public:
    // 构造函数
    String(): buflen(0), buffer(nullptr) {}
    String(unsigned n): buflen(n), buffer(new char[buflen + 1]) {
        memset(buffer, 0, buflen + 1);
    }
    String(char c): buflen(1), buffer(new char[2]) {
        buffer[0] = c;
        buffer[1] = '\0';
    }
    String(const char* s): buflen(strlen(s)), buffer(new char[buflen + 1]) {
        strcpy(buffer, s);
    }
    // 拷贝构造函数
    String(const String& s): buflen(s.buflen), buffer(new char[buflen + 1]) {
        strcpy(buffer, s.buffer);
    }
    // 析构函数
    ~String() {
        if (buffer) {
            delete[] buffer;
        }
    }
    // 重新赋值运算符
    String& operator=(const String &right) {
        if (this != &right) {
            if (buffer) {
                delete[] buffer;
            }
            buflen = right.buflen;
            buffer = new char[buflen + 1];
            strcpy(buffer, right.buffer);
        }
        return *this;
    }
    String& operator+=(const String &right) {
        unsigned newlen = buflen + right.buflen;
        char* newbuf = new char[newlen + 1];
        strcpy(newbuf, buffer);
        strcat(newbuf, right.buffer);
        if (buffer) {
            delete[] buffer;
        }
        buflen = newlen;
        buffer = newbuf;
        return *this;
    }
    // 重载字符串连接运算符
    friend String operator+(const String &left, const String &right) {
        String result(left);
        result += right;
        return result;
    }
    // 通过重载（）运算实现取子串
    String operator()(unsigned start, unsigned len) {
        if (start >= buflen) {
            return String();
        }
        if (start + len > buflen) {
            len = buflen - start;
        }
        char* newbuf = new char[len + 1];
        strncpy(newbuf, buffer + start, len);
        newbuf[len] = '\0';
        String result(newbuf);
        delete[] newbuf;
        return result;
    }
    // 通过成员函数实现子串
    String substr(unsigned start, unsigned len) const {
        if (start >= buflen) {
            return String();
        }
        if (start + len > buflen) {
            len = buflen - start;
        }
        char* newbuf = new char[len + 1];
        strncpy(newbuf, buffer + start, len);
        newbuf[len] = '\0';
        String result(newbuf);
        delete[] newbuf;
        return result;
    }
    // 字符串长度
    unsigned length() const {
        return buflen;
    }
    // 访问单个字符
    char& operator[](unsigned index) const {
        if (index >= buflen) {
            static char nullchar = '\0';
            return nullchar;
        }
        return buffer[index];
    }
    // 字符串比较
    int compare(const String& s) const {
    return strcmp(buffer, s.buffer);
}
// 到普通c字符串的转换
operator const char*() const {
    return buffer;
}
// 字符串输出
friend ostream &operator<<(ostream &out, const String &s) {
    out << s.buffer;
    return out;
}
// 字符串输入
friend istream &operator>>(istream &in, String &s) {
    char tmp[1024];
    in >> tmp;
    s = String(tmp);
    return in;
}
};

int main() {
String s1 = "hello";
String s2 = "world";
String s3 = s1 + s2;
String s4 = s3.substr(2, 5);
cout << "s1: " << s1 << endl;
cout << "s2: " << s2 << endl;
cout << "s3: " << s3 << endl;
cout << "s4: " << s4 << endl;
s1[0] = 'H';
cout << "s1: " << s1 << endl;
cout << "s1 == s2: " << (s1 == s2) << endl;
cout << "s1.compare(s2): " << s1.compare(s2) << endl;
cout << "Enter a string: ";
String s5;
cin >> s5;
cout << "s5: " << s5 << endl;
return 0;
}