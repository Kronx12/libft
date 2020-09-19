/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 11:26:31 by gbaud             #+#    #+#             */
/*   Updated: 2020/09/19 07:53:18 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef int	t_boolean;
# define TRUE 1
# define FALSE 0
# define WHITESPACE " \t\r\n\v\f"

/*
** Allocation Section
*/

void				ft_bzero(void *s, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_realloc(char *str, int size);
char				*ft_strdup(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_free_return(void *v);
/*
** Checker Section
*/

t_boolean			ft_isalnum(int c);
t_boolean			ft_isalpha(int c);
t_boolean			ft_isdigit(int c);
t_boolean			ft_isascii(int c);
t_boolean			ft_isprint(int c);
t_boolean			ft_allisalnum(char *str);
t_boolean			ft_allisalpha(char *str);
t_boolean			ft_allisdigit(char *str);
t_boolean			ft_allisascii(char *str);
t_boolean			ft_allisprint(char *str);
int					ft_strchr_int(const char *s, int c);
char				*ft_strchr_chr(const char *s, int c);
int					ft_strrchr_int(const char *s, int c);
char				*ft_strrchr_chr(const char *s, int c);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

/*
** List Section
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int					ft_free_strs(int count, ...);
int					ft_free_strs_tab(char **tab);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstremove_node(t_list **head_ref, t_list *del);
void				ft_lstremove_if(t_list **head, void *value,
						void (*del)(void *),
						int (*cond)(void *, void *));

/*
** Converters Section
*/

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n1);
char				*ft_ctos(char c);

/*
** Printer Section
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);

/*
** Get_Next_Line Section
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char				*ft_strfdup(char *src, int n, int f);
int					get_next_line(int fd, char **line);

/*
** Ft_printf Section
*/

typedef struct		s_flags
{
	int				min;
	char			flag;
	int				width;
	int				precision;
	char			type;
	char			*result;
}					t_flags;
typedef struct		s_str
{
	char			*str;
	int				len;
}					t_str;

char				*ftib(long long val2, char *base);
char				*ft_ulitoa_base(unsigned long long val, char *base);
char				*ft_charfjoin(char *s1, char c, int f);
t_str				*ft_structfjoin(t_str *s1, t_str *s2, int f);
t_str				*ft_strndup(t_str *str, int n, int f);
void				ft_putnstr(char *str, int len);
void				ft_replace(char *str, char c, char d);
t_str				*create_str(char *s, int l);
t_str				*create__str(char *s);
void				free_str(t_str *s);
t_flags				*init_flags(void);
void				fill_struct(const char *str, int *i,
						va_list *lst, t_flags *f);
void				fill_min(const char *str, int *i, va_list *lst, t_flags *f);
void				fill_flags(const char *str, int *i, t_flags *f);
void				fill_width(const char *str, int *i,
						va_list *lst, t_flags *f);
void				fill_precision(const char *str, int *i,
						va_list *lst, t_flags *f);
void				fill_type(const char *str, int *i,
						va_list *lst, t_flags *f);
void				flags_on_value(t_str **str, t_flags *f);
int					ft_printf(const char *str, ...) __attribute__
						((format(printf,1,2)));

/*
** String Functions Section
*/

size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char *s2, int j);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *fi, const char *se, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				**ft_split(char const *str, char charset);
void				ft_replace(char *str, char c, char d);
char				*ft_strtrim(char const *s, char const *set);
int					ft_strcmp(char *fi, char *se);
int					ft_count_char(char *str, char c);
int					ft_strtablen(char **tab);
char				**ft_rm_null_tab(char **tab, t_boolean f);

/*
** Btree Functions Section
*/

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

void				btree_print_str(t_btree *root);
void				btree_print_int(t_btree *root);
t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root, void *item,
						int (*cmpf)(void *, void *));
void				*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *));
int					btree_level_count(t_btree *root);
void				btree_apply_by_level(t_btree *root,
						void (*applyf)(void *item, int current_level,
						int is_first_elem));

/*
** Debug Functions Section
*/
void				ft_debug_str_1d(char **arr);
void				ft_debug_str_2d(char ***arr);

#endif
