#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool verifica(bool *v, size_t n){
    for (size_t i = 0; i != n; ++i) {
        if(!v[i]){
            return false;
        }
    }
    return true;
}
static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}

void BackTrack(const char **v, size_t v_size, bool *vccur, size_t i, char **res, int* overlapping, int *ovr_max, bool **is_in){
    if(i == 2){
        size_t lvl[2];
        for (size_t j = 0, h = 0; j != v_size; ++j){
            if(vccur[j]){
                lvl[h] = j;
                ++h;
            }
        }
        
        Overlap(v[lvl[0]], v[lvl[1]], overlapping);
        if(*overlapping > *ovr_max){
            *res = Overlap(v[lvl[0]], v[lvl[1]], overlapping);
            for (size_t j = 0; j != v_size; ++j){
                is_in[0][j] = vccur[j];
            }
            *ovr_max = *overlapping;
        }
        
        return;
    }
    
    for (size_t j = 0; j != v_size; ++j) {
        if (!vccur[j]) {
            if(!is_in[0][j]){
                vccur[j] = true;
                BackTrack(v ,v_size, vccur, i+1, res, overlapping, ovr_max, is_in);
                vccur[j] = false;
            }
        }
    }
    
    
}
char* SolveSuperstring(const char **v, size_t v_size){
    
    char *res = calloc(255, sizeof(char));
    bool *vccur = calloc(v_size, sizeof(bool));
    int over = 0, over_max = 0;
    bool *is_in = calloc(v_size, sizeof(bool));
    bool *best =calloc(v_size, sizeof(bool));
    
    while (!verifica(best, v_size)) {
        BackTrack(v, v_size, vccur, 0, &res, &over, &over_max, &is_in);
        over = 0;
        over_max = 0;
        for (size_t j = 0; j != v_size; ++j){
            if(!best[j]){
                best[j] = is_in[j];
            }
        }
    }
    
    
    
    res = realloc(res, strlen(res) * sizeof(char));
    free(vccur);
    free(is_in);
    free(best);
    return res;
}
