//#include <errno.h>
//#include "calculate.h"
//#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colorama.h"
#include "employee.h"

void cmd_employee(int argc, char *argv[]) {
    load_employees("employees.json");
    
    if (argc < 3) {
        printf("Usage: <program_name> employee <action> [args...]\n");
        printf("Actions:\n");
        printf(" employee list\n");
        printf(" employee add <id> <name> <salary>\n");
        printf(" employee update <id> <new_name> <new_salary>\n");
        printf(" employee delete <id>\n");
        return;
    }
    
    const char *action = argv[2];
    
    if (strcmp(action, "list") == 0) {
        display_employees();
    } else if (strcmp(action, "add") == 0) {
        if (argc < 6) {
            printf("Usage:\n");
            return;
        }
        
        int id = atoi(argv[3]);
        int salary = atof(argv[5]);
        
        add_employee(id, argv[4], salary);
    } else if (strcmp(action, "update") == 0) {
        if (argc < 6) {
            printf("Usage:\n");
            return;
        }
        
        int id_to_update = atoi(argv[3]);
        Employee *emp_to_update = find_employee_by_id(id_to_update);
        if (emp_to_update != NULL) {
            float new_salary = atof(argv[5]);
            update_employee_details(emp_to_update, argv[4], new_salary);
        } else {
            printf("Error\n");
        }
    } else if (strcmp(action, "delete") == 0) {
        if (argc < 4) {
            printf("Usage:\n");
            return;
        }
        
        int id_to_delete = atoi(argv[3]);
        
        delete_employee(id_to_delete);
    } else {
        printf("error\n");
    }
    
    save_employees("employees.json");
    free_all_employees();
}

int main(int argc, char *argv[]) {
    init_colorama();
    if (argc < 2) {
        printf("Usage:\n");
        return 1;
    }
    
    const char *command = argv[1];
    
    if (strcmp(command, "employee") == 0) {
        cmd_employee(argc, argv);
    }
    else {
        printf("error\n");
        return 1;
    }
    
    return 0;
}

/*
int main(int argc, char *argv[]) {
    init_colorama();
    int num1, num2, result, factorialResult, circleAreaResult, player_age;
    float float1 = 20.5;

    num1 = 7;
    num2 = num1 - 5;
    result = calculate(num1, num2, mul);
    int realArray[ARRAY_LENGTH] = {1, num1, 3, num2, 5, result};

    factorialResult = factorial(result);

    circleAreaResult = circleArea(result);
    str pythonCode = "def main(name):\n\treturn name\n";

    if (argc > 1) {
        if (strcmp(argv[1], "player") == 0) {
            Player player = {1, {7, 5, 2009}, "Indra", 97.5};
            player_age = 2025 - player.birthday.year;
            newjson("player_data.json", player.name, player_age);
            newfile("data.txt", player.name, "John");
            openfile("data.txt");
            printf("\nID: %d\nName: %s\nAge: %d\nScore: %f\n", player.id, player.name, player_age,
                   player.score);
        } else if (strcmp(argv[1], "math") == 0) {
            printf("Multiply: %d\n", result);
            printf("Circle Area: %d\n", circleAreaResult);
            printf("Factorial: %d\n", factorialResult);
        } else if (strcmp(argv[1], "etc") == 0) {
            printf("FakeArray: [%d, %f]\n", num1, float1);
            print(S_BRIGHT, F_CYAN, B_RESET, pythonCode);
            minecraft_coords("home");

            for (int i = 0; i < ARRAY_LENGTH; i++) {
                printf("RealArray: %d\n", realArray[i]);
            }
            wait();
        }
    } else {
        perror("Enter the arguments!");
        exit(1);
    }
    deinit_colorama();
    return 0;
}
*/