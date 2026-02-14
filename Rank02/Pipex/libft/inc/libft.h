/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:06:10 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/14 14:29:27 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

/* Structures */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_atod
{
	double		frac;
	double		base;
	double		val;
	const char	*paki;
	int			point;
}				t_atod;

/* ========================================================================== */
/*                                 FUNCTIONS                                  */
/* ========================================================================== */

/* ========================================== */
/*               CHARACTER TYPE               */
/* ========================================== */
int			ft_isalpha(int c);
int			ft_isdigit(int n);
int			ft_isalnum(int a);
int			ft_isascii(int c);
int			ft_isprint(int p);
int			ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

/* ========================================== */
/*                   MEMORY                   */
/* ========================================== */
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmeb, size_t sizem);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* ========================================== */
/*                   STRING                   */
/* ========================================== */
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_space(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ========================================== */
/*               CONVERSIONS                  */
/* ========================================== */
int			ft_atoi(const char *str);
int			ft_atoi_strict(const char *str, long *num);
char		*ft_itoa(int n);
double		ft_atod(const char *s, t_atod *atod);

/* ========================================== */
/*               MATH                         */
/* ========================================== */
int			ft_abs(int n);
void		sort_int_array(int *arr, int size);

/* ========================================== */
/*               PUT (Output FD)              */
/* ========================================== */
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

/* ========================================== */
/*               LISTS                        */
/* ========================================== */
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *));

/* ========================================== */
/*               GNL (Get Next Line)          */
/* ========================================== */
char		*get_next_line(int fd);

/* ========================================== */
/*               PRINTF                       */
/* ========================================== */
int			ft_printf(char const *format, ...);
int			ft_print_char(char c);
int			ft_print_string(char *str);
int			ft_print_nbr(int n);
int			ft_print_unsigned(unsigned int n);
int			ft_print_hexdecmi(unsigned long long int n);
int			ft_print_hexdecma(unsigned long long n);
int			ft_print_pointer(void *str);
int			ft_print_percent(void);
int			ft_print_format(va_list args, char c);

#endif
