<?php
/*
fast job insertion script
*/
require_once('bootstrap.php');

define('MX_RM', 6);
define('OV_RM', 7);
define('SS_RM', 8);

function run_sql($area, $section, $jobs)
{
	foreach($jobs as $jb)
	{
		$job = ORM::for_table('b_jobs')->create();
		$job->job_area = $area;
		$job->job_dept_id = 2;
		$job->job_freq_id = 1;
		$job->job_section = $section;
		$job->job_job = $jb;
		
		echo 'Added new job: Area('.$area.') - Sanitation - Weekly - Section('.$section.') - Job('. $jb. ')<br />';
		$job->save();
	}
}
function run_single_sql($area, $section, $jb, $freq)
{
	$job = ORM::for_table('b_jobs')->create();
	$job->job_dept_id = 2;
	$job->job_area = $area;
	$job->job_freq_id = $freq;
	$job->job_section = $section;
	$job->job_job = $jb;
}

/*
Mixing Room
*/

$lines = array('Die Head Cutter', 'Extruder', 'Proofer Belt', 'Dough Bot Conveyor', 'Mixer Platform', 'Mixer', 'Two Conveyors Total', 'Proofer Section', 'Floor', 'Augur');
run_sql(MX_RM, 'Line 1', $lines);
run_sql(MX_RM, 'Line 2', $lines);
run_sql(MX_RM, 'Line 3', $lines);
run_sql(MX_RM, 'Line 5', $lines);

$lines = array('Mixer', 'Dough Mixer Pump', 'Pump', 'Metal Detector Conveyor', 'Incline Conveyor', 'Mash Feeder', 'Sheeter Stone Roller', '14 Mesh Belt', 'Scraper Scrap Conveyor', 'Transfer Conveyor', 'Isaac Infrared Oven', 'Incline Transfer Conveyor', 'Shaker', 'Conveyor Belt', 'Floor', 'Augur');
run_sql(MX_RM, 'Line 4', $lines);

run_single_sql(MX_RM, 'Line 4', 'Vacumax Pipe', 3);

$lines = array('Mixer Tumbler', 'Mixer Platform', 'Dry Blend Feeder', 'Disintigrator', 'Five Conveyors Total', 'Smooth Sheeter Rolls', 'Rippled Sheeter Rolls', 'Proofer Belt', 'Dump Station(potato flakes)', 'Floor', 'Augur');
run_sql(MX_RM, 'Line 6', $lines);

$lines = array('Mixer', 'Mixer Tumber', 'Disintigrator', 'Smooth Sheeter Rolls', 'Rippled Sheeter Rolls', 'Platform - section', 'Eight Conveyors Total', 'Floor', 'Augur');

$lines = array('All Equipment', 'Clean Mixer Area');
run_sql(MX_RM, 'A20 Mixer', $lines);
run_sql(MX_RM, 'Mixer #3200', $lines);
run_sql(MX_RM, 'Mixer #7200', $lines);
run_sql(MX_RM, 'Mixer #9200', $lines);
run_sql(MX_RM, 'Mixer #10040', $lines);

$lines = array('Hopper for 2800 HP', 'Hopper for 6800 HP', 'Brushes', 'Sickles', 'Trashcans', 'Mixing Room Parts', 'White Tubs', 'Yellow Tubs', 'Cooler in AZO', 'Dump Station');
run_sql(MX_RM, '', $lines);

/*
Oven Room
*/

run_single_sql(OV_RM, 'Line 1', 'VPLS', 1);
run_single_sql(OV_RM, 'Line 3', 'VPLS', 1);

$lines = array('Cooker', 'Salter', 'Kiln', 'Two Incline Belts', 'Proofer', 'Proofer Boxes');
run_sql(OV_RM, 'Line 1', $lines);
run_sql(OV_RM, 'Line 2', $lines);
run_sql(OV_RM, 'Line 3', $lines);
run_sql(OV_RM, 'Line 5', $lines);

$lines = array('Oven', 'Conveyor', 'Conveyor Rollers');
for($i=1; $i<=7; ++$i)
{
	run_sql(OV_RM, 'Line '.$i, $lines);
}

/*
Seasoning Room
*/
$lines = array('Tumbler', 'Conveyor', 'Hopper', 'Scarf Plate', 'Oiler', 'Oiler Tank', 'Oiler Tank Slow', 'Walls', 'Floor', 'Augur');
for($i=1;$i<=7;++$i)
{
	if(3==$i) continue;
	run_sql(SS_RM, 'Season '.$i, $lines);
}

run_single_sql(SS_RM, 'Dust Collector 1', 'Dump', 1);
run_single_sql(SS_RM, 'Dust Collector 1', 'Clean', 3);
run_single_sql(SS_RM, 'Dust Collector 2', 'Dump', 1);
run_single_sql(SS_RM, 'Dust Collector 2', 'Clean', 3);
