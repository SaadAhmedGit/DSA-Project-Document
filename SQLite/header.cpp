#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;

void convertLittleToBigEndian(uint16_t* data) {
    for (int i = 0; i < 8; ++i) {
        data[i] = (data[i] >> 8) | (data[i] << 8);
    }
}


int main() {
    ofstream fp("example-db.bin", ios::out | ios::binary);
    uint16_t n = 65;
    //fp.seekg(16);
    fp.write((char*)&n, sizeof(n));
    //convertLittleToBigEndian(&n);
    //cout << n << endl;
}
