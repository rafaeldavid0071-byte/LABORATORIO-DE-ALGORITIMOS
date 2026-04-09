#include <stdio.h>





int main(){


    int v [5] = {1 ,2 ,3 ,4 ,5};

    for(int contador=0; contador < sizeof(v)/sizeof(v[0]) ;contador++){
            printf("%d\n",*(v+contador));
    }


    return 0;
}