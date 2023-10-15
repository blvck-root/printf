# printf
- This is a custom implementation of the `printf` function provided by the `stdio.h` library.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`.
- All files must be compiled on `Ubuntu 20.04 LTS` using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files should end with a new line.
- A `README.md` file must be present at the root folder of the project.
- Write all code in `Betty` style. Code will be checked using `betty-style.pl` and `betty-doc.pl`.
- Do not use global variables.
- Do not write more than 5 functions per file.
- Do not push your test files to your remote repository.
- Write the prototypes of all your functions in the `main.h` header file.
- Don't forget to push the header file.
- All header files should be include guarded.
- The `_putchar` function is not provided.

## Authorized functions and macros
- `write`, 
- `malloc`,
- `free`
- `va_list`
- `va_start`
- `va_arg`
- `va_end`
- `va_copy`

## Compilation
- Use this command to compile your code: 
`$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`
- Do not push any C file that contains a `main` function. All files containing `main` functions should be in the `test` folder.
- Main files used to test your code will include your main header file (`main.h`) 
`#include "main.h"`
- Consider using the gcc flag `-Wno-format` when testing with your `_printf` and the standard `printf`.

### Example test file
```
alex@ubuntu:~/c/printf$ cat main.c 
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
alex@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
alex@ubuntu:~/c/printf$
```
- Write more tests to test for edge cases.
- If the task doesn't specify what to do with an edge case, check how  the standard `printf` handles the edge case.
