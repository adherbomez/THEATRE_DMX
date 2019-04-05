<?php
//debut de session -- reccuperation des informations 
session_start();
require_once ('../class/class_bdd_php.php');
include("../class/class_socket.php");
require_once ("../class/class_progmanager.php");

$prog = new progmanager();
$sock= new TCP();

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
		if (isset($_SESSION['username']) && isset($_SESSION['password']))
		{
		    echo 'Bonjour ' . $_SESSION['username'];
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
			<p><button name="creerprog" onclick="ouvre_popup('progadd.php')">ajouter un programme</button></p>
			<p><button href ="#menuprog" name="deleteprog">supprimer un programme</button></p>
			<p><button   name="setprog">modifier un programme</button></p>
		</form>
	</div>

	<div id="menuprog">
		 <?php
		$bdd->Modelaccueil('');
		 ?>
	</div>

	<form  method="post">		
	<label>Nom du programme a ajouter</label><br>
	<input type="text" id="box" name="nomprog"><br>
	<input type="submit" value="valider" name="ajouterprogramme">
	</form>

	<div id="listprog">
		 <?php
		$bdd->listprog('');
		 ?>
	</div>

	

	<?php
		//destruction de la variable SESSION
		if (isset($_POST['deconnexion']))
		{
				session_unset();
				session_destroy();
		}
			if (!empty($_POST['nomprog']) && isset($_POST['ajouterprogramme']))
		{
				$prog->AjouterProgramme($bdd,$_POST['nomprog']);
				echo "programme OK ajout (IHM)";
		}
		else
		{
			echo "ECHEC AJOUT PROG (IHM)";
		}

		?>
</body>


<?php
//partie javascript qui contient AJAX + popup + modelisation des prog
?>
	<script type="text/javascript" src="../class/javascript.js"></script>
	
	<script type="text/javascript">
<?php
// function ouvre_popup(page) 
// 		{ 
// 			window.open(page,"nom_popup","menubar=yes, status=no, scrollbars=no, menubar=no, width=700, height=500"); 
// 		} 
?>

	</script>

	
</html>