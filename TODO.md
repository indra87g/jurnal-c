# Daftar Hal untuk Dipelajari Selanjutnya di C

Selamat! Anda sudah menguasai banyak konsep fundamental dalam bahasa C. Berikut adalah beberapa topik lanjutan yang direkomendasikan untuk memperdalam pemahaman Anda.

## 1. Manajemen Error Tingkat Lanjut
Anda sudah mulai menangani error (misalnya, `fopen` gagal), tetapi ada cara yang lebih sistematis untuk melakukannya.
- **`stderr`**: Pelajari kapan dan mengapa harus mencetak pesan error ke *standard error* (`stderr`) daripada *standard output* (`stdout`).
- **`errno` dan `perror`**: Pahami cara menggunakan variabel global `errno` dan fungsi `perror` untuk mendapatkan pesan error yang deskriptif dari sistem.
- **Exit Codes**: Gunakan `exit(EXIT_FAILURE)` untuk menghentikan program saat terjadi error fatal.

## 2. Pointer dan Manajemen Memori Dinamis
Pointer adalah salah satu fitur paling kuat di C. Pemahaman yang mendalam sangat penting.
- **Aritmatika Pointer**: Pelajari cara melakukan operasi matematika pada pointer (increment, decrement) dan bagaimana ini berhubungan dengan tipe data yang ditunjuk.
- **`calloc` dan `realloc`**: Selain `malloc`, pelajari `calloc` (yang menginisialisasi memori menjadi nol) dan `realloc` (untuk mengubah ukuran alokasi memori yang ada).
- **Pointer ke Fungsi**: Anda sudah menggunakannya! Dalami lebih lanjut, misalnya membuat array dari function pointer untuk menggantikan `if-else` atau `switch-case`.
- **Pointer ke Pointer (`**`)**: Pahami kasus penggunaan pointer ke pointer, misalnya saat Anda ingin sebuah fungsi mengubah pointer yang dioperkan padanya.

## 3. Struktur Data Fundamental
Array dan `struct` adalah awal yang baik. Sekarang coba implementasikan struktur data yang lebih dinamis.
- **Linked List (Senarai Berantai)**: Implementasikan *singly linked list*, *doubly linked list*, dan *circular linked list*. Ini akan sangat melatih pemahaman Anda tentang pointer dan `malloc`/`free`.
- **Stack dan Queue**: Implementasikan struktur data LIFO (Last-In, First-Out) dan FIFO (First-In, First-Out) menggunakan array atau linked list.
- **Hash Table**: Pelajari konsep hashing dan coba implementasikan hash table sederhana untuk penyimpanan dan pencarian data yang efisien.

## 4. Sistem Build dan Tooling
- **`Makefile` Lanjutan**: Pelajari tentang variabel, aturan implisit, dan *phony targets* (seperti `clean` dan `all`) di Makefile untuk mengotomatisasi proses kompilasi Anda secara lebih efisien.
- **Debugger (`gdb`)**: Belajar menggunakan GNU Debugger (`gdb`) adalah *game-changer*. Anda bisa menjalankan kode baris per baris, memeriksa nilai variabel, dan menemukan bug dengan jauh lebih cepat.
- **Valgrind**: Gunakan Valgrind untuk mendeteksi *memory leak* dan kesalahan manajemen memori lainnya.

## 5. Unit Testing
Menulis tes untuk kode Anda adalah praktik rekayasa perangkat lunak yang sangat baik.
- **Framework Testing**: Lihat framework testing sederhana seperti `minunit` atau yang lebih lengkap seperti `Check` atau `Unity` untuk mulai menulis tes otomatis untuk fungsi-fungsi Anda.

## 6. Mendalami Pustaka Standar C
Pustaka standar C sangat kaya. Jelajahi lebih banyak file header.
- **`<string.h>`**: Pelajari fungsi-fungsi lain seperti `strncpy`, `strcat`, `strchr`, `strstr`.
- **`<stdlib.h>`**: Jelajahi fungsi konversi string seperti `atoi`, `atof`, `strtol`.
- **`<math.h>`**: Gunakan fungsi matematika seperti `sqrt`, `pow`, `sin`, `cos`, dan konstanta seperti `M_PI`.

Semoga berhasil dalam perjalanan belajar Anda selanjutnya!
