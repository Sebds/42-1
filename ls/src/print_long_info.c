/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:25:37 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:25:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_acl_type(t_file *file)
{
	if ((file->perm & S_IFMT) == S_IFIFO)
		ft_printf("p");
	else if ((file->perm & S_IFMT) == S_IFCHR)
		ft_printf("c");
	else if ((file->perm & S_IFMT) == S_IFDIR)
		ft_printf("d");
	else if ((file->perm & S_IFMT) == S_IFBLK)
		ft_printf("b");
	else if ((file->perm & S_IFMT) == S_IFREG)
		ft_printf("-");
	else if ((file->perm & S_IFMT) == S_IFLNK)
		ft_printf("l");
	else if ((file->perm & S_IFMT) == S_IFSOCK)
		ft_printf("s");
	else if ((file->perm & S_IFMT) == S_IFWHT)
		ft_printf("w");
}

void	ft_print_permission(t_file *file, t_layout *layout)
{
	ft_print_acl_type(file);
	ft_printf((file->perm & S_IRUSR) ? "r" : "-");
	ft_printf((file->perm & S_IWUSR) ? "w" : "-");
	if (file->perm & S_IXUSR)
		ft_printf((file->perm & S_ISUID) ? "s" : "x");
	else
		ft_printf((file->perm & S_ISUID) ? "S" : "-");
	ft_printf((file->perm & S_IRGRP) ? "r" : "-");
	ft_printf((file->perm & S_IWGRP) ? "w" : "-");
	if (file->perm & S_IXGRP)
		ft_printf((file->perm & S_ISGID) ? "s" : "x");
	else
		ft_printf((file->perm & S_ISGID) ? "S" : "-");
	ft_printf((file->perm & S_IROTH) ? "r" : "-");
	ft_printf((file->perm & S_IWOTH) ? "w" : "-");
	if (file->perm & S_IXOTH)
		ft_printf((file->perm & S_ISVTX) ? "t" : "x");
	else
		ft_printf((file->perm & S_ISVTX) ? "T" : "-");
	ft_print_xattr(file, layout);
}

void	ft_print_xattr(t_file *file, t_layout *layout)
{
	char	*temp;
	char	*file_path;

	if (layout->path == NULL)
		temp = "";
	else
		temp = layout->path;
	file_path = ft_strjoin(temp, file->name);
	if (listxattr(file_path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_printf("@");
	else if (acl_get_link_np(file_path, ACL_TYPE_EXTENDED) != NULL)
		ft_printf("+");
	else
		ft_printf(" ");
	free(file_path);
}

void	ft_print_date(t_file *file)
{
	t_date date;

	date.less_six_monthes = ft_strsub(ctime(&file->date), 4, 12);
	date.more_six_monthes = ft_strsub(ctime(&file->date), 4, 7);
	date.year = ft_strsub(ctime(&file->date), 20, 4);
	date.future = ft_strsub(ctime(&file->date), 24, 5);
	if (time(0) - file->date < (365 / 2 * 86400) && time(0) >= file->date)
		ft_printf(" %s", date.less_six_monthes);
	else
	{
		ft_printf(" %s ", date.more_six_monthes);
		if (file->date < 253402297199)
			ft_printf("%s", date.year);
		else
			ft_printf("%s", date.future);
	}
	ft_delete_date(&date);
}
