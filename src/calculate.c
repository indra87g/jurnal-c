#include <stdio.h>
#include <limits.h> // Diperlukan untuk konstanta seperti INT_MIN

// Implementasi fungsi-fungsi dasar matematika.

int sum(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

// Implementasi fungsi pembagian.
int divide(int a, int b) {
    // Menangani pembagian dengan nol adalah hal yang sangat penting untuk mencegah
    // "undefined behavior" atau crash pada program.
    if (b != 0) {
        return a / b;
    } else {
        // Mengembalikan nilai '1' saat pembagian dengan nol bisa membingungkan.
        // Praktik yang lebih baik adalah mengembalikan nilai error yang jelas,
        // seperti INT_MIN (dari <limits.h>), dan memberi tahu pemanggil fungsi
        // bahwa terjadi error. Cara lain adalah dengan mengatur variabel error global (seperti errno).
        fprintf(stderr, "Error: Division by zero.\n");
        return 0; // Atau nilai error lain yang didokumentasikan.
    }
}

// Implementasi fungsi 'calculate' yang menggunakan function pointer.
// Ini adalah pola desain yang kuat yang memungkinkan perilaku dinamis.
// Fungsi ini tidak tahu operasi apa yang akan dilakukan; ia hanya mengeksekusi
// fungsi 'op' yang diberikan padanya.
int calculate(int a, int b, int (*op)(int, int)) { return op(a, b); }