function enableUpload()
{
	var c = document.getElementById("my_input_file");

	if (c.value.length > 0)
		document.getElementById('button_shoot').removeAttribute('disabled');
	else
		document.getElementById('button_shoot').setAttribute('disabled', "");
}

function selectFilter()	{
	var radios = document.getElementsByName('filter');

	for (var i = 0, length = radios.length; i < length; i++) {
		if (radios[i].checked) {
			SELECTED_FILTER = radios[i].value;
			break;
		}
	};
	if (document.getElementById('coverfilter'))
		document.getElementById('coverfilter').src = SELECTED_FILTER;
}

var video = document.querySelector("#my_camera");

function loadWebcam()
{
	navigator.getUserMedia = 	navigator.getUserMedia ||
								navigator.webkitGetUserMedia ||
								navigator.mozGetUserMedia ||
								navigator.msGetUserMedia ||
								navigator.oGetUserMedia;

	if (navigator.getUserMedia)
		navigator.getUserMedia({video: true}, handleVideo, videoError);
	else
		alert("You browser is not compatible... Go to account and click on 'Enable file input' for a better experience.");
}

function handleVideo(stream)
{
	video.src = window.URL.createObjectURL(stream);
}

function videoError(e)
{
	console.log(e);
	alert("Could not load video... Go to account and click on 'Enable file input' for a better experience.");
}

var SELECTED_FILTER = '';
selectFilter();

function upload_snapshot()
{
	var canvas = document.getElementById('my_canvas');
	canvas.width = 320;
	canvas.height = 240;
	canvas.getContext('2d').drawImage(video, 0, 0, 320, 240);
	document.getElementById('image_base').value = canvas.toDataURL('image/jpg');
	document.getElementById('form_webcam').submit();
}

if (document.getElementById("button_shoot") != null)
	document.getElementById("button_shoot").removeAttribute("disabled");