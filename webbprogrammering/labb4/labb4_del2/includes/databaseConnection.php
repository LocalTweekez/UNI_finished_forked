<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "guestbook";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$conn->query("CREATE DATABASE IF NOT EXISTS guestbook");
$conn->query("USE guestbook");

$sql = "CREATE TABLE IF NOT EXISTS GuestBookTable(
    postId INT not null primary key AUTO_INCREMENT,
    username VARCHAR(100),
    postContent tinytext,
    postDate VARCHAR(100));";

$conn->query($sql);

$conn->close();


?>
