#include <stdio.h>
#include <string.h>

void check_authentication() {
    char password[16];
    
    printf("Enter password: ");
    /* VULNERABILITY 1: gets() does not check bounds */
    gets(password); 

    /* VULNERABILITY 2: strcpy() without size limits */
    char backup_password[8];
    strcpy(backup_password, password); 

    if(strcmp(password, "admin123") == 0) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
}

int main() {
    check_authentication();
    return 0;
}

/*
CWE-120 (Buffer Overflow): 
The use of gets() allows for a buffer overflow if 
the user inputs more than 15 characters (plus the null terminator).

CWE-242 (Use of Inherently Dangerous Function):
The use of gets() is inherently dangerous because it 
does not perform bounds checking, which can lead 
to buffer overflows and potential security vulnerabilities.
*/