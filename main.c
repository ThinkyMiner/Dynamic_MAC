#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <time.h>

typedef unsigned char int8;
typedef unsigned short int16;
typedef unsigned int int32;
typedef unsigned long int int64;

struct s_mac
{
    int64 address : 48;
};

typedef struct s_mac MAC;

MAC generate_mac(void)
{
    int64 a, b;
    MAC mac;
    a = (long)arc4random();
    b = (long)arc4random();
    mac.address = ((a * b) % 281474976710656);
    // printf("%d\n", getpid());
    // printf("%lx\n", a * b);

    return mac;
}

int main()
{
    srand(getpid());

    MAC mac = generate_mac();
    printf("0x%lx\n", mac.address);

    return 0;
}