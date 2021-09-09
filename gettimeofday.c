#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

long long	time_to_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long			get_cur_time(void)
{
	struct timeval time;
	long			res;

	gettimeofday(&time, NULL);
	res = time_to_ms(time);
	return (res);
}

void	my_usleep(useconds_t time, int flag)
{
	long long	start_time;
	long long	cur_time;

	start_time = get_cur_time();
	while (1)
	{
		cur_time = get_cur_time();
		if (!(flag) || cur_time - start_time >= time)
			break ;
	}
}

void	shard_write(long long *ptr, long long value)
{
	*ptr = value;
}

int		main(void)
{
	long long		a;
	long long s, e;

	a = 5;
	printf("a: %lld\n", a);
	s = get_cur_time();
	my_usleep(10,0);
	e = get_cur_time();
	printf("%lldms\n", e - s);

	shard_write(&a, 10);
	printf("a: %lld\n", a);
	return (0);
}

//int		main(void)
//{
//	struct timeval s, e;
//	int diff;

//	long a, b;
//	long err = 10;
//	if (gettimeofday(&s, NULL))
//	{
//		perror("gettimeofday() call error");
//		exit(-1);
//	}

//	usleep(9000);

//	if (gettimeofday(&e, NULL))
//	{
//		perror("gettimeofday() call error");
//		exit(-1);
//	}
//	a = s.tv_sec * 1000 + s.tv_usec / 1000;
//	//printf("%ldms\n", a);
//	b = e.tv_sec * 1000 + e.tv_usec / 1000;
//	//printf("%ldms\n", b);
//	//diff = (e.tv_sec-s.tv_sec)*1000+(e.tv_usec - s.tv_usec)/1000;


//	diff = b - a;
//	if (write(1,"1\n",2) || write(1,"2\n",2))
//		printf("pass\n");
//	if (diff >= err)
//	{
//		printf("error!\n");
//		return (0);
//	}
//	printf("diff time: %dms\n", diff);
//	//printf("diff time: %ldms\n", b - a);

//	return (0);
//}
