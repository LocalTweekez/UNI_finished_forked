<?php
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
        $data= "$this->username| $this->postContent| $this->postDate\n";
        file_put_contents("posts.txt", $data, FILE_APPEND);
    }
             
    }


?>