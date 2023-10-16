<?php
function getPosts(){
    $posts = file("includes/posts.txt");
    //$postCount = explode("\n", $posts);
    for($i = sizeof($posts)-1; $i >=0; $i--){
        $parts = explode("|",$posts[$i]);
        echo "<h6><strong>".$parts[0] ."</strong> • ". $parts[2] . ":</h6><br>" ;
        echo "<h2>". $parts[1]."</h3> <br>";
        echo "<form action='includes/delete_post.php' method='post'>".'<td><button type="submit" name="deletePost" id="button_remove" value="'.$posts[$i].'" />Delete post</button></td> <br><hr>';
       
    }
}

?>