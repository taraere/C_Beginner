#define _XOPEN_SOURCE // for crypt
#include <stdio.h> // used for printf
#include <crypt.h> // for crypt


int main(void)
{
    // char* cr1 = crypt("t", "50");
    // char* cr2 = crypt("ta", "51");
    // char* cr3 = crypt("tar", "40");
    // char* cr4 = crypt("tara", "5a");

    printf("1: %s\n", crypt("t", "50"));
    printf("2: %s\n", crypt("ta", "51"));
    printf("3: %s\n", crypt("tar", "40"));
    printf("4: %s\n", crypt("tara", "5a"));
}