<?php
#	glob.php
#	This file outputs a list of categories with subcategories with articles.
#	Format for category names is _ for spaces.
#	Format for library names is - for spaces.
$dirs = glob( '*', GLOB_ONLYDIR );

$output = array();
foreach( $dirs as $dir ){
	$subdirs = glob( "$dir/*", GLOB_ONLYDIR );
	$subs = array();
	foreach( $subdirs as $subdir ){
		$tokens = explode( '/', $subdir );
	
		$subcat = str_replace( '_', ' ', $tokens[1] );
		$files = glob( $subdir.'/*.html' );
		
		$fs = array();
		foreach( $files as $file ){
			$tokens = explode( '/', $file );
			$ts = explode( '.', $tokens[2] );
			$fs[] = array( 
				'title'=>ucwords(str_replace( '-', ' ', $ts[0] )),
				'url'=> $file
				);
		}
		$subs[] = array(
			'name'=> ucwords($subcat),
			'articles'=> $fs
			);
	}
	
	$output[] = array( 
		'name'=> ucwords(str_replace( '_', ' ', $dir )),
		'subcategories'=> $subs
		);
}

echo json_encode( $output );