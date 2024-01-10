#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 打开输入文件和输出文件
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    // 确保文件已经成功打开
    if (!input_file.is_open()) {
        cerr << "Error: Failed to open input file" << endl;
        return 1;
    }

    if (!output_file.is_open()) {
        cerr << "Error: Failed to open output file" << endl;
        return 1;
    }

    // 循环读取输入文件中的每一行并写入到输出文件中
    string line;
    while (getline(input_file, line)) {
        output_file << line << endl;
    }

    // 关闭文件
    input_file.close();
    output_file.close();

    cout << "File copy successful" << endl;

    return 0;
}
