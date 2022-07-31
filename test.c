#include <stdio.h>
#include <string.h>
typedef struct sl{
	float red;
	float green;
	float blue;
}op;

void read_file(op *info);
void writing_to_file(op *info);




int main(void) {

	op info = {0};
	info.blue = 1;
	writing_to_file(&info);
	read_file(&info);
		printf("%f %f", info.red, info.green);
	return 0;
}

void writing_to_file(op *info) {
    FILE *f;
    f = fopen("/Users/richesse/Desktop/settings.txt", "w");
    fprintf(f,"%f\n", info->red);
    fprintf(f,"%f\n", info->green);
    fprintf(f,"%f\n", info->blue);
    fclose(f);
}

void read_file(op *info) {
    char str[100];
    float s =0;
    // int i = 0;
    FILE *f;
    f = fopen("/Users/richesse/Desktop/settings.txt", "r");
    while (fgets(str, 100 - 1, f)) {
       if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0'; 
       }
       sscanf(str, "%f", &s); 
       
    //    i++;
    }
    info->red = s;
    fclose(f);
}
