#include <stdio.h>

int main() {
	FILE *file = fopen("input2.txt", "r");
	if (file == 0) {
		perror("fopen failed:");
		return -1;
	}

	int pos = 50;
	int answer = 0;
	char line[10];
	while (fgets(line, sizeof(line), file)) {
		char dir;
		int steps;
		sscanf(line, "%c%d", &dir, &steps);

		if (dir == 'L') {
			if (steps > pos) {
				steps = (steps - pos) % 100;
				pos = 100 - steps;
			} else {
				pos -= steps;
			}
		} else {
			if ((steps + pos) > 100) {
				steps = (steps + pos) % 100;
				pos = steps;
			} else {
				pos += steps;
			}
		}

		if (pos == 100) pos = 0;
		if (pos == 0) ++answer;
	}

	printf("%d", answer);
}
