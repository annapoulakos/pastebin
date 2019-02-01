<?php

function key_exists_in_both($lhs, $rhs, $key, $key2=null){
	if(is_null($key2)){
		return array_key_exists($key, $lhs) and array_key_exists($key2, $rhs);
	} else {
		return array_key_exists($key, $lhs) and array_key_exists($key, $rhs);
	}
}

// Usage
if(key_exists_in_both($options, $locations[$index], 'title')){
	// Do something
}

if(key_exists_in_both($options, $locations[$index], 'address', 'address1')){
	// Do something
}