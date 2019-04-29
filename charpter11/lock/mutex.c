#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NHASH 29
#define HASH(id) (((unsigned long)id)%NHASH)
struct foo*fh[NHASH];
pthread_mutex_t hashlock=PTHREAD_MUTEX_INITIALIZER;

struct foo{
    int f_count;
    pthread_mutex_t f_lock;
    int f_id;
    struct foo * f_next;
};

struct foo* foo_alloc(int id)
{
    struct foo *fp;
    int idx;
    if((fp=malloc(sizeof(struct foo)))!=NULL)
    {
	fp->f_count=1;
	fp->f_id=id;
	if(pthread_mutex_init(&fp->f_lock,NULL)!=0)
	{
	    free(fp);
	    return(NULL);
	}
	idx=HASH(id);
	pthread_mutex_lock(&hashlock);
	fp->f_next=fh[idx];
	fh[idx]=fp;
	pthread_mutex_locl(&fp->f_lock);
    }
    return(fp);
}

struct foo*foo_find(int id)
{
    struct foo*fp;
    for(fp=fh[HASH(id)];fp!=NULL;fp=fp->next)
    {
	if(fp->f_id==id)
	{
	    foo_hold(fp);
	    break;
	}
    }
    pthread_mutex_unlock(&hashlock);
    return(fp);
}
void foo_rele(struct foo*fp)
{
    struct foo*tfp;
    int idx;
        
    pthread_mutex_lock(&fp->f_lock);
    if(fp->f_count==1)
    {
	pthread_mutex_unlock(&fp->f_lock);
	pthread_mutex_lock(&hashlock);
	pthread_mutex_lock(&fp->f_lock);
	if(fp->f_count!=1)
	{
	    fp->f_count--;
	    pthread_mutex_unlock(&fp->f_lock);
	    pthread_mutex_unlock(&hashlock);
	    return ;
	}
    }   
}

