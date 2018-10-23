/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:27:00 by mpetruno          #+#    #+#             */
/*   Updated: 2018/10/19 20:10:55 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define uintmax_t __uintmax_t // remove this
#define intmax_t long         // remove this

#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define ABS(X) (X < 0) ? -X : X
# define MAX(A, B) (A > B) ? A : B
# define MIN(A, B) (A > B) ? B : A

# define FLAGS "#0- +"
# define TYPES "sSpdDioOuUxXcCb%"

# define NTOA_BUFF_SIZE 65
# define OUTPUT_BUFF_SIZE 4096

# define F_HASH		(1U << 0U)
# define F_ZERO		(1U << 1U)
# define F_LEFT		(1U << 2U)
# define F_SPACE	(1U << 3U)
# define F_PLUS		(1U << 4U)
# define F_THOU		(1U << 5U)
# define F_PREC		(1U << 6U)

# define F_CHAR		(1U << 7U)
# define F_SHORT	(1U << 8U)
# define F_LONG		(1U << 9U)
# define F_LLONG	(1U << 10U)
# define F_INTMAX	(1U << 11U)
# define F_SIZE_T	(1U << 12U)

typedef struct s_outbuff t_outbuff;
struct	s_outbuff
{
	int					fd;
	int					count;
	unsigned char		buffer[OUTPUT_BUFF_SIZE + 1];
	unsigned char		*end;
//	void		(*flush)(t_outbuff *); // try to remove these functions
//	void		(*append)(t_outbuff *, const char *, int n);
};

typedef struct	s_fmarg
{
	int			flags;
	int			width;
	int			precision;
	char		type;
}				t_fmarg;

void			flush(t_outbuff *buff);
void			append(t_outbuff *buff, const char *str, int n);
void			appendnchr(t_outbuff *buff, const char *str, int n);
void			appendchr(t_outbuff *buff, const char c, int n);
void			initialize_output_buff(t_outbuff *buff, int fd);

int				ft_printf(const char *fmt, ...);
void			print_arg(t_fmarg *arg, va_list *ap, t_outbuff *buffer);
void			parse_flags(char **str, t_fmarg *arg, va_list *ap);
void			arg_to_str_di(t_fmarg *arg, va_list *ap, char *buff);
void			arg_to_str_oux(t_fmarg *arg, va_list *ap, char *buff);
void			arg_to_str_f(t_fmarg *arg, va_list *ap, char *buff);

void			print_f(t_fmarg *a, char *s, int len, t_outbuff *buffer);
void			print_di(t_fmarg *a, char *s, int len, t_outbuff *buffer);
void			print_u(t_fmarg *a, char *s, int len, t_outbuff *buffer);
void			print_o(t_fmarg *a, char *s, int len, t_outbuff *buffer);
void			print_x(t_fmarg *a, char *s, int len, t_outbuff *buffer);
void			print_c(t_fmarg *a, char *s, int len, t_outbuff *buffer);
void			print_s(t_fmarg *a, char *s, int len, t_outbuff *buffer);

void			pf_ulltoa_base(unsigned long long int n, int base,
				t_fmarg *fm, char *buff);
//int				get_arg_num(char **fmt);
//void			*get_arg_data(int id, va_list *ap, t_avlist *av);
#endif
