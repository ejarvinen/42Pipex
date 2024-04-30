/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:11:44 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/21 13:18:52 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_ULONG 4294967295

typedef struct s_list
{
	void			*content;
	int				allowed;
	struct s_list	*next;
}			t_list;

int		ft_isalpha(int var);

int		ft_isdigit(int var);

int		ft_isalnum(int var);

int		ft_isascii(int var);

int		ft_isprint(int var);

size_t	ft_strlen(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *hstack, const char *needle, size_t len);

void	ft_bzero(void *ptr, size_t n);

void	*ft_memset(void *ptr, int x, size_t n);

void	*ft_memmove(void *to, void *from, size_t n);

int		ft_toupper(int chr);

int		ft_tolower(int chr);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t n_e, size_t e_size);

void	*ft_memcpy(void *to, const void *from, size_t n);

char	*ft_strchr(const char *str, int chr);

char	*ft_strrchr(const char *str, int chr);

void	*ft_memchr(const void *str, int chr, size_t n);

int		ft_memcmp(const void *buf1, const void *buf2, size_t n);

size_t	ft_strlcpy(char *to, const char *from, size_t n);

size_t	ft_strlcat(char *to, const char *from, size_t to_size);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar(int c);

void	ft_putstr(char *str);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	**ft_split(char const *s, char c);

char	*ft_strdup(const char *str);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
