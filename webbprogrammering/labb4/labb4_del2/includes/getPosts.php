<?php
function getPosts(){
    $conn = mysqli_connect("localhost", "root", "", "guestbook");
    $posts = mysqli_query($conn, "SELECT * FROM GuestBookTable ORDER BY postId DESC");
   
    
    while($row = mysqli_fetch_assoc($posts)){
        echo "<h6><strong>".$row["username"] ."</strong> • ". $row["postDate"] . ":</h6><br>" ;
        echo "<h2>". $row["postContent"]."</h3> <br>";
        echo "<form action='includes/delete_post.php' method='post'>".'<td><button type="submit" name="deletePost" id="button_remove" value="'.$row["postId"].'" />Delete post</button></td> <br><hr>';
        
    }

    $conn->close();
}

?>