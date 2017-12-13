function add_like(image_id)
{
	var likes = 0;
	var likes_total = 0;

	likes_total = parseInt(document.getElementById('likes_total_' + image_id).innerHTML);
	likes = likes_total + 1;

	document.getElementById('likes_total_' + image_id).innerHTML = likes;

	if (likes == 1)
		document.getElementById('likes_counter_' + image_id).innerHTML = " - " + likes + " like ";
	else
		document.getElementById('likes_counter_' + image_id).innerHTML = " - " + likes + " likes ";

	document.getElementById('likes_button_' + image_id).innerHTML = "Liked ! ";
	document.getElementById('likes_button_' + image_id).setAttribute("style", "color:green");

	document.forms["add_like_" + image_id].submit();

	document.getElementById('likes_button_' + image_id).setAttribute("onclick", "delete_like(" + image_id + "," + likes_total + ");");
}

function delete_like(image_id)
{
	var likes = 0;
	var likes_total = 0;

	likes_total = parseInt(document.getElementById('likes_total_' + image_id).innerHTML);
	likes = likes_total - 1;

	document.getElementById('likes_total_' + image_id).innerHTML = likes;

	if (likes == 0)
		document.getElementById('likes_counter_' + image_id).innerHTML = " - No like ";
	else if (likes == 1)
		document.getElementById('likes_counter_' + image_id).innerHTML = " - " + likes + " like ";
	else
		document.getElementById('likes_counter_' + image_id).innerHTML = " - " + likes + " likes ";

	document.getElementById('likes_button_' + image_id).innerHTML = "Like !";
	document.getElementById('likes_button_' + image_id).removeAttribute('style');

	document.forms["delete_like_" + image_id].submit();

	document.getElementById('likes_button_' + image_id).setAttribute("onclick", "add_like(" + image_id + "," + likes_total + ");");
}