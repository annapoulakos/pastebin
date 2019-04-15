<?php defined( '_X_EXEC' ) or die( 'Restricted' ); ?>
<?php
[REDACTED]
include SERVER_LIB.'randomus_namus.class.php';
randomus_namus::setDb( 'crm' );

function GET( &$headers, $tokens )
{
	$response = array();
	$dbo = DatabaseManager::Load('access');

	$table = $dbo->escape($tokens[0]);
	$id_field = randomus_namus::fetch( $table.'_key' );
	$id = $dbo->escape($tokens[1]);

	switch( $id )
	{
	case 'all':
		$sql = "SELECT * FROM `$table` ORDER BY `$id_field` ASC";
		$result = $dbo->query( $sql );

		while( $row = $result->fetch_assoc() ) $response[] = $row;
		$headers[] = 'HTTP/1.1 200 OK';
		break;
	case 'list':
		$mfg_id = $dbo->escape( $tokens[2] );
		$sql = sprintf( randomus_namus::fetch( 'sql_'.$table.'_'.$id ), $mfg_id );

		$result = $dbo->query( $sql );
		while( $row = $result->fetch_assoc() ) $response[] = $row;
		$headers[] = 'HTTP/1.1 200 OK';
		break;
	default:
		if( !is_numeric( $id ) ) $headers[] = 'HTTP/1.1 400 Bad Request';
		else
		{
			$id = $dbo->escape( $id );
			$sql = "SELECT * FROM `$table` WHERE `$id_field`='$id'";
			$result = $dbo->query( $sql );

			while( $row = $result->fetch_assoc() ) $response[] = $row;
			$headers[] = 'HTTP/1.1 200 OK';
		}
		break;
	}

	return $response;
}
function POST( &$headers, $tokens )
{
	$headers[] = 'HTTP/1.1 405 Method Not Allowed';
}
function PUT( &$headers, $tokens )
{
	$headers[] = 'HTTP/1.1 405 Method Not Allowed';
}
function DELETE( &$headers, $tokens )
{
	$headers[] = 'HTTP/1.1 405 Method Not Allowed';
}