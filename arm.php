<?php
#include 'login.php';
$myFile="Command.txt";
$fh = fopen($myFile, 'w') or die ("Can not open the file");
fwrite($fh, "ARM");
fclose($fh);
sleep(2);
exec('python3 /var/www/html/status.py', $retval);

if ($retval[0] == 1){
/*
$subject = "SecuryPi Alarm!";
$message = "Activity detected at: Living Room(Id_1)";
$from = "";
$headers = "From:".$from;
mail($to,$subject,$message,$headers);
*/
echo 'ALARM!! Activity has been detected at "Living Room (Id_1)" and email has been sent';

} elseif ($retval[0] == 2) {
/*
$subject = "SecuryPi Alarm!";
$message = "Activity detected at: Kitchen(Id_2)";
$from = "";
$headers = "From:".$from;
mail($to,$subject,$message,$headers);
*/
echo 'ALARM!! Activity has been detected at "Kitchen (Id_2)" and email has been sent';

} else{
  echo "System Failed please call assistance";
}
?>