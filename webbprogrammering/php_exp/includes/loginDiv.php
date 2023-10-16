<!-- <style>
  .container{
    width: 50%;
    text-align: center;
    margin-top: 10%;
  }
  input{
    margin: 30px;
  }
</style> -->

<div class= container>

  <form action="includes/process_login.php" method="post">
    <label for="username">Username:</label>
    <input type="text" id="username" name="username"><br>
    
    <label for="password">Password:</label>
    <input type="password" id="password" name="password"><br>
    
    <input type="submit" value="Login">
  </form>
  
  <?php
if ($_GET['error']) {
  echo "<p>Invalid username or password.</p>";
}
?>
</div>