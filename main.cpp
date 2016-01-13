#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char *filename = "winning.txt";

    FILE *in_file = fopen(filename, "r");

    if (in_file != NULL) {
        
        int w1, w2, w3, w4, w5, pb;

        int winning_nums[100], power_balls[100];

        for (int i = 0; i < 100; i++) {
            winning_nums[i] = 0;
            power_balls[i] = 0;
        }

        while (fscanf(in_file, "%d %d %d %d %d %d\n", &w1, &w2, &w3, &w4, &w5, &pb) != EOF) {
            //printf("%d %d %d %d %d %d\n", w1, w2, w3, w4, w5, pb);

            winning_nums[w1]++;
            winning_nums[w2]++;
            winning_nums[w3]++;
            winning_nums[w4]++;
            
            winning_nums[w5]++;

            power_balls[pb]++;
        }

        fclose(in_file);

        int max = -1, max_i = 0;

        for (int i = 0; i < 100; i++) {
            printf("a[%d] = %d\n", i, winning_nums[i]);

            if (winning_nums[i] > max) {
                max = winning_nums[i];
                max_i = i;
            }
        }

        printf("Winning Num Max: %d occured %d times!\n", max_i, max);

        max = max_i = 0;

        for (int i = 0; i < 100; i++) {
            printf("a[%d] = %d\n", i, power_balls[i]);

            if (power_balls[i] > max) {
                max = power_balls[i];
                max_i = i;
            }
        }

        printf("Power Ball Max: %d occured %d times!\n", max_i, max);
    }
    else {
        perror("could not open file");
    }

    // open and read in file
    // add first 5 #s in line to a hash table / dictionary to calc freq
    // do the same for # 6 except in a different hash table
    //
    // ex: hashmap for winningnums, hashmap for powerballs
    //
    // keep track of highest freq as well

    // print out all numbers sorted by freq

    return 0;
}

