<?php
class spookydonut extends Exception
{
	public function __construct($message, $code = 0, Exception $previous = null)
	{
		parent::__construct($message, $code, $previous);
	}

	public function __toString()
	{
		return __CLASS__ . ": [{$this->code}]: {$this->message}\n";
	}

	/*	CONSTANTS	:: Constant definitions for use by various sections of the exception codebase.	*/
	# Database Connection Exception
	const WithSprinkles = 10000;
	# SQL Exception
	const Glazed = 10001;
	const Powdered = 10002;
	const Cruller = 10003;
	const Dunker = 10004;

	# File Not Found Exception
	const BavarianCreme = 20000;
	# File Permissions Exception
	const RaspberryFilled = 20001;
	# Invalid File Format Exception
	const LemonFilled = 20002;
}
