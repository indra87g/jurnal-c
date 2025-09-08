#pragma once
#include <stdlib.h>  // Direkomendasikan untuk menyertakan header standar yang relevan

// Mendefinisikan konstanta PI. Untuk presisi lebih tinggi, pertimbangkan
// menggunakan M_PI dari <math.h> setelah memeriksa ketersediaannya.
#define PI 3.141
#define ARRAY_LENGTH 6

// Menggunakan 'typedef char* str' bisa menyembunyikan sifat pointer dari tipe data,
// yang dapat menyebabkan kebingungan. Umumnya lebih baik menggunakan 'char*' secara
// eksplisit untuk kejelasan.
typedef char* str;

// Deklarasi fungsi utilitas
void hello(str myName, str yourName);
void sum_form();
void newjson(str filename, str name, int age);
void newfile(str filename, str message);
void minecraft_coords(str place);
void openfile(str filename);
int factorial(int num);
// Deklarasi 'sum' tidak seharusnya ada di sini karena definisinya ada di calculate.c.
// Seharusnya dideklarasikan di calculate.h untuk menjaga konsistensi.
// int sum(int num1, int num2);
int circleArea(int radius);

// struct untuk merepresentasikan tanggal
typedef struct {
    int day, month, year;
} Date;

// struct untuk merepresentasikan data pemain.
// Menggunakan array char 'name[50]' adalah pendekatan yang aman untuk string
// dengan panjang yang diketahui untuk menghindari alokasi memori manual.
typedef struct {
    int id;
    Date birthday;
    char name[50];
    float score;
} Player;

// struct sederhana untuk menyimpan koordinat 3D.
typedef struct {
    int x, y, z;
} Coords;

// Union adalah tipe data khusus di mana semua anggota berbagi lokasi memori yang sama.
// Ukuran union adalah ukuran anggota terbesarnya.
// Berguna untuk menginterpretasikan data yang sama dalam cara yang berbeda atau untuk
// menghemat memori ketika hanya satu anggota yang akan digunakan pada satu waktu.
union Data {
    int data1;
    float data2;
    char data3[15];
};