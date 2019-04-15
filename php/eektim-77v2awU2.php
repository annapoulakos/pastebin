<?php
// This is Tim's Code:
$query_to_run = "INSERT INTO jos_chronoforms_quote_home_finished_leads (recordtime, ipaddress, primary_name, email, phone, birthdate, address, year_built, apt, construction, city, square_footage, state, central_air, zip, wood_burner, city_township, township, coverage_amount, deductible, umbrella, notes, contact_method, quote_office_location) VALUES ('".date('Y-m-d')." - ".date('H:i:s')."', '".$_SERVER['REMOTE_ADDR']."', '".$_POST['primary_name']."', '".$_POST['email']."', '".$_POST['phone']."', '".$_POST['birthdate']."', '".$_POST['address']."', '".$_POST['year_built']."', '".$_POST['apt']."', '".$_POST['construction']."', '".$_POST['city']."', '".$_POST['square_footage']."', '".$_POST['state']."', '".$_POST['central_air']."', '".$_POST['zip']."', '".$_POST['wood_burner']."', '".$_POST['city_township']."', '".$_POST['township']."', '".$_POST['coverage_amount']."', '".$_POST['deductible']."', '".$_POST['umbrella']."', '".$_POST['notes']."', '".$_POST['contact_method']."', '".$_POST['quote_office_location']."')";

//echo "This is the query to be used: ".$query_to_run;
mysql_query($query_to_run);
//echo "Completed insert, time to close DB";

mysql_close($con);

///////////////////////////////////////////////////////////////////
// This is my code:
class core
{
	protected $_data = array();
	public function __get($key) { return (array_key_exists($key, $this->_data))?$this->_data[$key] : null; }
	public function __set($key, $value) { if($key == '_data') throw new Exception(); $this->_data[$key] = $value; }
	public function __isset($key) { return isset($this->_data[$key]); }
	public function __unset($key) { unset($this->_data[$key]); }
	public function __toString() { return '('.get_class($this).') '.count($this->_data).' items stored.'; }
	public function __destruct()
	{
		foreach($this->_data as $d) unset($d);
		unset($d);
		unset($this->_data);
	}
}

$fields = array(
	'primary_name', 'email', 'phone', 'birthdate',
	'address', 'year_built', 'apt', 'construction', 'city', 'square_footage',
	'state', 'central_air', 'zip', 'wood_burner', 'city_township', 'township',
	'coverage_amount', 'deductible', 'umbrella', 'notes', 'contact_method', 'quote_office_location'
	);

$formdata = new core();
foreach($fields as $field) $formdata->$field = $_POST[$field];

$db = JFactory::getDBO();

$query = "INSERT INTO #__table (";
$all_fields = array();
$all_fields[] = "`recordtime`";
$all_fields[] = "`ipaddress`";
foreach($fields as $field) $all_fields[] = "`$field`";
$query .= implode(', ', $all_fields);

$query .= ") VALUES (";

$all_values = array();
$all_values[] = $db->quote(date('Y-m-d - H:i:s'));
$all_values[] = $db->quote($_SERVER['REMOTE_ADDR']);
foreach($fields as $field) $all_values[] = $db->quote($formdata->$field);
$query .= implode(', ', $all_values);

$query .= ")";

$db->query($query);
