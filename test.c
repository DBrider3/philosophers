#include <stdio.h>
#include <pthread.h>




typedef enum		e_state
{
	think,
	eat,
	slp,
	die
}					t_state;

typedef struct      s_table
{
    int     num;
    int     time;
}                   t_table;


void     *philo(void *arg)
{
    t_table *table = (t_table*)arg;

    int i = 0;
    while (i++ < 5)
    {
        printf("thread run\n");
        table->num++;
        table->time++;
        printf("%d %d\n", table->num, table->time);
    }
}

//int     *philo(t_table *table)
//{
//    //t_table *table = (t_table*)arg;

//    int i = 0;
//    while (i++ < 5)
//    {
//        printf("thread run\n");
//        table->num++;
//        table->time++;
//        printf("%d %d\n", table->num, table->time);
//    }
//}

int     main(void)
{
    t_state stat;
    pthread_t thrd;
    t_table    table;
    int         thrd_id;
    stat = think;
    printf("%d\n", stat);
    table.num = 0;
    table.time = 0;

    thrd_id = pthread_create(&thrd, NULL, philo, &table);
    pthread_join(thrd, NULL);



    return (0);
}
