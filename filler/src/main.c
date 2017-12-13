/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:40:20 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_close_win(int keycode, t_env *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		mlx_destroy_image(info->mlx, info->frame_addr);
		mlx_destroy_image(info->mlx, info->black_addr);
		info->win = NULL;
		info->mlx = NULL;
		ft_printf("42 1337\n");
		exit(keycode);
	}
	return (0);
}

void	ft_quit(char *reason, t_env *info)
{
	int		x;
	int		y;
	char	*msg;

	if (FILLER_DEBUG)
	{
		ft_putstr_fd("\x1B[31m[EXIT] \x1B[0m", 2);
		ft_putendl_fd(reason, 2);
	}
	if (info && ENABLE_VISUALIZER && info->mlx && info->init_mlx)
	{
		x = info->width / 2.5;
		y = info->height + 25;
		msg = ft_strdup("Press 'Escape' to quit...");
		mlx_string_put(info->mlx, info->win, x, y, 0xFFFFFF, msg);
		ft_display_score(info);
		mlx_loop(info->mlx);
	}
	ft_printf("42 42\n");
	exit(0);
}

int		ft_visualizer(t_env *info)
{
	int	h;

	if (info->init_mlx == 0)
		ft_init_visualizer(info);
	if (ENABLE_VISUALIZER && info->mlx && info->win)
	{
		ft_reset_visualizer(info);
		ft_update_visualizer(info, 0, 0);
		h = info->height;
		mlx_put_image_to_window(info->mlx, info->win, info->black_addr, 0, h);
		ft_display_score(info);
		mlx_put_image_to_window(info->mlx, info->win, info->frame_addr, 0, 0);
		mlx_do_sync(info->mlx);
	}
	return (0);
}

int		ft_game_loop(int keycode, t_env *info)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$") && !info->got_char)
			ft_get_id(info, &line);
		else if (ft_strstr(line, "Plateau") && info->got_char)
			ft_get_board(info, &line);
		else if (ft_strstr(line, "Piece") && info->got_board && info->got_char)
		{
			ft_get_piece(info, &line);
			ft_evil_strategy_distance(info);
			ft_visualizer(info);
			ft_free_memory(info);
			info->count++;
		}
		else
			ft_quit("You won't segfault it.", info);
	}
	return (keycode);
}

int		main(void)
{
	t_env	*info;

	info = (t_env *)malloc(sizeof(t_env));
	if (info == NULL)
		ft_quit("Failed to malloc info struct", NULL);
	info->mlx = NULL;
	info->win = NULL;
	info->init_mlx = 0;
	info->count = 0;
	info->got_char = 0;
	info->got_board = 0;
	ft_game_loop(0, info);
	free(info);
	return (1);
}
