var pJS = function(tag_id)
{
	var canvas_el = document.querySelector('#' + tag_id + ' > .particles-js-canvas-el');

	this.pJS = {
		canvas: {
			el: canvas_el,
			w: canvas_el.offsetWidth,
			h: canvas_el.offsetHeigth
		},
		particles: {
			number: {
				value: 50,
				density: {
					enable: true,
					value_area: 800
				}
			},
			color: {
				value: '#fff'
			},
			opacity: {
				value: 1
			},
			size: {
				value: 5
			},
			line_linked: {
				opacity: 0.4,
				distance: 250,
				color: "#ffffff",
				width: 0
			},
			move: {
				speed: 4
			},
			array: []
		},
		tmp: {},
		fn: {
 			interact: {},
 			modes: {},
 			vendors:{}
 		}
	};

	var pJS = this.pJS;

//////////////////////////// CANVAS //////////////////////////

	pJS.fn.canvasInit = function()	{
		pJS.canvas.ctx = pJS.canvas.el.getContext('2d');
		pJS.canvas.w = pJS.canvas.el.offsetWidth;
		pJS.canvas.h = pJS.canvas.el.offsetHeight;
	};

	pJS.fn.canvasSize = function()	{
		pJS.canvas.el.width = pJS.canvas.w;
		pJS.canvas.el.height = pJS.canvas.h;

		window.addEventListener('resize', function()	{
			pJS.canvas.el.width = pJS.canvas.el.offsetWidth;
			pJS.canvas.el.height = pJS.canvas.el.offsetHeight;
			pJS.canvas.w = pJS.canvas.el.width;
			pJS.canvas.h = pJS.canvas.el.height;
			pJS.fn.vendors.densityAutoParticles();
		});
	};

	pJS.fn.canvasPaint = function()	{
		pJS.canvas.ctx.fillRect(0, 0, pJS.canvas.w, pJS.canvas.h);
	};

	pJS.fn.canvasClear = function(){
 		pJS.canvas.ctx.clearRect(0, 0, pJS.canvas.w, pJS.canvas.h);
 	};

////////////////////////// PARTICLES //////////////////////////////

	pJS.fn.particlesCreate = function()	{
		for (var i = 0; i < pJS.particles.number.value; i++) {
			pJS.particles.array.push(new pJS.fn.particles(pJS.particles.color, pJS.particles.opacity.value));
		}
	};

	pJS.fn.particles = function(color, opacity) {
		this.radius = Math.random() * pJS.particles.size.value;
		this.x = Math.random() * pJS.canvas.w;
		this.y = Math.random() * pJS.canvas.h;
		this.color = color;
		this.color.rgb = hexToRgb(color.value);
		this.opacity = Math.random() * opacity;
		this.vx = Math.random() - 0.5;
		this.vy = Math.random() - 0.5;
	};

/////////////
	pJS.fn.vendors.densityAutoParticles = function()	{
		var area = pJS.canvas.el.width * pJS.canvas.el.height / 1000;
		var nb_particles = area * pJS.particles.number.value / pJS.particles.number.density.value_area;
		var missing_particles = pJS.particles.array.length - nb_particles;

		if (missing_particles < 0)
			pJS.fn.modes.pushParticles(Math.abs(missing_particles));
		else
			pJS.fn.modes.removeParticles(missing_particles);
	};
///////////

	pJS.fn.modes.pushParticles = function(nb)	{
		for (var i = 0; i < nb; i++) {
			pJS.particles.array.push(new pJS.fn.particles(pJS.particles.color, pJS.particles.opacity.value));
		}
	};

	pJS.fn.modes.removeParticles = function(nb)	{
		pJS.particles.array.splice(0, nb);
	};

	pJS.fn.particles.prototype.draw = function()	{
		var p = this;
		var opacity = p.opacity;
		var radius = p.radius;

		var color_value = 'rgba(' + p.color.rgb.r + ',' + p.color.rgb.g + ',' + p.color.rgb.b + ',' + opacity + ')';

		pJS.canvas.ctx.fillStyle = color_value;
		pJS.canvas.ctx.beginPath();
		pJS.canvas.ctx.arc(p.x, p.y, radius, 0, Math.PI * 2, false);
		pJS.canvas.ctx.closePath();
		pJS.canvas.ctx.fill();
	};


	pJS.fn.particlesDraw = function()	{
		pJS.canvas.ctx.clearRect(0, 0, pJS.canvas.w, pJS.canvas.h);
		pJS.fn.particlesUpdate();

		for (var i = 0; i < pJS.particles.array.length; i++) {
			var p = pJS.particles.array[i].draw();
		}
	};

	pJS.fn.interact.linkParticles = function(p1, p2)	{
		var dx = p1.x - p2.x;
		var dy = p1.y - p2.y;
		var dist = Math.sqrt(dx * dx + dy * dy);

		if (dist < pJS.particles.line_linked.distance)
		{
			var color_line = hexToRgb(pJS.particles.line_linked.color);
			var opacity_line = pJS.particles.line_linked.opacity - (dist / (1/pJS.particles.line_linked.opacity)) / pJS.particles.line_linked.distance;
			pJS.canvas.ctx.strokeStyle = 'rgba(' + color_line.r + ',' + color_line.g + ',' + color_line.b + ',' + opacity_line + ')';
			pJS.canvas.ctx.lineWidth = pJS.particles.line_linked.width;
			pJS.canvas.ctx.beginPath();
			pJS.canvas.ctx.moveTo(p1.x, p1.y);
			pJS.canvas.ctx.lineTo(p2.x, p2.y);
			pJS.canvas.ctx.stroke();
			pJS.canvas.ctx.closePath();
		}
	};

	pJS.fn.particlesUpdate = function()	{
		for (var i = 0; i < pJS.particles.array.length; i++) {
			var p = pJS.particles.array[i];

			var ms = pJS.particles.move.speed / 2;
			p.x += p.vx * ms;
			p.y += p.vy * ms;

			if(	p.x + p.radius >= pJS.canvas.w ||
				p.x - p.radius <= 0 ||
				p.y + p.radius >= pJS.canvas.h ||
				p.y - p.radius <= 0)
			{
				p.x = Math.random() * (pJS.canvas.w - p.radius);
				p.y = Math.random() * (pJS.canvas.h - p.radius);
			}

			for(var j = i + 1; j < pJS.particles.array.length; j++)	{
				var p2 = pJS.particles.array[j];
				pJS.fn.interact.linkParticles(p, p2);
			}
		}
	};

////////////////////////// INIT //////////////////////////////////////

	pJS.fn.vendors.init = function()	{
		pJS.fn.canvasInit();
		pJS.fn.canvasSize();
		pJS.fn.canvasPaint();
		pJS.fn.particlesCreate();
		pJS.fn.vendors.densityAutoParticles();
		pJS.particles.line_linked.color_rgb_line = hexToRgb(pJS.particles.line_linked.color);
	};

	pJS.fn.vendors.draw = function()	{
		pJS.fn.particlesDraw();
		requestAnimFrame(pJS.fn.vendors.draw);
	};

	pJS.fn.vendors.start = function()	{
		pJS.fn.vendors.init();
		pJS.fn.vendors.draw();
	};

	pJS.fn.vendors.start();
};

