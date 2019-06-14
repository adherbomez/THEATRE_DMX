<?php
//debut de session -- reccuperation des informations 
session_start();
	//test pour savoir si les variables de session sont disponibles
		if (isset($_POST['$login']) && isset($_POST['$pass'] ))
		{
		  echo 'Bonjour ' . $_POST['$login'];
		}
		else
		{
			
		}

//initialisation des classes et des prérequis

require_once ('../class/class_bdd_php.php');
require_once ("../class/class_progmanager.php");
require_once ("../class/class_scenemanager.php");
require_once("../class/class_socket.php");

// definition des constantes

define('ipadress', 'localhost');
define('portsock', '9999');

//instanciation des classes

$sock= new TCP();
$sock->connexion(ipadress,portsock);
$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
$prog = new progmanager();
$scen= new scenemanager();

?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css">
	<link href="https://fonts.googleapis.com/css?family=Iceland|Monoton&display=swap" rel="stylesheet">

	<title>accueil SONO+</title>
</head>
<body>
			<!---------------------- ENTETE DU SITE ------------------------->
	
	<nav class="navbar navbar-dark bg-dark">
		
				<div class="col-offset-6"></div>
		 		<p class="h1">GESTION DES LUMIÈRES </p> 
		<form method="post">
  		  	<input class="btn btn-light" action="accueilboot.php" value="DECONNEXION" type="submit" name="deconnexion"> 
		</form>
	</nav>
		    
		   
		</nav>
	</div>
			<!---------------------- CORPS DU SITE ------------------------->
						<!---------------------- PARTIE MODELISATION DE LA BASE ------------------------->
	<div class="row" >
		<div class="col-md-8" id="menuprog">
			<div class="drop">
				<?php
					$bdd->Modelaccueil('');
				?>
			</div>
			
		</div>
		

			<!---------------------- CORPS DU SITE ------------------------->
						<!---------------------- PARTIE INTERRACTION AVEC LES PROGRAMMES ------------------------->

			<!-- ajout de programmes grace aux formulaires -->
		<div class="col-md-4"  id="settingsprog">
			<div class="contour">
				<h2>Nom du programme a supprimer</h2><br>
				<form  action="accueilboot.php" method="post">
						
						<?php
						$bdd->listprog('','idp');
						?>
						<br>
						<input type="submit"  class="btnset" value="supprimer programme" name="DeleteProg">
				</form>
			</div>

			<!-- suppression de programmes grace aux formulaires -->
			<div class="contour">
				
				<h2>Nom du programme a ajouter</h2><br>
				<form action="accueilboot.php" class="set" method="post">		
					<input style="max-width: 40%;" type="text" class="form-control" name="nomprog"><br>
					<input type="submit" class="btnset" value="ajouter programme" name="ajouterprogramme">
				</form>
			</div>
			<!-- ajout de scene a un programme grace aux formulaires -->
			<div class="contour">
				<h2>gestion des programmes </h2>
				<br><h6 class="contour">Pour ajouter une scène à un programme , choisissez un programme, une scene et un emplacement pour la scene</h6><br>
				<h6 class="contour">Pour supprimer une scène d'un programme , choisissez un programme, et l'emplacement de la scene à supprimer (l'emplacement)  </h6><br>

				<form method="post" action="accueilboot.php">
					<div id="scenelist">
						<label><h3>choisissez un programme</h3></label><br>
						<?php
							$bdd->listprog('','idp2');
						?>
							<br><label><h3>choisissez une scene</h3></label><br>
						<?php
							$bdd->listscene('','ids');
						?>

						<input style="max-width: 40%;" class="form-control" type="number" name="placescene" placeholder="place dans le programme " min="1" >	
					</div>

				
				<input type="submit" name="setscene" value="ajouter la scene au programme" >
				</form>
			</div>
				
			
			
		</div>
	</div>
			
		<?php
///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	// ajout de programme via le formulaire
	if (!empty($_POST['nomprog']) && isset($_POST['ajouterprogramme']))
	{
		$prog->AjouterProgramme($bdd,$_POST['nomprog']);
		echo "programme OK ajout (IHM)";
	}
	else
	{
		echo "ECHEC AJOUT PROG (IHM)";
	}

///////////////////////////////////////////////////////////////////////
	// suppression de programme via le formulaire
	if (!empty($_POST['DeleteProg']) && isset($_POST['idp']))
	{		
		echo "ya les variables";
		$prog->SupprimerProgramme($bdd,$_POST['idp']);
		echo "programme OK suppression (IHM)";
	}
	else
	{
		echo "ECHEC SUPPRESSION PROG (IHM)";
	}



///////////////////////////////////////////////////////////////////////
	// ajout de scene via le formulaire
	if (!empty($_POST['setscene']) && isset($_POST['ids']) && isset($_POST['idp2']) && isset($_POST['placescene']) )
	{
		if($_POST['ids'] == "")
			{
				$scen->SupprimerScene($bdd,$_POST['idp2'],$_POST['placescene']);

			}
		else
		{	

			if ($prog->compoexist($_POST['ids'],$_POST['placescene'])) 
			{
				$scen->ModifierScene($bdd,$_POST['idp2'],$_POST['ids'],$_POST['placescene']);
			}
			else 
			{
				$scen->AjouterScene($bdd,$_POST['idp2'],$_POST['ids'],$_POST['placescene']);
			}

		}
	
	}
	else
	{
		echo "probleme dans la saisie du formulaire";
	}

///////////////////////////////////////////////////////////////////////
	// suppression de scene du programme via le formulaire
	if (!empty($_POST['DeleteScene']) && isset($_POST['ids']))
	{		
		$scen->SupprimerScene($bdd,$_POST['ids']);
		echo "programme OK suppression (IHM)";
	}
	else
	{
		echo "ECHEC SUPPRESSION Scene (IHM)";
	}	
///////////////////////////////////////////////////////////////////////// 
	//lancement des scenes

	if(isset($_GET['item']))
	{
		$sock->envoie($_GET['item']);
	}

///////////////////////////////////////////////////////////////////////
	//destruction de la variable SESSION
		if (isset($_POST['deconnexion']))
		{
			session_unset();
			session_destroy();
			
		}
?>
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>

<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>

<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>
</html>