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
			// the numbers are 10 digits max
			// e.g. 8 digits can only have 1, 2, or 4 digit combinations
			// 2 - 1 : 3 - 1 : 4 - 1,2 : 5 - 1 : 6 - 1,2,3 : 7 - 1 : 8 - 1,2,4 : 9 - 1,3 : 10 - 1,2,5
			switch (n) {
			case 2: {
				if ((i / 10) == (i % 10)) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 3: {
				int a = i / 100;       // hundreds
				int b = (i / 10) % 10; // tens
				int c = i % 10;	       // ones
				if (a == b && b == c) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 4: {
				if ((i / 100) == (i % 100)) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int a = i / 1000;
				int b = (i / 100) % 10;
				int c = (i / 10) % 10;
				int d = i % 10;
				if (a == b && b == c && c == d) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 5: {
				int a = i / 10000;
				int b = (i / 1000) % 10;
				int c = (i / 100) % 10;
				int d = (i / 10) % 10;
				int e = i % 10;
				if (a == b && b == c && c == d && d == e) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 6: {
				if ((i / 1000) == (i % 1000)) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int aa = i / 10000;
				int bb = (i / 100) % 100;
				int cc = i % 100;
				if (aa == bb && bb == cc) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int a = i / 100000;
				int b = (i / 10000) % 10;
				int c = (i / 1000) % 10;
				int d = (i / 100) % 10;
				int e = (i / 10) % 10;
				int f = i % 10;
				if (a == b && b == c && c == d && d == e && e == f) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 7: {
				int a = i / 1000000;
				int b = (i / 100000) % 10;
				int c = (i / 10000) % 10;
				int d = (i / 1000) % 10;
				int e = (i / 100) % 10;
				int f = (i / 10) % 10;
				int g = i % 10;
				if (a == b && b == c && c == d && d == e && e == f && f == g) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 8: {
				if ((i / 10000) == (i % 10000)) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int a = i / 10000000;
				int b = (i / 1000000) % 10;
				int c = (i / 100000) % 10;
				int d = (i / 10000) % 10;
				int e = (i / 1000) % 10;
				int f = (i / 100) % 10;
				int g = (i / 10) % 10;
				int h = i % 10;
				if (a == b && b == c && c == d && d == e && e == f && f == g && g == h) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 9: {
				int aa = i / 1000000;
				int bb = (i / 1000) % 1000;
				int cc = i % 1000;
				if (aa == bb && bb == cc) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int a = i / 100000000;
				int b = (i / 10000000) % 10;
				int c = (i / 1000000) % 10;
				int d = (i / 100000) % 10;
				int e = (i / 10000) % 10;
				int f = (i / 1000) % 10;
				int g = (i / 100) % 10;
				int h = (i / 10) % 10;
				int j = i % 10;
				if (a == b && b == c && c == d && d == e && e == f && f == g && g == h && h == j) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			case 10: {
				if ((i / 100000) == (i % 100000)) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int aa = i / 100000000;
				int bb = (i / 1000000) % 100;
				int cc = (i / 10000) % 100;
				int dd = (i / 100) % 100;
				int ee = i % 100;
				if (aa == bb && bb == cc && cc == dd && dd == ee) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				int a = i / 1000000000;
				int b = (i / 100000000) % 10;
				int c = (i / 10000000) % 10;
				int d = (i / 1000000) % 10;
				int e = (i / 100000) % 10;
				int f = (i / 10000) % 10;
				int g = (i / 1000) % 10;
				int h = (i / 100) % 10;
				int j = (i / 10) % 10;
				int k = i % 10;
				if (a == b && b == c && c == d && d == e && e == f && f == g && g == h && h == j && j == k) {
					sum += i;
					printf("%lu\n", i);
					break;
				}

				break;
			}
			}
		}
	}
	printf("%llu\n", sum);
}
