<?php

/**
 * 
 */
class TCP
{
	private $adr;
	private $port;
	private $socket;

	
	function __construct()
	{
		$this->socket = socket_create(AF_INET, SOCK_STREAM, 0);

		if ($this->socket === false) {
			echo "socket_connect() a échoué : ($result)".socket_strerror(socket_last_error($this->socket))."<br>";
		}
		else {
			echo "OK socket.<br>";
		}
	}

	function connexion($adr,$port)
	{

		$this->adr = $adr;
		$this->port = $port;
		
			$res = socket_connect($this->socket, $this->adr, $this->port);
	}

	function envoie($buffer)
	{
		$length = strlen($buffer);
		$res = socket_write($this->socket, $buffer, $length);
		return $res;	
	}
}

?>