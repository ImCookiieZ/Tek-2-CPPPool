#include <stdio.h>
#include "string.h"


int main()
{
    string_t  s;
//    string_t  first_change;
    string_init(&s, "monday;;wednesday;");
    insert_c(&s, 3, "lololo");

//    string_init(&first_change, "first change");

//    char *str = malloc(10);
//    memset(str, '1', 9);
//    str[9] = 0;
//    s.insert_c(&s, 5, str);
    printf("standard :%s\n\n", s.str);
//    string_t **split = s.split_s(&s, ';');
//    char **split1 = s.split_c(&s, ';');
////    char **split_c = s.split_c(&s, 0);
//    for (int i = 0; split1[i]; i++)
//    {
//        printf("[%i]=", i);
//        split[i]->print(split[i]);
//        printf("\n");
//        printf("[%i]=%s\n", i, split1[i]);
//        fflush(stdout);
//
//        split[i]->string_destroy(split[i]);
//        free(split1[i]);
//        free(split[i]);
////        free(split[i]);
////        free(split[i]);
////        free(split_c[i]);
//    }
////    free(split);
//    free(split1);
//    free(split);
//    printf("%s\n", str);
//    free(str);
    s.string_destroy(&s);
//    first_change.string_destroy(&first_change);
    return 0;
}
//    s.append_c(&s, " second");
//        printf("%s\n", s.str);
//    string_t **test = split_s(&s, ' ');
//    for (int i = 0; test[i] != NULL; i++)
//        test[i]->print(test[i]);
//    s.join_s(&s, ' ', (const struct string_struct_s *const *) test);
//    printf("\n");
//    s.print(&s);
//    first_change = substr(&s, -3, -2);
//    printf("%s#\n", first_change->str);
//    fflush(stdout);
//    s.assign_c(&s, "hero");
//    printf("%s\n", s.str);
//    printf("%s\n", first_change.str);
//    char *mal = strdup("hu");
//    int p = s.copy(&s, mal, 3, 0);
//    printf("%s: %i\n", mal, p);
//    free(mal);
//    printf("\n");
//    s.assign_c(&s, "secondfirstthird");
//    s.assign_c(&first_change, "first");
//    s.insert_c(&first_change, 20, "huh");
//    int strstr = s.find_s(&s, &first_change, 0);
//    printf("%s\n%s\n%d", s.str, first_change.str, strstr);
//    s.assign_c(&s, "12");
//    int i = s.to_int(&s);
//    printf("%s\n%s\n%d", s.str, first_change.str, i);
//    string_destroy(&first_change);
//    string_destroy(&s);

