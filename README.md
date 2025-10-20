# The C Journal

[![wakatime](https://wakatime.com/badge/user/e3628b6b-08c8-497a-a679-c268fa16d35e/project/39fd7687-871d-4df9-a3b6-e3b944d769bc.svg)](https://wakatime.com/badge/user/e3628b6b-08c8-497a-a679-c268fa16d35e/project/39fd7687-871d-4df9-a3b6-e3b944d769bc)

## 16-08-2025
- Ada beberapa format specifier:
    - `%d` untuk integer
    - `%f` untuk float dan `%lf` untuk double
    - `%c` untuk char dengan karakter tunggal
    - `%s` untuk array of char
    - `%x` atau `%X` untuk hexadecimal
- `char` adalah datatype string untuk satu karakter. gunakan `char variabel[]` atau `char *variabel` untuk membuat array of char.
- `return 0` (atau `EXIT_SUCCESS`) menandakan program sukses, sedangkan nilai non-zero (seperti `1` atau `EXIT_FAILURE`) menandakan error.
- function `void` tidak bisa mengembalikan nilai (`return value;`), tapi bisa menggunakan `return;` untuk keluar dari fungsi lebih awal. Semua fungsi non-void **harus** mengembalikan nilai yang sesuai dengan tipe datanya.

## 17-08-2025
- Ada dua cara membuat const:
    - secara lokal dengan ```const data_type name = value```
    - secara global dengan ```#define name value```

## 18-08-2025
- Cara membuat loop:
    ```c 
    for (exp1; exp2; exp3) {
        // code block
    }
    ```
- Gunakan `data_type *name = &data` untuk mendapatkan memory address dari variabel 
- Atur jumlah data di Array dengan `data_type name[jumlah] = { data, moredata }`
- Recursion adalah teknik programming dimana sebuah function memanggil dirinya sendiri

## 19-08-2025
- C memiliki sistem module, menggunakan Header file (.h)

## 20-08-2025
- `struct` digunakan untuk menggabungkan beberapa tipe data berbeda menjadi satu
- `union` mirip `struct`, tapi semua fieldnya berbagi memori yang sama
- Struktur dasar file handler:
    ```c 
    FILE *fp = fopen(filename, method);
    ```
    - Selalu cek apakah `fopen` berhasil atau tidak, menggunakan `fp != NULL`
    - Selalu gunakan `fclose` di akhir file handler untuk menghindari memory leak
    - Untuk file besar, gunakan `fread` dan `fwrite`
- `typedef` digunakan untuk memberikan alias ke sebuah tipe data
    - Contoh: `typedef unsigned int uint;`
    - Ketika membuat `typedef` untuk array, nama tipe diletakkan **sebelum** ukuran array. Contoh: `typedef int MyIntArray[10];`

## 21-08-2025
- `Makefile` adalah automation script untuk C/C++
- `clang-format` adalah salah satu formatter untuk C, bisa diakses dengan command:
    ```bash
    clang-format -i *.c *.h
    ```
- cJSON adalah salah satu library untuk memproses file JSON. Contoh:
    ```c 
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "Test", "Indra");
    cJSON_Print(root);
    ```

## 22-08-2025
- `malloc` digunakan untuk mengalokasikan sejumlah byte memori secara dinamis di heap. Fungsi ini mengembalikan pointer ke memori yang dialokasikan tersebut.
    - Setelah digunakan, memori wajib dibebaskan dengan `free(variabel)` untuk mencegah memory leak.
- `pragma once` adalah include guard yang lebih ringkas dan modern daripada `ifndef`

## 24-08-2025
- Callback adalah fungsi yang diteruskan sebagai argumen ke fungsi lain
- `enum` adalah tipe data untuk membuat daftar label yang akan disimpan sebagai angka
## 02-09-2025
- `static` digunakan untuk mengubah scope dan lifetime dari sebuah variabel/fungsi
    - jika digunakan pada variabel/fungsi global, maka scope-nya akan terbatas hanya pada file (.c) tempat ia didefinisikan (internal linkage).
    - jika digunakan pada variabel lokal di dalam fungsi, nilainya akan dipertahankan di antara pemanggilan fungsi (lifetime-nya sepanjang eksekusi program).
- `struct` bisa diletakan di struct lain (nested), maupun dikumpulkan dalam sebuah array (array of struct)
- Dereference adalah teknik untuk mengambil isi dari alamat memori yg disimpan oleh pointer
- Dangling pointer terjadi ketika pointer menunjuk memori yang tidak valid
- Buffer overflow terjadi jika data lebih banyak daripada ukuran array 

## 14-09-2025
- `argc` dan `argv` digunakan untuk mengakses argument command line
    - `argc` untuk menyimpan jumlah argument 
    - `argv` untuk mengakses nilai (string) dari setiap argument
- `strcmp` adalah bagian dari `string.h` yang berfungsi untuk membandingkan string
- 
## 24-09-2025
- `usleep()` adalah bagian dari `unistd.h` yang berfungsi untuk menunda eksekusi program untuk jangka waktu tertentu. Diukur dengan satuan mikrodetik

## 25-09-2025
- "ANSI Escape Sequences" bisa digunakan untuk mewarnai teks yang muncul di terminal

## 15-10-2025
- Pointer bisa digunakan untuk:
    - Mengubah variabel di fungsi (pass by reference)
    - Dynamic memory management
    - Bekerja dengan array dan string
    - Membuat tipe data yang kompleks (Linked List, Tree, Graph)
    - Fungsi pointer

## 19-10-2025
- `stdlib.h` memiliki fungsi fungsi untuk konversi tipe data:
    - `atoi()` berfungsi untuk konversi char ke integer
    - `atof()` berfungsi untuk konversi char ke float
