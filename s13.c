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
	fprintf(stdout, "Исходная строка : %s \n", line);
	
	
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
	
	for (int i = 0; i < len_t; ++i) {
		long int num = strtol (tokens[i], NULL, 10);
		if (num == 0 && tokens[i] != 0 ) {
			fprintf (stderr, "Ошибка преобразования строки %s в число !\n", tokens[i]);
		} 
		else {
			fprintf (stdout, "Num : %ld\n", num);
		}
	}

	
	free(line) ;
	free (tokens) ;

	return 0;

}
