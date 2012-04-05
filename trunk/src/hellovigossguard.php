<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('hellovigossguard')) {
	dl('hellovigossguard.' . PHP_SHLIB_SUFFIX);
}
$a = encode("<?php echo 'helloworld!'; ?>");
run($a);?>
