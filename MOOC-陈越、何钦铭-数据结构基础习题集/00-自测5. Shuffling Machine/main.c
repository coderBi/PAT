#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* arr[54] = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13","H1"
                        ,"H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13","C1"
                        ,"C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13","D1"
                        ,"D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13"
                        ,"J1","J2"};
    int n, i, shuff[54];
    scanf("%d", &n);
    for(i = 0; i < 54; i++){
        scanf("%d", &shuff[i]);
    }

    for(i = 0; i < n; i++){
        char* temp[54];
        int j;
        for(j = 0; j < 54; j++){
            temp[shuff[j] - 1] = arr[j];
        }
        for(j = 0; j < 54; j++){
            arr[j] = temp[j];
        }
    }
    for(i = 0; i < 53; i++){
        printf("%s ", arr[i]);
    }
    printf("%s", arr[53]);
    return 0;
}
