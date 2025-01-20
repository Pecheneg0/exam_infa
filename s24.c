#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
int main() {
	fprintf (stdout, "Введите строку :");
	char* line = NULL;
	size_t size_l = 0;
	ssize_t read = getline (&line, &size_l, stdin);
	if (read == -1) {
		fprintf(stderr, "Ошибка чтения строки !\n");
		free(line);
		exit(1);
	}
	if (read != 0 && line[read - 1 ] == '\n') {
		line [read -1] = '\0';
	}
	fprintf(stdout, "Иссходная строка : %s ", line);
	
	
	// Разделение строки по токенам 
	char** tokens = NULL;
	const char* delim = " ";
	size_t len_t = 0;
	char* token = strtok (line, delim);

	while (token != 0) {
		tokens = realloc (tokens, sizeof (char*) * (len_t + 1));
		if (tokens ==  NULL) {
			fprintf(stderr, "Ошибка расширения памяти для массива tokens ! \n");
			free(line);
			free(tokens);
			exit(2);
		}	
		
		tokens[len_t] = token;
		fprintf(stdout, "Token № %lu : %s\n", len_t + 1, token);
	
		token = strtok (NULL, delim);
		len_t += 1;
	} 

	fprintf(stdout, "Ответ на задачу : \n");
	char alpha_arr []  = {'a', 'e', 'u','i','o'};
	int K = 0; // Счётчик слов, нач-ся на гласную букву.
	for (int i = 0; i < len_t; ++i) {
		for (int h = 0; h < 5; ++h) {
			if (tolower(tokens[i][0]) == alpha_arr[h] ) {
				K++;
				fprintf (stdout , "Слово № %d : %s\n", i+1, tokens[i]);
			}
		}
	}
	if (K == 0) {
		fprintf (stdout, "Таких слов нет\n");
	}
	
	free (tokens);
	free (line);
	return 0;
}
