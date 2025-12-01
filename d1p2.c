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
		char dir = 0;
		int steps = 0;
		sscanf(line, "%c%d", &dir, &steps);

		if (dir == 'L') {
			if (pos == 0) --answer;
			while (steps > 0) {
				if (pos > 0) {
					--pos;
					// in case it ends up on 0 right as steps run out
					if (pos == 0 && steps == 1) ++answer;
				} else {
					++answer;
					pos = 99;
				}
				--steps;
			}
		} else {
			while (steps > 0) {
				if (pos < 99) {
					++pos;
				} else {
					++answer;
					pos = 0;
				}
				--steps;
			}
		}
	}

	printf("%d", answer);
}
