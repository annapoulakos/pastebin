Environment: 
	PHP 5.3.x
	MySQL 5.1.x
	
Problem:
	I have two queries. One of them pulls data correctly, the other does not. It seems odd to me, as both queries look to do the same thing.
	
Incorrect Query:
	select `high_time_high`, `high_time_low`, `mid_time_high`, `mid_time_low`, `low_time_high`, `low_time_low`, `model_year`, max(`effective_date`) as `ed` from `helicopter_resale_price` where `helicopter_id`='122' and `model_year`='2005'
	
Correct Query:
	select `high_time_high`, `high_time_low`, `mid_time_high`, `mid_time_low`, `low_time_high`, `low_time_low` from `helicopter_resale_price` where `helicopter_id`='122' and `model_year`='2005' and `effective_date`='2010-12-09 12:00:00'
	
Datatable:
hth			htl			mth			mtl			lth			ltl			year	effective_date
8660000 	8450000 	9380000 	8960000 	10400000 	9890000 	2005 	2008-03-20 12:00:00
8360000 	8150000 	8880000 	8460000 	9700000 	9190000 	2005 	2008-12-16 12:00:00
8060000 	7850000 	8380000 	7960000 	9000000 	8490000 	2005 	2009-03-16 12:00:00
7690000 	7440000 	9030000 	8300000 	9400000 	9160000 	2005 	2009-05-05 12:00:00
6690000 	6440000 	8030000 	7300000 	8400000 	8160000 	2005 	2010-03-24 12:00:00
5690000 	5440000 	7030000 	6300000 	7400000 	7160000 	2005 	2010-06-18 12:00:00
4690000 	4440000 	5530000 	4800000 	5900000 	5660000 	2005 	2010-12-09 12:00:00