/*
Response from $.ajax():

["Adria Hillhouse","Anastacia Nourse","Antony Leavell","Augustus Meldrum","Carlyn Lashua","Carmen Boucher","Cedric Preston","Dusty Thiede","Elenora Grosvenor","Ethel Gallagher","Eugena Trombetta","Francisca Balcom","Franklyn Diver","Gay Levis","Hilton Barhorst","Hipolito Lockman","Imelda Aubrey","Inge Corbo","Jackelyn Tatem","Jaymie Johson","Juana Toenjes","Jule Papa","Katrina Julien","Keli Nightingale","Keneth Obrian","Kimberlee Weisgerber","Krista Pavon","Lavera Tassin","Leatha Shimizu","Lorretta Brumett","Makeda Lattea","Malisa Wallace","Malka Penton","Margaret Paxson","Maria Poydras","Michelina Daring","Miguelina Tokar","Nilda Nestor","Porsha Malloy","Sadie Hansel","Selina Luciano","Selma Brandstetter","Stacey Eubank","Steffanie Smits","Tawny Dentler","Teodoro Procopio","Tomika Sprenger","Tosha Hiser","Tyron Obrien","Veronique Hockaday"]
*/

/* This is the javascript: */
$.ajax({
	url: base_url,
	data: {task: 'list'},
	success: function(response){
		alert( response.length );
	}
});

/* Alert: 853 */