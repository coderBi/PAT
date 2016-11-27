#include <stdio.h>
#include <stdlib.h>

struct Money{
    int galleon;
    int sickle;
    int knut;
};

int main()
{
    struct Money arr[2];
    struct Money res;
    int i;

    for(i = 0; i < 2; i++){
        scanf("%d.%d.%d", &arr[i].galleon, &arr[i].sickle, &arr[i].knut);
    }

    if(arr[1].knut < arr[0].knut){
        arr[1].knut += 29;
        arr[1].sickle--;
    }
    if(arr[1].sickle < arr[0].sickle){
        arr[1].sickle += 17;
        arr[1].galleon--;
    }

    res.galleon = arr[1].galleon - arr[0].galleon;
    res.sickle = arr[1].sickle - arr[0].sickle;
    res.knut = arr[1].knut - arr[0].knut;

    if(res.galleon < 0){
        if(res.knut != 0){
            res.knut = 29 - res.knut;
            res.sickle = 16 - res.sickle;
            res.galleon++;
        } else if (res.sickle != 0){
            res.sickle = 17 - res.sickle;
            res.galleon++;
        }
        if(res.galleon == 0){
            printf("-");
        }
    }
    printf("%d.%d.%d", res.galleon, res.sickle, res.knut);

    return 0;
}
