#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Diperlukan untuk free()

#include "cJSON.h"

void hello(str myName, str yourName) { printf("%s: Hello %s!\n", myName, yourName); }

void sum_form() {
    int num1, num2, sum;
    printf("Enter first number: ");
    // scanf bisa berbahaya jika input tidak sesuai format yang diharapkan.
    // Selalu periksa nilai kembaliannya untuk memastikan input berhasil dibaca.
    if (scanf("%d", &num1) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return;
    }
    printf("Enter second number: ");
    if (scanf("%d", &num2) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return;
    }

    sum = num1 + num2;
    printf("Result: %d\n", sum);
}

void newjson(str filename, str name, int age) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", name);
    cJSON_AddNumberToObject(root, "age", age);

    str json_str = cJSON_Print(root);
    // Penting untuk memeriksa apakah alokasi memori oleh cJSON_Print berhasil.
    if (json_str == NULL) {
        fprintf(stderr, "Failed to create JSON string.\n");
        cJSON_Delete(root);
        return;
    }

    FILE *fp = fopen(filename, "w");
    if (fp) {
        fputs(json_str, fp);
        fclose(fp);
    } else {
        // Jika file gagal dibuka, tetap penting untuk membebaskan memori yang sudah dialokasikan.
        fprintf(stderr, "Failed to open file %s for writing.\n", filename);
    }

    cJSON_Delete(root); // Membebaskan root object cJSON.
    free(json_str);     // Membebaskan string JSON yang dialokasikan oleh cJSON_Print.
}

void newfile(str filename, str message) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        // Pesan error sebaiknya dicetak ke stderr, bukan stdout.
        perror("Error opening file"); // perror memberikan deskripsi error sistem yang lebih detail.
        return; // Penting untuk keluar dari fungsi jika file tidak bisa dibuka.
    }

    fprintf(fp, "%s", message);
    fclose(fp);
}

void openfile(str filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Buffer dengan ukuran tetap seperti ini berisiko 'buffer overflow' jika
    // ada baris dalam file yang lebih panjang dari ukuran buffer.
    char buffer[100];
    // `fgets` adalah cara yang aman untuk membaca baris per baris karena ia
    // menerima ukuran buffer maksimum untuk mencegah overflow.
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // printf sudah cukup, tidak perlu \n karena fgets menyimpannya.
    }
    fclose(fp);
}

void minecraft_coords(str place) {
    // Menggunakan array of structs adalah cara yang bagus untuk mengelola data terstruktur.
    Coords coordinates[3] = {{100, 75, 100}, {125, 70, 150}, {1250, 80, 500}};
    Coords selected = {0,0,0}; // Inisialisasi 'selected' untuk menghindari nilai acak jika 'place' tidak ditemukan.
    str place_now = "Unknown";

    // Rangkaian if-else if ini berfungsi, tetapi untuk perbandingan string yang banyak,
    // mungkin bisa dipertimbangkan struktur data lain seperti array of structs
    // yang berisi nama tempat dan koordinatnya, lalu di-loop.
    if (strcmp(place, "home") == 0) {
        selected = coordinates[0];
        place_now = "Home";
    } else if (strcmp(place, "farm") == 0) {
        selected = coordinates[1];
        place_now = "Farm";
    } else if (strcmp(place, "village") == 0) {
        selected = coordinates[2];
        place_now = "Village";
    }

    // Jika place_now masih "Unknown", berarti input tidak valid.
    if (strcmp(place_now, "Unknown") == 0) {
         printf("Location '%s' not found.\n", place);
    } else {
         printf("Your %s location: %d %d %d\n", place_now, selected.x, selected.y, selected.z);
    }
}

// Fungsi rekursif untuk menghitung faktorial.
// Perhatikan: fungsi ini bisa mengalami 'stack overflow' untuk 'num' yang besar.
// Juga, tidak menangani input negatif.
int factorial(int num) {
    if (num < 0) {
        fprintf(stderr, "Factorial is not defined for negative numbers.\n");
        return -1; // Mengembalikan nilai error.
    }
    if (num == 0 || num == 1) {
        return 1;
    } else {
        // Panggilan rekursif.
        return num * factorial(num - 1);
    }
}

// Menghitung luas lingkaran.
// Karena PI didefinisikan sebagai 3.141 (float/double) dan radius adalah int,
// hasilnya akan di-truncate menjadi int. Ini menyebabkan hilangnya presisi.
// Sebaiknya, fungsi ini mengembalikan tipe float atau double.
int circleArea(int radius) { return PI * radius * radius; }