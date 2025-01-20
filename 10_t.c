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
		line [read -1] = '\n';
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
	
	// Определение максималбного и минимао=льного токена .
	
	char* MIN = tokens [0]; 
	char* MAX = tokens [0];
	int i_max = 0;
	int i_min = 0;

	for (int i = 1; i < len_t; ++i) {
		if (strcmp(tokens[i], MAX) > 0) {
			MAX = tokens[i];
			i_max = i;
		}
		if (strcmp (tokens[i], MIN) < 0) {
			MIN = tokens [i]; 
			i_min = i;
		}
	}
	
	fprintf (stdout, "Максимальный токен : %s\t, индекс : %d\n", MAX, i_max);
	
	fprintf (stdout, "Минимальный токен : %s\t, индекс : %d\n", MIN, i_min);
	
	free(line);
	free(tokens);
	free (token);
	
	return 0;
}
