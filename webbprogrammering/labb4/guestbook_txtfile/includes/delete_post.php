<?php
include("class.php");


if(isset($_POST['deletePost'])) {

    $data = str_replace("\r\n", '', $_POST["deletePost"]);
    $file = "posts.txt";

    $content = file_get_contents($file);
    $content = str_replace($data, '', $content);
    $content = preg_replace('/^[ \t]*[\r\n]+/m', '', $content);
    file_put_contents($file, $content);

    // $sql = "DELETE FROM tablename where id = '$delete'"; 

}
header("location:/labb4_webb/index.php");
?>