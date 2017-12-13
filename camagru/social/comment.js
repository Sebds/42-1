function enableComment()
{
	var c = document.getElementById('comment').value;

	if (!c || c == '')
	{
		document.getElementById('button_add_comment').setAttribute("disabled", "");
		document.getElementById('button_add_comment').setAttribute("style", "color:greytext; margin-top:10px;");
	}
	else
	{
		document.getElementById('button_add_comment').removeAttribute("disabled");
		document.getElementById('button_add_comment').setAttribute("style", "background:white; margin-top:10px;");
	}
}