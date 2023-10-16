<?php
//session_start();

$username = $_POST['username'];
$password = $_POST['password'];

if ($username == "admin" && $password == "password") {
  $_SESSION['loggedin'] = true;
  header("Location: ../startPage.php");
  exit;
} else {
  header("Location: ../loginPage.php?error=true");
  exit;
}
?>