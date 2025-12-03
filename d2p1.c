#include <stdio.h>

#define LINE_SIZE 100
#define BUFFER_SIZE 30

int my_pow10(int n) {
	int result = 1;
	for (int i = 0; i < n; ++i)
		result *= 10;

	return result;
}

int main() {
	FILE *file = fopen("input2.txt", "r");
	if (file == 0) {
		perror("fopen failed");
		return -1;
	}

	unsigned long long sum = 0;
	char line[LINE_SIZE];
	while (fgets(line, sizeof(line), file)) {
		unsigned long min = 0;
		unsigned long max = 0;
		sscanf(line, "%lu-%lu", &min, &max);

		for (unsigned long i = min; i <= max; ++i) {
			int n = 0;
			{
				unsigned long temp = i;
				while (temp > 0) {
					temp /= 10;
					++n;
				}
			}
			if (n % 2 != 0) continue;
			else {
				int a = my_pow10(n / 2);
				if ((i / a) == (i % a)) sum += i;
			}
		}
	}
	printf("%llu\n", sum);
}
