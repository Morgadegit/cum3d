/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:08:50 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/07 13:46:12 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_strlen(char const *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char const *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2, int sw);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_itoa_uns(unsigned int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_get_size_number(int i);
char			*ft_dec_to_binary_convert(int x);
char			*ft_revert_array(char *s);
char			*get_hex_table();
int				ft_strcmp(char *s1, char *s2);
char			*ft_dec_to_binary_32bits_convert(char *number);
char			*ft_binary_to_hex_convert(char *number);
char			*ft_dec_to_hex_convert(long x);
char			*ft_d_t_h_conv_p(unsigned long long x);
unsigned int	ft_power(int root, int power);
void			ft_put_unsigned_fd(unsigned int nb, int fd);
unsigned int	ft_abs(int x);
int				ft_get_size_number(int i);
int				ft_get_size_unsigned(unsigned int i);
char			*ft_strncat(char *dst, char *src, int nb);
char			*ft_delchar(char *s, char c, char x);
char			*ft_strnjoin(char *dst, char *src, int nb, int sw);
char			*ft_strcat(char *dst, char *src);
void			ft_add_x_char(char **s, char *c, int n);
void			ft_strrep(char **s1, char *s2);
int			ft_nbrlen(int x);
int			ft_iswhite(char c);
int			ft_is_set_nbr(int x, int size, ...);
int			ft_is_btwn(int i, int min, int max);
char			*ft_strndup(char const *s, int x);
char			*ft_strlstr(char const *haystack, const char *needle, size_t len);
#endif
