<?php

session_start();

mysql_connect("localhost", "root", "password");
mysql_select_db("SecuryPi");



$username=$_POST['username'];
$password=$_POST['password'];

$username=stripcslashes($username);
$password=stripcslashes($password);

$username=mysql_real_escape_string($username);
$password=mysql_real_escape_string($password);


$result=mysql_query("Select * from Users where Username='$username' and Password='$password'");

$row=mysql_fetch_array($result);

$to = $row['Email'];


if($row['Username']== $username && $row['Password']== $password){
	
	header('Location: main.php');
	#echo "correct credentials";


}else{

	echo "error occured";
}


?>

