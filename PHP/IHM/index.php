<?php 
session_start();
include("../class/class_bdd_php.php") ?>

<!DOCTYPE html>
<html>

<head>
	<link rel="stylesheet" href="style.css" type="text/css">
	<title>Login</title>
</head>
<body>
						
	<?php 
	

		//on vérifie que le formulaire est rempli et qu'on appuie bien sur le bouton
		if (isset($_POST['button']) && !empty($_POST['username']) && !empty($_POST['password']))
		{

			$Utilisateur = new BDD($_POST['username'],$_POST['password'],'192.168.65.97','theater','root','root');
			$Utilisateur->compare('login');

			if($Utilisateur->isConnect())
			{
				echo"Connexion réussi!";
				$_SESSION['username']=$_POST['username'];
				$_SESSION['password']=$_POST['password'];
			}
			else
			{
				echo "Erreur: Login ou password incorrect!";
			}
		}

		//instance de l'objet de la classe utilisateur pour stocker dans la Session
		if(isset($_SESSION['username']))
		{

			$Utilisateur = new BDD($_SESSION['username'],$_SESSION['password'],'192.168.65.97','theater','root','root');
			
			?>
				<form action="index.php" method="post">	
					<input type="submit" id="button" name="deconnexion" value="DECONNEXION">
				</form>
			<?php
		}
		else
		{	
		//formulaire de connexion
			?>
			<div id="container">
				<h3>CONNEXION</h3>
					<form action="index.php" method="post">		
						<label>LOGIN<br>
						<input type="text" id="box" name="username"></label><br>
						<label>PASSWORD<br>
						<input type="password" id="box" name="password"></label>
						<input type="submit" id="button" name="button" value="CONNEXION"><br>
						<a href="index_inscription.php"> Inscription </a>
					</form>
			</div>

			<?php
		}
		//destruction de la variable SESSION
		if (isset($_POST['deconnexion']))
		{
				session_unset();
				session_destroy();
		}

		?>

			


</body>
</html>