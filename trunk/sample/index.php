<?php
/**
 *
 * hellovigossguard php源码加密工具
 * 
 * 加密处理文件
 * eg :(in cli mode) php index.php source_dir [to_dir|default: encode]
 * 将source_dir中的所有php文件加密输出到to_dir中
 * 
 * 本文件仅做加密批处理使用，可按照个人需要修改
 * author : hellovigoss<hellovigoss@gmail.com>
 * thanks : moxie<system123@gmail.com>
 * blog : http:www.php-ex.com
 *
 **/
if(!extension_loaded('hellovigossguard')) {
	die("请先安装加密加密工具");
}
if(count($argv) == 1){
	die("请输入需要加密的文件夹路径！");
}

$source_dir = $argv[1];
$encode_dir = isset($argv[2]) ? $argv[2] : 'encode';

@mkdir($encode_dir);
@mkdir($encode_dir . DIRECTORY_SEPARATOR . $source_dir);

$dir = read_dir_all($source_dir);

function read_dir_all($dir) {
	global $encode_dir;
	$ret = array('dirs'=>array(), 'files'=>array());
	if ($handle = opendir($dir)) {
		while (false !== ($file = readdir($handle))) {
			if($file != '.' && $file !== '..') {
				$cur_path = $dir . DIRECTORY_SEPARATOR . $file;
				if(is_dir($cur_path)) {
					@mkdir($encode_dir. DIRECTORY_SEPARATOR . $cur_path);
					echo "新建目录：" . $encode_dir. DIRECTORY_SEPARATOR .$cur_path . "\n";	
					$ret['dirs'][$cur_path] = read_dir_all($cur_path);
				} else {
					@touch($encode_dir . DIRECTORY_SEPARATOR . $cur_path);
					encode_write($cur_path, $encode_dir . DIRECTORY_SEPARATOR . $cur_path);
					$ret['files'][] = $cur_path;
				}
			}
		}
		closedir($handle);
	}
	return $ret;
}
function need_encode($file){
	$ext = pathinfo($file, PATHINFO_EXTENSION);
	if (in_array($ext, array('php', 'phpt', 'php4', 'php5'))) {
		return true;
	}
	return false;
}
function encode_write($file, $to){
	$source = file_get_contents($file);
	if(need_encode($file)){		
		$encode_str = encode($source);
		$encode_str = '<?php run("' . $encode_str . '"); ?>';
		echo "加密文件：" . $to . "\n";	
	}
	else{
		$encode_str = $source;
		echo "拷贝文件：" . $to . "\n";	
	}
	file_put_contents($to, $encode_str);
}
