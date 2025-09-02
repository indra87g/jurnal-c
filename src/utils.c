#include "utils.h"

#include <stdio.h>
#include <string.h>

#include "cJSON.h"

void hello(str myName, str yourName) { printf("%s: Hello %s!\n", myName, yourName); }

void sum_form() {
    int num1, num2, sum;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    printf("Result: %d\n", sum);
}

void newjson(str filename, str name, int age) {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", name);
    cJSON_AddNumberToObject(root, "age", age);

    str json_str = cJSON_Print(root);
    FILE *fp = fopen(filename, "w");

    if (fp) {
        fputs(json_str, fp);
        fclose(fp);
    }

    cJSON_Delete(root);
    free(json_str);
}

void newfile(str filename, str message) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File not found!\n");
    }

    fprintf(fp, "%s", message);
    fclose(fp);
}

void openfile(str filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s\n", buffer);
    }
    fclose(fp);
}

void minecraft_coords(str place) {
    Coords coordinates[3] = {{100, 75, 100}, {125, 70, 150}, {1250, 80, 500}};
    Coords selected;
    str place_now = "Unknown";

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
    printf("Your %s location: %d %d %d\n", place_now, selected.x, selected.y, selected.z);
}

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int circleArea(int radius) { return PI * radius * radius; }