<?php
session_start();
include('../class/class_progmanager.php');
$prog= new progmanager();
$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
?>
<!DOCTYPE html>
<html>
<head>
<title></title>
<link rel="stylesheet" href="style.css" type="text/css">
</head>
<body>
	<div id="addprog">
		<form action="accueil.php" method="post">		
			<label>Nom du programme a ajouter</label><br>
			<input type="text" id="box" name="nomprog"><br>
			<input type="submit" class="btnset" value="ajouter programme" name="ajouterprogramme">
		</form>
	</div>
	<div id="deleteprog">
		<form>
			<label>Nom du programme a supprimer</label><br>
				<?php
				$bdd->listprog('','idp');
				?><br>
				<input type="submit" class="btnset" value="supprimer programme" name="DeleteProg">
		</form>
	</div>
	<div id="setprog">
		<form action="accueil.php" method="post">		
			<label>Nom du programme a modifier</label><br>
			<?php
			$bdd->listprog('','setprog');
			?><br>
			<button class="btnset"  value="setprog" name="modifprog" onclick="setnom($_POST['setprog'])">modifer programme</button>
		</form>
	</div>
	<div id="addscene">
		<form action="accueil.php" method="post">		
			<label>Nom de la scene a ajouter</label><br>
			<input type="text" id="box" name="nomscene"><br>
			<input type="submit" class="btnset" value="ajouter scene" name="ajouterscene">
		</form>
	</div>
	<div id="deletescene">
		<form>
			<label>Nom de la scene a supprimer</label><br>
			<?php
				$bdd->listscene('','ids');
			?><br>
			<input type="submit" class="btnset" value="supprimer scene" name="DeleteScene">
		</form>
	</div>
	<div id="setscene"></div>
	
	<div>
	<?php
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
			$prog->SupprimerProgramme($bdd,$_POST['idp']);
			echo "programme OK suppression (IHM)";
	}
	else
	{
		echo "ECHEC SUPPRESSION PROG (IHM)";
	}
///////////////////////////////////////////////////////////////////////
	// ajout de scene via le formulaire
	if (!empty($_POST['nomscene']) && isset($_POST['ajouterscene']))
	{
		$scen->Ajouterscene($bdd,$_POST['nomscene']);
		echo "scene OK ajout (IHM)";
	}
	else
	{
		echo "ECHEC AJOUT scene (IHM)";
	}

///////////////////////////////////////////////////////////////////////
	// suppression de programme via le formulaire
	if (!empty($_POST['DeleteScene']) && isset($_POST['ids']))
	{		
			$scen->SupprimerScene($bdd,$_POST['ids']);
			echo "programme OK suppression (IHM)";
	}
	else
	{
		echo "ECHEC SUPPRESSION Scene (IHM)";
	}	
///////////////////////////////////////////////////////////////////////
	?>	
	<div>
</body>
</html>
