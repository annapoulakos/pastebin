// For Example, we can build a simple utilities library
var utilities = (function(me){
	me.add_numbers = function(x, y){
		return x + y;
	}

	return me;
})(utilities || {});

// In a separate file, we can add this:
var utilities = (function(me){
	me.sub_numbers = function(x, y){
		return x - y;
	}

	return me;
})(utilities || {});


// Now, the utilities module will have to functions:
console.log(utilities.add_numbers(1, 2));
console.log(utilities.sub_numbers(1, 2));