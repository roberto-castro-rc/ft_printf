#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

// Declaração da sua ft_printf
int ft_printf(const char *format, ...);

// Estrutura para armazenar saída e retorno
typedef struct {
    char *output;
    int return_value;
} TestResult;

// Captura a saída de uma função printf-like
TestResult capture_output(int (*func)(const char *, ...), const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Cria um arquivo temporário para redirecionar stdout
    char tmpfile[] = "/tmp/ft_printf_test_XXXXXX";
    int fd = mkstemp(tmpfile);
    if (fd == -1) {
        perror("mkstemp");
        exit(EXIT_FAILURE);
    }

    // Redireciona stdout para o arquivo temporário
    int saved_stdout = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(fd);

    // Chama a função (ft_printf ou printf)
    int ret = func(format, args);
    va_end(args);

    // Restaura stdout
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Lê o conteúdo do arquivo temporário
    FILE *file = fopen(tmpfile, "r");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *output = malloc(size + 1);
    fread(output, 1, size, file);
    output[size] = '\0';
    fclose(file);
    remove(tmpfile); // Remove o arquivo temporário

    return (TestResult){output, ret};
}

// Função para comparar os resultados
void compare_test(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Captura a saída da ft_printf
    va_list ft_args;
    va_copy(ft_args, args);
    TestResult ft_res = capture_output(ft_printf, format, ft_args);
    va_end(ft_args);

    // Captura a saída da printf
    va_list std_args;
    va_copy(std_args, args);
    TestResult std_res = capture_output(printf, format, std_args);
    va_end(std_args);

    // Compara as saídas e os retornos
    if (strcmp(ft_res.output, std_res.output) != 0 || ft_res.return_value != std_res.return_value) {
        printf("\033[0;31mFAIL\033[0m: \"%s\"\n", format);
        printf("  ft_printf: [\033[0;34m%s\033[0m] (ret = %d)\n", ft_res.output, ft_res.return_value);
        printf("  printf:    [\033[0;34m%s\033[0m] (ret = %d)\n", std_res.output, std_res.return_value);
    } else {
        printf("\033[0;32mPASS\033[0m: \"%s\"\n", format);
    }

    free(ft_res.output);
    free(std_res.output);
    va_end(args);
}

int main(void) {
    // Teste %c
    compare_test("%c", 'A');
    compare_test("%c", '\0');
    compare_test("%c", ' ');

    // Teste %s
    compare_test("%s", "Hello, World!");
    compare_test("%s", "");
    compare_test("%s", NULL); // Saída esperada: "(null)" para ft_printf vs. "(nil)" para printf (depende do sistema)

    // Teste %d e %i
    compare_test("%d", 42);
    compare_test("%d", -42);
    compare_test("%d", INT_MAX);
    compare_test("%d", INT_MIN);
    compare_test("%i", 42);
    compare_test("%i", -42);

    // Teste %u
    compare_test("%u", 42);
    compare_test("%u", UINT_MAX);

    // Teste %x e %X
    compare_test("%x", 255);
    compare_test("%x", 0);
    compare_test("%X", 255);
    compare_test("%X", 0);

    // Teste %p
    int x = 42;
    compare_test("%p", &x);
    compare_test("%p", NULL);

    // Teste %%
    compare_test("%%");

    // Teste combinado
    compare_test("Char: %c, String: %s, Int: %d, Hex: %x, Pointer: %p", 'A', "test", 42, 255, &x);

    return 0;
}