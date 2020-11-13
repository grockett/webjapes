#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
using namespace std;
namespace fs = std::filesystem;

int main() {
    vector<filesystem::path> files;
    filesystem::path path{ filesystem::current_path() };
    cout << "Path: " << path;

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.path().extension() == ".css")
        {
            files.push_back(entry.path());
        }       
    }

    for (auto file : files) {
        cout << "CSS file found:" << file << endl;
        fstream filez;
        string content;
        vector<string> lines;
        
        filez.open(file, ios::in);
        if (filez.is_open()) {  
            string tp;
            while (getline(filez, tp)) {
                lines.push_back(tp);
            }
            filez.close();
        }

        reverse(lines.begin(), lines.end());

        filez.open(file, ios::out);
        if (filez.is_open())    
        {
            for (string line : lines) {
                filez << line << endl;
            }
            filez.close(); 
        }
    }
}