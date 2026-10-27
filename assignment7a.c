#include <stdio.h>

int main()
{
    int p, f, i, j;
    int ref[50], frames[10];
    int front = 0, faults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &p);

    printf("Enter reference string: ");
    for (i = 0; i < p; i++)
        scanf("%d", &ref[i]);

    printf("Enter frame size: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\t\tResult\n");




    for (i = 0; i < p; i++) {
        hit = 0;
        for (j = 0; j < f; j++)
            if (frames[j] == ref[i]) {
                hit = 1;
                break;
            }

        if (hit == 0) {
            frames[front] = ref[i];
            front = (front + 1) % f;
            faults++;
        }



        printf("%d\t", ref[i]);
        for (j = 0; j < f; j++){
            if (frames[j]==-1){
                printf("- ");
            }
            else{
            printf("%d ", frames[j]);
            }
        }
            
        if (hit)
            printf("\t\tHit\n");
        else
            printf("\t\tFault\n");
    }

    printf("\nTotal page faults = %d\n", faults);
    printf("Total page hits   = %d\n", p - faults);

    return 0;
}
