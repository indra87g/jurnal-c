#pragma once

#define ARRAY_LENGTH 6

typedef char* str;

// Deklarasi fungsi utilitas
void sum_form();
void newjson(str filename, str name, int age);
void newfile(str filename, str myName, str yourName);
void minecraft_coords(str place);
void openfile(str filename);
void wait();

// struct untuk merepresentasikan tanggal
typedef struct {
    int day, month, year;
} Date;

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

union Data {
    int data1;
    float data2;
    char data3[15];
};