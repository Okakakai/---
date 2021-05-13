#include <stdio.h>
#include <regex.h>
#include <string.h>

int main(int count, char **fname)
{

    FILE *fp;
    char str[1024], buffer[512], result[14];

    const char regex[] = "^(070|080|090)-[0-9]{4}-[0-9]{4}$";
    regex_t preg;
    regmatch_t pm[1];

    int firstindex, lastindex;
    fp = fopen(fname[1], "r");

    if (fp == NULL)
    {
        printf("失敗\n");
        return 1;
    }

    if (regcomp(&preg, regex, REG_EXTENDED | REG_NEWLINE) != 0)
    {
        printf("regex is not");
        return 1;
    }
    while (fgets(buffer, 512, fp) != NULL)
    {
        strcat(str, buffer);
    }

    while (1)
    {
        if (regexec(&preg, str, 1, pm, 0) == 0)
        {
            firstindex = pm[0].rm_so;
            lastindex = pm[0].rm_eo;
            strncpy(result, str + firstindex, lastindex - firstindex);
            printf("検索がヒットしました\n\n電話番号 : %s\n", result);
        }
        else
        {
            printf("日本のじゃないよ\n");
            break;
        }
        strncpy(str, str + lastindex, sizeof str / sizeof str[0] - firstindex);
        printf("%s\n", str);
    }

    regfree(&preg);
    fclose(fp);

    return 0;
}
#include <stdio.h>
#include <regex.h>
#include <string.h>

int main(int count, char **fname)
{

    FILE *fp;
    char str[1024], buffer[512], result[14];

    const char regex[] = "^(070|080|090)-[0-9]{4}-[0-9]{4}$";
    regex_t preg;
    regmatch_t pm[1];

    int firstindex, lastindex;
    fp = fopen(fname[1], "r");

    if (fp == NULL)
    {
        printf("失敗\n");
        return 1;
    }

    if (regcomp(&preg, regex, REG_EXTENDED | REG_NEWLINE) != 0)
    {
        printf("regex is not");
        return 1;
    }
    while (fgets(buffer, 512, fp) != NULL)
    {
        strcat(str, buffer);
    }

    while (1)
    {
        if (regexec(&preg, str, 1, pm, 0) == 0)
        {
            firstindex = pm[0].rm_so;
            lastindex = pm[0].rm_eo;
            strncpy(result, str + firstindex, lastindex - firstindex);
            printf("検索がヒットしました\n\n電話番号 : %s\n", result);
        }
        else
        {
            printf("日本のじゃないよ\n");
            break;
        }
        strncpy(str, str + lastindex, sizeof str / sizeof str[0] - firstindex);
        printf("%s\n", str);
    }

    regfree(&preg);
    fclose(fp);

    return 0;
}

