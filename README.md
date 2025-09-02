# The C Journal

## 16-08-2025
- Ada beberapa format specifier:
    - `%d` untuk integer
    - `%f` untuk float dan double
    - `%c` untuk char dengan karakter tunggal
    - `%s` untuk array of char
    - `%x` atau `%X` untuk hexadecimal
- `char` adalah datatype untuk satu karakter. gunakan `char variabel[]` atau `char *variabel` untuk lebih dari satu karakter.
- `return 0` menandakan program sukses, sedangkan `return 1` berlaku sebaliknya
- function void tidak bisa menggunakan `return`. hanya function `main` yang bisa menggunakannya

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
    - Gunakan `typedef unsigned` untuk memberikan alias ke tipe data bawaan
    - Ketika bikin `typedef` untuk array, nama tipenya harus diletakkan setelah setelah ukuran array

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
- `malloc` digunakan untuk membuat variabel dengan ukuran sebanyak data yang dimasukkan user
    - Setelah digunakan, memori dibebaskan dengan `free(variabel)`
- `pragma once` adalah include guard yang lebih ringkas dan modern daripada `ifndef`

## 24-08-2025
- Callback adalah fungsi yang diteruskan sebagai argumen ke fungsi lain
- `enum` adalah tipe data untuk membuat daftar label yang akan disimpan sebagai angka
## 02-09-2025
- `static` digunakan untuk mengubah scope dan lifetime dari sebuah variabel/fungsi
    - jika digunakan secara global, maka variabel/fungsi yg bersangkutan akan diisolasi
    - jika digunakan secara lokal, maka variabel yg bersangkutan nilainya akan disimpan, bahkan saat sudah keluar dari fungsi
- `struct` bisa diletakan di struct lain (nested), maupun dikumpulkan dalam sebuah array (array of struct)
- Dereference adalah teknik untuk mengambil isi dari alamat memori yg disimpan oleh pointer
- Dangling pointer terjadi ketika pointer menunjuk memori yang tidak valid
- Buffer overflow terjadi jika data lebih banyak daripada ukuran array 