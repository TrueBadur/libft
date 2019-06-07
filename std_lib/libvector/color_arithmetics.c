/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <ehugh-be@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:11:17 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/06/07 13:19:47 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vec.h"

t_ucol4 col_add(t_ucol4 a, t_ucol4 b)
{
	t_ucol4 ret;

	ret.c_col.a = a.c_col.a + b.c_col.a;
	ret.c_col.r = a.c_col.r + b.c_col.r;
	ret.c_col.g = a.c_col.g + b.c_col.g;
	ret.c_col.b = a.c_col.b + b.c_col.b;
	return (ret);
}

t_ucol4 col_dif(t_ucol4 a, t_ucol4 b)
{
	t_ucol4 ret;

	ret.c_col.a = a.c_col.a - b.c_col.a;
	ret.c_col.r = a.c_col.r - b.c_col.r;
	ret.c_col.g = a.c_col.g - b.c_col.g;
	ret.c_col.b = a.c_col.b - b.c_col.b;
	return (ret);
}

t_ucol4 col_div_val(t_ucol4 a, int val)
{
	t_ucol4 ret;

	if (val == 0)
		return ((t_ucol4)0);
	ret.c_col.a = a.c_col.a / val;
	ret.c_col.r = a.c_col.r / val;
	ret.c_col.g = a.c_col.g / val;
	ret.c_col.b = a.c_col.b / val;
	return (ret);
}

t_ucol4 col_mult_val(t_ucol4 a, int val)
{
	t_ucol4 ret;

	ret.c_col.a = a.c_col.a * val;
	ret.c_col.r = a.c_col.r * val;
	ret.c_col.g = a.c_col.g * val;
	ret.c_col.b = a.c_col.b * val;
	return (ret);
}

t_ucol4 col_lerp(t_ucol4 start, t_ucol4 end, unsigned step, unsigned max)
{
	float p;
	t_ucol4 ret;

	p = step / (float)max;
	ret.c_col.a = (unsigned char)(start.c_col.a + ((end.c_col.a - start.c_col.a) * p));
	ret.c_col.r = (unsigned char)(start.c_col.r + ((end.c_col.r - start.c_col.r) * p));
	ret.c_col.g = (unsigned char)(start.c_col.g + ((end.c_col.g - start.c_col.g) * p));
	ret.c_col.b = (unsigned char)(start.c_col.b + ((end.c_col.b - start.c_col.b) * p));
	return (ret);
}
