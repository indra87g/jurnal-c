#pragma once
#include <stdio.h>
#include <stdarg.h>

#define F_RED "\033[31m" 
#define F_GREEN "\033[32m" 
#define F_YELLOW "\033[33m" 
#define F_BLUE "\033[34m" 
#define F_MAGENTA "\033[35m" 
#define F_CYAN "\033[36m" 
#define F_WHITE "\033[37m" 
#define F_RESET "\033[39m"

#define B_RED "\033[41m" 
#define B_GREEN "\033[42m" 
#define B_YELLOW "\033[43m" 
#define B_BLUE "\033[44m" 
#define B_MAGENTA "\033[45m"
#define B_CYAN "\033[46m" 
#define B_WHITE "\033[47m"
#define B_RESET "\033[49m"

#define S_BRIGHT "\033[1m" 
#define S_DIM "\033[2m" 
#define S_NORMAL "\033[22m" 
#define S_RESET_ALL "\033[0m"

void init_colorama();
void deinit_colorama();

void print(const char* style, const char* foreground, const char* background, const char* format, ...);

int is_colorama_initialized();