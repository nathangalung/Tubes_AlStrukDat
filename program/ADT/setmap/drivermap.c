#include <stdio.h>
#include "map.h"

int main() {
    Map myMap;
    CreateEmptyMap(&myMap);

    printf("Is map empty? %s\n", IsEmptyMap(myMap) ? "Yes" : "No");
    printf("Is map full? %s\n", IsFullMap(myMap) ? "Yes" : "No");

    Word key1, value1, key2, value2;
    key1=StringToWord("key1");
    value1=StringToWord("value1");
    key2=StringToWord("key2");
    value2=StringToWord("value2");

    InsertMap(&myMap, key1, value1);
    InsertMap(&myMap, key2, value2);

    printf("Is map empty? %s\n", IsEmptyMap(myMap) ? "Yes" : "No");
    printf("Is map full? %s\n", IsFullMap(myMap) ? "Yes" : "No");

    Word result1 = ValueMap(myMap, key1);
    Word result2 = ValueMap(myMap, key2);

    printf("Value for key1: %s\n", result1.TabWord);
    printf("Value for key2: %s\n", result2.TabWord);

    Word key3;
    key3=StringToWord("key3");

    printf("Is key3 a member of the map? %s\n", IsMemberMap(myMap, key3) ? "Yes" : "No");

    DeleteMap(&myMap, key1);

    printf("Is key1 a member of the map? %s\n", IsMemberMap(myMap, key1) ? "Yes" : "No");

    return 0;
}