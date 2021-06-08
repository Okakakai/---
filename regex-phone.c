#include <regex.h>
#include <stdio.h>
#include <string.h>

int main(int count, char **fname) {
    FILE *fp;
    char str[1024], result[14], buffer[512];

    const char regex[] = "(070|080|090)-[0-9]{4}-[0-9]{4}";
    regex_t preg;
    regmatch_t pm[1];

    int firstindex, lastindex;

    if (regcomp(&preg, regex, REG_EXTENDED | REG_NEWLINE) != 0) {
        printf("regex is not avairable");
        return 1;
    }
    fp = fopen(fname[1], "r");

    if (fp == NULL) {
        printf("did not file open\n");
        return 1;
    }

    while (fgets(str, 1024, fp) != NULL) {
        if (regexec(&preg, str, 1, pm, 0) == 0) {
            firstindex = pm[0].rm_so;
            lastindex = pm[0].rm_eo;
            strncpy(result, str + firstindex, lastindex - firstindex);
            strcpy(buffer, str);
            strncpy(str, buffer + lastindex,
                    (sizeof buffer / sizeof buffer[1]) - lastindex);
            printf("検索がヒットしました\n\n電話番号 : %s\n", result);
        } else {
            printf("...\n");
        }
    }
    printf("検索終了\n");
    regfree(&preg);
    fclose(fp);

    return 0;
}