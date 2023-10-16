<?php
include("class.php");

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $name = $_POST["userName"];
    $content = $_POST["postContent"];
    $date = date("G:i - d/m/Y");
    $post = new Post($name,$content, $date);
    $post->savePost();
    
}
header("location:../index.php");
?>
