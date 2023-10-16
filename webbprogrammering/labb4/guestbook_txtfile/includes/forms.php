<div class="container form-container">
    <h1><u> Create a post</u></h1><hr>
<form action="includes/process_form.php" method="post">
    <label for="userName">UserName:</label><br>
    <input type="text" name="userName" id=""><br><br>
    <label for="postContent">Message:</label><br>
    <textarea name="postContent" id="content-box" cols="40" rows="10"></textarea><br>
    <!--<input type="text" name="postContent" id="content-box"><br>-->
    <input type="submit" value="post" id="post-button">
</form>
</div>