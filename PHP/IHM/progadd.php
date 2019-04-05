<?php
session_start();
include('../class/class_progmanager.php');
$prog= new progmanager();

?>
<!DOCTYPE html>
<html>
<head>
<title></title>
</head>
<body>
	<form action="progadd.php" method="post">		
	<label>nom du programme</label><br>
	<input type="text" id="box" name="nomprog"><br>
	<input type="submit" value="valider" name="ajouterprogramme">
	</form>

	<div>
	<?php
	if (isset($_POST['ajouterprogramme']) && !empty($_POST['nomprog']))
	{
			if($prog->ajouterprogramme("",$_POST['ajouterprogramme']))
			{
				echo 'programme ajouté';
			}	
			else
			{
				echo "echec de l'ajout du programme";
			}
		
	}
	?>	
	<div>
</body>
</html>