//////////////// MICS ////////////////

function hexToRgb(hex){
	// By Tim Down - http://stackoverflow.com/a/5624139/3493650
	// Expand shorthand form (e.g. "03F") to full form (e.g. "0033FF")
	var shorthandRegex = /^#?([a-f\d])([a-f\d])([a-f\d])$/i;
	hex = hex.replace(shorthandRegex, function(m, r, g, b) {
		return r + r + g + g + b + b;
	});
	var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
	return result ? {
		r: parseInt(result[1], 16),
		g: parseInt(result[2], 16),
		b: parseInt(result[3], 16)
	} : null;
};



///////////////// WINDOW ///////////////////////

window.requestAnimFrame = (function()	{
	return window.requestAnimationFrame ||
	window.webkitRequestAnimationFrame ||
	window.mozRequestAnimationFrame    ||
	window.oRequestAnimationFrame      ||
	window.msRequestAnimationFrame     ||
	function(callback){
		window.setTimeout(callback, 1000 / 60);
	};
})();

window.cancelRequestAnimFrame = ( function() {
	return window.cancelAnimationFrame        ||
	window.webkitCancelRequestAnimationFrame ||
	window.mozCancelRequestAnimationFrame    ||
	window.oCancelRequestAnimationFrame      ||
	window.msCancelRequestAnimationFrame     ||
	clearTimeout
})();


window.pJSDom = [];

window.particlesJS = function(tag_id)	{
	var pJS_tag = document.getElementById(tag_id);
	var pJS_canvas_class = 'particles-js-canvas-el';

	var canvas_el = document.createElement('canvas');
	canvas_el.className = pJS_canvas_class;

	canvas_el.style.width = "100%";
	canvas_el.style.height = "100%";

	var canvas = document.getElementById(tag_id).appendChild(canvas_el);
	pJSDom.push(new pJS(tag_id));
};

// window.particlesJS.load = function(tag_id, path_config_json, callback){
//   var xhr = new XMLHttpRequest();
//   xhr.open('GET', path_config_json);
//   xhr.onreadystatechange = function (data) {
// 	if(xhr.readyState == 4){
// 	  if(xhr.status == 200){
// 		var params = JSON.parse(data.currentTarget.response);
// 		window.particlesJS(tag_id, params);
// 		if(callback) callback();
// 	  }else{
// 		console.log('Error pJS - XMLHttpRequest status: ' + xhr.status);
// 		console.log('Error pJS - File config not found');
// 	  }
// 	}
//   };
//   xhr.send();
// };