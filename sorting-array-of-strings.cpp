#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return a[0] > b[0];
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return a[0] < b[0];    
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int lena = 0;
    int repa = 0;
    int lenb = 0;
    int repb = 0;

    for (int i = 0; i < strlen(a); ++i){
        repa = 0;
        for (int j = i + 1; j < strlen(a); ++j){
            if (a[i] == a[j] && repa != 1){
                repa = 1;
            }
        }
        if (repa == 0){
            lena++;
        }
        repa = 0;
    }
    for (int i = 0; i < strlen(b); ++i){
        repb = 0;
        for (int j = i + 1; j < strlen(b); ++j){
            if (b[i] == b[j] && repb != 1){
                repb = 1;
            }
        }
        if (repb == 0){
            lenb++;
        }
        repb = 0;
    }
    if (lena > lenb){
        return 1;
    }else if(lena == lenb){
        return lexicographic_sort(a, b);
    }else{
        return 0;
    }
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) > strlen(b)){
        return 1;
    }else if(strlen(a) == strlen(b)){
        return lexicographic_sort(a, b);
    }else{
        return 0;
    }
}
void swap(char* a, char* b){
    char *temp;
    int size = strlen(a);
    temp = (char*)malloc(size*sizeof(char)); 
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    free(temp);
}

int partition(char** arr, int low, int high, int (*cmp_func)(const char* a, const char* b)){
    char *pivot;
    pivot = (char*)malloc(strlen(*arr)*sizeof(char)); 
    pivot = *(arr + high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j){
        if (!cmp_func(*(arr + j), pivot)){
            i++;
            swap(*(arr + i),*(arr + j));
        }
    }
    swap(*(arr + i + 1),*(arr + high));
    return (i + 1);
}

void quicksort(char** arr, int low, int high, int (*cmp_func)(const char* a, const char* b)){
    if (low < high){
        int pi = partition(arr, low, high, cmp_func);
        quicksort(arr, low, pi - 1, cmp_func);
        quicksort(arr, pi + 1, high, cmp_func);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){

    quicksort(arr, 0, len - 1, cmp_func);

}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}