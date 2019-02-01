<?php
	/*
		Template Name: Page with Tabs
	*/
?>

<?php get_header(); ?>
<h1><?php the_title(); ?></h1>


<div id="content">
	<?php if ( have_posts() ) while ( have_posts() ) : the_post(); ?>
	<div id="post-<?php the_ID(); ?>" <?php post_class('page'); ?>>
		
		
		<div id="firstleveltext" class="left">
			<?php the_content(); ?>
			
			<div class"clear"></div>
			<button value="" class="buttoncode" >Contact Us</button>
			<?php edit_post_link('Edit the above content', '<p class="editlink">', ' - To edit the tab content below go to the corresponding side menu in the admin section</p>'); ?>
		</div>
		
		<div id="firstlevelslide" class="left">
			<div id="lifeicons" class="boxshadow ">
				<div id="firstlevelpromo">
					<p><?php the_field('image_text'); ?></p>
					<?php the_post_thumbnail('promotion-image'); ?>  
				</div>
				<div class"clear" style="clear:both;"></div>
			</div>
			
		</div>
		
		<div style="clear:both;"></div>
		
		<?php
			$index = 0;
			
			$myQuery = "query";
			
			// Sub category Loop Start
			while( have_posts()): the_post();
		?>
		
		<div class="SecondLevTxt <?= ($index%2)? '': 'odd'?>">
			<h3>Mortgage Loans</h3>
			<ul>
				<li><a href="#" rel="toggle[Subcat1]">Subcat1</a></li>
				<li><a href="#" rel="toggle[Subcat2]">Subcat2</a></li>
				<li><a href="#" rel="toggle[Subcat3]">Subcat3</a></li>
				<li class="last"><a href="#" rel="toggle[Subcat4]">Subcat4</a></li>
			</ul>
			<div id="Subcat1" class="SubCat">
				<h4>Subcat Header</h4>
				<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent lectus turpis, dapibus ac ultrices non, suscipit id metus. Sed tempor imperdiet quam sed gravida. Vestibulum vel blandit nibh. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Vivamus aliquet dolor magna, ut scelerisque elit. Integer nec ante id mauris gravida suscipit. Phasellus libero enim, euismod eu malesuada in, convallis vitae elit. </p>
				<p>Proin sit amet est vel ante gravida porta volutpat ut arcu. Aenean sit amet purus mi. Nullam auctor nulla condimentum lectus mollis sit amet pulvinar est fermentum. Proin consectetur dolor non risus consequat et placerat mi pretium.</p>
			</div>
			<div id="Subcat2" class="SubCat">
				<h4>Subcat Header</h4>
				<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent lectus turpis, dapibus ac ultrices non, suscipit id metus. Sed tempor imperdiet quam sed gravida. Vestibulum vel blandit nibh. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Vivamus aliquet dolor magna, ut scelerisque elit. Integer nec ante id mauris gravida suscipit. Phasellus libero enim, euismod eu malesuada in, convallis vitae elit. </p>
				<p>Proin sit amet est vel ante gravida porta volutpat ut arcu. Aenean sit amet purus mi. Nullam auctor nulla condimentum lectus mollis sit amet pulvinar est fermentum. Proin consectetur dolor non risus consequat et placerat mi pretium.</p>
			</div>
			<div id="Subcat3" class="SubCat">
				<h4>Subcat Header</h4>
				<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent lectus turpis, dapibus ac ultrices non, suscipit id metus. Sed tempor imperdiet quam sed gravida. Vestibulum vel blandit nibh. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Vivamus aliquet dolor magna, ut scelerisque elit. Integer nec ante id mauris gravida suscipit. Phasellus libero enim, euismod eu malesuada in, convallis vitae elit. </p>
				<p>Proin sit amet est vel ante gravida porta volutpat ut arcu. Aenean sit amet purus mi. Nullam auctor nulla condimentum lectus mollis sit amet pulvinar est fermentum. Proin consectetur dolor non risus consequat et placerat mi pretium.</p>
			</div>
			<div id="Subcat4" class="SubCat"><?php echo do_shortcode('[contact-form-7 id="2406" title="Contact form 1"]'); ?></div>
		</div>
		
		<?php $index++; ?>
		<?php endwhile; ?>
		<?php /* Sub category Loop End */ ?> 
	</div>
</div>