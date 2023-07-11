#include <stdio.h>
extern int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size);
int main(void) {
    const int bam[] = { 10, 20, 30};
    const int bis[] = { 10, 6, 7, 8};
    
    
    int ret = 0;
    ret = AssegnaBiscotti(bam, 3, bis, 4);
    return 0;
}
