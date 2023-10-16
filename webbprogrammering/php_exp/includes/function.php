<?php
function createUnorderedListDiv($itemArray, $id = null, $class = null) {
    $idAttribute = $id ? 'id="' . $id . '"' : '';
    $classAttribute = $class ? 'class="' . $class . '"' : '';
    $listItems = '';
    foreach ($itemArray as $label => $item) {
      $listItems .= '<li><b>' . $label . ':</b> ' . $item . '</li>';
    }
    return '<div ' . $idAttribute . ' ' . $classAttribute . '><ul>' . $listItems . '</ul></div>';
}
  
  

?>


    
