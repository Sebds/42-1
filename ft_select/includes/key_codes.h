/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 05:12:23 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 06:53:55 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

# define MAX_KEY_STRING_LENGTH	6

# define KEY_CODE_MAX		(int)(-1)

# define KEY_CODE_CTRL_A	0x1
# define KEY_CODE_CTRL_B	0x2
# define KEY_CODE_CTRL_D	0x4
# define KEY_CODE_CTRL_E	0x5
# define KEY_CODE_CTRL_F	0x6
# define KEY_CODE_CTRL_G	0x7
# define KEY_CODE_CTRL_H	0x8
# define KEY_CODE_TAB		0x9
# define KEY_CODE_RET		0xa
# define KEY_CODE_CTRL_K	0xb
# define KEY_CODE_CTRL_L	0xc
# define KEY_CODE_CTRL_N	0xe
# define KEY_CODE_CTRL_P	0x10
# define KEY_CODE_CTRL_R	0x12
# define KEY_CODE_CTRL_T	0x14
# define KEY_CODE_CTRL_U	0x15
# define KEY_CODE_CTRL_V	0x16
# define KEY_CODE_CTRL_W	0x17

# define KEY_CODE_ESCAPE	0x1b
# define KEY_CODE_BKSPACE	0x7f
# define KEY_CODE_DELETE	0x7e335b1b
# define KEY_CODE_HOME		0x485b1b
# define KEY_CODE_END		0x461b5b
# define KEY_CODE_PUP		0x351b5b
# define KEY_CODE_PDOWN		0x7e361b5b
# define KEY_CODE_UP		0x415b1b
# define KEY_CODE_DOWN		0x421b5b
# define KEY_CODE_LEFT		0x441b5b
# define KEY_CODE_RIGHT		0x431b5b
# define KEY_CODE_SPACE		0x20

# define KEY_CODE_LOWER_A	0x61
# define KEY_CODE_LOWER_B	0x62
# define KEY_CODE_LOWER_C	0x63
# define KEY_CODE_LOWER_D	0x64
# define KEY_CODE_LOWER_E	0x65
# define KEY_CODE_LOWER_F	0x66
# define KEY_CODE_LOWER_G	0x67
# define KEY_CODE_LOWER_H	0x68
# define KEY_CODE_LOWER_I	0x69
# define KEY_CODE_LOWER_J	0x6a
# define KEY_CODE_LOWER_K	0x6b
# define KEY_CODE_LOWER_L	0x6c
# define KEY_CODE_LOWER_M	0x6d
# define KEY_CODE_LOWER_N	0x6e
# define KEY_CODE_LOWER_O	0x6f
# define KEY_CODE_LOWER_P	0x70
# define KEY_CODE_LOWER_Q	0x71
# define KEY_CODE_LOWER_R	0x72
# define KEY_CODE_LOWER_S	0x73
# define KEY_CODE_LOWER_T	0x74
# define KEY_CODE_LOWER_U	0x75
# define KEY_CODE_LOWER_V	0x76
# define KEY_CODE_LOWER_W	0x77
# define KEY_CODE_LOWER_X	0x78
# define KEY_CODE_LOWER_Y	0x79
# define KEY_CODE_LOWER_Z	0x7a

# define KEY_CODE_UPPER_A	0x41
# define KEY_CODE_UPPER_B	0x42
# define KEY_CODE_UPPER_C	0x43
# define KEY_CODE_UPPER_D	0x44
# define KEY_CODE_UPPER_E	0x45
# define KEY_CODE_UPPER_F	0x46
# define KEY_CODE_UPPER_G	0x47
# define KEY_CODE_UPPER_H	0x48
# define KEY_CODE_UPPER_I	0x49
# define KEY_CODE_UPPER_J	0x4a
# define KEY_CODE_UPPER_K	0x4b
# define KEY_CODE_UPPER_L	0x4c
# define KEY_CODE_UPPER_M	0x4d
# define KEY_CODE_UPPER_N	0x4e
# define KEY_CODE_UPPER_O	0x4f
# define KEY_CODE_UPPER_P	0x50
# define KEY_CODE_UPPER_Q	0x51
# define KEY_CODE_UPPER_R	0x52
# define KEY_CODE_UPPER_S	0x53
# define KEY_CODE_UPPER_T	0x54
# define KEY_CODE_UPPER_U	0x55
# define KEY_CODE_UPPER_V	0x56
# define KEY_CODE_UPPER_W	0x57
# define KEY_CODE_UPPER_X	0x58
# define KEY_CODE_UPPER_Y	0x59
# define KEY_CODE_UPPER_Z	0x5a

# define KEY_CODE_DIGIT_10	0x30
# define KEY_CODE_DIGIT_1	0x31
# define KEY_CODE_DIGIT_2	0x32
# define KEY_CODE_DIGIT_3	0x33
# define KEY_CODE_DIGIT_4	0x34
# define KEY_CODE_DIGIT_5	0x35
# define KEY_CODE_DIGIT_6	0x36
# define KEY_CODE_DIGIT_7	0x37
# define KEY_CODE_DIGIT_8	0x38
# define KEY_CODE_DIGIT_9	0x39

# define KEY_CODE_OTHER		0x0

typedef int		t_bool;

typedef int		t_key_type;

typedef struct	s_key
{
	t_key_type	type;
	char		value[MAX_KEY_STRING_LENGTH];
}				t_key;

typedef struct	s_key_desc
{
	t_key_type	k;
	char		*s;
}				t_key_desc;

typedef struct	s_key_funcs
{
	t_key_type	k;
	t_bool		(*f)(char *);
}				t_key_funcs;

#endif
