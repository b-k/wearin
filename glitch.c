#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(int argv, char **argc){
    if (argv<1) {fprintf(stderr, "Need a filename to glitch.\n"); exit(2);}
    int f=open(argc[1], O_RDWR);
    if (!f) {fprintf(stderr, "Couldn't open %s\n", argc[1]); exit(3);}

    off_t len = lseek(f, 0, SEEK_END);
    printf("len=%li\n", len);
    
    srandom(time(NULL));
    for (int i=0; i<50; i++){
        long int r = len * ((0.0+random())/RAND_MAX);
        printf("flipping %li\n", r);

        lseek(f, r, SEEK_SET);
        char c;
        read(f, &c, 1);
        lseek(f, r, SEEK_SET);
        c = ~(unsigned short int)c;
        write(f, &c, 1);
    }

    close(f);
}
