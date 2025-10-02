#include "colorama.h"
#include <stdlib.h>

static int colorama_initialized = 0;

void init_colorama() {
#ifdef _WIN32
    system("");
#endif
    colorama_initialized = 1;
}

void deinit_colorama() {
    printf("%s", STYLE_RESET_ALL);
    colorama_initialized = 0;
}

int is_colorama_initialized() {
    return colorama_initialized;
}

void print(const char* style, const char* foreground, const char* background, const char* format, ...) {
    if(!colorama_initialized) {
        init_colorama();
    }
    
    va_list args;
    va_start(args, format);
    
    if (style != NULL) {
        printf("%s", style);
    }
    if (background != NULL) {
        printf("%s", background);
    }
    
    if (foreground != NULL) {
        printf("%s", foreground);
    }
    vprintf(format, args);;
    printf("%s", STYLE_RESET_ALL);
    va_end(args);
}