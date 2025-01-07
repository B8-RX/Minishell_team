#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// Constantes pour les codes de retour des commandes
# define CMD_NOT_FOUND 127  // Commande non trouvée
# define CMD_NO_PERMISSION 126  // Permission refusée

// Enumération pour les types de redirection
typedef enum e_redirection_type {
	REDIR_NONE,       // Pas de redirection
	REDIR_INPUT,      // <
    REDIR_OUTPUT,     // >
    REDIR_APPEND,     // >>
    REDIR_HEREDOC     // <<
} t_redirection_type;

// Structure pour les redirections
typedef struct s_redirection {
    t_redirection_type type;  // Type de redirection
    char *file;               // Nom du fichier cible
    struct s_redirection *next; // Pointeur vers la redirection suivante
    // Cette liste chaînée doit être remplie par le parsing pour indiquer toutes les redirections
    // associées à la commande, par exemple les fichiers et leurs types.
} t_redirection;

// Enumération pour les types de connexions
typedef enum e_pipe_type {
    PIPE_NONE,        // Pas de pipe
    PIPE_SINGLE,      /* Commande connectée à un pipe (|), mais pas à la fin d'une chaîne
						 Exemple : Dans ls | grep txt, la commande ls aura PIPE_SINGLE.*/
    PIPE_END          /* Dernière commande d'une chaîne de pipes (|)
						 Exemple : Dans ls | grep txt, la commande grep aura PIPE_END. */
} t_pipe_type;

// Structure principale pour une commande
typedef struct s_command {
    char *cmd_name;           // Nom de la commande principale (pour éviter de manipuler args[0])
    char **args;              // Arguments de la commande (NULL-terminated)
    t_redirection *redirections; // Liste chaînée des redirections
    t_pipe_type pipe;         // Indique si la commande est connectée à un pipe
    bool is_builtin;          // Si la commande est un built-in
    struct s_command *next;   // Commande suivante dans une pipeline
    // Cette structure doit être remplie par le parsing et contient toutes les informations nécessaires
    // pour exécuter une commande, y compris les arguments, les redirections, et l'indicateur de built-in.
} t_command;

// Structure globale pour Minishell, que le parsing doit remplir et que l'exécution doit utiliser
typedef struct s_minishell {
    char **env;               // Variables d'environnement
    int exit_status;          // Dernier code de sortie ($?)
    t_command *commands;      // Liste chaînée des commandes à exécuter
    // Cette structure globale est utilisée pour passer les variables d'environnement
    // et la liste des commandes à l'exécution.
} t_minishell;

// Prototypes des fonctions principales
bool is_builtin_command(const char *cmd); 
// Vérifie si la commande passée est un built-in (retourne true si oui, false sinon)

t_command *create_command(char **args); 
// Crée une structure t_command à partir des arguments fournis (args) et initialise les champs correspondants

void execute_command(t_minishell *shell); 
// Parcourt la liste des commandes dans t_minishell et exécute chaque commande.
// Gère les redirections et les pipes. En cas d'erreur (commande non trouvée, redirection invalide),
// affiche un message d'erreur et met à jour le champ exit_status.

void free_command(t_command *command); 
// Libère la mémoire associée à une commande, y compris ses arguments et ses redirections

void free_minishell(t_minishell *shell); 
// Libère toute la mémoire associée à la structure t_minishell, y compris les commandes et l'environnement

#endif
