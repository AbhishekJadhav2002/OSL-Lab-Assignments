#include <stdio.h>
#define FRAME_SIZE 5 //>3 as per the assignment problem statement

struct page_frame
{
    int page_reference, checked_in_time;
};

int min_element_index(struct page_frame* page_references, size_t no_of_references) {
    int index = 0, min = page_references[0].checked_in_time;
    for (size_t page_no = 1; page_no < no_of_references; page_no++) {
        if(page_references[page_no].checked_in_time < min) {
            min = page_references[page_no].checked_in_time;
            index = page_no;
        }
    }
    return index;
}

void LRU(int no_of_references, int* page_references) {
    int page_faults = 0, page_hits = 0;
    struct page_frame main_memory[FRAME_SIZE] = {0, 0};
    int page_replaced = 0;
    for (int counter = 0; counter < no_of_references; counter++) {
        for(int page_frame_no = 0; page_frame_no < FRAME_SIZE; page_frame_no++) {
            if(main_memory[page_frame_no].page_reference != 0) {

            }
        }
    }
};

int main() {
    printf("--------------------------------------");
    printf("\n     Page Replacement using LRU");
    printf("\n--------------------------------------\nEnter total number of references: ");
    int no_of_references;
    scanf("%d", &no_of_references);

    printf("Enter page reference strings(space separated) : ");
    int page_references[no_of_references];
    for (int page_no = 0; page_no < no_of_references; page_no++)
    {
        scanf("%d", &page_references[page_no]);
    }
    LRU(no_of_references, page_references);
    return 0;
}