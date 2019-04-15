<?php
add_action('login_form', 'redirect_on_login');
function redirect_on_login(){
  global $redirect_to;
  $redirect_to = 'wp-admin/admin.php?page=my-test-page';
}
