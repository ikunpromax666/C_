#include<stdio.h>
#include<assert.h>
#include<string.h>
/*
  源字符必须以'\0'结束
  目标空间必须足够的大，能容下源字符的内容
  目标空间必须可变
  将源字符串中的'\0'拷贝到目标空间

char* my_strcpy( char* str1,const char* str2){
    assert(str1);
    assert(str2);
    //assert(str1&&str2);
    char* ret = str1;
    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
        //*str1++ = *str2++;
    }
    str1 = str2;
    return ret;
}
int main(){
    char arr1[20]= {'0'};
    char  arr2[] = {"abcdef"};
    my_strcpy(arr1,arr2);
    printf("%s",arr1);
    return 0 ;
}
源字符必须以'\0'结束
  目标空间必须足够的大，能容下源字符的内容
  目标空间必须可变
char* my_strcat(char* dest,const char* src){
    assert(dest);
    assert(src);
    char* ret = dest;
    while(*dest != '\0'){
        dest++;
    }
    while(*dest++ = *src++){
        ;
    }
    return ret;
}
int main(){
    char arr1[20] ="hello ";
    char arr2[] = "world";
    my_strcat(arr1,arr2);
    printf("%s",arr1);
    return 0;
}

int  my_strlen(char* str){
    int count = 0;
    while(*str != '\0'){
        str++;
        count++;
    }
    return count;
}
int main(){
    char arr[] = "abcdef";
    int sum = my_strlen(arr);
    printf("%d",sum);
    return 0;
}

第一个字符大于第二个字符，则返回大于0的数字
第一个字符等于第二个字符，则返回0
第一个字符小于第二个字符，则返回小于0的数字
int my_strcmp(const char* str1,const char* str2){
    assert(str1&&str2);
    while(*str1 == *str2){
        str1++;
        str2++;
        if(str1 == '\0'){
            return 0;
        }
    }
    if(*str1 > *str2){
        return 1;
    }
    else{
        return -1;
    }
}
int main(){
    char arr1[20] = {"abcdef"};
    char arr2[20] = {"abcdefg"};
    int  ret= 0;
    ret = my_strcmp(arr1,arr2);
    if(ret > 0){
        printf(">");
    }
    else if(ret == 0){
        printf("=");
    }
    else{
        printf("<");
    }
    return 0;
}
*/