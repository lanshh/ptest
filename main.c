#include "stdio.h"
int compatible_cmp(const char *compatible, int comlen)
{
	int ret = -1;
	char *rkstr = "rockchip";
	char *rkstr1 = "Rockchip";
	char *rkstr2 = "RK30board";
	const char *p;
	int len = 0;

	do {
		p = compatible + len;
		len += strlen(p) + 1;/* skip null terminate to next string */
		if (strstr(p, rkstr) || strstr(p, rkstr1) || strstr(p, rkstr2)) {
			ret = 0;
			break;
		}
	} while(len < comlen);
	return ret;
}

int main(int argc, char **argv)
{
	FILE *fd;
	//char *sys_path = "/proc/cpuinfo";
	char *sys_path = "/proc/device-tree/compatible";
	char compatible[2000] = {0};
	int comlen;

	fd = fopen(sys_path, "r");
	if (fd == 0) {
		printf("open %s fail\n", sys_path);
		return -1;
	}
	comlen = fread(compatible, 1, sizeof(compatible), fd);
	fclose(fd);
	if (0 == compatible_cmp(compatible, comlen)) {
		printf("device is rk inside\n");
	} else {
		printf("device is not rk inside\n");
	}
	return 0;
}