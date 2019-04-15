<?php
defined( '_X_EXEC' ) or die( 'Restricted' );

class Randomus_Namus
{
	const SELECT = "SELECT `value` FROM `kvs` WHERE `key`='%s'";
	const INSERT = "INSERT INTO `kvs` ( `key`, `value` ) VALUES( '%s', '%s' )";
	const UPDATE = "UPDATE `kvs` SET `value`='%s' WHERE `key`='%s'";
	const COUNT  = "SELECT COUNT(*) AS `c` FROM `kvs` WHERE `key`='%s'";
	const DELETE = "DELETE FROM `kvs` WHERE `key`='%s'";
	
	private $_dbo = null;
	public static function connect()
	{
		if( self::$_dbo == null ) self::$_dbo = new mysqli( host, user, pass, db );
	}
	
	public static function fetch( $k )
	{
		if( self::$_dbo == null ) self::connect();
		
		$k = self::$_dbo->real_escape_string( $k );
		$sql = sprintf( self::SELECT, $k );
		$result = self::$_dbo->query( $sql );
		if( !$result ) return 'MySQL Error';
		
		list( $v ) = $result->fetch_assoc();
		return $v;
	}
	
	public static function fill( $k, $v )
	{
		if( self::$_dbo == null ) self::connect();
		
		$k = self::$_dbo->real_escape_string( $k );
		$v = self::$_dbo->real_escape_string( $v );
		$sql = sprintf( self::COUNT, $k );
		$result = self::$_dbo->query( $sql );
		if( !$result ) return 'MySQL Error';
		list( $c ) = $result->fetch_assoc();
		if( 0 == $c )
		{
			$sql = sprintf( self::INSERT, $k, $v );
		}
		else
		{
			$sql = sprintf( self::UPDATE, $v, $k );
		}
		$result = self::$_dbo->query( $sql );
		if( !$result ) return 'MySQL Error';
		
		return 'KVS Successfully Updated';
	}
	
	public static function flop( $k )
	{
		if( self::$_dbo == null ) self::connect();
		
		$k = self::$_dbo->real_escape_string( $k );
		$sql = sprintf( self::DELETE, $k );
		$result = self::$_dbo->query( $sql );
		if( !$result ) return 'MySQL Error';
	}
}