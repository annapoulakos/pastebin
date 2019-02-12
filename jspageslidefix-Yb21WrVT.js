function setup( src ){
$('.second').pageslide({direction:'left', modal:true });
$('#pageslide').attr('data-target', src);
}
function setout(){
$.pageslide.close();
var target = $('#pageslide').attr('data-target');
var offset = target.offset().top;
$('html, body').animate({scrollTop: offset}, 1);
}
/* Default pageslide, moves to the right */
$(".first").pageslide();
/* Slide to the left, and make it model (you'll have to call $.pageslide.close() to close) */
$('.second').click( setup( $(this).attr('data-target') ) );
//$(".second").pageslide({ direction: "left", modal: true });