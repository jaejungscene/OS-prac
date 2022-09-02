#include <stdio.h>
#include <sys/stat.h>

int main()
{
   struct stat fileinfo;
   int check;
   check = stat("hard_data", &fileinfo);
   if(check == -1){
      printf("fail to get state\n");
      return 1;
   }

   printf("size: %lld\n", fileinfo.st_size);
   printf("permissions: %d\n", fileinfo.st_mode);
   printf("last modified: %lld\n", fileinfo.st_mtimespec.tv_sec);

}