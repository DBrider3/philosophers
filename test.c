//#include <unistd.h>
//#include <sys/time.h>
//#include <stdio.h>
////long long current_timestamp() {
////    struct timeval te;

////    gettimeofday(&te, NULL); //get current time
////    long long milliseconds= te.tv_sec*1000LL + te.tv_usec/1000; //calculate milliseconds
////    //printf("milliseconds: %lld\n", milliseconds);
////    return milliseconds;
////}
//long long	time_to_ms(struct timeval time)
//{
//	return (time.tv_sec * 1000 + time.tv_usec / 1000);
//}

//long long			get_cur_time(void)
//{
//	struct timeval time;
//	long			res;

//	gettimeofday(&time, NULL);
//	res = time_to_ms(time);
//	return (res);
//}

//int		main(void)
//{
//    long long s,e;

//    s = get_cur_time();
//    usleep(5000);
//    e = get_cur_time();
//	printf("%lldms\n", e - s);
//	return (0);
//}

#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%d\n", argc);
	return (0);
}
