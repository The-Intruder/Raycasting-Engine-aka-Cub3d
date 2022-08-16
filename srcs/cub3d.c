/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/13 10:04:59 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* -- Notes: ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* -- Notes: ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* -- Notes: ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* -- Notes: ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

// void	check_leaks(void)
// {
// 	system("leaks cub3d");
// }

/* -- Notes: ---------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */


/* -- Notes: this gonna render/trigger map player etc.. in the window */
/* -------------------------------------------------------------------------- */
void	render(t_cub *cub)
{
	cub->win.mlx = mlx_init();
    cub->win.win = mlx_new_window(cub->win.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");

	towD_rendering(cub);
	mlx_loop(cub->win.mlx);
}



int	main(int ac, char **av)
{
	t_cub	cub;
	
	if (ac != 2)
		return (EXIT_FAILURE);
	process_file_data(av[1], &cub.gen_data);
	render(&cub);
	ft_free_2d_char_arr(cub.gen_data.map_arr);
	return (EXIT_SUCCESS);
}
