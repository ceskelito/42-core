#include "get_next_line.h"

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *str;

	int i = 0;

	/* str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str); 
	str = get_next_line(fd);
	printf("%s", str);
	free(str);*/

	str = get_next_line(fd);
 	while(str) 
	{
		
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
		
	}
	free(str);
	free(str);


	close(fd);
}