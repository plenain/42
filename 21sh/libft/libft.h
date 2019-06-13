/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:32:51 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/16 16:53:59 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_addtomul(int i, int y);
int					ft_puiss(int b);
char				*ft_romanus(int b);
int					ft_countdeci(int a);
void				*ft_remalloc(void *lib, size_t n);
void				*ft_maxunsignedsize(void);
int					ft_pow(int a, int b);
size_t				ft_russianpeasant(size_t a, size_t b);
int					ft_getbitsystem(void);
int					ft_isbisextile(int y);
int					ft_maonthn(int y, int m);
int					ft_jds(int y, int m, int d);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				*ft_memdup(void const *s1, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_itoa(int n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strrchr(const char *str, int c);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *h, const char *n, size_t l);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putstr(char const *str);
char				*ft_strtrim(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
int					ft_strcmp (const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				**ft_strsplit(char const *s, char c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
char				*ft_strdup(const char *s1);
#endif
