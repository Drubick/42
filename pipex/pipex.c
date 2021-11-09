/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:02:28 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/09 16:02:21 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *file, int mode)
/*
abre un archivo y chekea sus permisos, si cumple los necesarios lo abre,
si no existe un archivo en el que escribir se crea uno 
*/
{
	if (mode == INFILE)
	{
		if (access(file, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, file, str_ichr(file, 0));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		if (access(file, R_OK))
		{
			print_pemrission_error(file);
			return (STDIN);
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}
/*
Con los S_* de open seteo los permisos a tru para luego abrirlos
*/

/*
consigo el path gurdando el string en bin y haciendole un return
*/
char	*get_path(char *instruction, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (instruction);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1)
	{
		dir = str_ndup(path, str_ichr(path, ':'));
		bin = path_join(dir, instruction);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (instruction);
}

/*
guardo los comandos en args y compruebo si existe el path
*/
void	exec(char *instruction, char **env, char *file)
{
	char	**args;
	char	*path;

	args = ft_split(instruction, ' ');
	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], env);
	if (access(file, W_OK))
		exit(1);
	execve(path, args, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, instruction, str_ichr(instruction, 0));
	write(STDERR, ": command not found\n", 20);
	exit (127);
}
/*
Si estamos en el proceso padre cerramos la salida de pipe
y cambiamos la entrada principal a STDIN, luego esperamos a que acabe 
el proceso hijo en cuestion,
Si estamos en el proceso hijo
*/

void	redirrect_pipe(char *instruction, char **env, int fdin, char *file)
{
	int	processid;
	int	pipefd[2];

	pipe(pipefd);
	processid = fork();
	if (processid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(processid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (access(file, W_OK))
			print_pemrission_error(file);
		if (fdin == STDIN)
			exit(1);
		else
			exec(instruction, env, file);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = openfile(argv[1], INFILE);
		fdout = openfile(argv[4], OUTFILE);
		if (fdout == STDOUT)
			exit(1);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		redirrect_pipe(argv[2], env, fdin, argv[4]);
		exec(argv[3], env, argv[4]);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}
