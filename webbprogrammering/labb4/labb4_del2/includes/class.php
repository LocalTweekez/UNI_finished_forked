<?php
//this file contains the class post which is a container containing the necessary information for a post
//
class Post{
    protected $username;
    protected $postContent;
    protected $postDate;

    function __construct($name, $content, $date){
        $this->username =$name;
        $this->postContent =$content;
        $this->postDate =$date;
    }
    function __destruct(){

    }
    function getUsername(){
        return  $this->username;
    }
    function getPostContent(){
        return  $this->postContent;
    }
    function getPostDate(){
        return  $this->postDate;
    }

    function savePost(){

        $conn = mysqli_connect("localhost", "root", "", "guestbook");
        mysqli_query($conn, "INSERT INTO GuestBookTable(username, postContent,postDate)VALUES ('$this->username', '$this->postContent', '$this->postDate')");
        $conn->close();
    }
             
    }


?>