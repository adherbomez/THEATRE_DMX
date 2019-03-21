
<?php include("../class/class_bdd_php.php") ?>

<!DOCTYPE html>
<html>

<head>
	<link rel="stylesheet" href="style.css" type="text/css">
	<title>Login</title>
</head>
<body>
						
<?php 

	//on vérifie que le formulaire est rempli et qu'on appuie bien sur le bouton
	if (isset($_POST['button2']) && !empty($_POST['username2']) && !empty($_POST['password2']))
	{

		$Utilisateur = new BDD($_POST['username2'],$_POST['password2'],'192.168.65.97','theater','root','root','login');

		if($Utilisateur->isConnect())
		{
			echo"Connexion réussi!";	
		}
		

	//appelle de la fonction connexion
		$Utilisateur->inscription('login');
		
	}
	//formulaire d'inscription
	?>

		<div id="container2">
			<h3>INSCRIPTION</h3>
				<form action="index_inscription.php" method="post">		
					<label>LOGIN<br>
					<input type="text" id="box" name="username2"></label><br>
					<label>PASSWORD<br>
					<input type="password" id="box" name="password2"></label><br>
					<input type="submit" id="button2" name="button2"  value="INSCRIPTION"><br>
					<a href="index.php"> Connexion </a>
				</form>
		</div>


</body>
</html>