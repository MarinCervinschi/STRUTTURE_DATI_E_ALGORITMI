#include <stdlib.h>
#include <stdbool.h>

bool VerificaStradaIlluminata(const int *light, bool *vccur, size_t size, int M, int R){
    int luce = 0;
    for (size_t i = 0;  i < size; ++i) {
        if(vccur[i]){
            if (light[i] - R > luce) {
                return false;
            }
            luce = light[i] + R;
        }
    }
    return luce >= M ? true : false;
}
bool VerificaSoluzioneValida(bool *ret, size_t size){
    for (size_t i = 0; i != size; ++i) {
        if(ret[i]){
            return false;
        }
    }
    return true;
}
void OptimalIlluminationRec(int M, int R, const int *light, size_t light_size, bool **ret, bool *vccur, int count, int *lampadine){
    
    if(VerificaStradaIlluminata(light ,vccur, light_size, M, R)){
        int lampadine_tmp = *lampadine;
        *lampadine = 0;
        for (size_t i = 0; i != light_size; ++i) {
            if (vccur[i]) {
                ++*lampadine;
            }
        }
        if(*lampadine < lampadine_tmp){
            for (size_t i = 0; i != light_size; ++i) {
                ret[0][i] = vccur[i];
            }
        }
    }
    if(count == (int)light_size){
        return;
    }
    for (size_t i = count; i != light_size; ++i) {
        vccur[i] = true;
        OptimalIlluminationRec(M, R, light, light_size, ret, vccur, count+1, lampadine);
        vccur[i] = false;
    }
    
}
bool* OptimalIllumination(int M, int R, const int *light, size_t light_size){
    if (!light || light_size == 0) {
        return NULL;
    }
    bool *ret = calloc(light_size, sizeof(bool));
    bool *vccur = calloc(light_size, sizeof(bool));
    int lampadine = 200;
    OptimalIlluminationRec(M, R, light, light_size, &ret, vccur, 0, &lampadine);
    
    if(VerificaSoluzioneValida(ret, light_size)){
        return NULL;
    }
    free(vccur);
    return ret;
}
