#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "command.h"

#define CWD_BUFFER 1024

int main(void) {

	char prompt[SHELL_BUFFER];
	Command *command = NULL;
	char *cwd;
	char *rl;
    
	/* Pega o cwd do usuario */
	cwd = getcwd(NULL, CWD_BUFFER);

	/* Printa no terminar o cwd do usuario */
	snprintf(prompt, CWD_BUFFER, "[%s] ", cwd);

	/* Aguarda uma entrada do usuario */
	while((rl = readline(prompt)) != NULL) {
		
		/* Encerra o shell */
		if(strcmp(rl, "exit") == 0) break;

		/* Nao houve comando */
		if(strcmp(rl, "") == 0) continue; 
		
		/* Le o comando da linha */
		command = command_read(rl);
			
		/* Chamda de sistema chmod */
		if(strcmp(command->argv[0], "chmod") == 0) {

			/* Verifica se foi passado 3 paramentros */
			if(command->argc == 3) 
		 		chmod(command->argv[2], atoi(command->argv[1]));
			else 
				printf("chmod uiltiliza dois parametros: chmod <modo numero> <arquivo> \n");
		
		/* Chamada de sistema para retornar o id do usuario */ 
		} else if(strcmp(command->argv[0], "id") == 0 && strcmp(command->argv[1], "-u") == 0) {
			printf("%d\n", getuid());
		} else {
			/* Caso seja o filho executar o execve */
			if(fork() == 0) {
				
				int r = execve(command->argv[0], command->argv, NULL); 
				
				/* Trata o erro do execve */					
				if(r == -1) { 
					perror("Comando nao encontrado");
					exit(1);
				}

			} else {
				/* Espero o filho retornar */
				wait(NULL);
			}
		}

		/* Adicionar o comando no historico do shell */
		add_history(rl);

		/* Libera memoria da string do comando */
		free(rl);

		/* Libera a memoria da string cwd */
		free(cwd);
	
		/* Pega o cwd do usuario de novo e imprimi */
		cwd = getcwd(NULL, CWD_BUFFER);
		snprintf(prompt, CWD_BUFFER, "(%s): ", cwd);
		
		/* Libera memoria da leitura do comando */
		command_destroy(command);

	}
	
	/* Libera memoria do readline */
	free(rl);

	return 0;
}
