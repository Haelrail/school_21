/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:41:30 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:42:04 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SHELL 			"minishell$ "
# define BUILTIN_NUM 	7
# define LONG_INT_MAX 	9223372036854775807
# define HEREDOC		".here_doc"

//Errors
# define EXIT_TOO_MANY_ARG	10
# define EXIT_WRONG_ARG		11
# define EXIT_DUP			81
# define TOKEN_ERROR		258
# define CMD_NOT_FOUND		127
# define SYMBOLS_ERROR		102

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>

typedef struct s_cmd
{
	char			*cmd_name;
	char			**cmd_argv;
	pid_t			pid;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_list
{
	void			*key;
	void			*val;
	struct s_list	*next;
}	t_list;

typedef void	(*t_builtin_ptr)(t_cmd *, void *);

typedef struct s_info
{
	t_builtin_ptr	builtin[BUILTIN_NUM];
	char			*reserved_words[BUILTIN_NUM];
	char			**envp;
	t_list			*envp_list;
	t_list			*export_list;
	char			*input;
	t_cmd			*args;
	int				cmd_num;
	int				**pipe;
	char			envp_f;
	char			exit_t;
	int				status;
	int				p_id;
}	t_info;

//	main_minishell_utils
void			ft_initializer(char **envp, t_info **info);
void			ft_signal(t_info *info, int i);
char			*ft_readline(t_info *info);
void			ft_executor(t_info *info);
void			ft_parser(t_info *info);
void			ft_destructor(t_info *info);

//	initializer_utils
//		init_sh_lvl.c
void			init_sh_lvl(t_info *info);

//	parser_utils
//		parse_findword_1.c
char			*find_word(char **input, t_info *info);
//		parse_findword_2.c
char			*single_parse(char **input, t_info *info);
char			*parse_double_quote(char **input, t_info *info);
//		parse_redirect.c
void			get_forward_redirect(char **input, t_info *info, t_cmd *cmnd);
void			get_double_forward_redirect(char **input,	\
					t_info *info, t_cmd *cmnd);
void			get_back_redirect(char **input, t_info *info, t_cmd *cmnd);
void			get_double_back_redirect(char **input,		\
					t_info *info, t_cmd *cmnd);
//	executor_utils
//		exec_utils.c
void			ft_exec_one_cmd(t_cmd *cmd, t_info *info);
void			ft_exec_many_cmd(t_cmd *cmds, t_info *info);
//		exec_bin.c
int				ft_exec_builtin(t_cmd *cmd, t_info *info);
void			ft_exec_bin(t_cmd *cmd, t_info *info);
//		exec_prcs.c
void			ft_fork(t_info *info, t_cmd *cmd, const char *str);
void			ft_waitpid(t_info *info, int pid);
//		exec_dup.c
void			ft_dup_zero(int infile);
void			ft_dup_one(int outfile);
//		exec_pipe.c
void			ft_pipe_one_cmd(t_cmd *cmd);
void			ft_pipes_init(t_info *info);
void			ft_close_all_pipes(t_info *info);
void			ft_close_pipe_exception(t_info *info);
void			ft_free_all_pipes(t_info *info);

//	builtins
void			builtin_echo(t_cmd *args, void *data);
void			builtin_cd(t_cmd *args, void *data);
void			builtin_pwd(t_cmd *args, void *data);
void			builtin_export(t_cmd *args, void *data);
void			builtin_unset(t_cmd *args, void *data);
void			builtin_env(t_cmd *args, void *data);
void			builtin_exit(t_cmd *args, void *data);

//		cd_utils
void			ft_search_oldpwd(char **oldpwd, t_info *info);
void			ft_cd_error(t_info *info, char **arr, int flag, char *oldpwd);

//	list
t_list			*ft_lstnew(char *key, char *val);
void			ft_lstdelone(t_list *elem);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_sort(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstclear(t_list **lst);
t_list			*ft_lstfindkey(t_list *lst, char *key);
void			ft_lstkick_key(t_list **lst, char *key);

//	cmd_list
t_cmd			*ft_cmdnew(char *cmd_name, char **cmd_argv);
void			ft_cmddelone(t_cmd *elem);
void			ft_cmdclear(t_cmd **cmd);
t_cmd			*ft_cmdlast(t_cmd *cmd);
void			ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
void			ft_cmdadd_front(t_cmd **cmd, t_cmd *new);
int				ft_cmdsize(t_cmd *cmd);

//	errors
void			ft_perror_exit(char *str, int error);
void			ft_perror(char *str);
void			ft_perror_cmd(t_info *info, char *cmd);
int				ft_perror_symbols(t_info *info, char *symbol);
int				ft_perror_file(t_info *info, char *infile);
int				ft_perror_eof(t_info *info);

//	arithmetic utils
int				ft_atoi(const char *str);
long long int	ft_atoll(const char *str);
long long int	ft_mod(long long num);
char			*ft_itoa(int n);

//	is utils
int				ft_isalpha(char c);
int				ft_isdigit(char c);
int				ft_isspace(char c);
int				ft_issymbol(char c);
int				ft_isnumber(char *str);

//	string utils
void			ft_bzero(void *b, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(char *src, int size);
char			**ft_double_realloc(char **src, int size);
int				ft_strlen(const char *s);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_wrdcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
void			ft_strfree(char *s);
char			*ft_strndup(const char *s, int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			**ft_split_halve(char const *s, char c);
int				ft_split_len(char **split);
void			ft_split_free(char **split);
char			*ft_strchr(const char *s, int c);

//	print utils
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char	*s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putsplit_fd(char **s, int fd);

#endif