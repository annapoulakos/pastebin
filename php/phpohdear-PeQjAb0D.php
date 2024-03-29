<?php
	$a = function($h,$v,&$i){ $i[] = array('label'=>$h,'value'=>$v); };
	$b = function($x){ return !is_numeric($x); };

	$imperial = array();
	$b($this->standard_tank_volume) or $a('Standard Tank Volume', number_format($this->standard_tank_volume), $imperial);
	$b($this->standard_tank_weight)  or $a('Standard Tank Weight lbs', number_format($this->standard_tank_weight), $imperial);
	$b($this->aux_ferry_tank_volume) or $a('Aux or Ferry Tank Volume gal', number_format($this->aux_ferry_tank_volume), $imperial);
	$b($this->aux_ferry_tank_weight) or $a('Aux or Ferry Tank Weight lbs', number_format($this->aux_ferry_tank_weight), $imperial);
	if ($this->added1_description != 'N/A' && $this->added1_description != 'NA'  && $this->added1_description !='') $imperial[] = array('label'=>'Description','value'=>$this->added1_description);
	if ($this->added2_description != 'N/A' && $this->added2_description != 'NA'  && $this->added1_description !='') $imperial[] = array('label'=>'Description','value'=>$this->added2_description);

	$metric = array();
	$b($this->standard_tank_volume) or $a('Standard Tank Volume liters', number_format($this->standard_tank_volume_metric), $metric);
	$b($this->standard_tank_weight)  or $a('Standard Tank Weight kg', number_format($this->standard_tank_weight_metric), $metric);
	$b($this->aux_ferry_tank_volume) or $a('Aux or Ferry Tank Volume liters', number_format($this->aux_ferry_tank_volume_metric), $metric);
	$b($this->aux_ferry_tank_weight) or $a('Aux or Ferry Tank Weight kg', number_format($this->aux_ferry_tank_weight_metric), $metric);
	if ($this->added1_description != 'N/A' && $this->added1_description != 'NA' && $this->added1_description !='') $metric[] = array('label'=>'Description','value'=>$this->added1_description);
	if ($this->added2_description != 'N/A' && $this->added2_description != 'NA' && $this->added1_description !='') $metric[] = array('label'=>'Description','value'=>$this->added2_description);

	return array( 'imperial' => $imperial, 'metric'=>$metric );
