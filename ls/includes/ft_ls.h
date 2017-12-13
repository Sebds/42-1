/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:20:21 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/13 22:20:21 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libftprintf/libft/includes/libft.h"
# include "../libftprintf/includes/libftprintf.h"
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <time.h>
# include <stdio.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <sys/xattr.h>

typedef struct		s_option
{
	int				dot_files;
	int				long_option;
	int				reverse;
	int				sort_time;
	int				recursive;
	int				single;
	long long		columns;
	long long		columns_temp;
	int				count_args;
	int				newline_dir;
	int				file_argv;
	int				bad_argv;
}					t_option;

typedef	struct		s_file
{
	mode_t			perm;
	int				link;
	int				link_len;
	char			*owner;
	int				owner_len;
	char			*group;
	int				group_len;
	long long		size;
	int				size_len;
	int				minor;
	int				minor_len;
	int				major;
	int				major_len;
	long			date;
	char			*name;
	char			*name_link;
	int				name_len;
	long long		block;
	struct s_file	*next;
}					t_file;

typedef struct		s_dir
{
	char			*path_dir;
	long			date;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_var
{
	DIR				*dir;
	struct dirent	*data;
	struct stat		buf;
	char			*path_file;
	int				i;
}					t_var;

typedef struct		s_layout
{
	int				max_link;
	int				max_owner;
	int				max_group;
	int				max_size;
	int				max_minor;
	int				max_major;
	int				max_name;
	long long		total_block;
	int				count_file;
	int				long_option;
	char			*path;
	int				newline_dir;
}					t_layout;

typedef struct		s_dimension
{
	int				col;
	int				line;
	int				newline;
	int				i;
	int				j;
	int				k;
}					t_dimension;

typedef struct		s_date
{
	char			*less_six_monthes;
	char			*more_six_monthes;
	char			*year;
	char			*future;
}					t_date;

void				ft_select_sort_dir(t_option *option, t_dir **dir_list);
void				ft_search_dir_info(t_dir *dir, t_var var, char *dir_path);
t_dir				*ft_search_dir(t_option *option, char **dir_path);

t_file				*ft_search_file_cur(char *file_path);
t_file				*ft_search_file_deep(char *t_f, char *t_p, char *f_p);
t_file				*ft_search_file(t_layout *layout, char **file_path);

void				ft_select_ls(t_file *f, t_layout l, t_option *o, char *p);
void				ft_ls(t_option *option, char *path_dir);

void				ft_get_layout(t_file *file, t_layout *layout);
void				ft_get_upid(t_file *file, struct stat buf);
void				ft_get_linked_name(t_file *file, char *path_file);
void				ft_get_file_len(t_file *file);
void				ft_get_file(t_file *file, char *path_dir, struct dirent *d);

void				ft_handle_bad_path(t_option *option, char **bad_argv);
void				ft_handle_file_list(t_option *option, char **file_argv);
void				ft_handle_dir_list(t_option *option, char **dir_argv);
char				**ft_alloc_tab(t_option *option, char **argv, int type);
char				**ft_create_tab_argv(t_option *optn, char **argv, int type);

int					ft_handle_dotfile(t_option *option, char *name);
void				ft_handle_recursive(t_file *f, t_option *o, char *path_dir);

void				ft_init_option(t_option *option);
void				ft_init_layout(t_layout *l, char *path_dir);
void				ft_init_var(t_var *var);

t_file				*ft_file_new(void);
t_dir				*ft_dir_new(void);
void				ft_file_push_back(t_file **list, t_file *cur);
void				ft_dir_push_back(t_dir **list, t_dir *cur);

void				ft_del_file_list(t_file **file_list);
void				ft_del_dir_list(t_dir **dir_list);
void				ft_delete_date(t_date *date);

void				ft_fill_option(t_option *option, char c);
void				ft_get_option(t_option *option, int argc, char **argv);

char				*ft_path(char *path_source);
void				ft_bad_dir(char *path_dir);
void				ft_empty_argv(void);
int					ft_valid_arg(char *s);
int					ft_no_spec_path(char **argv);

void				ft_print_acl_type(t_file *file);
void				ft_print_permission(t_file *file, t_layout *layout);
void				ft_print_xattr(t_file *file, t_layout *layout);
void				ft_print_date(t_file *file);

void				ft_print_long_option_file(t_file *file, t_layout *layout);
void				ft_print_long_option(t_file *f, t_layout l, t_option *o);

void				ft_print_modulo(t_file *f, t_layout l, int i, int newline);
void				ft_init_dimension(t_dimension *d, t_layout *l, t_option *o);
void				ft_print_normal(t_file *f, t_layout l, t_option *option);

void				ft_print_single(t_file *file_lst, t_option *option);

int					ft_search_current_dir(char *argv);
int					ft_search_deep_dir(char *t_f, char *t_p, char *argv);
int					ft_search_argv(t_option *option, char *argv);
void				ft_sort_tab(char **tab);

t_dir				*ft_sort_dir_time(t_dir *a, t_dir *b);
t_dir				*ft_sort_dir_name(t_dir *a, t_dir *b);
void				ft_split_dir(t_dir *source, t_dir **front, t_dir **back);
void				ft_sort_dir(t_dir **begin, char c);
void				ft_dir_reverse(t_dir **list);

t_file				*ft_sort_file_time(t_file *a, t_file *b);
t_file				*ft_sort_file_name(t_file *a, t_file *b);
void				ft_split_file(t_file *source, t_file **front, t_file **bck);
void				ft_sort_file(t_file **begin, char c);
void				ft_file_reverse(t_file **list);

int					ft_allow_recursive(char *dir_to_open);
int					ft_intlen(unsigned long long n);
int					ft_minor(int m);
int					ft_major(int m);
void				ft_usage(char c, char d);

#endif
