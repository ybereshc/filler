// Split map
map = map.split('\n');

// Colors
var style = [];
style["."] = "empty";
style["O"] = "player-1";
style["X"] = "player-2";
style["o"] = "touch-1";
style["x"] = "touch-2";

// Get tegs
var header = document.getElementById("header");
var place = document.getElementById("place");
var player = [document.getElementById("player-1"), document.getElementById("player-2")];
var score = [document.getElementById("score-1"), document.getElementById("score-2")];
var place = document.getElementById("place");
var range = document.getElementById("range");
var winner = document.getElementById("winner");

// Header
for (var i = 0; i < 5; i++) {
	header.innerHTML += map[i] + '\n';
}

// Player names
player[0].innerHTML = baseName(map[6]);
player[1].innerHTML = baseName(map[8]);


// Read map
var map_size = getSize(map[9]);
var Plateau = [];
var Piece = [];

for (var i = 0; i < map.length; i++) {
	var tmp = [];
	if (map[i].search(/^Plateau/) != -1) {
		for (var n = 0; n < map_size.y; n++) {
			tmp.push(map[i + n + 2].substr(4));
		}
		Plateau.push(tmp);
	}
}

// Create Place
var size = map_size.y < map_size.x ? map_size.y : map_size.x;
size = 800 / size;

var Place = [];
for (var y = 0; y < map_size.y; y++) {
	var tmp = [];
	var row = document.createElement("div");
	for (var x = 0; x < map_size.x; x++) {
		var div = document.createElement("div");
		div.style.width = div.style.height = `${size}px`;
		row.appendChild(div);
		tmp.push(div);
	}
	place.appendChild(row);
	Place.push(tmp);
}

range.max = Plateau.length;

// Print Map
function printMap() {
	var n = +range.value;
	var O = 0;
	var X = 0;
	var last = (n >= Plateau.length);
	place.className = null;
	if (last) n--;
	for (var y = map_size.y; y--;) {
		for (var x = map_size.x; x--;) {
			var c = Plateau[n][y][x];
			if (c == 'O' || c == 'o') O++;
			if (c == 'X' || c == 'x') X++;
			if (last) c = c.toUpperCase();
			Place[y][x].className = "color-" + style[c];;
		}
	}
	score[0].innerHTML = O;
	score[1].innerHTML = X;
	if (last) {
		O = +score[0].innerHTML;
		X = +score[1].innerHTML;
		if (O > X) {
			winner.innerHTML = player[0].innerHTML;
			winner.className = "color-" + style["o"];
		}
		else if (O < X) {
			winner.innerHTML = player[1].innerHTML;
			winner.className = "color-" + style["x"];
		}
		else
			winner.innerHTML = "dead heat";
		place.className = "winner-show";
		winner.innerHTML += "<br>winner";
	}
}

function getSize(line) {
	line = line.match(/\d+/g);
	return {y: +line[0], x: +line[1]};
}

function baseName(str) {
	var base = new String(str).substring(str.lastIndexOf('/') + 1);
		if(base.lastIndexOf(".") != -1)
			base = base.substring(0, base.lastIndexOf("."));
	return base;
}

var play = 1;

printMap();

var run = setInterval(() => {
	if (play) {
		range.value++;
		if (range.value == range.max) play = 0;
		printMap();
	}
}, 10000 / Plateau.length);

range.oninput = (e) => {
	printMap(e.target.value);
}

range.onclick = (e) => {
	play = 0;
}

document.body.onkeyup = (e) => {
	if (e.code == "Space") {
		play = !play;
	} else if (e.code == "Numpad0") {
		range.value = 0;
	} else if (e.code == "NumpadEnter") {
		range.value = range.max;
	} else if (e.code == "ArrowLeft") {
		range.value--;
	} else if (e.code == "ArrowRight") {
		range.value++;
	}
	printMap();
}






