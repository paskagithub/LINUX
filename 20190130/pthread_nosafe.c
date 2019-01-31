#include <func.h>


void* threadfunc(void*p)
{
	time_t t=time(NULL);
	char*ptime=ctime(&t);
	printf ("child %s\n",ptime);
	sleep(5);
	printf ("child %s\n",ptime);
}



int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,threadfunc,NULL);
	sleep(2);
	time_t t=time(NULL);
	char*mtime=ctime(&t);//ctime()为不可重用函数，main线程中可以修改子线程中的变量（相当于全局变量）
	printf ("main %s\n",mtime);
	pthread_join(pthid,NULL);
	return 0;
}


