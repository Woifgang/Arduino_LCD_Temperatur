<?php
define('DB_SERVER',"127.0.0.3");
define('DB_NAME',"db289129_201");
define('DB_USER',"db289129_201");
define('DB_PASSWORD',"Swag1234");
 
$conn = mysql_connect(DB_SERVER, DB_USER, DB_PASSWORD);
if(is_resource($conn))
{
  mysql_select_db(DB_NAME, $conn);
  mysql_query("SET NAMES 'utf8'", $conn);
  mysql_query("SET CHARACTER SET 'utf8'", $conn);
}
?>