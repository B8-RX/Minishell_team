/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:29:52 by ssghioua          #+#    #+#             */
/*   Updated: 2025/01/10 12:00:00 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>

// Constantes pour les codes de retour des commandes
# define CMD_NOT_FOUND 127
# define CMD_NO_PERMISSION 126
# define CMD_INVALID_ARGUMENT 2
# define CMD_SUCCESS 0
# define CMD_TERMINATED_BY_SIGNAL 128

// Enumération pour les types de redirection
typedef enum e_redirection_type
{
	REDIR_NONE,
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redirection_type;

// Structure pour les redirections
typedef struct s_redirection
{
	t_redirection_type		type;
	char					*file;
	bool					error_flag;
	struct s_redirection	*next;
}	t_redirection;

// Enumération pour les types de connexion via pipe
typedef enum e_pipe_type
{
	PIPE_NONE,
	PIPE_START,
	PIPE_MIDDLE,
	PIPE_END
}	t_pipe_type;

// Enumération pour les types de commandes
typedef enum e_cmd_type
{
	CMD_ABSOLUTE,
	CMD_RELATIVE,
	CMD_PATH
}	t_cmd_type;

// Structure principale pour une commande
typedef struct s_command
{
	char				*cmd_name;
	char				**args;
	t_redirection		*redirections;
	t_pipe_type			pipe;
	int					fd_in;
	int					fd_out;
	char				*resolved_path;
	int					exit_status;
	bool				is_builtin;
	t_cmd_type			cmd_type;
	struct s_command	*next;
}	t_command;

// Structure globale pour Minishell, que le parsing doit remplir
//		et que l'exécution doit utiliser
typedef struct s_minishell
{
	char			**env;
	int				exit_status;
	struct termios	old_termios;
	t_command		*commands;
}	t_minishell;

// Variable globale pour les signaux (limitée à une seule)
extern volatile sig_atomic_t	g_signal_status;

// Prototypes des fonctions principales
bool		is_builtin_command(const char *cmd);
t_command	*create_command(char **args);
void		execute_command(t_minishell *shell);
void		free_command(t_command *command);
void		free_minishell(t_minishell *shell);
void		setup_signal_handlers(void);
void		handle_signals(void);

#endif
//	======== DETAILS CONCERNANT LES STUCTURES DE DONNEES ==========
// typedef enum e_redirection_type
// {
//     REDIR_NONE,
//     REDIR_INPUT,      // <
//     REDIR_OUTPUT,     // >
//     REDIR_APPEND,     // >>
//     REDIR_HEREDOC     // <<
// }   t_redirection_type;
//
// // Structure pour les redirections
// typedef struct s_redirection
// {
//     t_redirection_type type;
//     char               *file;
//     bool               error_flag;      // Indique une erreur de fichier
//     struct s_redirection *next;
// }   t_redirection;
//
// // Enumération pour les types de commandes
// typedef enum e_cmd_type
// {
//     CMD_ABSOLUTE,      // Chemin absolu
//     CMD_RELATIVE,      // Chemin relatif
//     CMD_PATH           // Résolution via $PATH
// }   t_cmd_type;
//
// // Structure principale pour une commande
// typedef struct s_command
// {
//     char                *cmd_name;       // Nom de la commande
//     char                **args;          // Arguments de la commande
//     t_redirection       *redirections;   // Liste chaînée des redirections
//     t_pipe_type         pipe;            // Type de pipe (PIPE_START, ...)
//     int                 fd_in;           // Descripteur d'entrée
//     int                 fd_out;          // Descripteur de sortie
//     char                *resolved_path;  // Chemin résolu (pour execve)
//     int                 exit_status;     // Statut de sortie de la commande
//     bool                is_builtin;      // Commande interne ?
//     t_cmd_type          cmd_type;  // Type de commande (CMD_ABSOLUTE, ...)
//     struct s_command    *next;     // Commande suivante dans la pipeline
// }   t_command;
//
// typedef struct s_minishell
// {
//     char				**env;          // Variables d'environnement
//     int		        exit_status;    // Dernier code de sortie ($?)
//     struct termios	old_termios;	// Infos sur le terminal
//     t_command		*commands; // Liste chaînée des commandes à exécuter
// }   t_minishell;
// 
// ============   Exemple pour la commande ls -l ======
//
// t_command command = {
//     .cmd_name = "ls",                     // Nom de la commande
//     .args = (char *[]){"ls", "-l", NULL}, // Arguments de la commande
//     .redirections = NULL,                 // Pas de redirections
//     .pipe = PIPE_NONE,                    // Pas de pipe
//     .fd_in = STDIN_FILENO,                // Entrée standard
//     .fd_out = STDOUT_FILENO,              // Sortie standard
//     .resolved_path = "/bin/ls",           // Chemin vers l'exécutable
//     .exit_status = 0,                     // Code de sortie
//     .is_builtin = false,                  // Ce n'est pas un builtin
//     .cmd_type = CMD_PATH,                 // Trouvé dans le PATH
//     .next = NULL                          // Pas de commande suivante
// };
//
// Pourquoi c'est comme ça ?
//
//     cmd_name : C'est le nom de la commande qu'on exécute, ici ls.
//     args : La commande et ses arguments. Important :
//			ça se termine toujours par NULL.
//     redirections : On n'a pas de redirections ici (genre > ou <),
//			donc c'est NULL.
//     pipe : Pas de pipe, donc PIPE_NONE.
//     fd_in / fd_out : Par défaut, ça utilise l'entrée/sortie standard.
//     resolved_path : Le chemin complet de la commande 
//			 (ça peut venir du parsing $PATH).
//     is_builtin : Ce n'est pas une commande interne, donc false.
//     cmd_type : Comme ls vient du $PATH, on met CMD_PATH.
//     next : Pas d'autres commandes enchaînées ici, donc NULL.
