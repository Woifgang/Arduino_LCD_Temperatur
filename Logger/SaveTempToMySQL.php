<?php
/***********************************************************************************
  Autor:   Enrico Sadlowski                                                        *
  Kontakt: profwebapps@gmail.com                                                   *
                                                                                   *
  PROJEKT: Arduino-MultiSensor-Temperatur-Ueberwachung                             *
  -------------------------------------------------------------------------------  *
                                                                                   *
  Arduino ruft dieses Script auf, uebergibt Innen- und Aussentemperatur            *
  (TI und TA) sowie einen Key (key), der mit dem hier angegebenen Key              *
  identisch sein muss.                                                             *
  Wenn der Key identisch ist und beide Temperaturwerte uebergeben wurden,          *
  werden die Temperaturwerte und das aktuelle Datum in der Datenbank gespeichert.  *
                                                                                   *
***********************************************************************************/
 
define("KEY","MEINPASSWORT123");
 
include("../inc/db.inc.php");
 
if(isset($_GET['key']))
{
  if($_GET['key'] == KEY)
  {
    if(isset($_GET['T1']) && isset($_GET['T2']))
    {
      $TEMP1 = mysql_real_escape_string($_GET['T1']);
      $TEMP2 = mysql_real_escape_string($_GET['T2']);
      $DATUM = date("Y-m-d H:i:s");
 
      $result = mysql_query("INSERT INTO arduino_temperaturen (datumzeit, temp1, temp2) 
              VALUES('".$DATUM."', '".$TEMP1."', '".$TEMP2."') ") or die(mysql_error());
 
      if(mysql_affected_rows() == 1)
      {
        $result = "Temperaturwerte gespeichert";
      } else $result = "Fehler beim speichern der Daten in der MySQL-Datenbank";
    } else $result = "Keine Temperaturwerte übergeben";
  } else $result = "Falscher Key";
} else $result = "Kein Key übergeben";
 
print_r($result);
?>