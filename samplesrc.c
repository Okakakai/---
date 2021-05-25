#include <regex.h>
#include <stdio.h>

int main(void) {
    const char regex[] = "^(070|080|090)-[0-9]{4}-[0-9]{4}$";
    regex_t preg;
    char str[20];
    regmatch_t pm[1];

    if (regcomp(&preg, regex, REG_EXTENDED | REG_NEWLINE) != 0) {
        printf("regex is not available\n");
        return 1;
    }

    printf("電話番号を入力してください:");
    scanf("%s", str);

    if (regexec(&preg, str, 1, pm, 0) == 0) {
        printf("入力された電話番号は日本の携帯電話番号です.\n");
    } else {
        printf("入力された電話番号は日本の携帯電話番号ではありません\n")
    }

    regfree(&preg);
    fclose(fp);

    return 0;
}
