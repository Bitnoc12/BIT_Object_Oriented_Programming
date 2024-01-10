#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    // 确保输入参数正确
    if (argc != 3) {
        cout << "Usage: file_copy <input_file> <output_file>" << endl;
        return 1;
    }

    // 打开输入文件和输出文件
    ifstream input_file(argv[1]);
    ofstream output_file(argv[2]);

    // 确保文件打开成功
    if (!input_file.is_open() || !output_file.is_open()) {
        cout << "Error: failed to open file" << endl;
        return 1;
    }

    // 从输入文件读取内容并写入输出文件
    string line;
    while (getline(input_file, line)) {
        output_file << line << endl;
    }

    // 关闭文件
    input_file.close();
    output_file.close();

    return 0;
}
