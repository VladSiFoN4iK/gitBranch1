#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;

// Функция №1
vector<string> readLines(const string& path);
// Функция №2
void printLines(const vector<string>& lines);
// Функция №3
void writeLines(const vector<string>& lines, const string& path);

int main() {
    const string inputPath = "input.txt";
    const string outputPath = "output.txt";

    auto lines = readLines(inputPath);
    printLines(lines);
    writeLines(lines, outputPath);

    std::cout << "Done.\n";
    return 0;
}


vector<string> readLines(const string& path) {
    
    std::ifstream in(path);
    vector<string> lines;

    if (!in.is_open()) {
        return lines;
    }

    string s;
    while (std::getline(in, s)) {
        lines.push_back(s);
    }
    return lines;
}

void printLines(const vector<string>& lines) {
    for (const auto& s : lines) {
        std::cout << s << '\n';
    }
}


void writeLines(const vector<string>& lines, const string& path) {
    std::ofstream out(path);
    for (const auto& s : lines) {
        out << s << '\n';
    }
}
