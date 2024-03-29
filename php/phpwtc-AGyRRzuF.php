<?php
	protected function parseData($data, $table, $measure, $isTwoCol, $type)
	{
		// Type 0 is regular data with metric/imperial
		// Type 1 is regular data without metric/imperial
		// Type 2 is irregular key:value data
		// isTwoCol 0 is 1 column data
		// isTwoCol 1 is 2 column data, column headers set elsewhere.

		if ($type == 0)
		{
			$tbl = $data["spec"]->$table->$measure;
		}
		else if ($type == 1)
		{
			$tbl = $data["spec"]->$table->data;
		}
		else
		{
			$tbl = $data["spec"]->$table;
		}

		if ($type==2)
		{
			foreach($tbl as $key => $val)
			{
				if( $val != 'NA' )
				{
					$tableData .= '<tr><td class="head_cell">'. $key . '</td><td class="data_cell">'. $val .'</td></tr>';
				}
			}
		}
		else
			foreach($tbl as $t){
				if( $t->value == 'NA' ) continue;

				if (!$isTwoCol)
				{
					$tableData .= '<tr><td class="head_cell">'. $t->label . '</td><td class="data_cell">'. $t->value .'</td></tr>';
				}
				else
				{
					$tableData .= '<tr><td class="head_cell_b">'. $t->label . '</td><td class="data_cell_a">'. $t->valuea .'</td><td class="data_cell_b">'. $t->valueb .'</td></tr>';
				}
			}

		return $tableData;
	}
