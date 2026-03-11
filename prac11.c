#include <stdio.h>

int main() {
    int pages, frames, i, j, k;
    int page[50], frame[10];
    int page_faults = 0, index = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for(i = 0; i < pages; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[index] = page[i];
            index = (index + 1) % frames;
            page_faults++;
        }

        printf("\nFrames: ");
        for(k = 0; k < frames; k++) {
            printf("%d ", frame[k]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
