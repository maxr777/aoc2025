#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 110
#define SAMPLE_TEST_LINE_SIZE 15
#define TEST_LINE_SIZE 100

int main() {
	FILE *file = fopen("input2.txt", "r");
	if (file == 0) {
		perror("fopen failed");
		return -1;
	}

	unsigned long long sum = 0;
	char line[LINE_SIZE] = {};
	while (fgets(line, sizeof(line), file)) {
		char result[13] = {};
		int last_pos = 0;

		for (int i = 11, result_index = 0; i >= 0; --i, ++result_index) {
			for (int j = last_pos; j < TEST_LINE_SIZE - i; ++j) {
				if (line[j] > result[result_index]) {
					result[result_index] = line[j];
					last_pos = j + 1;
				}
			}
		}

		sum += atoll(result);
		printf("%s\n", result);
	}
	printf("%llu\n", sum);
}
