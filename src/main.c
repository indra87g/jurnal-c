#include <stdio.h>
#include <string.h>

#include "calculate.h"
#include "utils.h"

int main(int argc, char *argv[]) 
{
    if (argc > 1) {
        if (strcmp(argv[1], "hello") == 0) {
            printf("Hello World!\n");
        }
    } else {
        int num1, num2, result, factorialResult, circleAreaResult, player_age;
        num1 = 7;
        num2 = num1 - 5;

        result = calculate(num1, num2, mul);
        factorialResult = factorial(result);
        int realArray[ARRAY_LENGTH] = {1, num1, 3, num2, 5, result};
        circleAreaResult = circleArea(result);
        float float1 = 20.5;
        str pythonCode = "def main(name):\n\treturn name\n";

        Player player = {1, {7, 5, 2009}, "Indra", 97.5};
        player_age = 2025 - player.birthday.year;

        printf("ID: %d\nName: %s\nAge: %d\nScore: %f\n", player.id, player.name, player_age,
           player.score);
        printf("Result: %d\n", result);
        printf("Circle Area: %d\n", circleAreaResult);
        printf("FakeArray: [%d, %f]\n", num1, float1);
        hello(player.name, "John");
        printf("%s", pythonCode);

        for (int i = 0; i < ARRAY_LENGTH; i++) {
            printf("RealArray: %d\n", realArray[i]);
        }
        printf("Factorial Result: %d\n", factorialResult);

        minecraft_coords("home");
        newfile("data.txt", "Hello");
        openfile("data.txt");
        newjson("data.json", player.name, player_age);
    }
    return 0;
}