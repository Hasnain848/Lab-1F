#include<stdio.h>
char* recursiveconcat(char*dest, char* src);
int main(){
char dest[100]="Hello";
char src[]="World";
printf("%s",recursiveconcat(dest,src));

}
char* recursiveconcat(char* dest, char* src) {
    // Base case: if source string is empty, return destination
    if (*src == '\0')
        return dest;

    // Find end of destination string
    while (*dest != '\0') {
        dest++;
    }

    // Copy current source character
    *dest = *src;
    *(dest + 1) = '\0';

    // Recursively process remaining source string
    return recursiveconcat(dest+1, src + 1);
}