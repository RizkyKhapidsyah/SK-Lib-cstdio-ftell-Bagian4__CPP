#pragma warning(disable:4996)

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

// Jika kondisi tidak terpenuhi maka keluar dari program dengan pesan kesalahan.
void check(bool condition, const char* func, int line) {
    if (condition) {
        return;
    }
        
    std::perror(func);
    std::cerr << func << " failed in file " << __FILE__ << " at line # " << line - 1 << '\n';
    std::exit(EXIT_FAILURE);
}

int main() {
    // Siapkan array nilai FP.
    constexpr int SIZE{ 5 };
    double A[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    // Tulis array ke file.
    const char* fname = "/tmp/test.bin";
    FILE* file = std::fopen(fname, "wb");
    check(file != NULL, "fopen()", __LINE__);

    const int write_count = std::fwrite(A, sizeof(double), SIZE, file);
    check(write_count == SIZE, "fwrite()", __LINE__);

    std::fclose(file);

    // Baca nilai FP ke dalam array B.
    double B[SIZE];
    file = std::fopen(fname, "rb");
    check(file != NULL, "fopen()", __LINE__);

    long pos = std::ftell(file); // indikator posisi di awal file
    check(pos != -1L, "ftell()", __LINE__);
    std::cout << "pos: " << pos << '\n';

    const int read_count = std::fread(B, sizeof(double), 1, file); // baca satu nilai FP
    check(read_count == 1, "fread()", __LINE__);

    pos = std::ftell(file); // indikator posisi setelah membaca satu nilai FP
    check(pos != -1L, "ftell()", __LINE__);
    std::cout << "pos: " << pos << '\n';
    std::cout << "B[0]: " << B[0] << '\n'; // cetak satu nilai FP

    _getch();
    return EXIT_SUCCESS;
}