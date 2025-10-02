#pragma once
#include <stdio.h>
#include <stdarg.h>

#define FOREGROUND_RED "\033[31m" 
#define FOREGROUND_GREEN "\033[32m" 
#define FOREGROUND_YELLOW "\033[33m" 
#define FOREGROUND_BLUE "\033[34m" 
#define FOREGROUND_MAGENTA "\033[35m" 
#define FOREGROUND_CYAN "\033[36m" 
#define FOREGROUND_WHITE "\033[37m" 
#define FOREGROUND_RESET "\033[39m"

#define BACKGROUND_RED "\033[41m" 
#define BACKGROUND_GREEN "\033[42m" 
#define BACKGROUND_YELLOW "\033[43m" 
#define BACKGROUND_BLUE "\033[44m" 
#define BACKGROUND_MAGENTA "\033[45m"
#define BACKGROUND_CYAN "\033[46m" 
#define BACKGROUND_WHITE "\033[47m"
#define BACKGROUND_RESET "\033[49m"

#define STYLE_BRIGHT "\033[1m" 
#define STYLE_DIM "\033[2m" 
#define STYLE_NORMAL "\033[22m" 
#define STYLE_RESET_ALL "\033[0m"

void init_colorama();
void deinit_colorama();

void print(const char* style, const char* foreground, const char* background, const char* format, ...);

int is_colorama_initialized();