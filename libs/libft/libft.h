/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:19:41 by lade-lim          #+#    #+#             */
/*   Updated: 2023/03/23 10:50:50 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t	ft_array_size(char **array);
int		ft_atoi(const char *str);
void	*ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_free_array(char **matrix);
char	*gnl(int fd);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isfloat(char *str);
int		ft_isprint(int c);
int		ft_isrange(double value, double min, double max);
char	*ft_itoa(int n);
double	ft_atof(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *lst_new);
void	ft_lstadd_front(t_list **lst, t_list *lst_new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *str, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memset(void *str, int x, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *str, size_t size);
size_t	ft_strlcpy(char *dest, const char *str, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *largestr, const char *smallstr, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
size_t	ft_array_size(char **array);
int		ft_isspace(int c);
int		ft_isrange(double value, double min, double max);
int		ft_isfloat(char *str);
void	ft_free_array(char **matrix);

#endif 