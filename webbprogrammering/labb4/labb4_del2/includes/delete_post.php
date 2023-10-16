<?php
include("class.php");


if(isset($_POST['deletePost'])) {

    $data =  $_POST["deletePost"];
    $conn = mysqli_connect("localhost", "root", "", "guestbook");
    mysqli_query($conn, "DELETE FROM GuestBookTable WHERE postID = $data");
    $conn->close();

}
header("location:/labb4_webb/index.php");
?>