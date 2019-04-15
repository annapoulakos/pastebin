$(document).ready(function(){
	base_url = './api.php';
	
	function debug(){
		var next = $('#next_page').val();
		var prev = $('#prev_page').val();
		
		var task = $('#task').val();
		
		alert( 'Next: ' + next + '\nPrev: ' + prev + '\nTask: ' + task);
	};
	
	function propagate(response){
		$('#data').html(response.table);
		$('#prev_page').val(response.prev);
		$('#next_page').val(response.next);
		$('#task').val(response.task);
		
		if(response.prev < 1){
			$('.previous').toggleClass( 'previous prev-inactive' );
			} else {
			$('.prev-inactive').toggleClass('previous prev-inactive');
		}
		if(response.next < 1){
			$('.next').toggleClass('next-inactive next');
			} else {
			$('.next-inactive').toggleClass('next next-inactive');
		}
		$('.previous').unbind('click');
		$('.next').unbind('click');
		
		$('.previous').click( get_page );
		
	}
	function error(response)
	{
		alert(response.status);
	}
	
	function get_page(the_element)
	{
		var the_page = $(the_element).val();
		if(the_page < 1)return;
		var the_task = $('#task').val();
		
		$.ajax({
			url: base_url,
			data: { task: the_task, page: the_page },
			success: function(response) {
				if(response.status == 100) {
					propagate(response);
				}
				else { error(response); }
			}
		});
	}
	
	$('.button-1').click(function(){
		
	});
	
	$('.button-2').click(function(){
		
	});
	
	$('.button-3').click(function(){
		
	});
	
	$('.button-4').click(function(){
		window.location.href = '#';
	});
	
	$('.previous').click(function(){
		get_page('#prev_page');
	});
	
	$('.next').click(function(){
		get_page('#next_page');
	});
	
});