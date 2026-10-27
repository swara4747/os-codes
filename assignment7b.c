#include <stdio.h>

int main()
{
    int n, f, i, j, pos;
    int ref[50], frame[10], last[10];
    int faults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter frame size: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frame[i] = -1;
        last[i] = 0;
    }

    printf("\nPage\tFrames\t\tResult\n");

    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < f; j++)
            if (frame[j] == ref[i]) {
                hit = 1;
                last[j] = i;
                break;
            }

        if (hit == 0) {
            faults++;

            pos = -1;
            for (j = 0; j < f; j++)
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }

            if (pos == -1) {
                pos = 0;
                for (j = 1; j < f; j++)
                    if (last[j] < last[pos])
                        pos = j;
            }

            frame[pos] = ref[i];
            last[pos] = i;
        }

        printf("%d\t", ref[i]);
        for (j = 0; j < f; j++)
            printf("%d ", frame[j]);
        if (hit)
            printf("\t\tHit\n");
        else
            printf("\t\tFault\n");
    }

    printf("\nTotal page faults = %d\n", faults);
    printf("Total page hits   = %d\n", n - faults);

    return 0;
}
