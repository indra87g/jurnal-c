#pragma once
#define PI 3.141
#define ARRAY_LENGTH 6

typedef char* str;

void hello(str myName, str yourName);
void sum_form();
void newjson(str filename, str name, int age);
void newfile(str filename, str message);
void minecraft_coords(str place);
void openfile(str filename);
int factorial(int num);
int sum(int num1, int num2);
int circleArea(int radius);

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int id;
    Date birthday;
    char name[50];
    float score;
} Player;

typedef struct {
    int x, y, z;
} Coords;

union Data {
    int data1;
    float data2;
    char data3[15];
};