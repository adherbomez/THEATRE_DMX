


	$('#ajouterprogramme').click(function() 
	{
	    // L'URL du fichier dans lequel tu appelles ta fonctio
	    var url = '../IHM/modeleaccueil.php';
	    $.post(url, function(data)
	    {
		    // Tu affiches le contenu dans ta div
		    $('#menuprog').html(data);
	    });
});