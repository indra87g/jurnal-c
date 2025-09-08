#include <stdio.h>  // Untuk fungsi I/O seperti printf
#include <string.h> // Untuk fungsi string seperti strcmp (digunakan di dalam utils.c)

// Menyertakan header kustom. Ini adalah praktik yang baik untuk memisahkan
// deklarasi fungsi ke dalam file-file yang relevan.
#include "calculate.h"
#include "utils.h"

// `main` adalah titik masuk (entry point) dari setiap program C.
// Bentuk `int main(void)` atau `int main(int argc, char *argv[])` adalah standar.
int main() {
    // --- Inisialisasi Variabel ---
    // Merupakan praktik yang baik untuk menginisialisasi variabel saat dideklarasikan.
    int num1 = 7;
    int num2 = num1 - 5;

    // --- Penggunaan Function Pointer ---
    // Memanggil fungsi 'calculate' dengan 'mul' sebagai argumen callback.
    int result = calculate(num1, num2, mul);

    // --- Pemanggilan Fungsi dari Modul Lain ---
    int factorialResult = factorial(result);
    int realArray[ARRAY_LENGTH] = {1, num1, 3, num2, 5, result};
    // Perhatikan bahwa circleArea mengembalikan int, yang mungkin menyebabkan kehilangan presisi.
    int circleAreaResult = circleArea(result);
    float float1 = 20.5;
    str pythonCode = "def main(name):\n\treturn name\n";

    // --- Inisialisasi Struct ---
    // Cara yang bersih untuk menginisialisasi struct.
    Player player = {1, {7, 5, 2009}, "Indra", 97.5};
    int player_age = 2025 - player.birthday.year;

    // --- Output ---
    // Mencetak informasi yang telah diproses ke konsol.
    printf("ID: %d\nName: %s\nAge: %d\nScore: %f\n", player.id, player.name, player_age,
           player.score);
    printf("Result: %d\n", result);
    printf("Circle Area: %d\n", circleAreaResult);
    printf("FakeArray: [%d, %f]\n", num1, float1);
    hello(player.name, "John");
    printf("%s", pythonCode);

    // --- Looping ---
    // Loop for untuk mencetak isi array.
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("RealArray: %d\n", realArray[i]);
    }
    printf("Factorial Result: %d\n", factorialResult);

    // --- Operasi File dan JSON ---
    // Memanggil fungsi-fungsi utilitas yang telah Anda buat.
    minecraft_coords("home");
    newfile("data.txt", "Hello");
    openfile("data.txt");
    newjson("data.json", player.name, player_age);

    // Mengembalikan 0 dari main menandakan bahwa program telah selesai dengan sukses.
    return 0;
}