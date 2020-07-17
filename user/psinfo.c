#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main (int argc, char *argv[]){
	struct ptable *ptable;
	int count;
	int i;

	ptable = (struct ptable*)malloc(sizeof(struct ptable));

	psinfo(ptable, &count);

	printf("PID\tMEM\tNAME\n");
	for (i = 0; i < count; i++){
		printf("%d\t%dK\t%s\n", ptable->procs[i].pid, ptable->procs[i].mem / 1000, ptable->procs[i].name);
	}
	exit(0);
}
