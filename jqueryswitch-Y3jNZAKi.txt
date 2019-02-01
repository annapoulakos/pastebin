	jQuery(document).ready(function($){
		$.each( '.to-textbox', function(key, val){
			var tid = $(this).attr('id');
			var $parent = $(this).parent();
			$(this).remove();
			$parent.append('<textarea name="' + tid + '" id="' + tid + '"><textarea>');
			});
		
		});