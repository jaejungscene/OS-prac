#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

struct input_data
{
    char    oper[2];
    char    func[10]; 
    char    lib[30];
};

int main(int argc, char **argv)
{
    char oper[2];
    char left[11];
    char right[11];
    char buf[50];
    char null[1];
    int data_num;

    struct input_data plug_num[10]; 

    void *handle;

    int (*result)(int, int);
    int i;
    char *error;


    printf("Break Point\n");


    FILE *fp;

    // 설정파일을 읽어들이고 
    // 내용을 구조체에 저장한다. 
    fp = fopen("plugin.cfg", "r");
    data_num = 0;
    while(fgets(buf, 50, fp) != NULL)
    {
        buf[strlen(buf) -1] = '\0';
        sscanf(buf, "%[^,]%[,]%[^,]%[,]%s", plug_num[data_num].oper, 
                                               null,    
                                               plug_num[data_num].func, 
                                               null,
                                               plug_num[data_num].lib);
        data_num ++;
    }
    fclose(fp);

    printf("> ");
    memset(left, 0x00, 11);
    memset(right, 0x00, 11);
    scanf("%[0-9]%[^0-9]%[0-9]", left, oper, right);

    // 연산자를 비교해서 
    // 적당한 라이브러리를 불러온다. 
    for (i  = 0; i < data_num ; i++)
    {
        int state; 
        if ((state = strcmp(plug_num[i].oper, oper)) == 0) 
        {
            printf("my operator is      : %s\n", plug_num[i].oper);
            printf("my call function is : %s\n", plug_num[i].func);
            printf("my call file is : %s\n", plug_num[i].lib);
            break;
        }
    }    

    if (i == data_num)
    {
        printf("--> unknown operator\n");
        exit(0);
    }

    handle = dlopen(plug_num[i].lib, RTLD_NOW);
    if (!handle)
    {
        printf("*****open error*******\n");
        fputs(dlerror(), stderr);
        exit(1);
    }

    // 연산자에 적당한 함수를 불러온다. 
    result = dlsym(handle, plug_num[i].func);
    if ((error = dlerror()) != NULL)
    {
        printf("********function call error*********");
        fputs(error, stderr);
        exit(1);
    }

    printf("%s %s %s = %d\n",left, oper, right, result(atoi(left), atoi(right)) ); 

    dlclose(handle);
}