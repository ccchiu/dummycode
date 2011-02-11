#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
typedef void (* CALLBACK) (void);
void display(void);
void display(void) {
    printf("show dodo\n");
}
void s_timer(long sec,long usec,CALLBACK callback);
void s_timer(long sec,long usec,CALLBACK callback) {
    struct timeval tv;
    int retval;
    while (1) {
        tv.tv_sec = sec;
        tv.tv_usec = usec;
        retval = select(0, NULL, NULL, NULL, &tv);
        if (retval == -1)
            perror("select()");
        else if (retval) {
            ;
            /* FD_ISSET(0, &rfds) will be true. */
        } else {
            callback();
        }
    }
}



int main(void) {
    s_timer(5,0,display);
    return 0;
}
