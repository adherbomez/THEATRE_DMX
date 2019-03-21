<?php
//debut de session -- reccuperation des informations 
session_start();
include ('../class/class_bdd_php.php');
$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
?>

<!DOCTYPE html>

<html>
<head>
	<title>GESTION LUMIERE</title>
	<link rel="stylesheet" href="style.css" type="text/css">
</head>
<body>

	<?php 
	//test pour savoir si les variables de session sont disponibles
		if (isset($_SESSION['username']) AND isset($_SESSION['password']))
		{
		    echo 'Bonjour ' . $_SESSION['pseudo'];
		}
		else
		{
			echo 'pas de variable de session';
		}
	?>

	<form action="index.php" method="post">	
			<input type="submit" id="button" name="deconnexion" value="DECONNEXION">
	</form>


	<div>
		<form>	
			<p><button name="creerprog">ajouter un programme</button></p>
			<p><button name="deleteprog">supprimer un programme</button></p>
			<p><button name="setprog">modifier un programme</button></p>
		
		</form>
	</div>

	<div id="menuprog">
		<ul id="ongletsprog" type="circle">
		<?php 
		$bdd->Modelaccueil('');
		?>	
		</ul>
	</div>

	<?php
		//destruction de la variable SESSION
		if (isset($_POST['deconnexion']))
		{
				session_unset();
				session_destroy();
		}

		?>
</body>
</html>