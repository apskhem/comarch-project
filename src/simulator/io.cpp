#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int get_file_size(string path) {
    ifstream in_file(path, ios::binary);

    if (!in_file) {
        throw runtime_error("could not open file " + path + ".");
    }

    in_file.seekg(0, ios::end);
    int fsize = in_file.tellg();

    in_file.close();

    return fsize;
}

char* load_file_buffer(string path, int size) {
    char* const buffer = new char[size];

    ifstream in_file(path, ios::binary);

    if (!in_file) {
        throw runtime_error("could not open file " + path + ".");
    }

    in_file.read(buffer, size);
    in_file.close();

    return buffer;
}