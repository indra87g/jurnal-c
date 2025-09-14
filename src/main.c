#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "calculate.h"
#include "utils.h"

int main(int argc, char *argv[]) 
{
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
        if (strcmp(argv[1], "mcoords") == 0) {
            minecraft_coords("home");
        } else if (strcmp(argv[1], "player") == 0) {
            Player player = {1, {7, 5, 2009}, "Indra", 97.5};
            player_age = 2025 - player.birthday.year;
            newjson("player_data.json", player.name, player_age);
            newfile("data.txt", player.name, "John");
            openfile("data.txt");
            printf("\nID: %d\nName: %s\nAge: %d\nScore: %f\n", player.id, player.name, player_age, player.score);
        } else if (strcmp(argv[1], "math") == 0) {
            printf("Multiply: %d\n", result);
            printf("Circle Area: %d\n", circleAreaResult);
            printf("Factorial Result: %d\n", factorialResult);
        } else if (strcmp(argv[1], "etc") == 0) {
            printf("FakeArray: [%d, %f]\n", num1, float1);
            printf("%s", pythonCode);

            for (int i = 0; i < ARRAY_LENGTH; i++) {
                printf("RealArray: %d\n", realArray[i]);
            }
        }
    } else {
        perror("Enter the arguments!");
        exit(1);
    }
    return 0;
}