#include <stdio.h>
#include <string.h>

#include "calculate.h"
#include "utils.h"

int main() {
    int num1 = 7;
    int num2 = num1 - 5;
    int result = calculate(num1, num2, mul);
    int factorialResult = factorial(result);
    int realArray[ARRAY_LENGTH] = {1, num1, 3, num2, 5, result};
    int circleAreaResult = circleArea(result);
    float float1 = 20.5;
    str pythonCode = "def main(name):\n\treturn name\n";
    Player player = {1, {7, 5, 2009}, "Indra", 97.5};
    int player_age = 2025 - player.birthday.year;

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

    return 0;
}