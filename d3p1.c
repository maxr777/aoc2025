#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 110

int main() {
	FILE *file = fopen("input2.txt", "r");
	if (file == 0) {
		perror("fopen failed");
		return -1;
	}

	unsigned long long sum = 0;
	char line[LINE_SIZE] = {};
	while (fgets(line, sizeof(line), file)) {
		int pos = 0;
		char a = line[0];
		{
			int i = 0;
			while (line[i + 1] != '\0' && line[i + 1] != '\n') {
				if (line[i] > a) {
					a = line[i];
					pos = i;
				}
				++i;
			}
		}
		++pos;
		char b = line[pos];

		while (line[pos] != '\0' && line[pos] != '\n') {
			if (line[pos] > b) {
				b = line[pos];
			}
			++pos;
		}

		char result[3] = {};
		result[0] = a;
		result[1] = b;
		sum += atoi(result);

		// printf("%c%c\n", a, b);
	}
	printf("%llu\n", sum);
}
