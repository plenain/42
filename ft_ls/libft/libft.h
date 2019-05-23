/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# define COLOR_RESET ("\033[0m")
# define BASE_HEX ("0123456789ABCDEF")

/*
** Memory-related
*/

void					*ft_memset(void *ptr, int value, size_t num);
void					ft_bzero(void *sl, size_t n);
void					*ft_memcpy(void *destination, const void *source,
						size_t num);
void					*ft_memccpy(void *dest, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					*ft_memdup(const void *src, size_t size);
int						ft_adv_memcmp(const void *source, const char *hexdata);
void					ft_swap(void **str, void **str2);

/*
** String comparison / Searching
*/

char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(
						char const *s, char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strchr(const char *str, int character);
char					*ft_strrchr(const char *str, int character);
char					*ft_strstr(const char *str1, const char *str2);
char					*ft_strnstr(const char *s1, const char *s2,
						size_t length);
int						ft_strcmp(const char *str1, const char *str2);
int						ft_strncmp(const char *str1, const char *str2,
						size_t num);
size_t					ft_strlen(const char *s);
size_t					ft_strlen_if(const char *s, int (*f)(int));

/*
** Character comparisons
*/

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isprint(int c);
int						ft_isascii(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_ishex(int c);

/*
** String manipulation / creation
*/

char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoinfree(char *source, const char *concat);
char					*ft_strjoinfree_both(char *source, char *concat);
char					*ft_strjoinfree_last(const char *source, char *concat);
char					*ft_strjoin_if(char *source, char *concat,
						int (*f)(int));
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_strins(char *dest, const char *src,
						unsigned int pos);
char					*ft_strins_malloc(char *dest, const char *src,
						unsigned int pos);
char					*ft_strdup(const char *s);
char					*ft_strdup_if(const char *s, int (*f)(int));
char					*ft_strcpy(char *destination, const char *source);
char					*ft_strncpy(char *destination, const char *source,
						size_t num);
char					*ft_strcat(char *destination, const char *source);
char					*ft_strncat(char *destination, const char *source,
						size_t num);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strtolower(char *string);
char					*ft_strtoupper(char *string);
char					*ft_strcut(char *str, int start, int end);

/*
** Printing functions
*/

size_t					ft_putstr_non_printable(char *str);
size_t					ft_putnstr_non_printable(char *str, size_t n);
size_t					ft_putnstr_non_printable_fd(char *str, size_t n,
						int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr_base(unsigned int nbr, unsigned int base);
void					ft_putnbrendl(int n);
size_t					ft_putnstr(char *str, size_t n);
size_t					ft_putnstr_fd(char *str, size_t n, int fd);
int						ft_putchar(int c);
int						ft_print_char(char c, int amount);
int						ft_print_char_fd(char c, int amount, int fd);
size_t					ft_putstr(char const *s);
size_t					ft_putendl(char const *s);
void					ft_putchar_fd(int c, int fd);
size_t					ft_putstr_fd(char const *s, int fd);
size_t					ft_putendl_fd(char const *s, int fd);
int						ft_printf(const char *format, ...);
int						ft_printf_fd(const int fd, const char *format, ...);
void					*ft_print_memory(void *addr, unsigned int size);
void					ft_print_hex(unsigned int value, int length);
void					ft_print_hex_fd(unsigned int value, int length, int fd);

/*
** Unicode
*/

int						ft_putstr_uni(int *str);
int						ft_putnstr_uni(int *str, int len);
void					ft_putchar_uni(int c);
void					print_two_bytes(unsigned int c, int fd);
void					print_three_bytes(unsigned int c, int fd);
void					print_four_bytes(unsigned int c, int fd);
int						ft_strlen_uni(int *str);
void					ft_putchar_uni_fd(int c, int fd);
int						ft_putstr_uni_fd(int *str, int fd);
int						ft_putnstr_uni_fd(int *str, int len, int fd);

/*
** Bits
*/
int						ft_set_bit(int nbr, int idx, char value);
int						ft_get_bit(int nbr, int idx);
int						ft_get_firstbit(int nbr);
int						ft_get_lastbit(int nbr);

/*
** Utilities
*/
int						ft_max(int n1, int n2);
int						ft_min(int n1, int n2);
unsigned int			ft_abs(int value);
int						ft_floor(int min, int value);
int						ft_ceil(int max, int value);
int						nbrlen(long long n);
int						unbrlen(unsigned long long n);

/*
** Other
*/

int						ft_atoi(const char *str);
unsigned long			ft_atoi_base(const char *str, unsigned int base);
char					*ft_itoa(int n);
long long				ft_power(int nb, int power);

/*
** Memory reading
*/

char					read_char(void *n);
short					read_short(void *n);
int						read_int(void *n);
long					read_long(void *n);
long long				read_llong(void *n);

unsigned char			read_uchar(void *n);
unsigned short			read_ushort(void *n);
unsigned int			read_uint(void *n);
unsigned long			read_ulong(void *n);
unsigned long long		read_ullong(void *n);

#endif
