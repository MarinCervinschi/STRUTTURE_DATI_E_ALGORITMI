#include <stdio.h>
#include <stdlib.h>
extern char *GuidaLaPulce(const int *f, size_t f_size, int a, int b, int n, int h, size_t *ret_size);
int main(void) {
    {
        const int f[] ={12, 4, 7, 1, 15};
        
        char *ret = NULL;
        size_t ret_size = 0;
        ret = GuidaLaPulce(f, 5, 3, 15, 5, 9, &ret_size);
        printf("[%s] con %ld salti\n", ret, ret_size);
    }
    {
        const int f[] ={8, 3, 16, 6, 12, 20};
        
        char *ret = NULL;
        size_t ret_size = 0;
        ret = GuidaLaPulce(f, 5, 15, 13, 10, 11, &ret_size);
        printf("[%s] con %ld salti\n", ret, ret_size);
    }
    {
        const int f[] ={1, 6, 2, 14, 5, 17, 4};
        
        char *ret = NULL;
        size_t ret_size = 0;
        ret = GuidaLaPulce(f, 7, 16, 9, 5, 7, &ret_size);
        printf("[%s] con %ld salti\n", ret, ret_size);
    }
    
    return 0;
}
