#include <func.h>


void* threadfunc(void*p)
{
	time_t t=time(NULL);
	struct tm *m=gmtime(&t);
	printf ("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",m->tm_year+1900,m->tm_mon+1,m->tm_mday,m->tm_hour+8,m->tm_min,m->tm_sec,m->tm_wday,m->tm_yday);	
	sleep(5);
	printf ("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",m->tm_year+1900,m->tm_mon+1,m->tm_mday,m->tm_hour+8,m->tm_min,m->tm_sec,m->tm_wday,m->tm_yday);	
}



int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,threadfunc,NULL);
	sleep(2);
	time_t t=time(NULL);
	struct tm *m=gmtime(&t);
	printf ("%04d-%02d-%02d %02d:%02d:%02d %d %d\n",m->tm_year+1900,m->tm_mon+1,m->tm_mday,m->tm_hour+8,m->tm_min,m->tm_sec,m->tm_wday,m->tm_yday);	
    pthread_join(pthid,NULL);
	return 0;
}


