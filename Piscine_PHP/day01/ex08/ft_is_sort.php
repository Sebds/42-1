#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
	if (is_array($tab) == false)
		return (false);

	$original = $tab;
	sort($tab);
	$is_sorted = true;
	foreach ($tab as $key => $value)
	{
		if ($value != $original[$key])
		{
			$is_sorted = false;
		}
	}
	return ($is_sorted);
}
?>