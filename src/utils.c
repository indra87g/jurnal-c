#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cJSON.h"

void sum_form() {
    int num1, num2, sum;
    printf("Enter first number: ");
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
        fprintf(stderr, "Failed to open file %s for writing.\n", filename);
    }

    cJSON_Delete(root);
    free(json_str);
}

void newfile(str filename, str myName, str yourName) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%s: Hello, %s!", myName, yourName);
    fclose(fp);
}

void openfile(str filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}

void minecraft_coords(str place) {
    Coords coordinates[3] = {{100, 75, 100}, {125, 70, 150}, {1250, 80, 500}};
    Coords selected = {0, 0, 0};
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

    if (strcmp(place_now, "Unknown") == 0) {
        printf("Location '%s' not found.\n", place);
    } else {
        printf("\x1b[32mYour %s location: %d %d %d\n", place_now, selected.x, selected.y,
               selected.z);
    }
}

void wait() {
    printf("Wait a minute -");
    while (1) {
        usleep(200000);
        printf("\b\\");
        fflush(stdout);
        usleep(200000);
        printf("\b!");
        fflush(stdout);
        usleep(200000);
        printf("\b/");
        fflush(stdout);
        usleep(200000);
        printf("\b-");
        fflush(stdout);
    }
}