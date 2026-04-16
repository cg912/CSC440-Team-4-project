#include <stdio.h>

void log_user_input(char *user_input) {
    printf("User entered: ");
    
    /* VULNERABILITY: Untrusted input passed directly as the format string */
    printf(user_input); 
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        log_user_input(argv[1]);
    } else {
        printf("Please provide an argument.\n");
    }
    return 0;
}
/*
CWE-134 (Uncontrolled Format String): 
The user input from argv[1] is passed directly to printf() 
without a format string, allowing an attacker to 
potentially execute arbitrary code or cause a crash by 
crafting a malicious input that includes format specifiers.
*/