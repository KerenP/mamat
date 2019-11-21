#include <stdio.h>
#include <stdlib.h>

int* createBuff(int buffSize) {
    return (int*) malloc(sizeof(int) * buffSize);
}

void fillBuff(int* buff, int buffSize) {
    int i=0;
    for (i=0; i< buffSize;i+=2){
        buff[i]=i;
        buff[i+1] = buffSize -i;
    }
}

int sumBuff(int* buff, int buffSize) {
    int i,sum=0;
    for (i=0; i<buffSize;i++){
        sum+=buff[i];
    }
    return sum;
}

int main() {
    int* buff;
    int buffSize;
    scanf("%d",&buffSize);
    if (buffSize<1) {
        printf("wrong argument!\n");
        exit(-1);
    }
    buff = createBuff(buffSize);
    fillBuff(buff,buffSize);
    printf("buffer size: %d, sum is: %d\n", buffSize, sumBuff(buff,buffSize));    
    if (buffSize < 10)
        free(buff);
    return 0;
}
