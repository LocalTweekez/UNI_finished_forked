<!-- <style>
  #infoBox{
    margin: 10%;
    border: solid;
    font-size:x-large;
  }
</style> -->

<?php
function createInfoBox(){
  
  include("includes/function.php");
  $day = date("l");
  $dateTime = date("d-m-Y").date(" h:i:sa");
  if ($day == "Friday") {
    $dateTime= $dateTime." yey it's friday";
  }
    
  $itemArray = array('Date/Time' => $dateTime
  , 'Your IP-adress:' => $_SERVER['REMOTE_ADDR']
  , 'Path/filename:' => dirname(__FILE__)
  , 'User-agent: ' =>$_SERVER['HTTP_USER_AGENT']);
  $infoBox = createUnorderedListDiv($itemArray, 'infoBox', 'container');
  echo $infoBox;
}

?>