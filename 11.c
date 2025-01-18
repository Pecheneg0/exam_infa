#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int K = 0;      // Общее количество слов
    int K_be = 0;   // Количество слов, начинающихся и заканчивающихся на одну букву

    char input[100];
    printf("Введите строку: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Убираем символ новой строки, если он есть
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        printf("Исходная строка: %s\n", input);

        char beginning = '\0';  // Первая буква слова
        char ending = '\0';     // Последняя буква слова
        int in_word = 0;        // Флаг, указывающий, находимся ли мы внутри слова

        for (int i = 0; i <= strlen(input); ++i) {
            if (isalpha(input[i])) {  // Проверяем, является ли символ буквой
                if (!in_word) {       // Начало нового слова  // 1
                    beginning = tolower(input[i]);  // Запоминаем первую букву (в нижнем регистре)
                    in_word = 1;
                }
                ending = tolower(input[i]);  // Обновляем последнюю букву
            } 
            else if (in_word) {    // Конец слова
                K++;  // Увеличиваем счетчик слов
                if (beginning == ending) {
                    K_be++;  // Проверяем условие для слова
                }
                in_word = 0;  // Выходим из слова
            }
        }

        printf("\nКоличество слов в строке всего: %d", K);
        printf("\nКоличество слов, начинающихся и заканчивающихся на одну и ту же букву: %d", K_be);
        if (K_be == 0) {
            printf("\nСлов, начинающихся и заканчивающихся на одну и ту же букву, нет.");
        }
    } else {
        printf("Ошибка ввода.");
    }

    return 0;
}
