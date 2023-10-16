<?php include("includes/config.php"); ?>
<?php
$page_title = "Start";
session_start();
if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
  // User is not logged in, redirect to login page
  header('Location: loginPage.php');
  exit;
}
include("includes/header.php");
include("includes/navbar.php");
include("includes/footer.php");






?>