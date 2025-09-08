#pragma once

// Header ini mendeklarasikan fungsi-fungsi yang berhubungan dengan kalkulasi matematika.
// Menggunakan file header terpisah untuk modul yang berbeda (seperti kalkulasi)
// adalah praktik yang baik untuk menjaga keteraturan dan modularitas kode.

// Menjumlahkan dua integer.
int sum(int a, int b);

// Mengurangkan dua integer.
int sub(int a, int b);

// Mengalikan dua integer.
int mul(int a, int b);

// Membagi dua integer. Perhatikan implementasi di .c untuk penanganan kasus pembagian dengan nol.
int divide(int a, int b);

// Fungsi tingkat tinggi (higher-order function) yang menerima pointer ke fungsi sebagai argumen.
// Ini adalah contoh dari "callback", memungkinkan operasi yang fleksibel.
int calculate(int a, int b, int (*op)(int, int));