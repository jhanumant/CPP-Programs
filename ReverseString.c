#include <stdio.h>
#include <conio.h>

char string[10];
void reverse(char *str);

int main() {
	printf("Enter the input string");
	scanf("%s",&string);
	reverse(string);  //default gets address of first char
	return 0;
}

void reverse(char *str) {
	char *end = str;
	char temp;
	if (str) {
		while (*end) {
			end++;
		}
		end--;
	}
	while (str < end) {
		temp = *str;
		*str++ = *end;
		*end-- = temp;
	}
	printf("%s",string);
	getch();
}
