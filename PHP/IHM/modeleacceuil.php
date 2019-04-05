<?php
include ('../class/class_bdd_php.php');
	$res=new BDD('maxime','mdp','192.168.65.97','theater','root','root');

	$res->Modelaccueil($res);
?>