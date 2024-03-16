#include <stdio.h>

#include <linux/kernel.h>

#include <sys/syscall.h>

#include <unistd.h>

#include <sys/types.h>

void main(){

        int i=5;

		syscall(285,1);

       /*  while(1){

                i=(i+1) % 1000;

        } */

		

		

}