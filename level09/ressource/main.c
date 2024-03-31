#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av) {
    if (ac != 2) {
        printf("1 and only 1 arg required\n");
        return (1);
    }
    int fd = open(av[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening the file");
        return (1);
    }
    char buf[1];
    int i = 0;
    char dest[4000] = {0};
    while (read(fd, buf, 1) > 0 && i < (sizeof(dest) - 1)) {
		if (buf[0] == '\n')
			break ;
        dest[i] = buf[0] - i;
        i++;
		buf[0] = 0;
    }
    close(fd);
    printf("%s\n", dest);
    return (0);
}
