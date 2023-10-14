#include <stdio.h>

int num;

int static_function() 
{
    printf("no skip\n");
    static int number = 10; /* Static variable */
    number++;               /* Maintains the value of the previous execution */
    return number;
}

int normal_function()
{    
  int number = 10; /* Static variable */
  number++;               /* Maintains the value of the previous execution */
  return number;
}

// extern void func1();  // static function이므로 안됨
extern void func2();

int main() 
{
    /* Prints the result of two invocations to static_function */
    printf("%d\n", static_function()); /* Prints 11 */
    printf("%d\n\n", static_function()); /* Prints 12! */

    printf("%d\n", normal_function()); /* Prints 10 */
    printf("%d\n\n", normal_function()); /* Prints 10 */

    extern int k;
    printf("k = %d in (static_func_extern_num.c)\n", k);
    // func1();  // static function이므로 안됨
    func2();

    return 0;
}