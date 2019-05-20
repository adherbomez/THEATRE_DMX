<?php
//debut de session -- reccuperation des informations 
session_start();
require_once ('../class/class_bdd_php.php');
require_once ("../class/class_progmanager.php");
require_once ("../class/class_scenemanager.php");


require_once("../class/class_socket.php");

//$sock= new TCP();

// $sock->connexion('192.168.65.14','6666');
// $sock->envoie("connexion au serveur OK \n");
$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
$prog = new progmanager();
$scen= new scenemanager();

?>

<!DOCTYPE html>

<html>
<head>
	<title>GESTION LUMIERE</title>
	<link rel="stylesheet" href="style.css" type="text/css">

</head>
<body>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.0/jquery.min.js">
</script>		
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
	<div>			
		<div id="menu">

			<table >
			<tr>
				<td>
				<ul class="menutag">
					<li class=tag>PROGRAMME
						<ul>
							<a onclick="popup('./progadd.php#addprog');">
								<li class="tagadd">
								ajouter un programme
								</li>
							</a>
							<a onclick="popup('./progadd.php#deleteprog');">
							<li class="tag1">
								supprimer un programme 
							</li>
							</a>
							<a onclick="popup('./progadd.php#setprog');">
							<li class="tag1">
								modifier un programme
							</li>
							</a>	
						</ul> 			
					</li>
				</ul>
				</td>
				<td>
				<ul class="menutag">
					<li class=tag>SCENE
						<ul>
							<a onclick="popup('./progadd.php#addscene');">
							<li class="tag1">
								ajouter une scene
							</li>
							</a>
							<a onclick="popup('./progadd.php#deletescene');">
							<li class="tag1">
								supprimer une scene
							</li>
							</a>
							<a onclick="popup('./progadd.php#setscene');">
							<li class="tag1">
								modifier une scene
							</li>
							</a>
						</ul> 			
					</li>
				</ul>
			</td>
		</tr>
		</table>
			
		</div>
		<div id="Menuprog" >
			<?php
			$bdd->Modelaccueil('');
			?>
		</div>

	</div>
	
<?php
	//destruction de la variable SESSION
	if (isset($_POST['deconnexion']))
	{
			session_unset();
			session_destroy();
	}
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
	<script type="text/javascript" src="../class/javascript.js"></script>
	<script src="jquery.js"></script>
	<script>
		function setnom($champ){
			var rep;
			var titre=window.prompt("veuillez entrer le nouveau nom du programme","nom du programme");
			if(titre == null || titre == ""){
				rep="vous n'avez rien entré";
			}
			else
			{
			<?php
				echo "lancer la fonction";
			?>
			}
		}
		function refresh(url) {
			$.ajax({
			    url: this->url, // Ton fichier ou se trouve ton chat
			    success:
			    function(retour){
			        $('Menuprog').html(retour); // rafraichi toute ta DIV "bien sur il lui faut un id "
			    }
			});
			 
			}
	 	setInterval(refresh(), 1000) // Répète la fonction toutes les 10 sec

	</script>
	<script type="text/javascript">
	function popup(url)
	{
		newwin = window.open(url ,'','scrollbars=no,width=300,height=300,top=200,left=200' );
		if(newwin)
		{
		window.onfocus=function()
			{
				newwin.window.close()
			}
		}
	}
	</script>
	
</html>